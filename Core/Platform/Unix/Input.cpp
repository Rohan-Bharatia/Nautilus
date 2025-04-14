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

#ifndef _NT_CORE_PLATFORM_UNIX_INPUT_CPP_
    #define _NT_CORE_PLATFORM_UNIX_INPUT_CPP_

#include "../Input.h"

#include "../API.h"
#include "../../Clock.h"

#include <map>

namespace nt
{
    static std::map<Key, uint64_t> keyPressTimes;
    static std::map<Mouse, uint64_t> mousePressTimes;

    uint32_t Input<InputType::KEYBOARD>::keyCodeToInt(Key key)
    {
        return static_cast<int>(key);
    }

    bool Input<InputType::KEYBOARD>::isKeyDown(Key key)
    {
        Display* display = XOpenDisplay(NULL);
        
        if (display == NULL)
        {
            Logger::error("Failed to open display!");
            return false;
        }

        char keysReturn[32];
        XQueryKeymap(display, keysReturn);

        KeyCode keyCode = XKeysymToKeycode(display, keyCodeToInt(key));
        if (keyCode == NoSymbol)
        {
            XCloseDisplay(display);
            return false;
        }

        bool isPressed = (keysReturn[keyCode >> 3] & (1 << (keyCode & 7))) != 0;
        XCloseDisplay(display);
        return isPressed;
    }

    bool Input<InputType::KEYBOARD>::isKeyUp(Key key)
    {
        Display* display = XOpenDisplay(NULL);

        if (display == NULL)
        {
            Logger::error("Failed to open display!");
            return false;
        }

        char keysReturn[32];
        XQueryKeymap(display, keysReturn);

        KeyCode keyCode = XKeysymToKeycode(display, keyCodeToInt(key));
        if (keyCode == NoSymbol)
        {
            XCloseDisplay(display);
            return false;
        }

        bool isPressed = (keysReturn[keyCode >> 3] & (1 << (keyCode & 7))) == 0;
        XCloseDisplay(display);
        return isPressed;
    }

    bool Input<InputType::KEYBOARD>::isKeyPressed(Key key)
    {
        Clock clock;
        clock.start();
        if (isKeyDown(key))
        {
            keyPressTimes[key] = clock.getElapsedTime();
            return true;
        }
        return false;
    }

    bool Input<InputType::KEYBOARD>::isKeyReleased(Key key)
    {
        if (isKeyUp(key))
        {
            keyPressTimes.erase(key);
            return true;
        }
        return false;
    }

    bool Input<InputType::KEYBOARD>::isKeyHeld(Key key)
    {
        if (isKeyDown(key))
        {
            const double holdTime = 0.5;
            auto it               = keyPressTimes.find(key);
            Clock clock;
            clock.start();
            if (it != keyPressTimes.end())
            {
                double currentTime = clock.getElapsedTime();
                if (currentTime - it->second > holdTime)
                    return true;
            }
        }
        return false;
    }

    bool Input<InputType::KEYBOARD>::isKeyRepeated(Key key, uint32_t repeatCount, uint32_t delay)
    {
        if (isKeyDown(key))
        {
            auto it = keyPressTimes.find(key);
            Clock clock;
            clock.start();
            if (it != keyPressTimes.end())
            {
                double currentTime    = clock.getElapsedTime();
                double pressTime      = it->second;
                double repeatInterval = delay * repeatCount / 1000.0;
                if (currentTime - pressTime > repeatInterval)
                    return true;
            }
        }
        return false;
    }

    uint32_t Input<InputType::MOUSE>::mouseButtonCodeToInt(Mouse button)
    {
        return static_cast<int>(button);
    }

    bool Input<InputType::MOUSE>::isMouseButtonDown(Mouse button)
    {
        Display* display = XOpenDisplay(NULL);

        if (display == NULL)
        {
            Logger::error("Failed to open display!");
            return false;
        }

        char keysReturn[32];
        XQueryKeymap(display, keysReturn);

        KeyCode keyCode = XKeysymToKeycode(display, mouseButtonCodeToInt(button));
        if (keyCode == NoSymbol)
        {
            XCloseDisplay(display);
            return false;
        }

        bool isPressed = (keysReturn[keyCode >> 3] & (1 << (keyCode & 7))) != 0;
        XCloseDisplay(display);
        return isPressed;
    }

    bool Input<InputType::MOUSE>::isMouseButtonUp(Mouse button)
    {
        Display* display = XOpenDisplay(NULL);

        if (display == NULL)
        {
            Logger::error("Failed to open display!");
            return false;
        }

        char keysReturn[32];
        XQueryKeymap(display, keysReturn);

        KeyCode keyCode = XKeysymToKeycode(display, mouseButtonCodeToInt(button));
        if (keyCode == NoSymbol)
        {
            XCloseDisplay(display);
            return false;
        }

        bool isPressed = (keysReturn[keyCode >> 3] & (1 << (keyCode & 7))) == 0;
        XCloseDisplay(display);
        return isPressed;
    }

    bool Input<InputType::MOUSE>::isMouseButtonPressed(Mouse button)
    {
        Clock clock;
        clock.start();
        if (isMouseButtonDown(button))
        {
            mousePressTimes[button] = clock.getElapsedTime();
            return true;
        }
        return false;
    }

    bool Input<InputType::MOUSE>::isMouseButtonReleased(Mouse button)
    {
        if (isMouseButtonUp(button))
        {
            mousePressTimes.erase(button);
            return true;
        }
        return false;
    }

    bool Input<InputType::MOUSE>::isMouseButtonHeld(Mouse button)
    {
        if (isMouseButtonDown(button))
        {
            const double holdTime = 0.5;
            auto it               = mousePressTimes.find(button);
            Clock clock;
            clock.start();
            if (it != mousePressTimes.end())
            {
                double currentTime = clock.getElapsedTime();
                if (currentTime - it->second > holdTime)
                    return true;
            }
        }
        return false;
    }

    bool Input<InputType::MOUSE>::isMouseButtonRepeated(Mouse button, uint32_t repeatCount, uint32_t delay)
    {
        if (isMouseButtonDown(button))
        {
            auto it = mousePressTimes.find(button);
            Clock clock;
            clock.start();
            if (it != mousePressTimes.end())
            {
                double currentTime    = clock.getElapsedTime();
                double pressTime      = it->second;
                double repeatInterval = delay * repeatCount / 1000.0;
                if (currentTime - pressTime > repeatInterval)
                    return true;
            }
        }
        return false;
    }

    Vec2f Input<InputType::MOUSE>::getMousePosition()
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

    float Input<InputType::MOUSE>::getMouseScrollPosition()
    {
        Display* display = XOpenDisplay(NULL);

        if (display == NULL)
        {
            Logger::error("Failed to open display!");
            return 0.0f;
        }

        int wheelDelta = 0;
        XEvent event;
        XQueryPointer(display, DefaultRootWindow(display), &event.xbutton.x, &event.xbutton.y, &event.xbutton.x_root, &event.xbutton.y_root, &event.xbutton.same_screen);
        wheelDelta = event.xbutton.button;

        static float scrollPos = 0.0f;
        scrollPos             += (float)wheelDelta / 120.0f; // 120 is a common wheel delta value
        return scrollPos;
    }
}

#endif // _NT_CORE_PLATFORM_UNIX_INPUT_CPP_
