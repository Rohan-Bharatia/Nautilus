#pragma region LICENSE

//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2025 Rohan Bharatia

#pragma endregion LICENSE

#import "WindowCocoa.h"

namespace nt
{
    WindowCocoa::WindowCocoa(const WindowDesc& desc) :
        m_desc(desc), m_window(nullptr)
    {}

    void WindowCocoa::initialize()
    {
        // Set window properties
        NSWindowStyleMask style = NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskMiniaturizable | NSWindowStyleMaskResizable;
        if (!m_desc.resizable)
            style &= ~NSWindowStyleMaskResizable;
        if (!m_desc.movable)
            style &= ~NSWindowStyleMaskTitled;
        if (!m_desc.closable)
            style &= ~NSWindowStyleMaskClosable;
        if (!m_desc.maximizable)
            style &= ~NSWindowStyleMaskMiniaturizable;
        if (!m_desc.minimizable)
            style &= ~NSWindowStyleMaskMiniaturizable;
        if (!m_desc.canFullscreen)
            style &= ~NSWindowStyleMaskFullSizeContentView;

        // Create window
        m_window = [[NSWindow alloc] initWithContentRect:NSMakeRect(m_desc.position.x, m_desc.position.y, m_desc.width, m_desc.height)
                                               styleMask:style
                                                 backing:NSBackingStoreBuffered
                                                   defer:NO];

        // Center window (if necessary)
        if (m_desc.centered)
        {
            NSRect screenRect = [[NSScreen mainScreen] frame];
            NSRect windowRect = [m_window frame];
            float x           = (screenRect.size.width - windowRect.size.width) / 2;
            float y           = (screenRect.size.height - windowRect.size.height) / 2;
            [m_window setFrameOrigin:NSMakePoint(x, y)];
        }

        // Set window title & color
        [m_window setTitle:m_desc.title.c_str()];
        [m_window setBackgroundColor:[NSColor colorWithCalibratedRed:m_desc.backgroundColor.red / 255.0
                                                                 green:m_desc.backgroundColor.green / 255.0
                                                                  blue:m_desc.backgroundColor.blue / 255.0
                                                                 alpha:1.0]];

        // Set window states
        if (m_desc.visible)
        {
            if (m_desc.fullscreen)
            {
                [m_window setContentSize:[[NSScreen mainScreen] frame].size];
                [m_window setFrame:[[NSScreen mainScreen] frame] display:YES];
            }
            if (m_desc.maximized)
            {
                [m_window setContentSize:[[NSScreen mainScreen] frame].size];
                [m_window setFrame:[[NSScreen mainScreen] frame] display:YES];
            }
            if (m_desc.minimized)
                [m_window miniaturize:nil];
            if (!m_desc.fullscreen && !m_desc.maximized && !m_desc.minimized)
                [m_window orderOut:nil];
        }
        else
            [m_window makeKeyAndOrderFront:nil];

        // Set focus
        if (m_desc.focus)
            [m_window makeFirstResponder:nil];

        // Set modal state
        if (m_desc.modal)
            [NSApp runModalForWindow:m_window];

        // Callback function
        if (m_desc.onCreate)
            m_desc.onCreate();
    }

    bool WindowCocoa::pollEvents()
    {
        // Poll events
        NSEvent* event = [NSApp nextEventMatchingMask:NSEventMaskAny
                                            untilDate:[NSDate distantPast]
                                              inMode:NSDefaultRunLoopMode
                                             dequeue:YES];

        if (event)
        {
            [NSApp sendEvent:event];
            return true;
        }

        return false;
    }

    void WindowCocoa::update()
    {
        // Update window
        [m_window display];

        // Callback function
        if (m_desc.onUpdate)
            m_desc.onUpdate();
    }

    void WindowCocoa::destroy()
    {
        // Callback function
        if (m_desc.onDestroy)
            m_desc.onDestroy();

        // Destroy window
        if (m_window)
            [m_window close];
    }

    void* WindowCocoa::getHandle()
    {
        return static_cast<void*>(m_window);
    }

    WindowDesc WindowCocoa::getDescription()
    {
        return m_desc;
    }
} // namespace nt
