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

#ifndef _NT_CORE_PLATFORM_ANDROID_KEYBOARD_CPP_
    #define _NT_CORE_PLATFORM_ANDROID_KEYBOARD_CPP_

#include "../Event.h"

#include "../API.h"

namespace nt
{
    bool Event<EVENT_KEYBOARD>::isKeyPressed(int key)
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
        return keyCode == key;
    }

    bool Event<EVENT_KEYBOARD>::isKeyReleased(int key)
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
        return keyCode == key;
    }

    bool Event<EVENT_MOUSE>::isButtonReleased(int button)
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

    bool Event<EVENT_MOUSE>::isButtonHeld(int button)
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
        return keyCode == key;
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
        return Vec2f(0.0f, 0.0f);
    }
}

#endif // _NT_CORE_PLATFORM_ANDROID_KEYBOARD_CPP_
