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

@interface Window : UIObject
{
    UIWindow* m_handle.window;
}

namespace nt
{
    bool Window::initialize(const WindowDesc& desc)
    {
        m_desc = desc;

        m_handle.window = [[UIWindow alloc] initWithFrame:CGRectMake(desc.x, desc.y, desc.width, desc.height)];

        if (!m_handle.window)
        {
            [Logger error:"Failed to create window!"];
            return false;
        }

        [m_handle.window setBackgroundColor:[UIColor colorWithRed:m_desc.bgColor.r green:m_desc.bgColor.g blue:m_desc.bgColor.b alpha:m_desc.bgColor.a]];
        [m_handle.window setTitle:[NSString stringWithUTF8String:desc.title.c_str()]];

        if (!desc.resizable)
        {
            m_handle.window.frame = CGRectMake(desc.x, desc.y, desc.width, desc.height);
            m_handle.window.autoresizingMask = UIViewAutoresizingNone;
        }
        if (desc.borderless)
            m_handle.window.windowLevel = UIWindowLevelStatusBar;
        if (desc.fullscreenable)
            m_handle.window.frame = [[UIScreen mainScreen] bounds];
        if (!desc.maximizable)
            m_handle.window.autoresizingMask = UIViewAutoresizingNone;
        if (!desc.minimizable)
            m_handle.window.autoresizingMask = UIViewAutoresizingNone;

        if (desc.fullscreen)
        {
            [m_handle.window setFrame:[[UIScreen mainScreen] bounds]];
            [m_handle.window setWindowLevel:UIWindowLevelStatusBar];
        }
        else if (desc.maximized)
        {
            [m_handle.window setFrame:[[UIScreen mainScreen] bounds]];
            [m_handle.window setWindowLevel:UIWindowLevelNormal];
        }
        else if (desc.minimized)
            // Not applicable on iOS
        else if (desc.modal)
            [m_handle.window setWindowLevel:UIWindowLevelAlert];

        [m_handle.window makeKeyAndVisible];

        if (desc.onCreate)
            [desc onCreate];

        return true;
    }

    bool Window::pollEvents()
    {
        // Events are handled by the UIResponder chains with UIKit
        return true;
    }

    void Window::update()
    {
        // The window is updated automatically with UIKit

        if (desc.onUpdate)
            [desc onUpdate];
    }

    void Window::destroy()
    {
        if (desc.onClose)
            [desc onClose];
            
        if (m_handle.window)
        {
            [m_handle.window setHidden:YES];
            [m_handle.window release];
        }
    }

    const WindowDesc& Window::getWindowDesc() const
    {
        return m_desc;
    }

    const NativeHandle& Window::getHandle() const
    {
        return m_handle;
    }
} // namespace nt
