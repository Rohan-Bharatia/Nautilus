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

#ifndef _NT_CORE_ANDROID_WINDOW_CPP_
    #define _NT_CORE_ANDROID_WINDOW_CPP_

#include "../Window.h"

#include "../Logger.h"

namespace Nt
{
    bool Window::Initialize(void)
    {
        m_handle.app.userData     = this;
        m_handle.app.onInputEvent = NT_BIND_EVENT_FN(Window::HandleInput);
        m_handle.app.onAppCmd 	  = NT_BIND_EVENT_FN(Window::HandleCommand);
        m_handle.activity	      = m_handle.app->activity;
        m_handle.window		      = m_handle.app->window;
        
        return false;
    }

    void Window::OnUpdate(void)
    {
        int32 events;
        struct android_poll_source* source;

        while (ALooper_pollAll(0, nullptr, &events, NT_REINTERPRET_CAST(void**, &source)) >= 0)
            if (source)
            source->process(source->app, source);
    }

    void Window::Shutdown(void)
    {
        ANativeWindow_release(m_handle.window);

        NT_SAFE_DELETE(m_handle.app);
        NT_SAFE_DELETE(m_handle.activity);
        NT_SAFE_DELETE(m_handle.window);
    }

    Rect Window::GetSize(void)
    {
        return Rect(0, 0, ANativeWindow_getWidth(m_handle.window), ANativeWindow_getHeight(m_handle.window));
    }

    int32 Window::HandleInput(struct android_app* app, AInputEvent* event)
    {
        Window* window = NT_STATIC_CAST(Window*, app->userData);
            
        if (!window)
            return 0;

        if (AInputEvent_getType(event) == AINPUT_EVENT_TYPE_KEY)
        {
            int32 keyCode = AKeyEvent_getKeyCode(event);
            int32 action  = AKeyEvent_getAction(event);
            int32 repeat  = AKeyEvent_getRepeatCount(event);

            switch (action)
            {
                case AKEY_EVENT_ACTION_DOWN:
                {
                    KeyPressedEvent event(keyCode, repeat);
                    window->m_eventCallback(event);
                    break;
                }
                case AKEY_EVENT_ACTION_UP:
                {
                    KeyReleasedEvent event(keyCode);
                    window->m_eventCallback(event);
                    break;
                }
                case AKEY_EVENT_ACTION_MULTIPLE:
                {
                    KeyTypedEvent event(keyCode);
                    window->m_eventCallback(event);
                    break;
                }
            }
            return 1;
        }

        if (AInputEvent_getType(event) == AINPUT_EVENT_TYPE_MOTION)
        {
            int32 action       = AMotionEvent_getAction(event) & AMOTION_EVENT_ACTION_MASK;
            int32 pointerIndex = (AMotionEvent_getAction(event) & AMOTION_EVENT_ACTION_POINTER_INDEX_MASK) >> AMOTION_EVENT_ACTION_POINTER_INDEX_SHIFT;
            int32 x	           = AMotionEvent_getX(event, pointerIndex);
            int32 y	           = AMotionEvent_getY(event, pointerIndex);

            switch (action)
            {
                case AMOTION_EVENT_ACTION_DOWN:
                case AMOTION_EVENT_ACTION_POINTER_DOWN:
                {
                    MouseButtonPressedEvent event(0);
                    window->m_eventCallback(event);
                    break;
                }
                case AMOTION_EVENT_ACTION_UP:
                case AMOTION_EVENT_ACTION_POINTER_UP:
                {
                    MouseButtonReleasedEvent event(0);
                    window->m_eventCallback(event);
                    break;
                }
                case AMOTION_EVENT_ACTION_MOVE:
                {
                    MouseMovedEvent event(x, y);
                    window->m_eventCallback(event);
                    break;
                }
                case AMOTION_EVENT_ACTION_SCROLL:
                {
                    MouseScrolledEvent event(AMotionEvent_getAxisValue(event, AMOTION_EVENT_AXIS_HSCROLL, pointerIndex),
                                             AMotionEvent_getAxisValue(event, AMOTION_EVENT_AXIS_VSCROLL, pointerIndex));
                    window->m_eventCallback(event);
                    break;
                }
            }
            return 1;
        }

        return 0;
    }

    void Window::HandleCommand(struct android_app* app, int32 cmd)
    {
        Window* window = NT_STATIC_CAST(Window*, app->userData);
            
        if (!window)
            return;

        switch (cmd)
        {
            case APP_CMD_INIT_WINDOW:
            {
                WindowResizeEvent event(ANativeWindow_getWidth(app->window),
                                        ANativeWindow_getHeight(app->window));
                window->m_eventCallback(event);
                break;
            }
            case APP_CMD_TERM_WINDOW:
            {
                WindowCloseEvent event;
                window->m_eventCallback(event);
                break;
            }
        }
    }
} // namespace Nt

#endif // _NT_CORE_ANDROID_WINDOW_CPP_
