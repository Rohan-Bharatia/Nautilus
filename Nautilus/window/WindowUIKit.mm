//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#import "WindowIOS.h"

namespace nt
{
    WindowIOS::WindowIOS(const WindowDesc& desc) :
        m_window(nullptr), m_desc(desc)
    {}

    void WindowIOS::initialize()
    {
        // Create window
        m_window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];

        // Set window properties
        m_window.backgroundColor = [UIColor colorWithRed:m_desc.backgroundColor.red / 255.0
                                                    green:m_desc.backgroundColor.green / 255.0
                                                     blue:m_desc.backgroundColor.blue / 255.0
                                                    alpha:1.0];

        // Make window visible
        [m_window makeKeyAndVisible];

        // Callback function
        if (m_desc.onCreate)
            m_desc.onCreate();
    }

    bool WindowIOS::pollEvents()
    {
        // Poll events
        [[UIApplication sharedApplication] processEvents];

        return true;
    }

    void WindowIOS::update()
    {
        // Update window
        [m_window setNeedsDisplay];

        // Callback function
        if (m_desc.onUpdate)
            m_desc.onUpdate();
    }

    void WindowIOS::destroy()
    {
        // Callback function
        if (m_desc.onDestroy)
            m_desc.onDestroy();

        // Destroy window
        if (m_window)
            [m_window setHidden:YES];
    }

    void* WindowIOS::getHandle()
    {
        return static_cast<void*>(m_window);
    }
} // namespace nt