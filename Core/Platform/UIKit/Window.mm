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

@interface Window : WindowDesc
{
    WindowDesc m_desc;
}

@interface Window : NSObject
{
    NSWindow* m_window;
}

namespace nt
{
    void Window::create(const WindowDesc& desc)
    {
        m_desc = desc;

        m_window = [[UIWindow alloc] initWithFrame:CGRectMake(desc.x, desc.y, desc.width, desc.height)];

        if (!m_window)
        {
            Logger::error("Failed to create window!");
            abort();
        }

        [m_window setBackgroundColor:[UIColor colorWithRed:m_desc.bgColor.r green:m_desc.bgColor.g blue:m_desc.bgColor.b alpha:m_desc.bgColor.a]];
        [m_window setTitle:[NSString stringWithUTF8String:desc.title.c_str()]];

        if (!desc.resizable)
        {
            m_window.frame = CGRectMake(desc.x, desc.y, desc.width, desc.height);
            m_window.autoresizingMask = UIViewAutoresizingNone;
        }
        if (desc.borderless)
            m_window.windowLevel = UIWindowLevelStatusBar;
        if (desc.fullscreenable)
            m_window.frame = [[UIScreen mainScreen] bounds];
        if (!desc.maximizable)
            m_window.autoresizingMask = UIViewAutoresizingNone;
        if (!desc.minimizable)
            m_window.autoresizingMask = UIViewAutoresizingNone;

        if (desc.fullscreen)
        {
            [m_window setFrame:[[UIScreen mainScreen] bounds]];
            [m_window setWindowLevel:UIWindowLevelStatusBar];
        }
        else if (desc.maximized)
        {
            [m_window setFrame:[[UIScreen mainScreen] bounds]];
            [m_window setWindowLevel:UIWindowLevelNormal];
        }
        else if (desc.minimized)
            // Not applicable on iOS
        else if (desc.modal)
            [m_window setWindowLevel:UIWindowLevelAlert];

        [m_window makeKeyAndVisible];
    }

    bool Window::pollEvents()
    {
        // Events are handled by the UIResponder chains with UIKit
        return true;
    }

    void Window::update()
    {
        // The window is updated automatically with UIKit
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
