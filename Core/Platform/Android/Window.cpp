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

namespace nt
{
    static jclass javaClass                 = NULL;
    static jmethodID javaMethodCreate       = NULL;
    static jmethodID javaMethodUpdate       = NULL;
    static jmethodID javaMethodDestroy      = NULL;
    static jmethodID javaMethodGetDeltaTime = NULL;

    bool Window::initialize(const WindowDesc& desc)
    {
        m_desc = desc;

        // Get the JavaVM and JNIEnv
        JavaVM* javaVM            = NULL;
        JNIEnv* env               = NULL;
        ANativeActivity* activity = NULL;
        activity                  = (ANativeActivity*)m_handle.native;
        activity->vm->GetEnv((void**)&env, JNI_VERSION_1_6);
        activity->vm->AttachCurrentThread(&env, NULL);

        // Get the Java class and method IDs
        javaClass              = env->GetObjectClass(activity->clazz);
        javaMethodCreate       = env->GetMethodID(javaClass, "create", "(IIIIILjava/lang/String;IIIFZIZZZZZ)V");
        javaMethodUpdate       = env->GetMethodID(javaClass, "update", "()V");
        javaMethodDestroy      = env->GetMethodID(javaClass, "destroy", "()V");
        javaMethodGetDeltaTime = env->GetMethodID(javaClass, "getDeltaTime", "()F");

        // Call the Java method to create the window
        jstring titleStr        = env->NewStringUTF(desc.title.c_str());
        jboolean resizable      = desc.resizable      ? JNI_TRUE : JNI_FALSE;
        jboolean borderless     = desc.borderless     ? JNI_TRUE : JNI_FALSE;
        jboolean fullscreenable = desc.fullscreenable ? JNI_TRUE : JNI_FALSE;
        jboolean fullscreen     = desc.fullscreen     ? JNI_TRUE : JNI_FALSE;
        jboolean maximized      = desc.maximized      ? JNI_TRUE : JNI_FALSE;
        jboolean minimized      = desc.minimized      ? JNI_TRUE : JNI_FALSE;
        jboolean modal          = desc.modal          ? JNI_TRUE : JNI_FALSE;

        env->CallVoidMethod(activity->clazz, javaMethodCreate, desc.x, desc.y, desc.width, desc.height, titleStr, desc.bgColor.r, desc.bgColor.g, desc.bgColor.b, desc.bgColor.a, resizable, borderless, fullscreenable, fullscreen, maximized, minimized, modal);

        env->DeleteLocalRef(titleStr);

        if (!m_handle.native)
        {
            Logger::error("Failed to create window!");
            return false;
        }

        if (m_desc.onCreate)
            m_desc.onCreate();

        return true;
    }

    bool Window::pollEvents()
    {
        // In Android, events are handled by the Java code
        return true;
    }

    void Window::update()
    {
        // In Android, the window is updated automatically

        if (m_desc.onUpdate)
            m_desc.onUpdate();
    }

    void Window::destroy()
    {
        if (m_desc.onClose)
            m_desc.onClose();
            
        JavaVM* javaVM            = NULL;
        JNIEnv* env               = NULL;
        ANativeActivity* activity = NULL;
        if (m_handle.native)
        {
            activity                  = (ANativeActivity*)m_handle.native;
            activity->vm->GetEnv((void**)&env, JNI_VERSION_1_6);
            activity->vm->AttachCurrentThread(&env, NULL);
            env->CallVoidMethod(activity->clazz, javaMethodDestroy);
        }
    }

    const WindowDesc& Window::getWindowDesc() const
    {
        return m_desc;
    }

    const NativeHandle& Window::getHandle() const
    {
        return m_handle;
    }
} // namespace nt

#endif // _NT_CORE_PLATFORM_ANDROID_WINDOW_CPP_
