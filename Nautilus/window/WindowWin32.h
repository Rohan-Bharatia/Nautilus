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

#ifndef _NT_WINDOW_WINDOW_WIN32_h_
    #define _NT_WINDOW_WINDOW_WIN32_h_

#include "WindowBase.h"

#include <../../backends/include/glad/gl.h>
#include <../../backends/include/glad/wgl.h>

#include <Windows.h>

namespace nt
{
    class WindowWin32 :
        public WindowBase
    {
    public:
        WindowWin32()                                    = default;
        WindowWin32(const WindowDesc& desc, const GraphicsAPI& api);
        ~WindowWin32()                                   = default;
        WindowWin32(const WindowWin32& other)            = default;
        WindowWin32& operator=(const WindowWin32& other) = default;

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
        HWND m_hwnd;
        HINSTANCE m_hinstance;
        GLuint m_vao, m_vbo, m_ebo, m_vertex, m_fragment, m_program;

        static LRESULT CALLBACK wndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
    };
} // namespace nt

#endif // _NT_WINDOW_WINDOW_WIN32_h_
