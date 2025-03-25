#pragma region LICENSE

//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2025 Rohan Bharatia

#pragma endregion LICENSE

#import "WindowUIKit.h"

namespace nt
{
    WindowUIKit::WindowUIKit(const WindowDesc& desc) :
        m_window(nullptr), m_desc(desc)
    {}

    void WindowUIKit::initialize()
    {
        // Set window properties
        UIWindowSceneConfiguration *configuration = [[UIWindowSceneConfiguration alloc] initWithSize:[[UIScreen mainScreen] bounds].size];
        configuration.windowSceneClass            = [UIWindowScene class];


        // Create window
        m_window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds] windowScene:[UIWindowScene sceneWithSession:nil configuration:configuration]];

        // Set window background color
        m_window.backgroundColor = [UIColor colorWithRed:m_desc.backgroundColor.red / 255.0
                                                    green:m_desc.backgroundColor.green / 255.0
                                                    blue:m_desc.backgroundColor.blue / 255.0
                                                    alpha:1.0];

        // Set window states
        if (m_desc.visible)
            m_window.hidden = NO;
        else
            m_window.hidden = YES;

        // Set modal state
        if (m_desc.modal)
        {
            UIViewController *viewController      = [[UIViewController alloc] init];
            viewController.modalPresentationStyle = UIModalPresentationFullScreen;
            [m_window.rootViewController presentViewController:viewController animated:YES completion:nil];
        }

        // Callback function
        if (m_desc.onCreate)
            m_desc.onCreate();
    }

    bool WindowUIKit::pollEvents()
    {
        // Poll events
        [[UIApplication sharedApplication] processEvents];

        return true;
    }

    void WindowUIKit::update()
    {
        // Update window
        [m_window setNeedsDisplay];

        // Callback function
        if (m_desc.onUpdate)
            m_desc.onUpdate();
    }

    void WindowUIKit::destroy()
    {
        // Callback function
        if (m_desc.onDestroy)
            m_desc.onDestroy();

        // Destroy window
        if (m_window)
            [m_window setHidden:YES];
    }

    void* WindowUIKit::getHandle()
    {
        return static_cast<void*>(m_window);
    }

    WindowDesc WindowUIKit::getDescription()
    {
        return m_desc;
    }
} // namespace nt
