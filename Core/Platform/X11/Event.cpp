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

#ifndef _NT_CORE_PLATFORM_X11_KEYBOARD_CPP_
    #define _NT_CORE_PLATFORM_X11_KEYBOARD_CPP_

#include "../Event.h"

#include "../Logger.h"
#include "../API.h"

namespace nt
{
    bool Event<EVENT_KEYBOARD>::isKeyPressed(int key)
    {
        Display* display = XOpenDisplay(NULL);
        if (display == NULL)
        {
            Logger::error("Failed to open display!");
            return false;
        }

        char keys_return[32];
        XQueryKeymap(display, keys_return);

        KeyCode keyCode = XKeysymToKeycode(display, key);
        if (keyCode == NoSymbol)
        {
            XCloseDisplay(display);
            return false;
        }

        bool isPressed = (keys_return[keyCode >> 3] & (1 << (keyCode & 7))) != 0;
        XCloseDisplay(display);
        return isPressed;
    }

    bool Event<EVENT_KEYBOARD>::isKeyReleased(int key)
    {
        Display* display = XOpenDisplay(NULL);
        if (display == NULL)
        {
            Logger::error("Failed to open display!");
            return false;
        }

        char keys_return[32];
        XQueryKeymap(display, keys_return);

        KeyCode keyCode = XKeysymToKeycode(display, key);
        if (keyCode == NoSymbol)
        {
            XCloseDisplay(display);
            return false;
        }

        bool isPressed = (keys_return[keyCode >> 3] & (1 << (keyCode & 7))) == 0;
        XCloseDisplay(display);
        return isPressed;
    }

    bool Event<EVENT_KEYBOARD>::isKeyRepeated(int key, int count)
    {
        static int repeatCount = 0;
        if (Event<EVENT_KEYBOARD>::isKeyPressed(key))
        {
            ++repeatCount;
            return repeatCount >= count;
        }
        else
        {
            repeatCount = 0;
            return false;
        }
    }

    bool Event<EVENT_MOUSE>::isButtonPressed(int button)
    {
        Display* display = XOpenDisplay(NULL);
        if (display == NULL)
        {
            Logger::error("Failed to open display!");
            return false;
        }

        char keys_return[32];
        XQueryKeymap(display, keys_return);

        KeyCode keyCode = XKeysymToKeycode(display, key);
        if (keyCode == NoSymbol)
        {
            XCloseDisplay(display);
            return false;
        }

        bool isPressed = (keys_return[keyCode >> 3] & (1 << (keyCode & 7))) != 0;
        XCloseDisplay(display);
        return isPressed;
    }

    bool Event<EVENT_MOUSE>::isButtonReleased(int button)
    {
        Display* display = XOpenDisplay(NULL);
        if (display == NULL)
        {
            Logger::error("Failed to open display!");
            return false;
        }

        char keys_return[32];
        XQueryKeymap(display, keys_return);

        KeyCode keyCode = XKeysymToKeycode(display, key);
        if (keyCode == NoSymbol)
        {
            XCloseDisplay(display);
            return false;
        }

        bool isPressed = (keys_return[keyCode >> 3] & (1 << (keyCode & 7))) == 0;
        XCloseDisplay(display);
        return isPressed;
    }

    bool Event<EVENT_MOUSE>::isButtonHeld(int button)
    {
        Display* display = XOpenDisplay(NULL);
        if (display == NULL)
        {
            Logger::error("Failed to open display!");
            return false;
        }

        char keys_return[32];
        XQueryKeymap(display, keys_return);

        KeyCode keyCode = XKeysymToKeycode(display, key);
        if (keyCode == NoSymbol)
        {
            XCloseDisplay(display);
            return false;
        }

        bool isPressed = (keys_return[keyCode >> 3] & (1 << (keyCode & 7))) != 0;
        XCloseDisplay(display);
        return isPressed;
    }

    bool Event<EVENT_MOUSE>::isButtonRepeated(int button, int count)
    {
        static int repeatCount = 0;
        if (Event<EVENT_MOUSE>::isButtonPressed(button))
        {
            ++repeatCount;
            return repeatCount >= count;
        }
        else
        {
            repeatCount = 0;
            return false;
        }
    }

    Vec2f Event<EVENT_MOUSE>::getMousePosition()
    {
        Display* display = XOpenDisplay(NULL);
        if (display == NULL)
        {
            Logger::error("Failed to open display!");
            return Vec2f();
        }

        Window root = RootWindow(display, DefaultScreen(display));
        Window child;
        int x, y;
        unsigned int mask;
        XQueryPointer(display, root, &child, &child, &x, &y, &x, &y, &mask);
        XCloseDisplay(display);
        return Vec2f((float)x, (float)y);
    }
}

#endif // _NT_CORE_PLATFORM_X11_KEYBOARD_CPP_
