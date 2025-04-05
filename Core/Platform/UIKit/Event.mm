//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                                 ...
//
//                  Copyright (c) Rohan Bharatia 2025

#import "../Event.h"

#import "../API.h"

namespace nt
{
    bool Event<EVENT_KEYBOARD>::isKeyPressed(int key)
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
                    return (int)character == key;
                }
            }
        }
        return false;
    }

    bool Event<EVENT_KEYBOARD>::isKeyReleased(int key)
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

    bool Event<EVENT_KEYBOARD>::isKeyRepeated(int key, int count)
    {
        static int repeatCount = 0;
        if (Event<EVENT_KEYBOARD>::isKeyPressed(key))
        {
            ++repeatCount;
            return repeatCount >= count;
        }
        else
        {
            repeatCount = 0;
            return false;
        }
    }

    bool Event<EVENT_MOUSE>::isMousePressed(int button)
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
                    return (int)character == key;
                }
            }
        }
        return false;
    }

    bool Event<EVENT_MOUSE>::isMouseReleased(int button)
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

    bool Event<EVENT_MOUSE>::isMouseHeld(int button)
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
                    return (int)character == key;
                }
            }
        }
        return false;
    }

    bool Event<EVENT_MOUSE>::isMouseRepeated(int button, int count)
    {
        static int repeatCount = 0;
        if (Event<EVENT_MOUSE>::isMousePressed(button))
        {
            ++repeatCount;
            return repeatCount >= count;
        }
        else
        {
            repeatCount = 0;
            return false;

        }
    }
}
