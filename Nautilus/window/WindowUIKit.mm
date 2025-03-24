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
    WindowUIKit::WindowUIKit(const WindowDesc& desc, const GraphicsAPI& api) :
        m_desc(desc), m_api(api), m_window(nullptr),
        m_vao(0), m_vbo(0), m_program(0), m_vertex(0), m_fragment(0)
    {}

    void WindowUIKit::initialize()
    {
        // Create window
        m_window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];

        // Set window properties
        m_window.backgroundColor = [UIColor colorWithRed:m_desc.backgroundColor.red / 255.0
                                                    green:m_desc.backgroundColor.green / 255.0
                                                     blue:m_desc.backgroundColor.blue / 255.0
                                                    alpha:1.0];

        // Make window visible
        [m_window makeKeyAndVisible];

        // Initialize GLAD
        gladLoadGL((GLADloadproc)EGLGetProcAddress);

        // Initialize OpenGL
        EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
        EGLSurface surface = eglCreateWindowSurface(display, eglChooseConfig(display, NULL, NULL, 1), 1, NULL);
        eglMakeCurrent(display, surface, surface, eglCreateContext(display, eglChooseConfig(display, NULL, NULL, 1), EGL_NO_CONTEXT, NULL));

        // Enable depth (3d) support
        glEnable(GL_DEPTH_TEST);

        // Callback function
        if (m_desc.onCreate)
            m_desc.onCreate();
    }

    void WindowUIKit::shader(std::string vertex, std::string fragment)
    {
        // Create and compile vertex shader
        m_vertex                 = glCreateShader(GL_VERTEX_SHADER);
        const char* vertexSource = vertex.c_str();
        glShaderSource(m_vertex, 1, &vertexSource, NULL);
        glCompileShader(m_vertex);

        // Create and compile fragment shader
        m_fragment                 = glCreateShader(GL_FRAGMENT_SHADER);
        const char* fragmentSource = fragment.c_str();
        glShaderSource(m_fragment, 1, &fragmentSource, NULL);
        glCompileShader(m_fragment);

        // Create and link program
        m_program = glCreateProgram();
        glAttachShader(m_program, m_vertex);
        glAttachShader(m_program, m_fragment);
        glLinkProgram(m_program);

        // Use program
        glUseProgram(m_program);
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

    void WindowUIKit::frame(std::vector<ReadableVertex> vertices)
    {
        // Render
        glGenVertexArrays(1, &m_vao);
        glBindVertexArray(m_vao);

        glGenBuffers(1, &m_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(ReadableVertex), vertices.data(), GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ReadableVertex), (void*)(sizeof(float) * 3)); // Position

        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(ReadableVertex), (void*)(sizeof(float) * 2)); // Texture

        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(ReadableVertex), (void*)(sizeof(float) * 4)); // Color

        glDrawArrays(GL_TRIANGLES, 0, vertices.size());

        glDisableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        glDeleteVertexArrays(1, &m_vao);
        glDeleteBuffers(1, &m_vbo);
    }

    void WindowUIKit::clear(const Color& color)
    {
        glClearColor(color.red / 255.0f, color.green / 255.0f, color.blue / 255.0f, color.alpha);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void WindowUIKit::swapBuffers()
    {
        EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
        EGLSurface surface = eglCreateWindowSurface(display, eglChooseConfig(display, NULL, NULL, 1), 1, NULL);
        eglSwapBuffers(surface, surface);
    }

    void WindowUIKit::destroy()
    {
        // Callback function
        if (m_desc.onDestroy)
            m_desc.onDestroy();

        glDeleteVertexArrays(1, &m_vao);
        glDeleteBuffers(1, &m_vbo);
        glDeleteProgram(m_program);
        glDeleteShader(m_vertex);
        glDeleteShader(m_fragment);

        EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
        eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        eglDestroyContext(display, eglGetCurrentContext());

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
