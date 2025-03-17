#pragma once

#ifndef _NT_WINDOW_WINDOW_WIN32_h_
    #define _NT_WINDOW_WINDOW_WIN32_h_

#include "WindowBase.h"

#include <Windows.h>

namespace nt
{
    class WindowWin32 : 
        public WindowBase
    {
    public:
        WindowWin32()                                    = default;
        WindowWin32(const WindowDesc& desc);
        ~WindowWin32()                                   = default;
        WindowWin32(const WindowWin32& other)            = default;
        WindowWin32& operator=(const WindowWin32& other) = default;

        void initialize() override;
        bool pollEvents() override;
        void update() override;
        void destroy() override;

        void* getHandle() override;

    private:
        HWND m_hwnd;
        HINSTANCE m_hinstance;
        WindowDesc m_desc;

        static LRESULT CALLBACK wndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
    };
} // namespace nt

#endif // _NT_WINDOW_WINDOW_WIN32_h_