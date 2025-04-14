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

#ifndef _NT_CORE_PLATFORM_EMSCRIPTEN_INPUT_CPP_
    #define _NT_CORE_PLATFORM_EMSCRIPTEN_INPUT_CPP_

#include "../Input.h"

#include "../API.h"
#include "../../Clock.h"

#include <map>

namespace nt
{
    static std::map<Key, uint64_t> keyPressTimes;
    static std::map<Mouse, uint64_t> mousePressTimes;

    static std::unordered_set<std::string> keysDown;
    static std::unordered_map<std::string, double> keyPressTimes;

    static std::unordered_set<int> mouseDown;
    static std::unordered_map<int, double> mousePressTimes;

    static Vec2f mousePos = {0.0f, 0.0f};
    static float mouseScroll = 0.0f;

    static val window = val::global("window");

    static std::string keyToString(Key key) {
        return std::string(1, static_cast<char>(key));
    }

    static void setupInputEvents()
    {
        val document = val::global("document");

        document.call<void>("addEventListener", std::string("keydown"), val::module_property("onKeyDown"));
        document.call<void>("addEventListener", std::string("keyup"), val::module_property("onKeyUp"));
        document.call<void>("addEventListener", std::string("mousedown"), val::module_property("onMouseDown"));
        document.call<void>("addEventListener", std::string("mouseup"), val::module_property("onMouseUp"));
        document.call<void>("addEventListener", std::string("mousemove"), val::module_property("onMouseMove"));
        document.call<void>("addEventListener", std::string("wheel"), val::module_property("onWheel"));
    }

    EMSCRIPTEN_BINDINGS(input_events) {
        function("onKeyDown", optional_override([](val event) {
            std::string code = event["key"].as<std::string>();
            keysDown.insert(code);
            keyPressTimes[code] = emscripten_get_now() / 1000.0;
        }));

        function("onKeyUp", optional_override([](val event) {
            std::string code = event["key"].as<std::string>();
            keysDown.erase(code);
            keyPressTimes.erase(code);
        }));

        function("onMouseDown", optional_override([](val event) {
            int button = event["button"].as<int>();
            mouseDown.insert(button);
            mousePressTimes[button] = emscripten_get_now() / 1000.0;
        }));

        function("onMouseUp", optional_override([](val event) {
            int button = event["button"].as<int>();
            mouseDown.erase(button);
            mousePressTimes.erase(button);
        }));

        function("onMouseMove", optional_override([](val event) {
            mousePos = Vec2f(event["clientX"].as<float>(), event["clientY"].as<float>());
        }));

        function("onWheel", optional_override([](val event) {
            mouseScroll += event["deltaY"].as<float>() / 100.0f;
        }));
    }

    uint32_t Input<InputType::KEYBOARD>::keyCodeToInt(Key key)
    {
        return static_cast<int>(key);
    }

    bool Input<InputType::KEYBOARD>::isKeyDown(Key key)
    {
        return keysDown.contains(keyToString(key));
    }

    bool Input<InputType::KEYBOARD>::isKeyUp(Key key)
    {
        return !keysDown.contains(keyToString(key));
    }

    bool Input<InputType::KEYBOARD>::isKeyPressed(Key key)
    {
        Clock clock;
        clock.start();
        if (isKeyDown(key))
        {
            keyPressTimes[key] = clock.getElapsedTime();
            return true;
        }
        return false;
    }

    bool Input<InputType::KEYBOARD>::isKeyReleased(Key key)
    {
        if (isKeyUp(key))
        {
            keyPressTimes.erase(key);
            return true;
        }
        return false;
    }

    bool Input<InputType::KEYBOARD>::isKeyHeld(Key key)
    {
        if (isKeyDown(key))
        {
            const double holdTime = 0.5;
            auto it               = keyPressTimes.find(key);
            Clock clock;
            clock.start();
            if (it != keyPressTimes.end())
            {
                double currentTime = clock.getElapsedTime();
                if (currentTime - it->second > holdTime)
                    return true;
            }
        }
        return false;
    }

    bool Input<InputType::KEYBOARD>::isKeyRepeated(Key key, uint32_t repeatCount, uint32_t delay)
    {
        if (isKeyDown(key))
        {
            auto it = keyPressTimes.find(key);
            Clock clock;
            clock.start();
            if (it != keyPressTimes.end())
            {
                double currentTime    = clock.getElapsedTime();
                double pressTime      = it->second;
                double repeatInterval = delay * repeatCount / 1000.0;
                if (currentTime - pressTime > repeatInterval)
                    return true;
            }
        }
        return false;
    }

    uint32_t Input<InputType::MOUSE>::mouseButtonCodeToInt(Mouse button)
    {
        return static_cast<int>(button);
    }

    bool Input<InputType::MOUSE>::isMouseButtonDown(Mouse button)
    {
        return mouseDown.contains(mouseButtonCodeToInt(button));
    }

    bool Input<InputType::MOUSE>::isMouseButtonUp(Mouse button)
    {
        return !mouseDown.contains(mouseButtonCodeToInt(button));
    }

    bool Input<InputType::MOUSE>::isMouseButtonPressed(Mouse button)
    {
        Clock clock;
        clock.start();
        if (isMouseButtonDown(button))
        {
            mousePressTimes[button] = clock.getElapsedTime();
            return true;
        }
        return false;
    }

    bool Input<InputType::MOUSE>::isMouseButtonReleased(Mouse button)
    {
        if (isMouseButtonUp(button))
        {
            mousePressTimes.erase(button);
            return true;
        }
        return false;
    }

    bool Input<InputType::MOUSE>::isMouseButtonHeld(Mouse button)
    {
        if (isMouseButtonDown(button))
        {
            const double holdTime = 0.5;
            auto it               = mousePressTimes.find(button);
            Clock clock;
            clock.start();
            if (it != mousePressTimes.end())
            {
                double currentTime = clock.getElapsedTime();
                if (currentTime - it->second > holdTime)
                    return true;
            }
        }
        return false;
    }

    bool Input<InputType::MOUSE>::isMouseButtonRepeated(Mouse button, uint32_t repeatCount, uint32_t delay)
    {
        if (isMouseButtonDown(button))
        {
            auto it = mousePressTimes.find(button);
            Clock clock;
            clock.start();
            if (it != mousePressTimes.end())
            {
                double currentTime    = clock.getElapsedTime();
                double pressTime      = it->second;
                double repeatInterval = delay * repeatCount / 1000.0;
                if (currentTime - pressTime > repeatInterval)
                    return true;
            }
        }
        return false;
    }

    Vec2f Input<InputType::MOUSE>::getMousePosition()
    {
        POINT point;
        GetCursorPos(&point);
        return Vec2f((float)point.x, (float)point.y);
    }

    float Input<InputType::MOUSE>::getMouseScrollPosition()
    {
        int wheelDelta = 0;
        if (GetMessageExtraInfo() != 0)
            wheelDelta = GET_WHEEL_DELTA_WPARAM(GetMessageExtraInfo());
        static float scrollPos = 0.0f;
        scrollPos             += (float)wheelDelta / WHEEL_DELTA;
        return scrollPos;
    }
}

#endif // _NT_CORE_PLATFORM_EMSCRIPTEN_INPUT_CPP_
