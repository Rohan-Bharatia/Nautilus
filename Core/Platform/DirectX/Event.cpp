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

#ifndef _NT_CORE_PLATFORM_DIRECTX_EVENT_CPP_
    #define _NT_CORE_PLATFORM_DIRECTX_EVENT_CPP_

#include "../Event.h"

#include "../API.h"
#include "../../Threading.h"

namespace nt
{
    bool Event<EVENT_KEYBOARD>::isKeyPressed(int key)
    {
        return GetAsyncKeyState(key) < 0;
    }

    bool Event<EVENT_KEYBOARD>::isKeyReleased(int key)
    {
        return GetAsyncKeyState(key) >= 0;
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
        return GetAsyncKeyState(button) < 0;
    }

    bool Event<EVENT_MOUSE>::isButtonReleased(int button)
    {
        return GetAsyncKeyState(button) >= 0;
    }

    bool Event<EVENT_MOUSE>::isButtonHeld(int button)
    {
        return GetAsyncKeyState(button) < 0;
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
        POINT pos;
        GetCursorPos(&pos);
        return Vec2f((float)pos.x, (float)pos.y);
    }
}

#endif // _NT_CORE_PLATFORM_DIRECTX_EVENT_CPP_
