//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#ifndef _NT_WINDOW_EVENT_cpp_
    #define _NT_WINDOW_EVENT_cpp_

#include "Event.h"

#include "../core/Timer.h"

namespace nt
{
    bool Event::isKeyUp(int key)
    {
        return !isKeyDown(key);
    }
    
    bool Event::isKeyPressed(int key)
    {
        return isKeyDown(key);
    }
    
    bool Event::isKeyDoublePressed(int key, uint32 timeout)
    {
        Timer timer;
        if (isKeyPressed(key))
            timer.start();
        if (isKeyPressed(key))
            timer.stop();
        return (timer.getElapsedTime() <= timeout);
    }

    bool Event::isMouseButtonUp(int button)
    {
        return !isMouseButtonDown(button);
    }

    bool Event::isMouseButtonPressed(int button)
    {
        return isMouseButtonDown(button);
    }

    bool Event::isMouseButtonDoublePressed(int button, uint32 timeout)
    {
        Timer timer;
        if (isMouseButtonPressed(button))
            timer.start();
        if (isMouseButtonPressed(button))
            timer.stop();
        return (timer.getElapsedTime() <= timeout);
    }
} // namespace nt

#endif // _NT_WINDOW_EVENT_cpp_