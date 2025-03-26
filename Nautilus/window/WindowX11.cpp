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
    WindowX11::WindowX11(const WindowDesc& desc) :
        m_desc(desc), m_display(nullptr), m_window(None),
        m_vao(0), m_vbo(0), m_ebo(0), m_vshader(0), m_fshader(0), m_program(0)
    {}

    void WindowX11::initialize()
    {
        // Set window properties
        XSetWindowAttributes attrs;
        attrs.event_mask       = ExposureMask | KeyPressMask | ButtonPressMask;
        attrs.background_color = m_desc.backgroundColor.red << 16 | m_desc.backgroundColor.green << 8 | m_desc.backgroundColor.blue;

        if (!m_desc.resizable)
            attrs.override_redirect = True;
            if (!m_desc.movable)
                attrs.override_redirect = True;
            if (!m_desc.closable)
                attrs.override_redirect = True;
            if (!m_desc.maximizable)
                attrs.override_redirect = True;
            if (!m_desc.minimizable)
                attrs.override_redirect = True;
            if (!m_desc.canFullscreen)
                attrs.override_redirect = True;

            // Create window
            m_display = XOpenDisplay(nullptr);
            m_window  = XCreateWindow(m_display, RootWindow(m_display, 0), m_desc.position.x, m_desc.position.y,
                                      m_desc.width, m_desc.height, 1, BlackPixel(m_display, 0), WhitePixel(m_display, 0),
                                      InputOutput, CopyFromParent, CWEventMask | CWOverrideRedirect, &attrs);

        // Center window (if necessary)
        if (m_desc.centered)
        {
            int screenWidth  = DisplayWidth(m_display, 0);
            int screenHeight = DisplayHeight(m_display, 0);
            int x            = (screenWidth - m_desc.width) / 2;
            int y            = (screenHeight - m_desc.height) / 2;
            XMoveWindow(m_display, m_window, x, y);
        }

        // Set window states
        if (m_desc.visible)
        {
            if (m_desc.fullscreen)
            {
                XEvent event;
                event.type = MapNotify;
                event.xmap.window = m_window;
                event.xmap.event = m_window;
                event.xmap.x = 0;
                event.xmap.y = 0;
                event.xmap.width = m_desc.width;
                event.xmap.height = m_desc.height;
                event.xmap.override_redirect = False;
                XSendEvent(m_display, m_window, False, StructureNotifyMask, &event);
            }
            if (m_desc.maximized)
            {
                XEvent event;
                event.type = MapNotify;
                event.xmap.window = m_window;
                event.xmap.event = m_window;
                event.xmap.x = 0;
                event.xmap.y = 0;
                event.xmap.width = m_desc.width;
                event.xmap.height = m_desc.height;
                event.xmap.override_redirect = False;
                XSendEvent(m_display, m_window, False, StructureNotifyMask, &event);
            }
            if (m_desc.minimized)
                XIconifyWindow(m_display, m_window, 0);
            if (!m_desc.fullscreen && !m_desc.maximized && !m_desc.minimized)
                XMapWindow(m_display, m_window);
        }
        else
            XUnmapWindow(m_display, m_window);

        // Set focus
        if (m_desc.focused)
            XSetInputFocus(m_display, m_window, RevertToParent, CurrentTime);

        // Set modal state
        if (m_desc.modal)
        {
            XGrabKeyboard(m_display, m_window, True, GrabModeAsync, GrabModeAsync, CurrentTime);
            XGrabPointer(m_display, m_window, True, ButtonPressMask | ButtonReleaseMask, GrabModeAsync, GrabModeAsync, None, None, CurrentTime);
        }

        // Initialize OpenGL
        gladLoadGL((GLADloadfunc)glXGetProcAddress);
        gladLoadGLX(m_display, DefaultScreen(m_display), (GLADloadfunc)glXGetProcAddress);

        XVisualInfo* vi    = glXChooseVisual(m_display, DefaultScreen(m_display), NULL);
        GLXContext context = glXCreateContext(m_display, vi, nullptr, GL_TRUE);
        glXMakeCurrent(m_display, m_window, context);

        // Callback function
        if (m_desc.onCreate)
            m_desc.onCreate();
    }

    void WindowX11::useShader(std::string vertex, std::string fragment)
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

    void WindowX11::clear(const Color& color)
    {
        // Clear screen with specified color
        glClearColor(color.red / 255.0f, color.green / 255.0f, color.blue / 255.0f, color.alpha);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void WindowX11::swapBuffers()
    {
        // Swap front and back buffers
        glXSwapBuffers(m_display, m_window);
    }

    void WindowX11::destroy()
    {
        // Callback function
        if (m_desc.onDestroy)
            m_desc.onDestroy();

        // Delete program
        glDeleteProgram(m_program);

        // Delete OpenGL context
        glXMakeCurrent(m_display, None, nullptr);
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
