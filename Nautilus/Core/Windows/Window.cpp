#pragma region LICENSE

//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//
//                  Copyright (c) Rohan Bharatia 2025

#pragma endregion LICENSE

#ifndef _NT_CORE_WINDOWS_WINDOW_CPP_
    #define _NT_CORE_WINDOWS_WINDOW_CPP_

#include "../Window.h"

#include "../Logger.h"

namespace Nt
{
    bool Window::Initialize(void)
    {
        m_handle.hinstance = GetModuleHandle(nullptr);

        WNDCLASSEX wc{};
        wc.cbSize	 = sizeof(WNDCLASSEX);
        wc.style	 = CS_HREDRAW | CS_VREDRAW;
        wc.lpfnWndProc	 = &Window::WndProc;
        wc.cbClsExtra	 = 0;
        wc.cbWndExtra	 = 0;
        wc.hInstance	 = m_handle.hinstance;
        wc.hIcon	 = LoadIcon(nullptr, IDI_APPLICATION);
        wc.hCursor	 = LoadCursor(nullptr, IDC_ARROW);
        wc.hbrBackground = NT_REINTERPRET_CAST(HBRUSH, COLOR_WINDOW + 1);
        wc.lpszMenuName  = nullptr;
        wc.lpszClassName = L"Nt::Window";
        wc.hIconSm	 = LoadIcon(nullptr, IDI_APPLICATION);

        if (!RegisterClassEx(&wc))
        {
            Logger::Error("Failed to create window class!");
            return false;
        }

        m_handle.hwnd = CreateWindowEx(0, wc.lpszClassName, std::wstring(m_desc.title.begin(), m_desc.title.end()).c_str(),
                                       WS_OVERLAPPEDWINDOW, m_desc.position.x, m_desc.position.y, m_desc.width, m_desc.height,
                                       nullptr, nullptr, m_handle.hinstance, NT_REINTERPRET_CAST(LPVOID, this));

        if (!m_handle.hwnd)
        {
            Logger::Error("Failed to create window!");
            return false;
        }

        ShowWindow(m_handle.hwnd, SW_SHOWMAXIMIZED);
        UpdateWindow(m_handle.hwnd);

        return true;
    }

    void Window::OnUpdate(void)
    {
        MSG msg{};
        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            return;

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        UpdateWindow(m_handle.hwnd);
    }

    void Window::Shutdown(void)
    {
        DestroyWindow(m_handle.hwnd);
        UnregisterClass(L"Nt::Window", m_handle.hinstance);
    }

    Rect Window::GetSize(void)
    {
        RECT rc;
        GetClientRect(m_handle.hwnd, &rc);
        return Rect(rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top);
    }

    LRESULT CALLBACK Window::WndProc(HWND hwnd, UINT msg, WPARAM wprm, LPARAM lprm)
    {
        Window* wnd = nullptr;
        if (msg == WM_CREATE)
        {
            LPCREATESTRUCT cs = NT_REINTERPRET_CAST(LPCREATESTRUCT, lprm);
            SetWindowLongPtr(hwnd, GWLP_USERDATA, NT_REINTERPRET_CAST(LONG_PTR, cs->lpCreateParams));
            wnd = NT_REINTERPRET_CAST(Window*, cs);
        }
        else
            wnd = NT_REINTERPRET_CAST(Window*, GetWindowLongPtr(hwnd, GWLP_USERDATA);

        switch (msg)
        {
            case WM_KEYDOWN:
            {
                KeyPressedEvent event(wprm, (wprm >> 16) & 0xffff);
            m_eventCallback(event);
            return 0;
            }
            case WM_KEYUP:
            {
                KeyReleasedEvent event(wprm);
            m_eventCallback(event);
            return 0;
            }
            case WM_CHAR:
            {
            KeyTypedEvent event(wprm);
            m_eventCallback(event);
            return 0;
            }
            case WM_LBUTTONDOWN:
            {
            MouseButtonPressedEvent event(0);
            m_eventCallback(event);
            return 0;
            }
            case WM_LBUTTONUP:
            {
            MouseButtonReleasedEvent event(0);
            m_eventCallback(event);
            return 0;
            }
            case WM_RBUTTONDOWN:
            {
            MouseButtonPressedEvent event(1);
            m_eventCallback(event);
            return 0;
            }
            case WM_RBUTTONUP:
            {
            MouseButtonReleasedEvent event(1);
            m_eventCallback(event);
            return 0;
            }
            case WM_XBUTTONDOWN:
            {
            MouseButtonPressedEvent event((GET_XBUTTON_WPARAM(wprm) == XBUTTON1) ? 4 : 5);
            m_eventCallback(event);
            return 0;
            }
            case WM_XBUTTONUP:
            {
            MouseButtonReleasedEvent event((GET_XBUTTON_WPARAM(wprm) == XBUTTON1) ? 4 : 5);
            m_eventCallback(event);
            return 0;
            }
            case WM_MOUSEMOVE:
            {
            MouseMovedEvent event(GET_X_LPARAM(lprm), GET_Y_LPARAM(lprm));
            m_eventCallback(event);
            return 0;
            }
            case WM_SCROLLWHEEL:
            {
            MouseScrolledEvent event(0.0f, GET_WHEEL_DELTA_WPARAM(wprm));
            m_eventCallback(event);
            return 0;
            }
            case WM_SIZE:
            {
                WindowResizeEvent event(LOWORD(lprm), HIWORD(lprm));
            m_eventCallback(event);
            return 0;
            }
            case WM_QUIT:
            {
                WindowCloseEvent event;
            m_eventCallback(event);
            return 0;
            }
            case WM_PAINT:
            {
                PAINTSTRUCT ps;
            HDC hdc       = BeginPaint(hwnd, &ps);
            RECT rc;
            GetClientRect(hwnd, &rc);
            HBRUSH hbrush = CreateSolidBrush(RGB(m_wnd->m_desc.bgColor.r,
                                 m_wnd->m_desc.bgColor.g
                                 m_wnd->n_desc.bgColor.b));
            FillRect(hdc, &rc, hbrush);
            DeleteObject(hbrush);
            EndPaint(hdc);
            }
            case WM_DESTROY:
                PostQuitMessage(0);
            return 0;
            default:
            return DefWindowProc(hwnd, msg, wprm, lprm);
        }
    }
} // namespace Nt

#endif // _NT_CORE_WINDOWS_WINDOW_CPP_
