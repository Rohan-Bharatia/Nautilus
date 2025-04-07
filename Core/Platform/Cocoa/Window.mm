//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                                 ...
//
//                  Copyright (c) Rohan Bharatia 2025

#import "../Window.h"

#import "../../Logger.h"

@interface Window : WindowDesc
{
    WindowDesc m_desc;
}

@interface Window : NSObject
{
    UIWindow* m_window;
}

namespace nt
{
    void Window::create(const WindowDesc& desc)
    {
        m_desc = desc;

        NSWindowStyleMask style = NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskMiniaturizable;

        if (!desc.resizable)
            style &= ~(NSWindowStyleMaskResizable);
        if (desc.borderless)
            style &= ~(NSWindowStyleMaskTitled);
        if (desc.fullscreenable)
            style |= NSWindowStyleMaskFullScreen;
        if (!desc.maximizable)
            style &= ~(NSWindowStyleMaskZoomable);
        if (!desc.minimizable)
            style &= ~(NSWindowStyleMaskMiniaturizable);

        m_window = [[NSWindow alloc] initWithContentRect:NSMakeRect(desc.x, desc.y, desc.width, desc.height)
                                                styleMask:style
                                                  backing:NSBackingStoreBuffered
                                                    defer:NO];

        if (!m_window)
        {
            Logger::error("Failed to create window!");
            abort();
        }

        [m_window setTitle:[NSString stringWithUTF8String:desc.title.c_str()]];
        [m_window setBackgroundColor:[NSColor colorWithRed:m_desc.bgColor.r green:m_desc.bgColor.g blue:m_desc.bgColor.b alpha:m_desc.bgColor.a]];

        if (desc.fullscreen)
        {
            [m_window setFrame:[[NSScreen mainScreen] frame] display:YES];
            [m_window setCollectionBehavior:NSWindowCollectionBehaviorFullScreenPrimary];
        }
        else if (desc.maximized)
        {
            [m_window setFrame:[[NSScreen mainScreen] frame] display:YES];
            [m_window setCollectionBehavior:NSWindowCollectionBehaviorFullScreenAuxiliary];
        }
        else if (desc.minimized)
            [m_window miniaturize:nil];
        else if (desc.modal)
            [m_window setLevel:NSModalPanelWindowLevel];

        [m_window makeKeyAndOrderFront:nil];
    }

    bool Window::pollEvents()
    {
        NSEvent* event;
        while ((event = [NSApp nextEventMatchingMask:NSEventMaskAny untilDate:nil inMode:NSDefaultRunLoopMode dequeue:YES]))
            [NSApp sendEvent:event];
        return true;
    }

    void Window::update()
    {
        [NSApp updateWindows];
    }

    void Window::destroy()
    {
        if (m_window)
        {
            [m_window close];
            [m_window release];
        }
    }

    NSWindow* Window::getNativeHandle()
    {
        return m_window;
    }

    float Window::getDeltaTime()
    {
        static CFTimeInterval lastTime = 0;
        CFTimeInterval currentTime     = CFAbsoluteTimeGetCurrent();
        float deltaTime                = (currentTime - lastTime);
        lastTime                       = currentTime;
        return deltaTime;
    }

    Rect Window::getSize()
    {
        return Rect(m_window.frame.origin.x, m_window.frame.origin.y, m_window.frame.size.width, m_window.frame.size.height);
    }
}
