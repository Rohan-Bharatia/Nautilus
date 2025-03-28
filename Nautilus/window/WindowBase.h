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

#pragma once

#ifndef _NT_WINDOW_WINDOW_BASE_h_
    #define _NT_WINDOW_WINDOW_BASE_h_

#include "WindowDesc.h"
#include "../math/Vertex.h"
#include "../math/Mat4x4.h"

#include <memory>
#include <vector>

namespace nt
{
    class WindowBase
    {
    public:
        virtual void initialize()                                 = 0;
        virtual bool pollEvents()                                 = 0;
        virtual void update()                                     = 0;
        virtual void frame(std::vector<ReadableVertex>& vertices) = 0;
        virtual void clear(const Color& color)                    = 0;
        virtual void swapBuffers()                                = 0;
        virtual void translate(float x, float y, float z)         = 0;
        virtual void scale(float x, float y, float z)             = 0;
        virtual void rotateX(float x)                             = 0;
        virtual void rotateY(float y)                             = 0;
        virtual void rotateZ(float z)                             = 0;
        virtual void destroy()                                    = 0;

        virtual void* getHandle()           = 0;
        virtual WindowDesc getDescription() = 0;
    };

    std::shared_ptr<WindowBase> createWindow(const WindowDesc& desc);
} // namespace nt

#endif // _NT_WINDOW_WINDOW_BASE_h_
