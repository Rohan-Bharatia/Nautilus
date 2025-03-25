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

#import <Cocoa/Cocoa.h>

namespace nt
{
    class WindowCocoa :
        public WindowBase
    {
    public:
        WindowCocoa()                                    = default;
        WindowCocoa(const WindowDesc& desc);
        ~WindowCocoa()                                   = default;
        WindowCocoa(const WindowCocoa& other)            = default;
        WindowCocoa& operator=(const WindowCocoa& other) = default;

        void initialize() override;
        bool pollEvents() override;
        void update() override;
        void clear(const Color& color) override;
        void swapBuffers() override;
        void destroy() override;

        void* getHandle() override;
        WindowDesc getDescription() override;

    private:
        WindowDesc m_desc;
        NSWindow* m_window;
        GLuint m_vao, m_vbo, m_ebo, m_vshader, m_fshader, m_program;
    };
} // namespace nt

#endif // _NT_WINDOW_WINDOW_COCAO_h_
