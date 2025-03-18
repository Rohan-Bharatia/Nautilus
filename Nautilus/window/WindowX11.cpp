//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#ifndef _NT_WINDOW_WINDOW_X11_cpp_
    #define _NT_WINDOW_WINDOW_X11_cpp_

#include "WindowX11.h"

namespace nt
{
    WindowX11::WindowX11(const WindowDesc& desc) :
        m_display(nullptr), m_window(None), m_desc(desc)
    {}

    void WindowX11::initialize()
    {
        m_display = XOpenDisplay(nullptr);

        // Create window
        m_window = XCreateSimpleWindow(m_display, RootWindow(m_display, 0),
                                       m_desc.position.x, m_desc.position.y, m_desc.width, m_desc.height, 1,
                                       BlackPixel(m_display, 0), WhitePixel(m_display, 0));

        // Set window properties
        XSetWindowAttributes attrs;
        attrs.event_mask       = ExposureMask | KeyPressMask | ButtonPressMask;
        attrs.background_color = m_desc.backgroundColor.red << 16 | m_desc.backgroundColor.green << 8 | m_desc.backgroundColor.blue;
        XChangeWindowAttributes(m_display, m_window, CWEventMask, &attrs);

        // Map window
        XMapWindow(m_display, m_window);

        // Callback function
        if (m_desc.onCreate)
            m_desc.onCreate();
    }

    bool WindowX11::pollEvents()
    {
        XEvent event;
        while (XPending(m_display))
        {
            XNextEvent(m_display, &event);
            if (event.type == ClientMessage && event.xclient.data.l[0] == WM_DELETE_WINDOW)
                return false;
        }
        return true;
    }

    void WindowX11::update()
    {
        // Update window
        XFlush(m_display);

        // Callback function
        if (m_desc.onUpdate)
            m_desc.onUpdate();
    }

    void WindowX11::destroy()
    {
        // Callback function
        if (m_desc.onDestroy)
            m_desc.onDestroy();

        // Destroy window
        if (m_window)
            XDestroyWindow(m_display, m_window);
        if (m_display)
            XCloseDisplay(m_display);
    }

    void* WindowX11::getHandle()
    {
        return static_cast<void*>(m_window);
    }
} // namespace nt

#endif // _NT_WINDOW_WINDOW_X11_cpp_