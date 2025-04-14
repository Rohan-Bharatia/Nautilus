//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                                 ...
//
//                  Copyright (c) Rohan Bharatia 2025

#import "../Input.h"

#import "../API.h"
#import "../../Clock.h"

#import <map>

namespace nt
{
    static std::map<Key, uint64_t> keyPressTimes;
    static std::map<Mouse, uint64_t> mousePressTimes;

    uint32_t Input<InputType::KEYBOARD>::keyCodeToInt(Key key)
    {
        return static_cast<int>(key);
    }

    bool Input<InputType::KEYBOARD>::isKeyDown(Key key)
    {
        UIResponder* responder = [UIApplication sharedApplication].keyWindow.firstResponder;
        if ([responder isKindOfClass:[UIKeyInput class]])
        {
            UIKeyInput* keyInput = (UIKeyInput*)responder;
            if ([keyInput hasText])
            {
                NSString* text = [keyInput text];
                if (text.length == 1)
                {
                    unichar character = [text characterAtIndex:0];
                    return (int)character == [keyCodeToInt:key];
                }
            }
        }
        return false;
    }

    bool Input<InputType::KEYBOARD>::isKeyUp(Key key)
    {
        UIResponder* responder = [UIApplication sharedApplication].keyWindow.firstResponder;
        if ([responder isKindOfClass:[UIKeyInput class]])
        {
            UIKeyInput* keyInput = (UIKeyInput*)responder;
            if (![keyInput hasText])
                return true;
        }
        return false;
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
        UIResponder* responder = [UIApplication sharedApplication].keyWindow.firstResponder;
        if ([responder isKindOfClass:[UIMouseInput class]])
        {
            UIMouseInput* mouseInput = (UIMouseInput*)responder;
            if ([mouseyInput hasText])
            {
                NSString* text = [mouseInput text];
                if (text.length == 1)
                {
                    unichar character = [text characterAtIndex:0];
                    return (int)character == [mouseButtonCodeToInt:button];
                }
            }
        }
        return false;
    }

    bool Input<InputType::MOUSE>::isMouseButtonUp(Mouse button)
    {
        UIResponder* responder = [UIApplication sharedApplication].keyWindow.firstResponder;
        if ([responder isKindOfClass:[UIMouseInput class]])
        {
            UIMouseInput* mouseInput = (UIMouseInput*)responder;
            if (![mouseyInput hasText])
                return true;
        }
        return false;
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
        return [Vec2f:0.0f, 0.0f];
    }

    float Input<InputType::MOUSE>::getMouseScrollPosition()
    {
        UIResponder* responder = [UIApplication sharedApplication].keyWindow.firstResponder;
        if ([responder isKindOfClass:[UIScrollView class]])
        {
            UIScrollView* scrollView = (UIScrollView*)responder;
            return scrollView.contentOffset.y;
        }
        return 0.0f;
    }
}
