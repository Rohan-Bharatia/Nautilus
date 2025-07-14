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

#ifndef _NT_RENDERER_CONTEXT_CPP_
    #define _NT_RENDERER_CONTEXT_CPP_

#include "Context.h"

namespace Nt
{
    GraphicsContext::GraphicsContext(Window* window) :
        m_window(window)
    {
        NT_ASSERT(window, "Window reference cannot be null!");
    }

    void GraphicsContext::SetClearColor(const Color& color)
    {
        m_clearColor = color;
    }

    GraphicsHandle GraphicsContext::GetHandle(void)
    {
        return m_handle;
    }
} // namespace Nt

#endif // _NT_RENDERER_CONTEXT_CPP_
