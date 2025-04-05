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

#include <string>

namespace nt
{
    class NT_API Window
    {
    public:
        Window()                               = default;
        ~Window()                              = default;
        Window(const Window& other)            = default;
        Window &operator=(const Window& other) = default;

        void create(const std::string& title);
        bool pollEvents();
        void update();
        void destroy();

        void* getNativeHandle();
        float getDeltaTime();

    private:
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
    };
}

#endif // _NT_CORE_PLATFORM_WINDOW_H_
