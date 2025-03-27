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

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>

namespace nt
{
    class WindowX11 :
        public WindowBase
    {
    public:
        WindowX11()                                  = default;
        WindowX11(const WindowDesc& desc);
        ~WindowX11()                                 = default;
        WindowX11(const WindowX11& other)            = default;
        WindowX11& operator=(const WindowX11& other) = default;

        void initialize() override;
        bool pollEvents() override;
        void update() override;
        void frame(std::vector<ReadableVertex>& vertices) override;
        void clear(const Color& color) override;
        void swapBuffers() override;
        void destroy() override;

        void* getHandle() override;
        WindowDesc getDescription() override;

    private:
        WindowDesc m_desc;
        Display* m_display;
        Window m_window;
    };
} // namespace nt

#endif // _NT_WINDOW_WINDOW_X11_h_
