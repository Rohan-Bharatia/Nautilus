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

#ifndef _NT_CORE_PLATFORM_D3D12_WINDOW_CPP_
    #define _NT_CORE_PLATFORM_D3D12_WINDOW_CPP_

#include "../Window.h"

#include "../../Logger.h"

namespace nt
{
    static LRESULT NT_CALLBACK wndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
    {
        switch (msg)
        {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wp, lp);
        }
        return 0;
    }

    void Window::create(const std::string& title)
    {
        WNDCLASSEXA wc;
        wc.cbSize        = sizeof(WNDCLASSEXA);
        wc.style         = CS_CLASSDC;
        wc.lpfnWndProc   = &wndProc;
        wc.cbClsExtra    = 0;
        wc.cbWndExtra    = 0;
        wc.hInstance     = GetModuleHandle(NULL);
        wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
        wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
        wc.lpszMenuName  = NULL;
        wc.lpszClassName = title.c_str();
        wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

        if (!RegisterClassExA(&wc))
        {
            Logger::error("Failed to register window class!");
            return;
        }

        m_hwnd = CreateWindowA(wc.lpszClassName, title.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, wc.hInstance, NULL);
        if (!m_hwnd)
        {
            Logger::error("Failed to create window!");
            return;
        }

        ShowWindow(m_hwnd, SW_SHOW);
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
}

#endif // _NT_CORE_PLATFORM_D3D12_WINDOW_CPP_
