#pragma once

#ifndef _NT_WINDOW_WINDOW_X11_h_
    #define _NT_WINDOW_WINDOW_X11_h_

#include "WindowBase.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>

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
        void destroy() override;

        void* getHandle() override;

    private:
        Display* m_display;
        Window m_window;
        WindowDesc m_desc;
    };
} // namespace nt

#endif // _NT_WINDOW_WINDOW_X11_h_