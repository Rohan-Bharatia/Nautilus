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

#ifndef _NT_WINDOW_EVENT_WIN32_cpp_
    #define _NT_WINDOW_EVENT_WIN32_cpp_

#include "Event.h"

#include <Windows.h>

namespace nt
{
    bool Event::isKeyDown(int key)
    {
        return GetAsyncKeyState(key) & 0x8000;
    }

    bool Event::isMouseButtonDown(int button)
    {
        return GetAsyncKeyState(button) & 0x8000;
    }

    Vec2f Event::getMousePosition()
    {
        POINT pos;
        GetCursorPos(&pos);
        return Vec2f(static_cast<float>(pos.x), static_cast<float>(pos.y));
    }
} // namespace nt

#endif // _NT_WINDOW_EVENT_WIN32_cpp_
