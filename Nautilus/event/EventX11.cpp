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

#ifndef _NT_WINDOW_EVENT_X11_cpp_
    #define _NT_WINDOW_EVENT_X11_cpp_

#include "Event.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>

namespace nt
{

    bool Event::isKeyDown(int key)
    {
        Display* display = XOpenDisplay(NULL);
        if (display == NULL)
            return false;

        XKeyboardState state;
        XGetKeyboardState(display, &state);

        KeyCode keycode = XKeysymToKeycode(display, key);

        if (keycode != 0)
            return (state.keybit[keycode >> 3] & (1 << (keycode & 7))) != 0;
        return false;
    }

    bool Event::isMouseButtonDown(int button)
    {
        Display* display = XOpenDisplay(NULL);
        if (display == NULL)
            return false;

        XEvent event;
        XQueryPointer(display, DefaultRootWindow(display), &event.xbutton.same_screen,
                      &event.xbutton.x, &event.xbutton.y, &event.xbutton.x_root, &event.xbutton.y_root,
                      &event.xbutton.state);

        return (event.xbutton.state & button) != 0;
    }

    Vec2f Event::getMousePosition()
    {
        Display* display = XOpenDisplay(NULL);
        if (display == NULL)
            return Vec2f(0.0f, 0.0f);

        Window root = DefaultRootWindow(display);
        Window child;
        int rootX, rootY, winX, winY;
        unsigned int mask;

        XQueryPointer(display, root, &root, &child, &rootX, &rootY, &winX, &winY, &mask);

        return Vec2f(static_cast<float>(rootX), static_cast<float>(rootY));
    }
} // namespace nt

#endif // _NT_WINDOW_EVENT_X11_cpp_
