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

#import <EGL/egl.h>
#import <GLES2/gl2.h>

namespace nt
{
    WindowUIKit::WindowUIKit(const WindowDesc& desc) :
        m_desc(desc), m_window(nullptr)
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

        // Initialize OpenGL
        EAGLContext* context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
        [EAGLContext setCurrentContext:context];

        glEnable(GL_DEPTH_TEST);

        UIView view  = [[UIView alloc] initWithFrame:CGRectMake(0, 0, m_window.frame.size.width, m_window.frame.size.height)];
        CGRect frame = view.frame;
        glViewport(0, 0, frame.size.width, frame.size.height);

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

    void WindowUIKit::frame(std::vector<ReadableVertex>& vertices)
    {
        // Enable vertex arrays
        glVertexPointer(3, GL_FLOAT, sizeof(ReadableVertex), &vertices[0].position);
        glEnableClientState(GL_VERTEX_ARRAY);

        // Enable texture arrays
        glTexCoordPointer(2, GL_FLOAT, sizeof(ReadableVertex), &vertices[0].uv);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);

        // Enable color arrays
        glColorPointer(4, GL_FLOAT, sizeof(ReadableVertex), &vertices[0].color);
        glEnableClientState(GL_COLOR_ARRAY);

        // Draw the vertices
        glDrawArrays(GL_TRIANGLES, 0, vertices.size());

        // Disable v/t/c arrays
        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);
    }

    void WindowUIKit::clear(const Color& color)
    {
        glClearColor(color.red / 255.0, color.green / 255.0, color.blue / 255.0, color.alpha);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void WindowUIKit::swapBuffers()
    {
        [[EAGLContext currentContext] presentRenderbuffer:GL_RENDERBUFFER];
    }

    void WindowUIKit::destroy()
    {
        // Callback function
        if (m_desc.onDestroy)
            m_desc.onDestroy();

        // Destroy OpenGL
        EAGLContext* context = [EAGLContext currentContext];
        [EAGLContext setCurrentContext:nil];
        [context release];

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
