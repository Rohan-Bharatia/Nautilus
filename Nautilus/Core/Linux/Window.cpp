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

#ifndef _NT_CORE_LINUX_WINDOW_CPP_
    #define _NT_CORE_LINUX_WINDOW_CPP_

#include "../Window.h"

#include "../Logger.h"

namespace Nt
{
    static char* ColorToHex(Color col)
    {
	static char hex[8];
    	snprintf(hex, sizeof(hex), "#%02X%02X%02X",
		 NT_STATIC_CAST(uint8, col.r) & 0xff,
		 NT_STATIC_CAST(uint8, col.g) & 0xff,
		 NT_STATIC_CAST(uint8, col.b) & 0xff);
    	return hex;
    }

    bool Window::Initialize(void)
    {
	m_handle.display = XOpenDisplay(nullptr);

	if (!m_handle.display)
	{
	    Logger::Error("Failed to open displzy!");
	    return false;
	}

	int24 screen    = DefaultScreen(m_handle.display);
	::Window root   = RootWindow(m_handle.display, screen);
	XVisualInfo* vi = new XVisualInfo;
	
	XMatchVisualInfo(m_handle.display, screen, 24, TrueColor, vi);
	m_handle.colormap = XCreateColormap(m_handle.display,root, vi->visual, AllocNone);

	XSetWindowAttributes swa{};
	swa.event_mask = ExposureMask | KeyPressMask | KeyReleaseMask |
			 ButtonPressMask | ButtonReleaseMask |
			 PointerMotionMask | StructureNotifyMask;
	swa.colormap   = m_handle.colormap;

	m_handle.window = XCreateWindow(m_handle.display, root, m_desc.position.x, m_desc.position.y,
					m_desc.width, m_desc.height, 0, vi->depth, InputOutput, vi->visual,
					CWColormap | CWEventMask, &swa);

	if (!m_handle.window)
	{
	    Logger::Error("Failed to create window!");
	    return false;
	}

	XStoreName(m_handle.display, m_handle.window, m_desc.title.c_str());
	XMapWindow(m_handle.display, m_handle.window);

	XColor col;
	XParseColor(m_handle.display, m_handle.colormap, ColorToHex(m_desc.bgColor), &col);
	XAllocColor(m_handle.display, m_handle.colormap, &col);

	XSetWindowBackground(m_handle.display, m_handle.window, col.pixel);

	XClearWindow(m_handle.display, m_handle.window);
	XFlush(m_handle.display);

	return true;
    }

    void Window::OnUpdate(void)
    {
	while (XPending(m_handle.display))
	{
	    XEvent e;
	    XNextEvent(m_handle.display, &e);

	    switch (e.type)
	    {
		case KeyPress:
		{
		    KeyPressedEvent event1(e.xkey.keycode, 0);
		    KeyTypedEvent event2(e.xkey.keycode);
		    m_eventCallback(event1);
		    m_eventCallback(event2);
		    break;
		}
		case KeyRelease:
		{
		    KeyReleasedEvent event(e.xkey.keycode);
		    m_eventCallback(event);
		    break;
		}
		case ButtonPress:
		{
		    if (e.xbutton.button == Button4 || e.xbutton.button == Button5)
		    {
		    	MouseScrolledEvent event(0.0f, (e.xbutton.button == Button4) ? 1.0f : -1.0f);
		    	m_eventCallback(event);
		    }
		    else
		    {
			MouseButtonPressedEvent event(e.xbutton.button);
			m_eventCallback(event);
		    }
		    break;
		}
		case ButtonRelease:
		{
		    MouseButtonReleasedEvent event(e.xbutton.button);
		    m_eventCallback(event);
		    break;
		}
		case MotionNotify:
		{
		    MouseMovedEvent event(e.xmotion.x, e.xmotion.y);
		    m_eventCallback(event);
		    break;
		}
		case ConfigureNotify:
		{
		    WindowResizeEvent event(e.xconfigure.width, e.xconfigure.height);
		    m_eventCallback(event);
		    break;
		}
		case ClientMessage:
		{
		    WindowCloseEvent event;
		    m_eventCallback(event);
		    break;
		}
		default:
		    break;
	    }
	}
    }

    void Window::Shutdown(void)
    {
	XDestroyWindow(m_handle.display, m_handle.window);
	XFreeColormap(m_handle.display, m_handle.colormap);
	XCloseDisplay(m_handle.display);

	NT_SAFE_DELETE(m_handle.display);
    }
} // namespace Nt

#endif // _NT_CORE_LINUX_WINDOW_CPP_
