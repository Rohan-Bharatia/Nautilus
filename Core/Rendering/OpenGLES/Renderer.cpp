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

#ifndef _NT_CORE_RENDERING_OPENGLES_RENDERER_CPP_
    #define _NT_CORE_RENDERING_OPENGLES_RENDERER_CPP_

#include "../Renderer.h"

#include "../../Logger.h"

namespace nt
{
    bool Renderer::initialize(ANativeActivity native, Rect size)
    {
        // Get the native window
        ANativeWindow* window = wnd.getNativeHandle()->window;
        if (!window)
        {
            Logger::error("Failed to get native window!");
            return false;
        }

        // Create an EGL display
        EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
        if (display == EGL_NO_DISPLAY)
        {
            Logger::error("Failed to get EGL display!");
            return false;
        }

        // Initialize the EGL display
        if (!eglInitialize(display, nullptr, nullptr))
        {
            Logger::error("Failed to initialize EGL display!");
            return false;
        }

        // Create an EGL surface
        EGLSurface surface = eglCreateWindowSurface(display, eglGetConfigs(display, nullptr, nullptr), window, nullptr);
        if (surface == EGL_NO_SURFACE)
        {
            Logger::error("Failed to create EGL surface!");
            return false;
        }

        // Create an EGL context
        EGLContext context = eglCreateContext(display, eglGetConfigs(display, nullptr, nullptr), EGL_NO_CONTEXT, nullptr);
        if (context == EGL_NO_CONTEXT)
        {
            Logger::error("Failed to create EGL context!");
            return false;
        }

        // Make the EGL context current
        if (!eglMakeCurrent(display, surface, surface, context))
        {
            Logger::error("Failed to make EGL context current!");
            return false;
        }

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
        eglSwapBuffers(m_display, m_surface);
    }

    void Renderer::shutdown()
    {
        // Shutdown the EGL display and context
        eglMakeCurrent(m_display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        eglDestroyContext(m_display, m_context);
        eglDestroySurface(m_display, m_surface);
        eglTerminate(m_display);
    }
}

#endif // _NT_CORE_RENDERING_OPENGLES_RENDERER_CPP_
