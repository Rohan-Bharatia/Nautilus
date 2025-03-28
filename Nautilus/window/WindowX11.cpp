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

#include "../core/Timer.h"

#include <GL/gl.h>
#include <GL/glx.h>

namespace nt
{
    WindowX11::WindowX11(const WindowDesc& desc) :
        m_desc(desc), m_scale(1.0f, 1.0f, 1.0f),  m_display(nullptr), m_window(None)
    {}

    void WindowX11::initialize()
    {
        // Set window properties
        XSetWindowAttributes attrs;
        attrs.event_mask       = ExposureMask | KeyPressMask | ButtonPressMask;
        attrs.background_pixel = m_desc.backgroundColor.red << 16 | m_desc.backgroundColor.green << 8 | m_desc.backgroundColor.blue;

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
            m_window = XCreateWindow(m_display, RootWindow(m_display, 0), m_desc.position.x, m_desc.position.y,
                                     m_desc.width, m_desc.height, 1, CopyFromParent, InputOutput, NULL,
                                     CWEventMask | CWOverrideRedirect, &attrs);

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
                event.type                   = MapNotify;
                event.xmap.window            = m_window;
                event.xmap.event             = m_window;
                event.xmap.display           = m_display;
                event.xmap.override_redirect = False;
                XSendEvent(m_display, m_window, False, StructureNotifyMask, &event);
            }
            if (m_desc.maximized)
            {
                XEvent event;
                event.type                   = MapNotify;
                event.xmap.window            = m_window;
                event.xmap.event             = m_window;
                event.xmap.display           = m_display;
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
        int glAttrs[] =
        {
            GLX_RGBA,
            GLX_DOUBLEBUFFER,
            GLX_RED_SIZE,   8,
            GLX_GREEN_SIZE, 8,
            GLX_BLUE_SIZE,  8,
            GLX_DEPTH_SIZE, 24,
            None,
        };

        XVisualInfo* vi = XGetVisualInfo(m_display, VisualScreenMask, nullptr, glAttrs);
        GLXContext glxc = glXCreateContext(m_display, vi, nullptr, True);
        glXMakeCurrent(m_display, m_window, glxc);

        glEnable(GL_DEPTH_TEST);

        Window root, parent;
        int x, y;
        unsigned int width, height, border, depth;

        XGetGeometry(m_display, m_window, &root, &x, &y, &width, &height, &border, &depth);
        glViewport(0, 0, width, height);

        // Callback function
        if (m_desc.onCreate)
            m_desc.onCreate();
    }

    bool WindowX11::pollEvents()
    {
        Atom WM_DELETE_WINDOW = XInternAtom(m_display, "WM_DELETE_WINDOW", False);
        XSetWMProtocols(m_display, m_window, &WM_DELETE_WINDOW, 1);

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

    void WindowX11::frame(std::vector<ReadableVertex>& vertices)
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

        // Manipulate w/ matrix
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRotatef(m_pitch.inRadians(), 1.0f, 0.0f, 0.0f);
        glRotatef(m_roll.inRadians(), 0.0f, 1.0f, 0.0f);
        glRotatef(m_yaw.inRadians(), 0.0f, 0.0f, 1.0f);
        glTranslatef(m_translation.x, m_translation.y, m_translation.z);
        glScalef(m_scale.x, m_scale.y, m_scale.z);

        // Draw the vertices
        glDrawArrays(GL_TRIANGLES, 0, vertices.size());

        // Disable v/t/c arrays
        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);
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

    void WindowX11::translate(float x, float y, float z)
    {
        m_translation += Vec3f(x, y, z);
    }

    void WindowX11::scale(float x, float y, float z)
    {
        m_scale += Vec3f(x, y, z);
    }

    void WindowX11::rotateX(float x)
    {
        m_pitch += radians(x);
    }

    void WindowX11::rotateY(float y)
    {
        m_roll += radians(y);
    }

    void WindowX11::rotateZ(float z)
    {
        m_yaw += radians(z);
    }

    void WindowX11::destroy()
    {
        // Callback function
        if (m_desc.onDestroy)
            m_desc.onDestroy();

        // Destroy OpenGL
        glXMakeCurrent(m_display, None, nullptr);

        // Destroy window
        if (m_window)
            XDestroyWindow(m_display, m_window);
        if (m_display)
            XCloseDisplay(m_display);
    }

    void* WindowX11::getHandle()
    {
        return static_cast<void*>(&m_window);
    }

    WindowDesc WindowX11::getDescription()
    {
        return m_desc;
    }
} // namespace nt

#endif // _NT_WINDOW_WINDOW_X11_cpp_
