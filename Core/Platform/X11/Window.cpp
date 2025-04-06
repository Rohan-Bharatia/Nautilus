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

#ifndef _NT_CORE_PLATFORM_X11_WINDOW_CPP_
    #define _NT_CORE_PLATFORM_X11_WINDOW_CPP_

#include "../Window.h"

#include "../../Logger.h"

namespace nt
{
    void Window::create(const WindowDesc& desc)
    {
        m_desc    = desc;
        m_display = XOpenDisplay(NULL);
        if (!m_display)
        {
            Logger::error("Failed to open display!");
            abort();
        }

        m_window = XCreateSimpleWindow(display, RootWindow(display, DefaultScreen(display)), desc.x, desc.y, desc.width, desc.height, 1, BlackPixel(m_display, 0), WhitePixel(m_display, 0));
        if (!m_window)
        {
            Logger::error("Failed to create window!");
            abort();
        }

        // Set the window title
        // XTextProperty name;
        // name.value    = (unsigned char*)desc.title.c_str();
        // name.encoding = XA_STRING;
        // name.format   = 8;
        // name.nitems   = desc.title.length();
        // XSetWMName(m_display, m_window, &name);

        // Set the window title & color (RGB)
        uint32_t color = desc.bgColor.r << 16 | desc.bgColor.g << 8 | desc.bgColor.b;
        XStoreName(m_display, m_window, desc.title.c_str());
        XSetWindowBackground(m_display, m_window, color);


        // Map the window to the screen
        XMapWindow(m_display, m_window);

        // Set up the window's event mask
        unsigned long eventMask = ExposureMask | KeyPressMask | KeyReleaseMask | ButtonPressMask | ButtonReleaseMask | PointerMotionMask;
        XSelectInput(m_display, m_window, eventMask);
    }

    bool Window::pollEvents()
    {
        XEvent event;
        while (XPending(m_display))
        {
            XNextEvent(m_display, &event);

            if (event.type == ClientMessage)
            {
                // Handle client message event (e.g. window close request)
                if (event.xclient.data.l[0] == XInternAtom(m_display, "WM_DELETE_WINDOW", False))
                    return false;
            }
        }

        return true;
    }

    void Window::update()
    {
        XFlush(m_display);
    }

    void Window::destroy()
    {
        if (m_window)
            XDestroyWindow(m_display, m_window);

        if (m_display)
            XCloseDisplay(m_display);
    }

    void* Window::getNativeHandle()
    {
        return (void*)m_window;
    }

    float Window::getDeltaTime()
    {
        static unsigned long lastTime = 0;
        unsigned long currentTime     = XGetTime(m_display);
        float deltaTime               = (currentTime - lastTime) / 1000.0f;
        lastTime                      = currentTime;
        return deltaTime;
    }

    Rect Window::getSize()
    {
        XWindowAttributes attributes;
        XGetWindowAttributes(m_display, m_window, &attributes);
        return Rect(attributes.x, attributes.y, attributes.width, attributes.height);
    }
}

#endif // _NT_CORE_PLATFORM_X11_WINDOW_CPP_
