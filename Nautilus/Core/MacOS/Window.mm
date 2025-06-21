#pragma region LICENSE

//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                                 ...
//
//                  Copyright (c) Rohan Bharatia 2025

#pragma endregion LICENSE

#ifndef _NT_CORE_MACOS_WINDOW_MM_
    #define _NT_CORE_MACOS_WINDOW_MM_

#import "../Window.h"

#import "../Logger.h"

@interface MacOSWindowDelegate : NSObject<NSWindowDelegate>
@property(nonatomic, assign) Nt::Window* window;
@end

@implementation MacOSWindowDelegate

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initwithFrame:frame];
}

- (void)windowDidResize:(NSNotification*)notification
{
    Nt::WindowResizeEvent event(self.window->m_handle.window.frame.size.width, self.window->m_handle.window.frame.size.height);
    self.window->m_eventCallback(event);
}

- (void)windowWillClose:(NSNotification*)notification
{
    Nt::WindowCloseEvent event;
    self.window->m_eventCallback(event);
}

@end

namespace Nt
{
    bool Window::Initialize(void)
    {
        NSApplication* app = [NSApplication sharedApplication];
        [app setActivityPolicy:NSApplicationActivityPolicyRegular];

        NSRect frame 	 = NSMakeRect(m_desc.position.x, m_desc.position.y, m_desc.width, m_desc.height);
        NSUInteger style = NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable;

        m_handle.window = [[NSWindow alloc] initWithContentRect: frame
                                                    styleMask:style
                                                        backing:NSBackingStoreBuffered
                                                            defer:NO];
        
        if (!m_handle.window)
        {
            [Logger Error:@"Failed to create window!"];
            return false;
        }

        [m_handle.window setTitle:[NSString stringWithUTF8String:m_desc.title.c_str()]];
        [[m_handle contentView] setBackgroundColor:[NSColor colorWithRed:m_desc.bgColor.r / 255.0f
                                                                    green:m_desc.bgColor.g / 255.0f
                                                                     blue:m_desc.bgColor.b / 255.0f
                                                                    alpha:m_desc.bgColor.a]];
        [m_handle.window makeKeyAndOrderFront:nil];

        m_handle.delegate = [[MacOSWindowDelegate alloc] init];
        
        if (!m_handle.delegate)
        {
            [Logger Error:@"Failed to create window delegate!"];
            return false;
        }

        m_delegate.window = this;

        [app finishLaunching];

        [m_handle.window setAcceptsMouseMovedEvents:YES];
        [m_handle.window makeFirstResponder:m_handle.window.contentView];

        return true;
    }

    void Window::OnUpdate(void)
    {
	    NSEvent* event;
        while ((event = [NSApp nextEventMatchingMask:NSEventMaskAny
                                            untilDate:nil
                                               inMode:NSDefaultRunLoopMode
                                              dequeue:YES]))
	
        {
            switch (event.type)
            {
            case NSEventTypeKeyDown:
            {
                KeyPressedEvent event1(event.keyCode, event.isARepeat));
                KeyTypedEvent event2(event.keyCode);
                m_eventCallback(event1);
                m_eventCallback(event2);
                break;
            }
            case NSEventTypeKeyUp:
            {
                KeyReleasedEvent event(event.keyCode);
                m_eventCallback(event);
                break;
            {
            case NSEventTypeLeftMouseDown:
            case NSEventTypeRightMouseDown:
            case NSEventTypeOtherMouseDown:
            {
                MouseButtonPressedEvent event(event.buttonNumber);
                m_eventCallback(event);
                break;
            }
            case NSEventTypeLeftMouseUp:
            case NSEventTypeRightMouseDown:
            case NSEventTypeOtherMouseDown:
            {
                MouseButtonReleasedEvent event(event.buttonNumber);
                m_eventCallback(event);
                break;
            }
            case NSEventTypeMouseMoved:
            case NSEventTypeLeftMouseMoved:
            case NSEventTypeRightMouseMoved:
            case NSEventTypeOtherMouseMoved:
            {
                MouseMovedEvent event(event.locationInWindow.x, event.locationInWindow.y);
                m_eventCallback(event);
                break;
            }
            case NSEventTypeScrollWheel:
            {
                MouseScrolledEvent event(event.scrollingDeltaX, event.scrollingDeltaY);
                m_eventCallback(event);
                break;
            }
            default:
                break;
            }

            [NSApp sendEvent:event];
        }
    }

    void Window::Shutdown(void)
    {
        [m_handle.window close];
        [m_handle.delegate release];

        NT_SAFE_DELETE(m_handle.window);
        NT_SAFE_DELETE(m_handle.delegate);
    }

    Rect Window::GetSize(void)
    {
        NSRect frame = [m_handle.window frame];
        return Rect(frame.origin.x, frame.origin.y, frame.size.width, frame.size.height);
    }
} // namespace Nt

#endif // _NT_CORE_MACOS_WINDOW_MM_
