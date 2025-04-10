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

#pragma once

#ifndef _NT_CORE_PLATFORM_WINDOW_H_
    #define _NT_CORE_PLATFORM_WINDOW_H_

#include "Platform.h"
#include "API.h"
#include "../Math/Rect.h"
#include "../Math/Color.h"

#include <string>

namespace nt
{
    struct NT_API WindowDesc
    {
        // Window settings
        uint32_t x;
        uint32_t y;
        uint32_t width;
        uint32_t height;
        std::string title;
        Color bgColor;

        // Window options
        bool resizable      = true;
        bool borderless     = false;
        bool fullscreenable = true;
        bool maximizable    = true;
        bool minimizable    = true;

        // Window states
        bool fullscreen = false;
        bool maximized  = false;
        bool minimized  = false;
        bool modal      = false;
    };

    class NT_API Window
    {
    public:
        Window()                               = default;
        ~Window()                              = default;
        Window(const Window& other)            = default;
        Window &operator=(const Window& other) = default;

        void create(const WindowDesc& desc);
        bool pollEvents();
        void update();
        void destroy();

    #if defined(NT_PLATFORM_WINDOWS)
        HWND getNativeHandle();
    #elif defined(NT_PLATFORM_UNIX)
        Window* getNativeHandle();
    #elif defined(NT_PLATFORM_MACOS)
        NSWindow* getNativeHandle();
    #elif defined(NT_PLATFORM_IOS)
        UIWindow* getNativeHandle();
    #elif defined(NT_PLATFORM_ANDROID)
        ANativeActivity* getNativeHandle();
    #endif // defined(NT_PLATFORM_WINDOWS)
        float getDeltaTime();
        Rect getSize();

    private:
        WindowDesc m_desc;
    #if defined(NT_API_DIRECTX)
        HWND m_hwnd = nullptr;
    #elif defined(NT_API_X11)
        Window* m_window = nullptr;
        Display* m_display = nullptr;
    #elif defined(NT_API_COCOA)
        NSWindow* m_window = nullptr;
    #elif defined(NT_API_UIKIT)
        UIWindow* m_window = nullptr;
    #elif defined(NT_API_ANDROID)
        ANativeActivity* m_native = nullptr;
    #endif // defined(NT_API_DIRECTX), defined(NT_API_X11), defined(NT_API_COCOA), defined(NT_API_UIKIT), defined(NT_API_ANDROID)

    #if defined(NT_API_DIRECTX)
        static LRESULT NT_CALLBACK wndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
    #endif // defined(NT_API_DIRECTX)
    };
}

#endif // _NT_CORE_PLATFORM_WINDOW_H_
