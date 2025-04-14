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

#ifndef _NT_CORE_PLATFORM_WINDOWS_RENDERER_CPP_
    #define _NT_CORE_PLATFORM_WINDOWS_RENDERER_CPP_

#include "Renderer.h"
#include "../API.h"
#include "../../Logger.h"

namespace nt
{
    bool Renderer::initialize(Window window)
    {
        m_handle = window.getHandle();

        // Initialize OpenGL
        PIXELFORMATDESCRIPTOR pfd{};
        pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
        pfd.nVersion = 1;
        pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        pfd.iPixelType = PFD_TYPE_RGBA;
        pfd.cColorBits = 32;
        pfd.cDepthBits = 24;
        pfd.iLayerType = PFD_MAIN_PLANE;

        HDC hdc = GetDC(m_handle.hwnd);

        int pf = ChoosePixelFormat(hdc, &pfd);
        SetPixelFormat(hdc, pf, &pfd);

        m_handle.hglrc = wglCreateContext(hdc);
        wglMakeCurrent(hdc, m_handle.hglrc);

        if (!m_handle.hglrc)
        {
            Logger::error("Failed to create OpenGL context!");
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
        SwapBuffers(GetDC(m_handle.hwnd));
    }

    void Renderer::endFrame()
    {
        glEnd();
    }

    void Renderer::shutdown()
    {
        wglDeleteContext(m_handle.hglrc);
        ReleaseDC(m_handle.hwnd, GetDC(m_handle.hwnd));
    }
}

#endif // _NT_CORE_PLATFORM_WINDOWS_RENDERER_CPP_
