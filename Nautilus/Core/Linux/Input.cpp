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

#ifndef _NT_CORE_INPUT_LINUX_CPP_
    #define _NT_CORE_INPUT_LINUX_CPP_

#include "../Input.h"

namespace Nt
{
    bool Input::Initialize(WindowHandle handle)
    {
        s_handle              = handle;
        s_keyStates.clear();
        s_mouseButtonStates.clear();
        s_mousePosition       = Vec2f(0.0f, 0.0f);
        s_mouseScrollPosition = Vec2f(0.0f, 0.0f);
        s_touchActive.clear();
        s_touchPositions.clear();
        s_activeTouchCount    = 0;

        return true;
    }

    void Input::OnUpdate(void)
    {
        s_mouseScrollPosition = Vec2f(0.0f, 0.0f);

        for (auto& [key, state] : s_keyStates)
            if (state == InputState::Pressed)
                state = InputState::Held;

        for (auto& [button, state] : s_mouseButtonStates)
            if (state == InputState::Pressed)
                state = InputState::Held;

        char keyMap[32];
        XQueryKeymap(s_handle.display, keyMap);

        for (int32 i = 0; i < 256; ++i)
        {
            bool isPressed          = (keyMap[i / 8] & (1 << (i % 8))) != 0;
            InputState currentState = GetKeyState(i);

            if (isPressed && currentState == InputState::Released)
                SetKeyState(i, InputState::Pressed);
            else if (!isPressed && (currentState == InputState::Pressed || currentState == InputState::Held))
                SetKeyState(i, InputState::Released);
        }

        ::Window root, child;
        int24 rootX, rootY, winX, winY;
        uint24 mask;

        if (XQueryPointer(s_handle.display, s_handle.window, &root, &child, &rootX, &rootY, &winX, &winY, &mask))
        {
            SetMousePosition(Vec2f(NT_STATIC_CAST(float32, winX),
                                   NT_STATIC_CAST(float32, winY)));

            for (int32 i = 0; i < 3; ++i)
            {
                uint32 bmask = (i == 0) ? Button1Mask : (i == 1) ? Button2Mask : Button3Mask;
                bool isPressed = (mask & bmask) != 0;
                InputState currentState = GetMouseButtonState(i);

                if (isPressed && currentState == InputState::Released)
                    SetKeyState(i, InputState::Pressed);
                else if (!isPressed && (currentState == InputState::Pressed || currentState == InputState::Held))
                    SetKeyState(i, InputState::Released);
            }
        }

        while (XPending(s_handle.display))
        {
            XEvent event;
            XNextEvent(s_handle.display, &event);

            switch(event.type)
            {
                case KeyPress:
                    SetKeyState(NT_STATIC_CAST(uint32, XLookupKeysym(&event.xkey, 0)), InputState::Pressed);
                    break;
                case KeyRelease:
                    SetKeyState(NT_STATIC_CAST(uint32, XLookupKeysym(&event.xkey, 0)), InputState::Released);
                    break;
                case ButtonPress:
                    if (event.xbutton.button >= 1 &&
                        event.xbutton.button <= 3)
                        SetMouseButtonState(event.xbutton.button - 1, InputState::Pressed);
                    else if (event.xbutton.button == 4)
                        SetMouseScrollPosition(Vec2f(0.0f, 1.0f));
                    else if (event.xbutton.button == 5)
                        SetMouseScrollPosition(Vec2f(0.0f, -1.0f));
                    break;
                case ButtonRelease:
                    if (event.xbutton.button >= 1 &&
                        event.xbutton.button <= 3)
                        SetMouseButtonState(event.xbutton.button - 1, InputState::Released);
                    break;
                case MotionNotify:
                    SetMousePosition(Vec2f(NT_STATIC_CAST(float32, event.xmotion.x),
                                           NT_STATIC_CAST(float32, event.xmotion.y)));
                    break;
                default:
                    break;
            }
        }
    }

    void Input::Shutdown(void)
    {
        s_keyStates.clear();
        s_mouseButtonStates.clear();
        s_mousePosition       = Vec2f(0.0f, 0.0f);
        s_mouseScrollPosition = Vec2f(0.0f, 0.0f);
        s_touchActive.clear();
        s_touchPositions.clear();
        s_activeTouchCount    = 0;
    }
} // namespace Nt

#endif // _NT_CORE_INPUT_LINUX_CPP_
