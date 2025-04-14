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

#ifndef _NT_CORE_PLATFORM_EMSCRIPTEN_RENDERER_CPP_
    #define _NT_CORE_PLATFORM_EMSCRIPTEN_RENDERER_CPP_

#include "Renderer.h"
#include "../API.h"
#include "../../Logger.h"

namespace nt
{
    bool Renderer::initialize(Window window)
    {
        m_handle = window.getHandle();

        // Initialize OpenGL
        EmscriptenWebGLContextAttributes attr;
        emscripten_webgl_init_context_attributes(&attr);
        attr.alpha                     = true;
        attr.depth                     = true;
        attr.stencil                   = false;
        attr.antialias                 = true;
        attr.majorVersion              = 2; // WebGL v2 = GLES v3
        attr.minorVersion              = 0;
        attr.enableExtensionsByDefault = true;

        m_handle.context = emscripten_webgl_create_context("#canvas", &attr);

        if (m_handle.context <= 0)
        {
            Logger::error("Failed to create WebGL2 context.");
            return false;
        }

        EMSCRIPTEN_RESULT res = emscripten_webgl_make_context_current(m_handle.context);

        if (res != EMSCRIPTEN_RESULT_SUCCESS)
        {
            Logger::error("Failed to make WebGL2 context current.");
            return false;
        }

        glEnable(GL_DEPTH_TEST);

        int width                               = emscripten_get_canvas_element_width("canvas");
        int height                              = emscripten_get_canvas_element_height("canvas");
        glViewport(0, 0, width, height);

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
        emscripten_webgl_swap_buffers(m_handle.context);
    }

    void Renderer::endFrame()
    {
        glEnd();
    }

    void Renderer::shutdown()
    {
        emscripten_webgl_destroy_context(m_handle.context);
    }
}

#endif // _NT_CORE_PLATFORM_EMSCRIPTEN_RENDERER_CPP_
