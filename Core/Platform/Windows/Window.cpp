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

#ifndef _NT_CORE_PLATFORM_WINDOWS_WINDOW_CPP_
    #define _NT_CORE_PLATFORM_WINDOWS_WINDOW_CPP_

#include "../Window.h"

#include "../../Logger.h"

namespace nt
{
    static const char* WINDOW_CLASS_NAME = "nt::Window";

    bool Window::initialize(const WindowDesc& desc)
    {
        m_desc = desc;

        m_handle.hinstance = GetModuleHandle(NULL);

        if (!m_handle.hinstance)
        {
            Logger::error("Failed to get module handle!");
            return false;
        }

        WNDCLASSEX wc{};
        wc.cbSize        = sizeof(WNDCLASSEX);
        wc.style         = CS_HREDRAW | CS_VREDRAW;
        wc.lpfnWndProc   = &Window::wndProc;
        wc.cbClsExtra    = 0;
        wc.cbWndExtra    = 0;
        wc.hInstance     = m_handle.hinstance;
        wc.hIcon         = LoadIcon(m_handle.hinstance, IDI_APPLICATION);
        wc.hCursor       = LoadCursor(m_handle.hinstance, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wc.lpszMenuName  = NULL;
        wc.lpszClassName = WINDOW_CLASS_NAME;
        wc.hIconSm       = LoadIcon(m_handle.hinstance, IDI_APPLICATION);

        if (!RegisterClassEx(&wc))
        {
            Logger::error("Failed to register window class!");
            return false;
        }

        m_handle.hmenu = CreatePopupMenu();

        if (!m_handle.hmenu)
        {
            Logger::error("Failed to create popup menu!");
            return false;
        }

        DWORD style = WS_OVERLAPPEDWINDOW;
        if (desc.borderless)
            style &= ~WS_BORDER;
        if (!desc.resizable)
            style &= ~(WS_SIZEBOX | WS_THICKFRAME);
        if (desc.fullscreenable)
            style |= WS_MAXIMIZEBOX;
        if (!desc.maximizable)
            style &= ~WS_MAXIMIZEBOX;
        if (!desc.minimizable)
            style &= ~WS_MINIMIZEBOX;

        m_handle.hwnd = CreateWindowEx(0, WINDOW_CLASS_NAME, desc.title.c_str(), style, desc.x, desc.y,
                                       desc.width, desc.height, m_handle.hwnd, m_handle.hmenu, m_handle.hinstance, this);

        if (!m_handle.hwnd)
        {
            Logger::error("Failed to create window!");
            return false;
        }

        SetWindowLongPtr(m_handle.hwnd, GWLP_USERDATA, (LONG_PTR)this);

        if (desc.fullscreen)
        {
            ShowWindow(m_handle.hwnd, SW_SHOWMAXIMIZED);
            SetWindowPos(m_handle.hwnd, HWND_TOPMOST, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_FRAMECHANGED);
        }
        else if (desc.maximized)
            ShowWindow(m_handle.hwnd, SW_SHOWMAXIMIZED);
        else if (desc.minimized)
            ShowWindow(m_handle.hwnd, SW_SHOWMINIMIZED);
        else
            ShowWindow(m_handle.hwnd, SW_SHOW);

        if (desc.modal)
        {
            SetWindowLongPtr(m_handle.hwnd, GWL_STYLE, GetWindowLongPtr(m_handle.hwnd, GWL_STYLE) & ~WS_OVERLAPPEDWINDOW);
            SetWindowPos(m_handle.hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
        }

        UpdateWindow(m_handle.hwnd);

        if (desc.onCreate)
            desc.onCreate();

        return true;
    }

    bool Window::pollEvents()
    {
        MSG msg{};
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);

            if (m_desc.onUpdate)
                m_desc.onUpdate();

            if (msg.message == WM_QUIT)
                return false;
        }

        return true;
    }

    void Window::update()
    {
        UpdateWindow(m_handle.hwnd);
    }

    void Window::close()
    {
        if (m_desc.onClose)
            m_desc.onClose();

        UnregisterClass(WINDOW_CLASS_NAME, m_handle.hinstance);
        if (m_handle.hinstance)
            FreeLibrary(m_handle.hinstance);
        if (m_handle.hmenu)
            DestroyMenu(m_handle.hmenu);
        if (m_handle.hwnd)
            DestroyWindow(m_handle.hwnd);
    }

    const WindowDesc& Window::getWindowDesc() const
    {
        return m_desc;
    }

    const NativeHandle& Window::getHandle() const
    {
        return m_handle;
    }

    LRESULT CALLBACK Window::wndProc(HWND hwnd, UINT msg, WPARAM wprm, LPARAM lprm)
    {
        Window* wnd = nullptr;

        if (msg == WM_NCCREATE)
        {
            CREATESTRUCT* cs = (CREATESTRUCT*)lprm;
            wnd              = (Window*)cs->lpCreateParams;
            SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)wnd);
        }
        else
            wnd = (Window*)GetWindowLongPtr(hwnd, GWLP_USERDATA);

        if (!hwnd)
        {
            Logger::error("Failed to create window!");
            return 0;
        }

        switch (msg)
        {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            return 0;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc       = BeginPaint(hwnd, &ps);
            HBRUSH hbrush = CreateSolidBrush(RGB(wnd->m_desc.background.r, wnd->m_desc.background.g, wnd->m_desc.background.b));
            FillRect(hdc, &ps.rcPaint, hbrush);
            DeleteObject(hbrush);
            EndPaint(hwnd, &ps);
            return 0;
        }
        default:
            return DefWindowProc(hwnd, msg, wprm, lprm);
        }
    }
} // namespace nt

#endif // _NT_CORE_PLATFORM_WINDOWS_WINDOW_CPP_
