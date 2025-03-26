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

#ifndef _NT_WINDOW_WINDOW_UIKIT_h_
    #define _NT_WINDOW_WINDOW_UIKIT_h_

#include "WindowBase.h"

#import <UIKit/UIKit.h>

namespace nt
{
    class WindowUIKit :
        public WindowBase
    {
    public:
        WindowUIKit()                                  = default;
        WindowUIKit(const WindowDesc& desc);
        ~WindowUIKit()                                 = default;
        WindowUIKit(const WindowUIKit& other)            = default;
        WindowUIKit& operator=(const WindowUIKit& other) = default;

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
        UIWindow* m_window;
        GLuint m_vao, m_vbo, m_ebo, m_vshader, m_fshader, m_program;
    };
} // namespace nt

#endif // _NT_WINDOW_WINDOW_UIKIT_h_
