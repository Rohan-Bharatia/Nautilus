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

#ifndef _NT_WINDOW_WINDOW_COCAO_h_
    #define _NT_WINDOW_WINDOW_COCAO_h_

#include "WindowBase.h"

#include <../../backends/include/glad/gl.h>
#include <../../backends/include/glad/egl.h>

#import <Cocoa/Cocoa.h>

namespace nt
{
    class WindowCocoa :
        public WindowBase
    {
    public:
        WindowCocoa()                                    = default;
        WindowCocoa(const WindowDesc& desc, const GraphicsAPI& api);
        ~WindowCocoa()                                   = default;
        WindowCocoa(const WindowCocoa& other)            = default;
        WindowCocoa& operator=(const WindowCocoa& other) = default;

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
        NSWindow* m_window;
        GLuint m_vao, m_vbo, m_ebo, m_vertex, m_fragment, m_program;
    };
} // namespace nt

#endif // _NT_WINDOW_WINDOW_COCAO_h_
