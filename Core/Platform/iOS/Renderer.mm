//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                                 ...
//
//                  Copyright (c) Rohan Bharatia 2025

#import "Renderer.h"
#import "../API.h"
#import "../../Logger.h"

namespace nt
{
    bool Renderer::initialize(Window window)
    {
        m_handle = window.getHandle();

        // Initialize OpenGL
        CGLPixelFormatAttribute attribs[9] =
        {
            kCGLPFAAccelerated,
            kCGLPFAOpenGLProfile, (CGLPixelFormatAttribute)kCGLOGLPVersion_Legacy,
            kCGLPFADoubleBuffer,
            kCGLPFAColorSize, (CGLPixelFormatAttribute)24,
            kCGLPFADepthSize, (CGLPixelFormatAttribute)24,
            (CGLPixelFormatAttribute)0
        };

        CGLPixelFormatObj pf;
        GLint npf;
        CGLChoosePixelFormat(attribs, &pf, &npf);
        if (!pf)
        {
            Logger::error("Failed to choose pixel format!");
            return false;
        }

        CGLCreateContext(pf, nullptr, &m_handle.context);
        CGLDestroyPixelFormat(pf);

        if (!m_handle.context)
        {
            Logger::error("Failed to create OpenGL context.");
            return false;
        }

        CGLSetCurrentContext(m_handle.context);

        glEnable(GL_DEPTH_TEST);

        CGRect rect          = m_handle.view.bounds;
        EAGLContext* context = [EAGLContext currentContext];
        glViewport(0, 0, rect.size.width, rect.size.height);

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
        CGLFlushDrawable(m_handle.context);
    }

    void Renderer::endFrame()
    {
        glEnd();
    }

    void Renderer::shutdown()
    {
        CGLSetCurrentContext(nullptr);
        CGLDestroyContext(m_handle.context);
    }
}
