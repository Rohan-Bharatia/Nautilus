//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#pragma once

#ifndef _NT_WINDOW_EVENT_h_
    #define _NT_WINDOW_EVENT_h_

#include "../core/Types.h"
#include "../math/Vec2.h"

#include <unordered_map>

namespace nt
{
    class Event
    {
    public:
        Event()                              = default;
        ~Event()                             = default;
        Event(const Event& other)            = default;
        Event& operator=(const Event& other) = default;

        // Keyboard events
        static bool isKeyDown(int key);
        static bool isKeyUp(int key);
        static bool isKeyPressed(int key);
        static bool isKeyDoublePressed(int key, uint32 timeout=500);

        // Mouse events
        static bool isMouseButtonDown(int button);
        static bool isMouseButtonUp(int button);
        static bool isMouseButtonPressed(int button);
        static bool isMouseButtonDoublePressed(int button, uint32 timeout=500);
        static Vec2f getMousePosition();

    };
} // namespace nt

#endif // _NT_WINDOW_EVENT_h_