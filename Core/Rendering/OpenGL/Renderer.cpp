#pragma region LICENSE

//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                                 ...
//
//                  Copyright (c) Rohan Bharatia 2025

#pragma endregion LICENSE

#ifndef _NT_CORE_RENDERING_OPENGL_RENDERER_CPP_
    #define _NT_CORE_RENDERING_OPENGL_RENDERER_CPP_

#include "../Renderer.h"

#include "../../Logger.h"

namespace nt
{
    bool Renderer::initialize(Window window, Rect size)
    {
        // Open the X11 display
        m_display = XOpenDisplay(nullptr);
        if (!m_display)
        {
            return false;
        }

        // Get the X11 screen
        m_screen = DefaultScreen(m_display);

        // Create an X11 colormap
        m_colormap = XCreateColormap(m_display, window, DefaultVisual(m_display, m_screen), AllocNone);
        if (!m_colormap)
        {
            XCloseDisplay(m_display);
            return false;
        }

        // Create an OpenGL context
        m_context = glXCreateContext(m_display, window, nullptr, true, nullptr);
        if (!m_context)
        {
            XCloseDisplay(m_display);
            return false;
        }

        // Make the OpenGL context current
        glXMakeCurrent(m_display, window, m_context);

        glEnable(GL_DEPTH_TEST);

        return true;
    }

    void Renderer::clear(Color col)
    {
        // Clear the screen
        glClearColor(col.r, col.g, col.b, col.a);
        glClear(GL_COLOR_BUFFER_BIT || GL_DEPTH_BUFFER_BIT);
    }

    void Renderer::beginFrame()
    {
        // Begin a new frame
        glClear(GL_COLOR_BUFFER_BIT || GL_DEPTH_BUFFER_BIT);
    }

    void Renderer::drawTriangle(Vertex a, Vertex b, Vertex c)
    {
        // Draw a triangle (xyz, uv, rgba)
        glBegin(GL_TRIANGLES);
            glVertex3f(a.pos.x, a.pos.y, a.pos.z);
            glTexCoord2f(a.uv.x, a.uv.y);
            glColor4f(a.col.r, a.col.g, a.col.b, a.col.a);

            glVertex3f(b.pos.x, b.pos.y, b.pos.z);
            glTexCoord2f(b.uv.x, b.uv.y);
            glColor4f(b.col.r, b.col.g, b.col.b, b.col.a);

            glVertex3f(c.pos.x, c.pos.y, c.pos.z);
            glTexCoord2f(c.uv.x, c.uv.y);
            glColor4f(c.col.r, c.col.g, c.col.b, c.col.a);
        glEnd();
    }

    void Renderer::endFrame()
    {
        // End the current frame
        glXSwapBuffers(m_display, window);
    }

    void Renderer::shutdown()
    {
        // Shutdown the OpenGL context and X11 display
        glXDestroyContext(m_display, m_context);
        XCloseDisplay(m_display);
    }
}

#endif // _NT_CORE_RENDERING_OPENGL_RENDERER_CPP_
