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

#pragma once

#ifndef _NT_CORE_INPUT_H_
    #define _NT_CORE_INPUT_H_

#include "Window.h"

namespace Nt
{
    enum class InputState
    {
        InputStateNone = 0,
        Pressed,
        Released,
        Held,
    };

    class NT_API Input
    {
    public:
        NT_CLASS_DEFAULTS(Input)

        static bool Initialize(WindowHandle handle);
        static void OnUpdate(void);
        static void Shutdown(void);

        static bool IsKeyPressed(uint32 keyCode);
        static bool IsKeyReleased(uint32 keyCode);
        static bool IsKeyHeld(uint32 keyCode);
        static InputState GetKeyState(uint32 keyCode);
        static void SetKeyState(uint32 keyCode, InputState state);

        static bool IsMouseButtonPressed(uint32 button);
        static bool IsMouseButtonReleased(uint32 button);
        static bool IsMouseButtonHeld(uint32 button);
        static InputState GetMouseButtonState(uint32 button);
        static void SetMouseButtonState(uint32 button, InputState state);
        static Vec2f GetMousePosition(void);
        static void SetMousePosition(Vec2f pos);
        static float32 GetMouseX(void);
        static float32 GetMouseY(void);
        static Vec2f GetMouseScrollPosition(void);
        static void SetMouseScrollPosition(Vec2f pos);
        static float32 GetMouseScrollX(void);
        static float32 GetMouseScrollY(void);

        static bool IsTouchActive(uint32 touchIndex=0);
        static Vec2f GetTouchPosition(uint32 touchIndex=0);
        static float32 GetTouchX(uint32 touchIndex=0);
        static float32 GetTouchY(uint32 touchIndex=0);
        static uint32 GetActiveTouchCount(void);
        static void SetTouchState(uint32 touchIndex, bool active, Vec2f pos);

        // TODO: Implement cross-platform gamepad support
        /*
        static bool IsGamepadConnected(uint32 gamepadIndex=0);
        static bool IsGamepadButtonPressed(uint32 gamepadIndex, uint32 button);
        static bool IsGamepadButtonReleased(uint32 gamepadIndex, uint32 button);
        static bool IsGamepadButtonHeld(uint32 gamepadIndex, uint32 button);
        static InputState GetGamepadButtonState(uint32 gamepadIndex, uint32 button);
        static float32 GetGamepadAxis(uint32 gamepadIndex, uint32 axis);
        */

    private:
        static WindowHandle s_handle;
        static std::unordered_map<uint32, InputState> s_keyStates;
        static std::unordered_map<uint32, InputState> s_mouseButtonStates;
        static Vec2f s_mousePosition;
        static Vec2f s_mouseScrollPosition;
        static std::unordered_map<uint32, bool> s_touchActive;
        static std::unordered_map<uint32, Vec2f> s_touchPositions;
        static uint32 s_activeTouchCount;
    };
} // namespace Nt

#endif // _NT_CORE_INPUT_H_
