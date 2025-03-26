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
        EGLint num_configs;
        EGLint attribs[] =
        {
            EGL_SURFACE_TYPE,    EGL_WINDOW_BIT,
            EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
            EGL_RED_SIZE,        8,
            EGL_GREEN_SIZE,      8,
            EGL_BLUE_SIZE,       8,
            EGL_DEPTH_SIZE,      24,
            EGL_NONE
        };

        eglChooseConfig(display, attribs, &config, 1, &num_configs);

        EGLSurface surface = eglCreateWindowSurface(display, config, (EGLNativeWindowType)m_window, NULL);
        EGLContext ctx     = eglCreateContext(display, config, EGL_NO_CONTEXT, NULL);

        eglMakeCurrent(display, surface, surface, ctx);

        // Callback function
        if (m_desc.onCreate)
            m_desc.onCreate();
    }

    void WindowAndroid::useShader(std::string vertex, std::string fragment)
    {
        // Create and compile vertex shader
        m_vshader                = glCreateShader(GL_VERTEX_SHADER);
        const char* vertexSource = vertex.c_str();
        glShaderSource(m_vshader, 1, &vertexSource, nullptr);
        glCompileShader(m_vshader);

        // Create and compile fragment shader
        m_fshader                  = glCreateShader(GL_FRAGMENT_SHADER);
        const char* fragmentSource = fragment.c_str();
        glShaderSource(m_fshader, 1, &fragmentSource, nullptr);
        glCompileShader(m_fshader);

        // Create program and attach shaders
        GLuint program = glCreateProgram();
        glAttachShader(program, m_vshader);
        glAttachShader(program, m_fshader);
        glLinkProgram(program);

        // Use program
        glUseProgram(program);

        // Delete shaders (program has a reference to them)
        glDeleteShader(m_vshader);
        glDeleteShader(m_fshader);

        // Store program ID
        m_program = program;
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

    void WindowAndroid::clear(const Color& color)
    {
        // Clear screen with specified color
        glClearColor(color.red / 255.0f, color.green / 255.0f, color.blue / 255.0f, color.alpha);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void WindowAndroid::swapBuffers()
    {
        // Swap front and back buffers
        eglSwapBuffers(EGL_NO_DISPLAY, EGL_NO_SURFACE);
    }

    void WindowAndroid::destroy()
    {
        // Callback function
        if (m_desc.onDestroy)
            m_desc.onDestroy();

        // Delete program
        glDeleteProgram(m_program);

        // Delete OpenGL context
        eglMakeCurrent(EGL_NO_DISPLAY, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        eglDestroyContext(EGL_NO_DISPLAY, eglGetCurrentContext());
        eglDestroySurface(EGL_NO_DISPLAY, eglGetCurrentSurface(EGL_DRAW));

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
