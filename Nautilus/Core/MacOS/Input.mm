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

#ifndef _NT_CORE_INPUT_MACOS_CPP_
    #define _NT_CORE_INPUT_MACOS_CPP_

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

        @autorealspool
        {
            NSEvent* event;
            while ((event = [NSApp nextEventMatchingMask:NSEventMaskAny
                                               untilDate:[NSDate distantPast]
                                                  inMode:NSDefaultRunLoopMode
                                                 dequeue:YES]))
            {
                switch([event type])
                {
                    case NSEventTypeKeyDown:
                        SetKeyState(NT_STATIC_CAST(uint32, [event keyCode]), InputState::Pressed);
                        break;
                    case NSEventTypeKeyUp:
                        SetKeyState(NT_STATIC_CAST(uint32, [event keyCode]), InputState::Released);
                        break;
                    case NSEventTypeLeftMouseDown:
                        SetMouseButtonState(0, InputState::Pressed);
                        break;
                    case NSEventTypeLeftMouseUp:
                        SetMouseButtonState(0, InputState::Released);
                        break;
                    case NSEventTypeRightMouseDown:
                        SetMouseButtonState(1, InputState::Pressed);
                        break;
                    case NSEventTypeRightMouseUp:
                        SetMouseButtonState(1, InputState::Released);
                        break;
                    case NSEventTypeOtherMouseDown:
                        SetMouseButtonState(2, InputState::Pressed);
                        break;
                    case NSEventTypeOtherMouseUp:
                        SetMouseButtonState(2, InputState::Released);
                        break;
                    case NSEventTypeMouseMoved:
                    case NSEventTypeLeftMouseDragged:
                    case NSEventTypeRightMouseDragged:
                    case NSEventTypeOtherMouseDragged:
                        SetMousePosition(Vec2f(NT_STATIC_CAST(float32, [event locactionInWindow].x),
                                               NT_STATIC_CAST(float32, [event locationInWindow].y)));
                    case NSEventTypeScrollWheel:
                        SetMouseScrollPosition(Vec2f(NT_STATIC_CAST(float32, [event scrollingDeltaX]),
                                                     NT_STATIC_CAST(float32, [event scrollingDeltaY])));
                    default:
                        break;
                }
            }
        }

        NSPoint mouseLocation = [NSEvent mouseLocation];
        NSView* view          = (__bridge NSView*)((__bridge void*)(window contentView);
        NSPoint localPoint    = [view convertPoint:mouseLocation fromView:nil];
        SetMousePosition(Vec2f(NT_STATIC_CAST(float32, localPoint.x),
                               NT_STATIC_CAST(float32, localPoint.y)));
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

#endif // _NT_CORE_INPUT_MACOS_CPP_
