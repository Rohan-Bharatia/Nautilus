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

#ifndef _NT_CORE_PLATFORM_UNIX_WINDOW_CPP_
    #define _NT_CORE_PLATFORM_UNIX_WINDOW_CPP_

#include "../Window.h"

#include "../../Logger.h"

namespace nt
{
    bool Window::initialize(const WindowDesc& desc)
    {
        m_desc = desc;

        m_handle.display = XOpenDisplay(NULL);

        if (!m_handle.display)
        {
            Logger::error("Failed to open display!");
            return false;
        }

        XSetWindowAttributes attributes;
        attributes.event_mask = ExposureMask | KeyPressMask | KeyReleaseMask | ButtonPressMask | ButtonReleaseMask | PointerMotionMask;

        if (!desc.resizable)
            attributes.event_mask &= ~(ConfigureRequestMask | ConfigureNotifyMask);
        if (desc.borderless)
            attributes.border_width = 0;
        else
            attributes.border_width = 1;
        if (desc.fullscreenable)
            attributes.event_mask |= StructureNotifyMask;
        if (desc.maximizable)
            attributes.event_mask |= StructureNotifyMask;
        if (desc.minimizable)
            attributes.event_mask |= StructureNotifyMask;

        m_handle.window = XCreateWindow(m_handle.display, RootWindow(m_handle.display, DefaultScreen(m_handle.display)), desc.x, desc.y, desc.width, desc.height, attributes.border_width, CopyFromParent, InputOutput, CopyFromParent, CWEventMask | CWBorderWidth, &attributes);

        if (!m_handle.window)
        {
            Logger::error("Failed to create window!");
            return false;
        }

        // Set the window title
        XTextProperty name;
        name.value    = (unsigned char*)desc.title.c_str();
        name.encoding = XA_STRING;
        name.format   = 8;
        name.nitems   = desc.title.length();
        XSetWMName(m_handle.display, m_handle.window, &name);

        // Set the window title & color (RGB)
        uint32_t color = desc.bgColor.r << 16 | desc.bgColor.g << 8 | desc.bgColor.b;
        XStoreName(m_handle.display, m_handle.window, desc.title.c_str());
        XSetWindowBackground(m_handle.display, m_handle.window, color);

        // Map the window to the screen
        XMapWindow(m_handle.display, m_handle.window);

        // Set up the window's event mask
        XSelectInput(m_handle.display, m_handle.window, attributes.event_mask);

        if (desc.fullscreen)
        {
            XEvent event;
            event.type = MapNotify;
            event.xmap.window = m_handle.window;
            event.xmap.event  = m_handle.window;
            event.xmap.x      = 0;
            event.xmap.y      = 0;
            event.xmap.width  = DisplayWidth(m_handle.display, DefaultScreen(m_handle.display));
            event.xmap.height = DisplayHeight(m_handle.display, DefaultScreen(m_handle.display));
            XSendEvent(m_handle.display, m_handle.window, False, StructureNotifyMask, &event);
        }
        else if (desc.maximized)
        {
            XEvent event;
            event.type              = ConfigureNotify;
            event.xconfigure.window = m_handle.window;
            event.xconfigure.event  = m_handle.window;
            event.xconfigure.x      = 0;
            event.xconfigure.y      = 0;
            event.xconfigure.width  = DisplayWidth(m_handle.display, DefaultScreen(m_handle.display));
            event.xconfigure.height = DisplayHeight(m_handle.display, DefaultScreen(m_handle.display));
            XSendEvent(m_handle.display, m_handle.window, False, StructureNotifyMask, &event);
        }
        else if (desc.minimized)
        {
            XIconifyWindow(m_handle.display, m_handle.window, DefaultScreen(m_display));
        }
        else if (desc.modal)
        {
            XSetWindowAttributes attr;
            attr.override_redirect = True;
            XChangeWindowAttributes(m_handle.display, m_handle.window, CWOverrideRedirect, &attr);
        }

        if (desc.onCreate)
            desc.onCreate();

        return true;
    }

    bool Window::pollEvents()
    {
        XEvent event;
        while (XPending(m_handle.display))
        {
            XNextEvent(m_handle.display, &event);

            if (event.type == ClientMessage)
            {
                if (event.xclient.data.l[0] == XInternAtom(m_display, "WM_DELETE_WINDOW", False))
                    return false;
            }
        }

        return true;
    }

    void Window::update()
    {
        XFlush(m_handle.display);

        if (m_desc.onUpdate)
            m_desc.onUpdate();
    }

    void Window::close()
    {
        if (m_desc.onClose)
            m_desc.onClose();

        if (m_handle.window)
            XDestroyWindow(m_handle.display, m_handle.window);
        if (m_handle.display)
            XCloseDisplay(m_handle.display);
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

#endif // _NT_CORE_PLATFORM_UNIX_WINDOW_CPP_
