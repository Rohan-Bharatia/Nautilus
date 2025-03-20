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
        m_window(nullptr), m_desc(desc)
    {}

    void WindowCocoa::initialize()
    {
        // Create window
        m_window = [[NSWindow alloc] initWithContentRect:NSMakeRect(m_desc.position.x, m_desc.position.y, m_desc.width, m_desc.height)
                                               styleMask:NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskMiniaturizable
                                                 backing:NSBackingStoreBuffered
                                                   defer:NO];

        // Set window properties
        [m_window setTitle:m_desc.title.c_str()];
        [m_window setBackgroundColor:[NSColor colorWithCalibratedRed:m_desc.backgroundColor.red / 255.0
                                                                 green:m_desc.backgroundColor.green / 255.0
                                                                  blue:m_desc.backgroundColor.blue / 255.0
                                                                 alpha:1.0]];

        // Make window visible
        [m_window makeKeyAndOrderFront:nil];

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
