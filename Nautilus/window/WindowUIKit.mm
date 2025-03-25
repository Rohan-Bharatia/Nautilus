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
        m_desc(desc), m_window(nullptr),
        m_vao(0), m_vbo(0), m_ebo(0), m_vshader(0), m_fshader(0), m_program(0)
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
        EAGLContext* ctx   = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
        EGLDisplay display = [ctx eaglDisplay];
        EGLConfig config;
        EGLint num_configs;
        EGLint attribs[]   =
        {
            EGL_SURFACE_TYPE,    EGL_WINDOW_BIT,
            EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
            EGL_RED_SIZE,        8,
            EGL_GREEN_SIZE,      8,
            EGL_BLUE_SIZE,       8,
            EGL_DEPTH_SIZE,      24,
            EGL_NONE
        };

        eglChooseConfig(display, attribs, &config, 1, &num_configs);

        EGLSurface surface = eglCreateWindowSurface(display, config, (EGLNativeWindowType)window, NULL);
        EGLContext context = eglCreateContext(display, config, EGL_NO_CONTEXT, NULL);

        eglMakeCurrent(display, surface, surface, context);

        // Callback function
        if (m_desc.onCreate)
            m_desc.onCreate();
    }

    void WindowUIKit::useShader(std::string vertex, std::string fragment)
    {
        // Create and compile vertex shader
        m_vshader                = glCreateShader(GL_VERTEX_SHADER);
        const char* vertexSource = vertex.c_str();
        glShaderSource(m_vshader, 1, &vertexSource, nullptr);
        glCompileShader(m_vshader);

        // Create and compile fragment shader
        m_fshader                  = glCreateShader(GL_FRAGMENT_SHADER);
        const char* fragmentSource = fragment.c_str();
        glShaderSource(m_fshader, 1, &fragmentSource, nullptr);
        glCompileShader(m_fshader);

        // Create program and attach shaders
        GLuint program = glCreateProgram();
        glAttachShader(program, m_vshader);
        glAttachShader(program, m_fshader);
        glLinkProgram(program);

        // Use program
        glUseProgram(program);

        // Delete shaders (program has a reference to them)
        glDeleteShader(m_vshader);
        glDeleteShader(m_fshader);

        // Store program ID
        m_program = program;
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

    void WindowUIKit::clear(const Color& color)
    {
        // Clear screen with specified color
        glClearColor(color.red / 255.0f, color.green / 255.0f, color.blue / 255.0f, color.alpha);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void WindowUIKit::swapBuffers()
    {
        // Swap front and back buffers
        [[EAGLContext currentContext] presentRenderbuffer:GL_RENDERBUFFER];
    }

    void WindowUIKit::destroy()
    {
        // Callback function
        if (m_desc.onDestroy)
            m_desc.onDestroy();

        // Delete program
        glDeleteProgram(m_program);

        // Delete OpenGL context
        [[EAGLContext currentContext] release];

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
