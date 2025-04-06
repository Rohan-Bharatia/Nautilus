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

#ifndef _NT_CORE_PLATFORM_EVENT_H_
    #define _NT_CORE_PLATFORM_EVENT_H_

#include "Platform.h"
#include "../Math/Vec2.h"

namespace nt
{
    enum EventType
    {
        EVENT_KEYBOARD,
        EVENT_MOUSE,
    };

    template<EventType E>
    class NT_API Event;

    template<>
    class NT_API Event<EVENT_KEYBOARD>
    {
    public:
        static bool isKeyPressed(int key);
        static bool isKeyReleased(int key);
        static bool isKeyRepeated(int key, int count=2);
    };

    template<>
    class NT_API Event<EVENT_MOUSE>
    {
    public:
        static bool isButtonPressed(int button);
        static bool isButtonReleased(int button);
        static bool isButtonHeld(int button);
        static bool isButtonRepeated(int button, int count=2);
        static Vec2f getMousePosition();
    };
}

#endif // _NT_CORE_PLATFORM_EVENT_H_
