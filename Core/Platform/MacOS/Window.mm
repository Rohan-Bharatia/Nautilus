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
    NSWindow* m_handle.window;
}

namespace nt
{
    bool Window::initialize(const WindowDesc& desc)
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

        m_handle.window = [[NSWindow alloc] initWithContentRect:NSMakeRect(desc.x, desc.y, desc.width, desc.height)
                                                        styleMask:style
                                                          backing:NSBackingStoreBuffered
                                                            defer:NO];

        if (!m_handle.window)
        {
            [Logger error:"Failed to create window!"];
            return false;
        }

        [m_handle.window setTitle:[NSString stringWithUTF8String:desc.title.c_str()]];
        [m_handle.window setBackgroundColor:[NSColor colorWithRed:m_desc.bgColor.r green:m_desc.bgColor.g blue:m_desc.bgColor.b alpha:m_desc.bgColor.a]];

        if (desc.fullscreen)
        {
            [m_handle.window setFrame:[[NSScreen mainScreen] frame] display:YES];
            [m_handle.window setCollectionBehavior:NSWindowCollectionBehaviorFullScreenPrimary];
        }
        else if (desc.maximized)
        {
            [m_handle.window setFrame:[[NSScreen mainScreen] frame] display:YES];
            [m_handle.window setCollectionBehavior:NSWindowCollectionBehaviorFullScreenAuxiliary];
        }
        else if (desc.minimized)
            [m_handle.window miniaturize:nil];
        else if (desc.modal)
            [m_handle.window setLevel:NSModalPanelWindowLevel];

        [m_handle.window makeKeyAndOrderFront:nil];

        if (desc.onCreate)
            [desc onCreate];

        return true;
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

        if (desc.onUpdate)
            [desc onUpdate];
    }

    void Window::close()
    {
        if (desc.onClose)
            [desc onClose];

        if (m_handle.window)
        {
            [m_handle.window close];
            [m_handle.window release];
        }
    }

    const WindowDesc& Window::getWindowDesc() const
    {
        return m_desc;
    }

    const NativeHandle& Window::getHandle() const
    {
        return m_handle;
    }
} // namespace nt
