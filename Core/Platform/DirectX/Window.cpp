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

#ifndef _NT_CORE_PLATFORM_DIRECTX_WINDOW_CPP_
    #define _NT_CORE_PLATFORM_DIRECTX_WINDOW_CPP_

#include "../Window.h"

#include "../../Logger.h"

namespace nt
{
    void Window::create(const WindowDesc& desc)
    {
        m_desc = desc;

        WNDCLASSEXA wc;
        wc.cbSize        = sizeof(WNDCLASSEXA);
        wc.style         = CS_CLASSDC;
        wc.lpfnWndProc   = &Window::wndProc;
        wc.cbClsExtra    = 0;
        wc.cbWndExtra    = 0;
        wc.hInstance     = GetModuleHandle(NULL);
        wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
        wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
        wc.lpszMenuName  = NULL;
        wc.lpszClassName = desc.title.c_str();
        wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

        if (!RegisterClassExA(&wc))
        {
            Logger::error("Failed to register window class!");
            return;
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

        m_hwnd = CreateWindowA(wc.lpszClassName, desc.title.c_str(), style, desc.x, desc.y, desc.width, desc.height, NULL, NULL, wc.hInstance, NULL);
        if (!m_hwnd)
        {
            Logger::error("Failed to create window!");
            abort();
        }

        SetWindowLongPtr(m_hwnd, GWLP_USERDATA, (LONG_PTR)this);

        if (desc.fullscreen)
        {
            ShowWindow(m_hwnd, SW_SHOWMAXIMIZED);
            SetWindowPos(m_hwnd, HWND_TOPMOST, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_FRAMECHANGED);
        }
        else if (desc.maximized)
            ShowWindow(m_hwnd, SW_SHOWMAXIMIZED);
        else if (desc.minimized)
            ShowWindow(m_hwnd, SW_SHOWMINIMIZED);
        else
            ShowWindow(m_hwnd, SW_SHOW);

        if (desc.modal)
        {
            SetWindowLongPtr(m_hwnd, GWL_STYLE, GetWindowLongPtr(m_hwnd, GWL_STYLE) & ~WS_OVERLAPPEDWINDOW);
            SetWindowPos(m_hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
        }

        UpdateWindow(m_hwnd);
    }

    bool Window::pollEvents()
    {
        MSG msg;
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                return false;

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        return true;
    }

    void Window::update()
    {
        UpdateWindow(m_hwnd);
    }

    void Window::destroy()
    {
        if (m_hwnd)
            DestroyWindow(m_hwnd);
    }

    void* Window::getNativeHandle()
    {
        return (void*)&m_hwnd;
    }

    float Window::getDeltaTime()
    {
        static LARGE_INTEGER lastTime{};
        LARGE_INTEGER currentTime;
        LARGE_INTEGER freq;

        if (!lastTime.QuadPart)
        {
            QueryPerformanceFrequency(&freq);
            QueryPerformanceCounter(&lastTime);
        }

        QueryPerformanceCounter(&currentTime);
        float deltaTime = (float)(currentTime.QuadPart - lastTime.QuadPart) / (float)freq.QuadPart;
        lastTime        = currentTime;

        return deltaTime;
    }

    Rect Window::getSize()
    {
        RECT rect;
        GetClientRect(m_hwnd, &rect);
        return Rect(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top);
    }

    LRESULT NT_CALLBACK Window::wndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
    {
        Window* wnd = nullptr;
        if (msg == WM_NCCREATE)
        {
            CREATESTRUCT* cs = (CREATESTRUCT*)lp;
            wnd              = (Window*)cs->lpCreateParams;
            SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)wnd);
        }
        else
            wnd = (Window*)GetWindowLongPtr(hwnd, GWLP_USERDATA);

        if (!wnd)
            return DefWindowProcA(hwnd, msg, wp, lp);

        switch (msg)
        {
        case WM_CLOSE:
        {
            DestroyWindow(hwnd);
            break;
        }
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            break;
        }
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            FillRect(hdc, &ps.rcPaint, CreateSolidBrush(RGB(wnd->m_desc.bgColor.r, wnd->m_desc.bgColor.g, wnd->m_desc.bgColor.b)));
            EndPaint(hwnd, &ps);
            break;
        }
        default:
        {
            return DefWindowProc(hwnd, msg, wp, lp);
        }
        }
        return 0;
    }
}

#endif // _NT_CORE_PLATFORM_DIRECTX_WINDOW_CPP_
