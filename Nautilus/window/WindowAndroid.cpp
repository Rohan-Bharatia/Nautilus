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

#ifndef _NT_WINDOW_WINDOW_ANDROID_cpp_
    #define _NT_WINDOW_WINDOW_ANDROID_cpp_

#include "WindowAndroid.h"

#include <EGL/egl.h>
#include <GLES2/gl2.h>

namespace nt
{
    WindowAndroid::WindowAndroid(const WindowDesc& desc) :
        m_window(nullptr), m_desc(desc)
    {}

    void WindowAndroid::initialize()
    {
        // Create window
        m_window = ANativeWindow_fromSurface(env, surface);

        // Set window size & color
        ANativeWindow_setBuffersGeometry(m_window, m_desc.width, m_desc.height, WINDOW_FORMAT_RGBA_8888);

        // Set window states
        if (m_desc.visible)
            ANativeWindow_show(m_window);
        else
            ANativeWindow_hide(m_window);

        // Set modal state
        if (m_desc.modal)
        {
            JNIEnv *env      = (JNIEnv *)SDL_AndroidGetJNIEnv();
            jobject activity = (jobject)SDL_AndroidGetActivity();
            jclass clazz     = env->GetObjectClass(activity);
            jmethodID method = env->GetMethodID(clazz, "startActivity", "(Landroid/content/Intent;)V");
            jobject intent   = env->NewObject(env->FindClass("android/content/Intent"), env->GetMethodID(env->FindClass("android/content/Intent"), "<init>", "()V"));
            env->CallVoidMethod(activity, method, intent);
            env->DeleteLocalRef(intent);

            // Set the modal window as the current window
            ANativeWindow_setFlags(m_window, AWINDOW_FLAG_NOT_FOCUSABLE);
        }

        // Initialize OpenGL
        EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
        EGLint major, minor;
        eglInitialize(display, &major, &minor);

        EGLConfig config;
        EGLint configCount;
        eglChooseConfig(display, NULL, &config, 1, &configCount);
        EGLSurface surface = eglCreateWindowSurface(display, config, m_window, NULL);

        eglMakeCurrent(display, surface, surface, NULL);

        glEnable(EGL_DEPTH_TEST);

        int width  = ANativeWindow_getWidth(m_window);
        int height = ANativeWindow_getHeight(m_window);

        glViewport(0, 0, width, height);

        // Callback function
        if (m_desc.onCreate)
            m_desc.onCreate();
    }

    bool WindowAndroid::pollEvents()
    {
        // Poll events
        AInputQueue* queue = AInputQueue_attachLooper(env, looper, LOOPER_ID_MAIN, NULL);
        AInputEvent* event;
        while (AInputQueue_getEvent(queue, &event) >= 0)
        {
            AInputQueue_preDispatchEvent(queue, event);
            int handled = 0;
            dispatchInputEvent(event, &handled);
            AInputQueue_finishEvent(queue, event, handled);
        }
        AInputQueue_detachLooper(queue);

        return true;
    }

    void WindowAndroid::update()
    {
        // Update window
        ANativeWindow_unlockAndPost(m_window);

        // Callback function
        if (m_desc.onUpdate)
            m_desc.onUpdate();
    }

    void WindowAndroid::frame(std::vector<ReadableVertex>& vertices)
    {
        // Enable vertex arrays
        glVertexPointer(3, GL_FLOAT, sizeof(ReadableVertex), &vertices[0].position);
        glEnableClientState(GL_VERTEX_ARRAY);

        // Enable texture arrays
        glTexCoordPointer(2, GL_FLOAT, sizeof(ReadableVertex), &vertices[0].uv);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);

        // Enable color arrays
        glColorPointer(4, GL_FLOAT, sizeof(ReadableVertex), &vertices[0].color);
        glEnableClientState(GL_COLOR_ARRAY);

        // Draw the vertices
        glDrawArrays(GL_TRIANGLES, 0, vertices.size());

        // Disable v/t/c arrays
        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);
    }

    void WindowAndroid::clear(const Color& color)
    {
        glClearColor(color.red / 255.0f, color.green / 255.0f, color.blue / 255.0f, color.alpha);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void WindowAndroid::swapBuffers()
    {
        eglSwapBuffers(eglGetDisplay(EGL_DEFAULT_DISPLAY), eglGetSurface(EGL_DEFAULT_DISPLAY, EGL_BACK_BUFFER));
    }

    void WindowAndroid::destroy()
    {
        // Callback function
        if (m_desc.onDestroy)
            m_desc.onDestroy();

        // Destroy OpenGL
        eglDestroySurface(eglGetDisplay(EGL_DEFAULT_DISPLAY), eglGetSurface(EGL_DEFAULT_DISPLAY, EGL_BACK_BUFFER));
        eglTerminate(eglGetDisplay(EGL_DEFAULT_DISPLAY));

        // Destroy window
        if (m_window)
            ANativeWindow_release(m_window);
    }

    void* WindowAndroid::getHandle()
    {
        return static_cast<void*>(m_window);
    }

    WindowDesc WindowAndroid::getDescription()
    {
        return m_desc;
    }
} // namespace nt

#endif // _NT_WINDOW_WINDOW_ANDROID_h_
