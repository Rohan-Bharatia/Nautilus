//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#ifndef _NT_WINDOW_EVENT_ANDROID_cpp_
    #define _NT_WINDOW_EVENT_ANDROID_cpp_

#include "Event.h"

#include <android/input.h>

namespace nt
{
    bool Event::isKeyDown(int key)
    {
        AInputEvent *event = AInputEvent_new();
        if (AInputEvent_getType(event) == AINPUT_EVENT_TYPE_KEY)
        {
            int keyCode = AKeyEvent_getKeyCode(event);
            return AInputEvent_getScanCode(event, keyCode) == key;
        }
        AInputEvent_delete(event);
        return false;
    }

    bool Event::isMouseButtonDown(int button)
    {
        AInputEvent *event = AInputEvent_new();
        if (AInputEvent_getType(event) == AINPUT_EVENT_TYPE_MOTION)
        {
            int buttonState = AMotionEvent_getButtonState(event, button);
            return buttonState == AMOTION_EVENT_BUTTON_STATE_PRESSED;
        }
        AInputEvent_delete(event);
        return false;
    }

    Vec2f Event::getMousePosition()
    {
        AInputEvent *event = AInputEvent_new();
        if (AInputEvent_getType(event) == AINPUT_EVENT_TYPE_MOTION)
        {
            float x = AMotionEvent_getX(event, 0);
            float y = AMotionEvent_getY(event, 0);
            AInputEvent_delete(event);
            return Vec2f(x, y);
        }
        AInputEvent_delete(event);
        return Vec2f(0, 0);
    }
} // namespace nt

#endif // _NT_WINDOW_EVENT_ANDROID_cpp_