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

#pragma once

#ifndef _NT_CORE_PLATFORM_RENDERER_H_
    #define _NT_CORE_PLATFORM_RENDERER_H_

#include "Platform.h"
#include "Window.h"
#include "../Math/Color.h"
#include "../Math/Vertex.h"

namespace nt
{
    class Renderer
    {
    public:
        Renderer()                           = default;
        ~Renderer()                          = default;
        Renderer(const Renderer&)            = default;
        Renderer& operator=(const Renderer&) = default;

        bool initialize(Window window);
        void beginFrame();
        void clear(Color col);
        void drawTriangle(Vertex a, Vertex b, Vertex c);
        void swapBuffers();
        void endFrame();
        void shutdown();

    private:
        NativeHandle m_handle;
    };
}

#endif // _NT_CORE_PLATFORM_RENDERER_H_
