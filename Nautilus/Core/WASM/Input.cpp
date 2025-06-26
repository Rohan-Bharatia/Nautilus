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

#ifndef _NT_CORE_INPUT_WASM_CPP_
    #define _NT_CORE_INPUT_WASM_CPP_

#include "../Input.h"

namespace Nt
{
    static EM_BOOL OnKeyDown(int eventType, const EmscriptenKeyboardEvent* e, void* userData)
    {
        Input::SetKeyState(NT_STATIC_CAST(uint32, e->keyCode), Input::Pressed);
        return EM_TRUE;
    }

    static EM_BOOL OnKeyUp(int eventType, const EmscriptenKeyboardEvent* e, void* userData)
    {
        Input::SetKeyState(NT_STATIC_CAST(uint32, e->keyCode), Input::Released);
        return EM_TRUE;
    }

    static EM_BOOL OnMouseDown(int eventType, const EmscriptenMouseEvent* e, void* userData)
    {
        Input::SetMouseButtonState(NT_STATIC_CAST(uint32, e->button), Input::Pressed);
        Input::SetMousePosition(Vec2f(NT_STATIC_CAST(float32, e->targetX),
                                      NT_STATIC_CAST(float32, e->targetY)));
        return EM_TRUE;
    }

    static EM_BOOL OnMouseUp(int eventType, const EmscriptenMouseEvent* e, void* userData)
    {
        Input::SetMouseButtonState(NT_STATIC_CAST(uint32, e->button), Input::Released);
        Input::SetMousePosition(Vec2f(NT_STATIC_CAST(float32, e->targetX),
                                      NT_STATIC_CAST(float32, e->targetY)));
        return EM_TRUE;
    }

    static EM_BOOL OnMouseMove(int eventType, const EmscriptenMouseEvent* e, void* userData)
    {
        Input::SetMouseButtonState(NT_STATIC_CAST(uint32, e->button), Input::Pressed);
        Input::SetMousePosition(Vec2f(NT_STATIC_CAST(float32, e->targetX),
                                      NT_STATIC_CAST(float32, e->targetY)));
        return EM_TRUE;
    }

    static EM_BOOL OnWheel(int eventType, const EmscriptenWheelEvent* e, void* userData)
    {
        Input::SetMouseScrollPosition(Vec2f(NT_STATIC_CAST(float32, e->deltaX),
                                            NT_STATIC_CAST(float32, e->deltaY)));
        return EM_TRUE;
    }

    static EM_BOOL OnTouchStart(int eventType, const EmscriptenTouchEvent* e, void* userData)
    {
        for (int32 i = 0; i < e->numTouches; ++i)
        {
            const EmscriptenTouchPoint& touch = e->touches[i];
            Input::SetTouchState(NT_STATIC_CAST(uint32, touch.identifier), true,
                                 Vec2f(NT_STATIC_CAST(float32, touch.targetX),
                                       NT_STATIC_CAST(float32, touch.targetY)));
        }
        return EM_TRUE;
    }

    static EM_BOOL OnTouchEnd(int eventType, const EmscriptenTouchEvent* e, void* userData)
    {
        for (int32 i = 0; i < e->numTouches; ++i)
        {
            const EmscriptenTouchPoint& touch = e->touches[i];
            Input::SetTouchState(NT_STATIC_CAST(uint32, touch.identifier), false);
        }
        return EM_TRUE;
    }

    static EM_BOOL OnTouchMove(int eventType, const EmscriptenTouchEvent* e, void* userData)
    {
        for (int32 i = 0; i < e->numTouches; ++i)
        {
            const EmscriptenTouchPoint& touch = e->touches[i];

            Input::SetTouchState(NT_STATIC_CAST(uint32, touch.identifier), true,
                                 Vec2f(NT_STATIC_CAST(float32, touch.targetX),
                                       NT_STATIC_CAST(float32, touch.targetY)));
        }
        return EM_TRUE;
    }

    bool Input::Initialize(WindowHandle handle)
    {
        s_handle              = handle;
        s_keyStates.clear();
        s_mouseButtonStates.clear();
        s_mousePosition       = Vec2f(0.0f, 0.0f);
        s_mouseScrollPosition = Vec2f(0.0f, 0.0f);
        s_touchActive.clear();
        s_touchPositions.clear();
        s_activeTouchCount    = 0;

        emscripten_set_keydown_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, nullptr, EM_TRUE, OnKeyDown);
        emscripten_set_keyup_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, nullptr, EM_TRUE, OnKeyUp);
        emscripten_set_mousedown_callback(s_handle.canvas["id"], nullptr, EM_TRUE, OnMouseDown);
        emscripten_set_mouseup_callback(s_handle.canvas["id"], nullptr, EM_TRUE, OnMouseUp);
        emscripten_set_mousemove_callback(s_handle.canvas["id"], nullptr, EM_TRUE, OnMouseMove);
        emscripten_set_wheel_callback(s_handle.canvas["id"], nullptr, EM_TRUE, OnWheel);
        emscripten_set_touchstart_callback(s_handle.canvas["id"], nullptr, EM_TRUE, OnTouchStart);
        emscripten_set_touchend_callback(s_handle.canvas["id"], nullptr, EM_TRUE, OnTouchEnd);
        emscripten_set_touchmove_callback(s_handle.canvas["id"], nullptr, EM_TRUE, OnTouchMove);
        emscripten_set_touchcancel_callback(s_handle.canvas["id"], nullptr, EM_TRUE, OnTouchEnd);

        return true;
    }

    void Input::OnUpdate(void)
    {
        s_mouseScrollPosition = Vec2f(0.0f, 0.0f);

        for (auto& [key, state] : s_keyStates)
            if (state == InputState::Pressed)
                state = InputState::Held;

        for (auto& [button, state] : s_mouseButtonStates)
            if (state == InputState::Pressed)
                state = InputState::Held;
    }

    void Input::Shutdown(void)
    {
        emscripten_set_keydown_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, nullptr, EM_TRUE, nullptr);
        emscripten_set_keyup_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, nullptr, EM_TRUE, nullptr);
        emscripten_set_mousedown_callback(s_handle.canvas["id"], nullptr, EM_TRUE, nullptr);
        emscripten_set_mouseup_callback(s_handle.canvas["id"], nullptr, EM_TRUE, nullptr);
        emscripten_set_mousemove_callback(s_handle.canvas["id"], nullptr, EM_TRUE, nullptr);
        emscripten_set_wheel_callback(s_handle.canvas["id"], nullptr, EM_TRUE, nullptr);
        emscripten_set_touchstart_callback(s_handle.canvas["id"], nullptr, EM_TRUE, nullptr);
        emscripten_set_touchend_callback(s_handle.canvas["id"], nullptr, EM_TRUE, nullptr);
        emscripten_set_touchmove_callback(s_handle.canvas["id"], nullptr, EM_TRUE, nullptr);
        emscripten_set_touchcancel_callback(s_handle.canvas["id"], nullptr, EM_TRUE, nullptr);

        s_keyStates.clear();
        s_mouseButtonStates.clear();
        s_mousePosition       = Vec2f(0.0f, 0.0f);
        s_mouseScrollPosition = Vec2f(0.0f, 0.0f);
        s_touchActive.clear();
        s_touchPositions.clear();
        s_activeTouchCount    = 0;
    }
} // namespace Nt

#endif // _NT_CORE_INPUT_WASM_CPP_
