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

#ifndef _NT_CORE_INPUT_WINDOWS_CPP_
    #define _NT_CORE_INPUT_WINDOWS_CPP_

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

        BYTE keyboardState[256];
        if (GetKeyboardState(keyboardState))
        {
            for (int32 i = 0; i < 256; ++i)
            {
                bool isPressed          = (keyboardState[i] & 0x80) != 0;
                InputState currentState = GetKeyState(i);

                if (isPressed && currentState == InputState::Released)
                    SetKeyState(i, InputState::Pressed);
                else if (!isPressed && (currentState == InputState::Pressed || currentState == InputState::Held))
                    SetKeyState(i, InputState::Released);
            }
        }

        POINT mousePos;
        if (GetCursorPos(&mousePos))
        {
            ScreenToClient(s_handle.hwnd, &mousePos);
            SetMousePosition(Vec2f(NT_STATIC_CAST(float32, mousePos.x),
                                   NT_STATIC_CAST(float32, mousePos.y)));
        }

        for (int32 i = 0; i < 3; ++i)
        {
            int32 vkb               = (i == 0) ? VK_LBUTTON : (i == 1) ? VK_RBUTTON : VK_MBUTTON;
            bool isPressed          = (GetAsyncKeyState(vkb) & 0x8000) != 0;
            InputState currentState = GetMouseButtonState(i);

            if (isPressed && currentState == InputState::Released)
                SetMouseButtonState(i, InputState::Pressed);
             else if (!isPressed && (currentState == InputState::Pressed || currentState == InputState::Held))
                SetMouseButtonState(i, InputState::Released);
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

#endif // _NT_CORE_INPUT_WINDOWS_CPP_
