//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                                 ...
//
//                  Copyright (c) Rohan Bharatia 2025

#import "../Window.h"

#import "../../Logger.h"

@interface Window : NSObject
{
    NSWindow* m_window;
}

namespace nt
{

    void Window::create(const std::string& title)
    {
        m_window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
        [m_window setBackgroundColor:[UIColor whiteColor]];
        [m_window makeKeyAndVisible];
    }

    bool Window::pollEvents()
    {
        // In UIKit, events are handled by the UIResponder chains
        return true;
    }

    void Window::update()
    {
        // In UIKit, the window is updated automatically
    }

    void Window::destroy()
    {
        if (m_window)
        {
            [m_window setHidden:YES];
            [m_window release];
        }
    }

    void* Window::getNativeHandle()
    {
        return (void*)m_window;
    }

    float Window::getDeltaTime()
    {
        static CFTimeInterval lastTime = 0;
        CFTimeInterval currentTime     = CACurrentMediaTime();
        float deltaTime                = (currentTime - lastTime);
        lastTime                       = currentTime;
        return deltaTime;
    }
}
