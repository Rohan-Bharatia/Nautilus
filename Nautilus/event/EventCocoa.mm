//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#import "Event.h"

#import <AppKit/AppKit.h>

namespace nt
{       
    bool Event::isKeyDown(int key)
    {
        NSEvent *event = [NSApp currentEvent];
        if (event.type == NSKeyDown)
        {
            unsigned short keyCode = [event keyCode];
            return keyCode == key;
        }
        return false;
    }
    
    bool Event::isMouseButtonDown(int button)
    {
        NSEvent *event = [NSApp currentEvent];
        if (event.type == NSMouseDown || event.type == NSMouseDragged)
        {
            NSUInteger buttonMask = [event buttonNumber];
            switch (button)
            {
                case Mouse::MOUSE_BUTTON_LEFT:
                    return buttonMask == 0;
                case Mouse::MOUSE_BUTTON_RIGHT:
                    return buttonMask == 1;
                case Mouse::MOUSE_BUTTON_MIDDLE:
                    return buttonMask == 2;
                default:
                    return false;
            }
        }
        return false;
    }
    
    Vec2f Event::getMousePosition()
    {
        NSPoint mouseLocation = [NSEvent mouseLocation];
        return Vec2f(mouseLocation.x, mouseLocation.y);
    }
} // namespace nt