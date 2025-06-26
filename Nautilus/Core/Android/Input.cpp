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

#ifndef _NT_CORE_INPUT_ANDROID_CPP_
    #define _NT_CORE_INPUT_ANDROID_CPP_

#include "../Input.h"

namespace Nt
{
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

        int32 events;
        struct android_poll_source* source;

        while (ALooper_pollAll(0, nullptr, &events, NT_REINTERPRET_CAST(void**, &source)) >= 0)
        {
            if (source)
                source->process(s_handle.app);
        }
    }

    void Input::Shutdown(void)
    {
        s_keyStates.clear();
        s_mouseButtonStates.clear();
        s_mousePosition       = Vec2f(0.0f, 0.0f);
        s_mouseScrollPosition = Vec2f(0.0f, 0.0f);
        s_touchActive.clear();
        s_touchPositions.clear();
        s_activeTouchCount    = 0;
    }
} // namespace Nt

#endif // _NT_CORE_INPUT_ANDROID_CPP_
