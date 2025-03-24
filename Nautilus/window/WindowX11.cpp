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

#ifndef _NT_WINDOW_WINDOW_X11_cpp_
    #define _NT_WINDOW_WINDOW_X11_cpp_

#include "WindowX11.h"

namespace nt
{
    WindowX11::WindowX11(const WindowDesc& desc, const GraphicsAPI& api) :
        m_desc(desc), m_api(api), m_display(nullptr), m_window(None),
        m_vao(0), m_vbo(0), m_program(0), m_vertex(0), m_fragment(0)
    {}

    void WindowX11::initialize()
    {
        m_display = XOpenDisplay(nullptr);

        // Create window
        m_window = XCreateSimpleWindow(m_display, RootWindow(m_display, 0),
                                       m_desc.position.x, m_desc.position.y, m_desc.width, m_desc.height, 1,
                                       BlackPixel(m_display, 0), WhitePixel(m_display, 0));

        // Set window properties
        XSetWindowAttributes attrs;
        attrs.event_mask       = ExposureMask | KeyPressMask | ButtonPressMask;
        attrs.background_color = m_desc.backgroundColor.red << 16 | m_desc.backgroundColor.green << 8 | m_desc.backgroundColor.blue;
        XChangeWindowAttributes(m_display, m_window, CWEventMask, &attrs);

        // Map window
        XMapWindow(m_display, m_window);

        // Initialize GLAD
        gladLoadGL((GLADloadproc)glXGetProcAddress);

        // Initialize OpenGL
        glXMakeCurrent(m_display, m_window, glXCreateContext(display, glXChooseVisual(display, DefaultScreen(m_display), NULL), NULL, True));

        // Enable depth (3d) support
        glEnable(GL_DEPTH_TEST);

        // Callback function
        if (m_desc.onCreate)
            m_desc.onCreate();
    }

    void WindowX11::shader(std::string vertex, std::string fragment)
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

    bool WindowX11::pollEvents()
    {
        XEvent event;
        while (XPending(m_display))
        {
            XNextEvent(m_display, &event);
            if (event.type == ClientMessage && event.xclient.data.l[0] == WM_DELETE_WINDOW)
                return false;
        }
        return true;
    }

    void WindowX11::update()
    {
        // Update window
        XFlush(m_display);

        // Callback function
        if (m_desc.onUpdate)
            m_desc.onUpdate();
    }

    void WindowX11::frame(std::vector<ReadableVertex> vertices)
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

    void WindowX11::clear(const Color& color)
    {
        glClearColor(color.red / 255.0f, color.green / 255.0f, color.blue / 255.0f, color.alpha);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void WindowX11::swapBuffers()
    {
        glXSwapBuffers(m_display, m_window);
    }

    void WindowX11::destroy()
    {
        // Callback function
        if (m_desc.onDestroy)
            m_desc.onDestroy();

        glDeleteVertexArrays(1, &m_vao);
        glDeleteBuffers(1, &m_vbo);
        glDeleteProgram(m_program);
        glDeleteShader(m_vertex);
        glDeleteShader(m_fragment);
        glXMakeCurrent(m_display, None, NULL);
        glXDestroyContext(m_display, glXGetCurrentContext());

        // Destroy window
        if (m_window)
            XDestroyWindow(m_display, m_window);
        if (m_display)
            XCloseDisplay(m_display);
    }

    void* WindowX11::getHandle()
    {
        return static_cast<void*>(m_window);
    }

    WindowDesc WindowX11::getDescription()
    {
        return m_desc;
    }
} // namespace nt

#endif // _NT_WINDOW_WINDOW_X11_cpp_
