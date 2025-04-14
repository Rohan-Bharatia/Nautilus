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

#ifndef _NT_CORE_PLATFORM_ANDROID_INPUT_CPP_
    #define _NT_CORE_PLATFORM_ANDROID_INPUT_CPP_

#include "../Input.h"

#include "../API.h"
#include "../../Clock.h"

#include <map>

namespace nt
{
    static std::map<Key, uint64_t> keyPressTimes;
    static std::map<Mouse, uint64_t> mousePressTimes;

    uint32_t Input<InputType::KEYBOARD>::keyCodeToInt(Key key)
    {
        return static_cast<int>(key);
    }

    bool Input<InputType::KEYBOARD>::isKeyDown(Key key)
    {
        JNIEnv* env;
        jobject activity;
        jclass clazz;
        jmethodID method;

        // Get the activity and its class
        activity = (jobject)GetActivity();
        clazz    = env->GetObjectClass(activity);

        // Get the method to get the current key event
        method = env->GetMethodID(clazz, "getCurrentKeyEvent", "()Landroid/view/KeyEvent;");

        // Get the current key event
        jobject event = env->CallObjectMethod(activity, method);

        // Check if the key is pressed
        jclass eventClass = env->GetObjectClass(event);
        jmethodID getKeyCodeMethod = env->GetMethodID(eventClass, "getKeyCode", "()I");
        jint keyCode = env->CallIntMethod(event, getKeyCodeMethod);
        return keyCode == keyCodeToInt(key);
    }

    bool Input<InputType::KEYBOARD>::isKeyUp(Key key)
    {
        JNIEnv* env;
        jobject activity;
        jclass clazz;
        jmethodID method;

        // Get the activity and its class
        activity = (jobject)GetActivity();
        clazz = env->GetObjectClass(activity);

        // Get the method to get the current key event
        method = env->GetMethodID(clazz, "getCurrentKeyEvent", "()Landroid/view/KeyEvent;");

        // Get the current key event
        jobject event = env->CallObjectMethod(activity, method);

        // Check if the key is released
        jclass eventClass = env->GetObjectClass(event);
        jmethodID getActionMethod = env->GetMethodID(eventClass, "getAction", "()I");
        jint action = env->CallIntMethod(event, getActionMethod);
        return action == KeyEvent.ACTION_UP;
    }

    bool Input<InputType::KEYBOARD>::isKeyPressed(Key key)
    {
        Clock clock;
        clock.start();
        if (isKeyDown(key))
        {
            keyPressTimes[key] = clock.getElapsedTime();
            return true;
        }
        return false;
    }

    bool Input<InputType::KEYBOARD>::isKeyReleased(Key key)
    {
        if (isKeyUp(key))
        {
            keyPressTimes.erase(key);
            return true;
        }
        return false;
    }

    bool Input<InputType::KEYBOARD>::isKeyHeld(Key key)
    {
        if (isKeyDown(key))
        {
            const double holdTime = 0.5;
            auto it               = keyPressTimes.find(key);
            Clock clock;
            clock.start();
            if (it != keyPressTimes.end())
            {
                double currentTime = clock.getElapsedTime();
                if (currentTime - it->second > holdTime)
                    return true;
            }
        }
        return false;
    }

    bool Input<InputType::KEYBOARD>::isKeyRepeated(Key key, uint32_t repeatCount, uint32_t delay)
    {
        if (isKeyDown(key))
        {
            auto it = keyPressTimes.find(key);
            Clock clock;
            clock.start();
            if (it != keyPressTimes.end())
            {
                double currentTime    = clock.getElapsedTime();
                double pressTime      = it->second;
                double repeatInterval = delay * repeatCount / 1000.0;
                if (currentTime - pressTime > repeatInterval)
                    return true;
            }
        }
        return false;
    }

    uint32_t Input<InputType::MOUSE>::mouseButtonCodeToInt(Mouse button)
    {
        return static_cast<int>(button);
    }

    bool Input<InputType::MOUSE>::isMouseButtonDown(Mouse button)
    {
        JNIEnv* env;
        jobject activity;
        jclass clazz;
        jmethodID method;

        // Get the activity and its class
        activity = (jobject)GetActivity();
        clazz    = env->GetObjectClass(activity);

        // Get the method to get the current key event
        method = env->GetMethodID(clazz, "getCurrentKeyEvent", "()Landroid/view/KeyEvent;");

        // Get the current key event
        jobject event = env->CallObjectMethod(activity, method);

        // Check if the key is pressed
        jclass eventClass = env->GetObjectClass(event);
        jmethodID getKeyCodeMethod = env->GetMethodID(eventClass, "getKeyCode", "()I");
        jint keyCode = env->CallIntMethod(event, getKeyCodeMethod);
        return keyCode == mouseButtonCodeToInt(button);
    }

    bool Input<InputType::MOUSE>::isMouseButtonUp(Mouse button)
    {
        JNIEnv* env;
        jobject activity;
        jclass clazz;
        jmethodID method;

        // Get the activity and its class
        activity = (jobject)GetActivity();
        clazz = env->GetObjectClass(activity);

        // Get the method to get the current key event
        method = env->GetMethodID(clazz, "getCurrentKeyEvent", "()Landroid/view/KeyEvent;");

        // Get the current key event
        jobject event = env->CallObjectMethod(activity, method);

        // Check if the key is released
        jclass eventClass = env->GetObjectClass(event);
        jmethodID getActionMethod = env->GetMethodID(eventClass, "getAction", "()I");
        jint action = env->CallIntMethod(event, getActionMethod);
        return action == KeyEvent.ACTION_UP;
    }

    bool Input<InputType::MOUSE>::isMouseButtonPressed(Mouse button)
    {
        Clock clock;
        clock.start();
        if (isMouseButtonDown(button))
        {
            mousePressTimes[button] = clock.getElapsedTime();
            return true;
        }
        return false;
    }

    bool Input<InputType::MOUSE>::isMouseButtonReleased(Mouse button)
    {
        if (isMouseButtonUp(button))
        {
            mousePressTimes.erase(button);
            return true;
        }
        return false;
    }

    bool Input<InputType::MOUSE>::isMouseButtonHeld(Mouse button)
    {
        if (isMouseButtonDown(button))
        {
            const double holdTime = 0.5;
            auto it               = mousePressTimes.find(button);
            Clock clock;
            clock.start();
            if (it != mousePressTimes.end())
            {
                double currentTime = clock.getElapsedTime();
                if (currentTime - it->second > holdTime)
                    return true;
            }
        }
        return false;
    }

    bool Input<InputType::MOUSE>::isMouseButtonRepeated(Mouse button, uint32_t repeatCount, uint32_t delay)
    {
        if (isMouseButtonDown(button))
        {
            auto it = mousePressTimes.find(button);
            Clock clock;
            clock.start();
            if (it != mousePressTimes.end())
            {
                double currentTime    = clock.getElapsedTime();
                double pressTime      = it->second;
                double repeatInterval = delay * repeatCount / 1000.0;
                if (currentTime - pressTime > repeatInterval)
                    return true;
            }
        }
        return false;
    }

    Vec2f Input<InputType::MOUSE>::getMousePosition()
    {
        return Vec2f(0.0f, 0.0f);
    }

    float Input<InputType::MOUSE>::getMouseScrollPosition()
    {
        JNIEnv* env;
        jobject activity;
        jclass clazz;
        jmethodID method;

        // Get the activity and its class
        activity = (jobject)GetActivity();
        clazz = env->GetObjectClass(activity);

        // Get the method to get the current MotionEvent
        method = env->GetMethodID(clazz, "getCurrentMotionEvent", "()Landroid/view/MotionEvent;");

        // Get the current MotionEvent
        jobject event = env->CallObjectMethod(activity, method);

        // Check if the event is a scroll event
        jclass eventClass = env->GetObjectClass(event);
        jmethodID getActionMethod = env->GetMethodID(eventClass, "getAction", "()I");
        jint action = env->CallIntMethod(event, getActionMethod);
        if (action == MotionEvent.ACTION_SCROLL)
        {
            // Get the scroll amount
            jmethodID getAxisValueMethod = env->GetMethodID(eventClass, "getAxisValue", "(I)F");
            jfloat scrollAmount = env->CallFloatMethod(event, getAxisValueMethod, MotionEvent.AXIS_VSCROLL);
            return scrollAmount;
        }
        return 0.0f;
    }
}

#endif // _NT_CORE_PLATFORM_ANDROID_INPUT_CPP_
