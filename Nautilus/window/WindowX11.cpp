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

#ifndef _NT_WINDOW_WINDOW_X11_cpp_
    #define _NT_WINDOW_WINDOW_X11_cpp_

#include "WindowX11.h"

namespace nt
{
    WindowX11::WindowX11(const WindowDesc& desc) :
        m_desc(desc), m_display(nullptr), m_window(None)
    {}

    void WindowX11::initialize()
    {
        // Set window properties
        XSetWindowAttributes attrs;
        attrs.event_mask       = ExposureMask | KeyPressMask | ButtonPressMask;
        attrs.background_pixel = m_desc.backgroundColor.red << 16 | m_desc.backgroundColor.green << 8 | m_desc.backgroundColor.blue;

        if (!m_desc.resizable)
            attrs.override_redirect = True;
            if (!m_desc.movable)
                attrs.override_redirect = True;
            if (!m_desc.closable)
                attrs.override_redirect = True;
            if (!m_desc.maximizable)
                attrs.override_redirect = True;
            if (!m_desc.minimizable)
                attrs.override_redirect = True;
            if (!m_desc.canFullscreen)
                attrs.override_redirect = True;

            // Create window
            m_display = XOpenDisplay(nullptr);
            m_window = XCreateWindow(m_display, RootWindow(m_display, 0), m_desc.position.x, m_desc.position.y,
                                     m_desc.width, m_desc.height, 1, CopyFromParent, InputOutput, NULL,
                                     CWEventMask | CWOverrideRedirect, &attrs);

        // Center window (if necessary)
        if (m_desc.centered)
        {
            int screenWidth  = DisplayWidth(m_display, 0);
            int screenHeight = DisplayHeight(m_display, 0);
            int x            = (screenWidth - m_desc.width) / 2;
            int y            = (screenHeight - m_desc.height) / 2;
            XMoveWindow(m_display, m_window, x, y);
        }

        // Set window states
        if (m_desc.visible)
        {
            if (m_desc.fullscreen)
            {
                XEvent event;
                event.type                   = MapNotify;
                event.xmap.window            = m_window;
                event.xmap.event             = m_window;
                event.xmap.display           = m_display;
                event.xmap.override_redirect = False;
                XSendEvent(m_display, m_window, False, StructureNotifyMask, &event);
            }
            if (m_desc.maximized)
            {
                XEvent event;
                event.type                   = MapNotify;
                event.xmap.window            = m_window;
                event.xmap.event             = m_window;
                event.xmap.display           = m_display;
                event.xmap.override_redirect = False;
                XSendEvent(m_display, m_window, False, StructureNotifyMask, &event);
            }
            if (m_desc.minimized)
                XIconifyWindow(m_display, m_window, 0);
            if (!m_desc.fullscreen && !m_desc.maximized && !m_desc.minimized)
                XMapWindow(m_display, m_window);
        }
        else
            XUnmapWindow(m_display, m_window);

        // Set focus
        if (m_desc.focused)
            XSetInputFocus(m_display, m_window, RevertToParent, CurrentTime);

        // Set modal state
        if (m_desc.modal)
        {
            XGrabKeyboard(m_display, m_window, True, GrabModeAsync, GrabModeAsync, CurrentTime);
            XGrabPointer(m_display, m_window, True, ButtonPressMask | ButtonReleaseMask, GrabModeAsync, GrabModeAsync, None, None, CurrentTime);
        }

        // Callback function
        if (m_desc.onCreate)
            m_desc.onCreate();
    }

    bool WindowX11::pollEvents()
    {
        Atom WM_DELETE_WINDOW = XInternAtom(m_display, "WM_DELETE_WINDOW", False);
        XSetWMProtocols(m_display, m_window, &WM_DELETE_WINDOW, 1);

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
        return static_cast<void*>(&m_window);
    }

    WindowDesc WindowX11::getDescription()
    {
        return m_desc;
    }
} // namespace nt

#endif // _NT_WINDOW_WINDOW_X11_cpp_
