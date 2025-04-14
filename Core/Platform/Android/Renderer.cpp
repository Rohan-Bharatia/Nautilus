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

#ifndef _NT_CORE_PLATFORM_ANDROID_RENDERER_CPP_
    #define _NT_CORE_PLATFORM_ANDROID_RENDERER_CPP_

#include "Renderer.h"
#include "../API.h"
#include "../../Logger.h"

namespace nt
{
    bool Renderer::initialize(Window window)
    {
        m_handle = window.getHandle();

        // Initialize OpenGL
        m_handle.display = eglGetDisplay(EGL_DEFAULT_DISPLAY);

        if (m_handle.display == EGL_NO_DISPLAY)
        {
            Logger::error("Failed to get EGL display!");
            return false;
        }

        if (!eglInitialize(m_handle.display, nullptr, nullptr))
        {
            Logger::error("Failed to initialize EGL!");
            return false;
        }

        EGLint configAttribs[15] =
        {
            EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT,
            EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
            EGL_RED_SIZE, 8,
            EGL_GREEN_SIZE, 8,
            EGL_BLUE_SIZE, 8,
            EGL_ALPHA_SIZE, 8,
            EGL_DEPTH_SIZE, 24,
            EGL_NONE,
        };

        EGLint configCount;

        if (!eglChooseConfig(m_handle.display, configAttribs, &m_handle.config, 1, &configCount))
        {
            Logger::error("Failed to choose EGL config!");
            return false;
        }

        m_handle.surface = eglCreateWindowSurface(m_handle.display, m_handle.config, m_handle.native, nullptr);

        if (m_handle.surface == EGL_NO_SURFACE)
        {
            Logger::error("Failed to create EGL surface!");
            return false;
        }

        EGLint contextAttribs[3] =
        {
            EGL_CONTEXT_CLIENT_VERSION, 3,
            EGL_NONE
        };

        m_handle.context = eglCreateContext(m_handle.display, m_handle.config, nullptr, contextAttribs);

        if (m_handle.context == EGL_NO_CONTEXT)
        {
            Logger::error("Failed to create EGL context!");
            return false;
        }

        if (!eglMakeCurrent(m_handle.display, m_handle.surface, m_handle.surface, m_handle.context))
        {
            Logger::error("Failed to make EGL context current!");
            return false;
        }

        glEnable(GL_TEXTURE_2D);
        glEnable(GL_DEPTH_TEST);

        glViewport(0, 0, window.getWindowDesc().width, window.getWindowDesc().height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, window.getWindowDesc().width, window.getWindowDesc().height, 0, -1, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        return true;
    }

    void Renderer::beginFrame()
    {
        glBegin(GL_TRIANGLES);
    }

    void Renderer::clear(Color col)
    {
        glClearColor(col.r / 255.0f, col.g / 255.0f, col.b / 255.0f, col.a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Renderer::drawTriangle(Vertex a, Vertex b, Vertex c)
    {
        glVertex3f(a.pos.x, a.pos.y, a.pos.z);
        glTexCoord2f(a.uv.x, a.uv.y);
        glColor4f(a.col.r / 255.0f, a.col.g / 255.0f, a.col.b / 255.0f, a.col.a);
        glVertex3f(b.pos.x, b.pos.y, b.pos.z);
        glTexCoord2f(b.uv.x, b.uv.y);
        glColor4f(b.col.r / 255.0f, b.col.g / 255.0f, b.col.b / 255.0f, b.col.a);
        glVertex3f(c.pos.x, c.pos.y, c.pos.z);
        glTexCoord2f(c.uv.x, c.uv.y);
        glColor4f(c.col.r / 255.0f, c.col.g / 255.0f, c.col.b / 255.0f, c.col.a);
    }

    void Renderer::swapBuffers()
    {
        eglSwapBuffers(m_handle.display, m_handle.surface);
    }

    void Renderer::endFrame()
    {
        glEnd();
    }

    void Renderer::shutdown()
    {
        if (m_handle.display != EGL_NO_DISPLAY)
        {
            eglMakeCurrent(m_handle.display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
            eglDestroyContext(m_handle.display, m_handle.context);
            eglDestroySurface(m_handle.display, m_handle.surface);
            eglTerminate(m_handle.display);
        }
    }
}

#endif // _NT_CORE_PLATFORM_ANDROID_RENDERER_CPP_
