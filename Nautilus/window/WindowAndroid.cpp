//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

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

        // Set window properties
        ANativeWindow_setBuffersGeometry(m_window, m_desc.width, m_desc.height, WINDOW_FORMAT_RGBA_8888);

        // Make window visible
        ANativeWindow_show(m_window);

        // Callback function
        if (m_desc.onCreate)
            m_desc.onCreate();
    }

    bool WindowUIKit::pollEvents()
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

    void WindowAndroid::destroy()
    {
        // Callback function
        if (m_desc.onDestroy)
            m_desc.onDestroy();

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
