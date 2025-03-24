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

#ifndef _NT_WINDOW_WINDOW_X11_h_
    #define _NT_WINDOW_WINDOW_X11_h_

#include "WindowBase.h"

#include <../../backends/include/glad/gl.h>
#include <../../backends/include/glad/glx.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

namespace nt
{
    class WindowX11 :
        public WindowBase
    {
    public:
        WindowX11()                                  = default;
        WindowX11(const WindowDesc& desc, const GraphicsAPI& api);
        ~WindowX11()                                 = default;
        WindowX11(const WindowX11& other)            = default;
        WindowX11& operator=(const WindowX11& other) = default;

        void initialize() override;
        void shader(std::string vertex, std::string fragment);
        bool pollEvents() override;
        void update() override;
        void frame(std::vector<ReadableVertex> vertices) override;
        void clear(const Color& color) override;
        void swapBuffers() override;
        void destroy() override;

        void* getHandle() override;
        WindowDesc getDescription() override;

    private:
        WindowDesc m_desc;
        GraphicsAPI m_api;
        Display* m_display;
        Window m_window;
        GLuint m_vao, m_vbo, m_ebo, m_vertex, m_fragment, m_program;
    };
} // namespace nt

#endif // _NT_WINDOW_WINDOW_X11_h_
