//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#ifndef _NT_WINDOW_WINDOW_WIN32_cpp_
    #define _NT_WINDOW_WINDOW_WIN32_cpp_

#include "WindowWin32.h"

namespace nt
{
    WindowWin32::WindowWin32(const WindowDesc& desc) : 
        m_hwnd(nullptr), m_hinstance(nullptr), m_desc(desc)
    {}

    void WindowWin32::initialize()
    {
        m_desc      = m_desc;
        m_hinstance = GetModuleHandle(NULL);

        // Create window context
        WNDCLASSEXA wc{0};
        wc.cbSize        = sizeof(WNDCLASSEXA);
        wc.style         = CS_HREDRAW | CS_VREDRAW;
        wc.lpfnWndProc   = &WindowWin32::wndProc;
        wc.hInstance     = m_hinstance;
        wc.hCursor       = LoadCursor(nullptr, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wc.lpszClassName = "NautilusWindowClass";


        RegisterClassExA(&wc);

        // Create window
        m_hwnd = CreateWindowExA(0, wc.lpszClassName, m_desc.title.c_str(), WS_OVERLAPPEDWINDOW, 
                                 m_desc.position.x, m_desc.position.y, m_desc.width, m_desc.height, 
                                 nullptr, nullptr, m_hinstance, nullptr);
        
        SetWindowLongPtr(m_hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

        ShowWindow(m_hwnd, SW_SHOWDEFAULT);
        UpdateWindow(m_hwnd);

        // Callback function
        if (m_desc.onCreate)
            m_desc.onCreate();
    }

    bool WindowWin32::pollEvents()
    {
        MSG msg{};
        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                return false;

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        return true;
    }

    void WindowWin32::update()
    {
        UpdateWindow(m_hwnd);

        // Callback function
        if (m_desc.onUpdate)
            m_desc.onUpdate();
    }

    void WindowWin32::destroy()
    {
        // Callback function
        if (m_desc.onDestroy)
            m_desc.onDestroy();

        if (m_hwnd)
            DestroyWindow(m_hwnd);
    }

    void* WindowWin32::getHandle()
    {
        return static_cast<void*>(m_hwnd);
    }

    LRESULT CALLBACK WindowWin32::wndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
    {
        WindowWin32* win = nullptr;

        if (msg == WM_NCCREATE)
        {
            CREATESTRUCT* cs = reinterpret_cast<CREATESTRUCT*>(lp);
            win              = reinterpret_cast<WindowWin32*>(cs->lpCreateParams);
            SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(win));
        }
        else
            win = reinterpret_cast<WindowWin32*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

        switch (msg)
        {
            case WM_DESTROY:
            case WM_CLOSE:
                PostQuitMessage(0);
                break;
            case WM_PAINT:
            {
                PAINTSTRUCT ps;
                HBRUSH hbrush = CreateSolidBrush(RGB(win->m_desc.backgroundColor.red, 
                                                     win->m_desc.backgroundColor.green, 
                                                     win->m_desc.backgroundColor.blue));
                HDC hdc       = BeginPaint(hwnd, &ps);
                FillRect(hdc, &ps.rcPaint, hbrush);
                EndPaint(hwnd, &ps);
                DeleteObject(hbrush);
                break;
            }
            default:
                return DefWindowProc(hwnd, msg, wp, lp);
        }
        
        return 0;
    }

    WindowDesc WindowWin32::getDescription()
    {
        return m_desc;
    }
} // namespace nt

#endif // _NT_WINDOW_WINDOW_WIN32_cpp_