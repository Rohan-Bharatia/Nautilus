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

#ifndef _NT_CORE_INPUT_CPP_
    #define _NT_CORE_INPUT_CPP_

#include "Input.h"

namespace Nt
{
    WindowHandle Input::s_handle;
    std::unordered_map<uint32, InputState> Input::s_keyStates;
    std::unordered_map<uint32, InputState> Input::s_mouseButtonStates;
    Vec2f Input::s_mousePosition;
    Vec2f Input::s_mouseScrollPosition;
    std::unordered_map<uint32, bool> Input::s_touchActive;
    std::unordered_map<uint32, Vec2f> Input::s_touchPositions;
    uint32 Input::s_activeTouchCount;

    bool Input::IsKeyPressed(uint32 keyCode)
    {
        return GetKeyState(keyCode) == InputState::Pressed;
    }

    bool Input::IsKeyReleased(uint32 keyCode)
    {
        return GetKeyState(keyCode) == InputState::Released;
    }

    bool Input::IsKeyHeld(uint32 keyCode)
    {
        return GetKeyState(keyCode) == InputState::Held;
    }

    InputState Input::GetKeyState(uint32 keyCode)
    {
        auto it = s_keyStates.find(keyCode);
        return (it != s_keyStates.end()) ? it->second : InputState::Released;
    }

    void Input::SetKeyState(uint32 keyCode, InputState state)
    {
        s_keyStates[keyCode] = state;
    }

    bool Input::IsMouseButtonPressed(uint32 button)
    {
        return GetMouseButtonState(button) == InputState::Pressed;
    }

    bool Input::IsMouseButtonReleased(uint32 button)
    {
        return GetMouseButtonState(button) == InputState::Released;
    }

    bool Input::IsMouseButtonHeld(uint32 button)
    {
        return GetMouseButtonState(button) == InputState::Held;
    }

    InputState Input::GetMouseButtonState(uint32 button)
    {
        auto it = s_mouseButtonStates.find(button);
        return (it != s_mouseButtonStates.end()) ? it->second : InputState::Released;
    }

    void Input::SetMouseButtonState(uint32 button, InputState state)
    {
        s_mouseButtonStates[button] = state;
    }

    Vec2f Input::GetMousePosition(void)
    {
        return s_mousePosition;
    }

    void Input::SetMousePosition(Vec2f pos)
    {
        s_mousePosition = pos;
    }

    float32 Input::GetMouseX(void)
    {
        return s_mousePosition.x;
    }

    float32 Input::GetMouseY(void)
    {
        return s_mousePosition.y;
    }

    Vec2f Input::GetMouseScrollPosition(void)
    {
        return s_mouseScrollPosition;
    }

    void Input::SetMouseScrollPosition(Vec2f pos)
    {
        s_mouseScrollPosition = pos;
    }

    float32 Input::GetMouseScrollX(void)
    {
        return s_mouseScrollPosition.x;
    }

    float32 Input::GetMouseScrollY(void)
    {
        return s_mouseScrollPosition.y;
    }

    bool Input::IsTouchActive(uint32 touchIndex)
    {
        auto it = s_touchActive.find(touchIndex);
        return (it != s_touchActive.end()) ? it->second : false;
    }

    Vec2f Input::GetTouchPosition(uint32 touchIndex)
    {
        auto it = s_touchPositions.find(touchIndex);
        return (it != s_touchPositions.end()) ? it->second : GetMousePosition();
    }

    float32 Input::GetTouchX(uint32 touchIndex)
    {
        return s_touchPositions[touchIndex].x;
    }

    float32 Input::GetTouchY(uint32 touchIndex)
    {
        return s_touchPositions[touchIndex].y;
    }

    uint32 Input::GetActiveTouchCount(void)
    {
        return s_activeTouchCount;
    }

    void Input::SetTouchState(uint32 touchIndex, bool active, Vec2f pos)
    {
        s_touchActive[touchIndex]    = active;
        s_touchPositions[touchIndex] = pos;
    }
} // namespace Nt

#endif // _NT_CORE_INPUT_CPP_
