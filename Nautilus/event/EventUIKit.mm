//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#import "Event.h"

#import <UIKit/UIKit.h>

namespace nt
{
    bool Event<EventType::KEYBOARD>::isKeyDown(int key)
    {
        UIWindow *window = [UIApplication sharedApplication].keyWindow;
        UIView *view = window.rootViewController.view;
        UIResponder *responder = view.firstResponder;

        if ([responder isKindOfClass:[UIKeyboard class]])
        {
            UIKeyboard *keyboard = (UIKeyboard *)responder;
            return [keyboard isKeyDown:key];
        }

        return false;
    }

    bool Event<EventType::MOUSE>::isMouseButtonDown(int button)
    {
        UITouch *touch = [UITouch touchWithEvent:nil];
        return [touch isButtonDown:button];
    }

    Vec2f Event<EventType::MOUSE>::getMousePosition()
    {
        UITouch *touch = [UITouch touchWithEvent:nil];
        return Vec2f(touch.locationInView(nil).x, touch.locationInView(nil).y);
    }
}