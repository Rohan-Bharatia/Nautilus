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

#ifndef _NT_CORE_PLATFORM_ANDROID_WINDOW_CPP_
    #define _NT_CORE_PLATFORM_ANDROID_WINDOW_CPP_

#include "../Window.h"

#include "../../Logger.h"

static jclass javaClass                 = NULL;
static jmethodID javaMethodCreate       = NULL;
static jmethodID javaMethodUpdate       = NULL;
static jmethodID javaMethodDestroy      = NULL;
static jmethodID javaMethodGetDeltaTime = NULL;

namespace nt
{
    void Window::create(const std::string& title)
    {
        // Get the JavaVM and JNIEnv
        JavaVM* javaVM            = NULL;
        JNIEnv* env               = NULL;
        ANativeActivity* activity = NULL;
        activity                  = (ANativeActivity*)m_native;
        activity->vm->GetEnv((void**)&env, JNI_VERSION_1_6);
        activity->vm->AttachCurrentThread(&env, NULL);

        // Get the Java class and method IDs
        javaClass              = env->GetObjectClass(activity->clazz);
        javaMethodCreate       = env->GetMethodID(javaClass, "create", "(Ljava/lang/String;)V");
        javaMethodUpdate       = env->GetMethodID(javaClass, "update", "()V");
        javaMethodDestroy      = env->GetMethodID(javaClass, "destroy", "()V");
        javaMethodGetDeltaTime = env->GetMethodID(javaClass, "getDeltaTime", "()F");

        // Call the Java method to create the window
        jstring titleStr = env->NewStringUTF(title.c_str());
        env->CallVoidMethod(activity->clazz, javaMethodCreate, titleStr);
        env->DeleteLocalRef(titleStr);
    }

    bool Window::pollEvents()
    {
        // In Android, events are handled by the Java code
        return true;
    }

    void Window::update()
    {
        // In Android, the window is updated automatically
    }

    void Window::destroy()
    {
        JavaVM* javaVM            = NULL;
        JNIEnv* env               = NULL;
        ANativeActivity* activity = NULL;
        if (m_native)
        {
            activity                  = (ANativeActivity*)m_native;
            activity->vm->GetEnv((void**)&env, JNI_VERSION_1_6);
            activity->vm->AttachCurrentThread(&env, NULL);
            env->CallVoidMethod(activity->clazz, javaMethodDestroy);
        }
    }

    void* Window::getNativeHandle()
    {
        return (void*)m_native;
    }

    float Window::getDeltaTime()
    {
        JavaVM* javaVM            = NULL;
        JNIEnv* env               = NULL;
        ANativeActivity* activity = NULL;
        activity                  = (ANativeActivity*)m_native;
        activity->vm->GetEnv((void**)&env, JNI_VERSION_1_6);
        activity->vm->AttachCurrentThread(&env, NULL);
        float deltaTime = env->CallFloatMethod(activity->clazz, javaMethodGetDeltaTime);
        return deltaTime;
    }
}

#endif // _NT_CORE_PLATFORM_ANDROID_WINDOW_CPP_
