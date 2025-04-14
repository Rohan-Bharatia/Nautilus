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

#ifndef _NT_CORE_PLATFORM_INPUT_H_
    #define _NT_CORE_PLATFORM_INPUT_H_

#include "../Math/Vec2.h"

#include <cstdint>

namespace nt
{
    enum class InputType
    {
        KEYBOARD,
        MOUSE,
    };

    enum class Key
    {
        UNKNOWN          = 0x00,
        SPACE            = 0x20,
        APOSTROPHE       = 0x27,
        COMMA            = 0x2C,
        MINUS            = 0x2D,
        PERIOD           = 0x2E,
        SLASH            = 0x2F,
        ZERO             = 0x30,
        ONE              = 0x31,
        TWO              = 0x32,
        THREE            = 0x33,
        FOUR             = 0x34,
        FIVE             = 0x35,
        SIX              = 0x36,
        SEVEN            = 0x37,
        EIGHT            = 0x38,
        NINE             = 0x39,
        SEMICOLON        = 0x3B,
        EQUALS           = 0x3D,
        A                = 0x41,
        B                = 0x42,
        C                = 0x43,
        D                = 0x44,
        E                = 0x45,
        F                = 0x46,
        G                = 0x47,
        H                = 0x48,
        I                = 0x49,
        J                = 0x4A,
        K                = 0x4B,
        L                = 0x4C,
        M                = 0x4D,
        N                = 0x4E,
        O                = 0x4F,
        P                = 0x50,
        Q                = 0x51,
        R                = 0x52,
        S                = 0x53,
        T                = 0x54,
        U                = 0x55,
        V                = 0x56,
        W                = 0x57,
        X                = 0x58,
        Y                = 0x59,
        Z                = 0x5A,
        LEFT_BRACKET     = 0x5B,
        BACKSLASH        = 0x5C,
        RIGHT_BRACKET    = 0x5D,
        GRAVE_ACCENT     = 0x60,
        WORLD_1          = 0x61,
        WORLD_2          = 0x62,
        ESCAPE           = 0x1B,
        ENTER            = 0x0D,
        TAB              = 0x09,
        BACKSPACE        = 0x08,
        INSERT           = 0x2D,
        DEL              = 0x2E,
        RIGHT            = 0x27,
        LEFT             = 0x25,
        DOWN             = 0x28,
        UP               = 0x26,
        PAGE_UP          = 0x21,
        PAGE_DOWN        = 0x22,
        HOME             = 0x24,
        END              = 0x23,
        CAPS_LOCK        = 0x14,
        SCROLL_LOCK      = 0x46,
        NUM_LOCK         = 0x45,
        PRINT_SCREEN     = 0x2A,
        PAUSE            = 0x13,
        F1               = 0x70,
        F2               = 0x71,
        F3               = 0x72,
        F4               = 0x73,
        F5               = 0x74,
        F6               = 0x75,
        F7               = 0x76,
        F8               = 0x77,
        F9               = 0x78,
        F10              = 0x79,
        F11              = 0x7A,
        F12              = 0x7B,
        CTRL_LEFT        = 0xA2,
        CTRL_RIGHT       = 0xA3,
        ALT_LEFT         = 0xA4,
        ALT_RIGHT        = 0xA5,
        SHIFT_LEFT       = 0xA0,
        SHIFT_RIGHT      = 0xA1,
        NUMPAD_0         = 0x60,
        NUMPAD_1         = 0x61,
        NUMPAD_2         = 0x62,
        NUMPAD_3         = 0x63,
        NUMPAD_4         = 0x64,
        NUMPAD_5         = 0x65,
        NUMPAD_6         = 0x66,
        NUMPAD_7         = 0x67,
        NUMPAD_8         = 0x68,
        NUMPAD_9         = 0x69,
        NUMPAD_DIVIDE    = 0x6F,
        NUMPAD_MULTIPLY  = 0x6A,
        NUMPAD_SUBTRACT  = 0x6D,
        NUMPAD_ADD       = 0x6B,
        NUMPAD_ENTER     = 0x0D,
        NUMPAD_DECIMAL   = 0x6E,
        NUMPAD_DEL       = 0x2E,
        NUMPAD_INS       = 0x2D,
        NUMPAD_HOME      = 0x24,
        NUMPAD_END       = 0x23,
        NUMPAD_PAGE_UP   = 0x21,
        NUMPAD_PAGE_DOWN = 0x22,
        NUMPAD_RIGHT     = 0x27,
        NUMPAD_LEFT      = 0x25,
        NUMPAD_DOWN      = 0x28,
        NUMPAD_UP        = 0x26,
    };

    enum class Mouse
    {
        LEFT   = 0x01,
        RIGHT  = 0x02,
        MIDDLE = 0x03,
        X1     = 0x05,
        X2     = 0x06,
    };

    template<InputType T>
    class NT_API Input
    {};

    template<>
    class NT_API Input<InputType::KEYBOARD>
    {
    public:
        static uint32_t keyCodeToInt(Key key);

        static bool isKeyDown(Key key);
        static bool isKeyUp(Key key);
        static bool isKeyPressed(Key key);
        static bool isKeyReleased(Key key);
        static bool isKeyHeld(Key key);
        static bool isKeyRepeated(Key key, uint32_t repeatCount, uint32_t delay);
    };

    template<>
    class NT_API Input<InputType::MOUSE>
    {
    public:
        static uint32_t mouseButtonCodeToInt(Mouse button);

        static bool isMouseButtonDown(Mouse button);
        static bool isMouseButtonUp(Mouse button);
        static bool isMouseButtonPressed(Mouse button);
        static bool isMouseButtonReleased(Mouse button);
        static bool isMouseButtonHeld(Mouse button);
        static bool isMouseButtonRepeated(Mouse button, uint32_t repeatCount, uint32_t delay);
        static Vec2f getMousePosition();
        static float getMouseScrollPosition();
    };
}

#endif // _NT_CORE_PLATFORM_INPUT_H_
