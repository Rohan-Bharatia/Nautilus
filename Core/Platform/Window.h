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
#include "NativeHandle.h"
#include "../Math/Color.h"

#include <cstdint>
#include <string>
#include <functional>

namespace nt
{
    struct WindowDesc
    {
        // Window properties
        uint32_t x        = 100;
        uint32_t y        = 100;
        uint32_t width    = 1024;
        uint32_t height   = 768;
        std::string title = "Nautilus Application";
        Color background  = nt::Color(51, 77, 77, 1.0f);

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

        // Window callbacks
        std::function<void()> onCreate = nullptr;
        std::function<void()> onUpdate = nullptr;
        std::function<void()> onClose  = nullptr;
    };

    class NT_API Window
    {
    public:
        Window()                         = default;
        ~Window()                        = default;
        Window(const Window&)            = default;
        Window& operator=(const Window&) = default;

        bool initialize(const WindowDesc& desc);
        bool pollEvents();
        void update();
        void close();

        const WindowDesc& getWindowDesc() const;
        const NativeHandle& getHandle() const;

    private:
        WindowDesc m_desc;
        NativeHandle m_handle;

    #if defined(NT_PLATFORM_WINDOWS)
        static LRESULT CALLBACK wndProc(HWND hwnd, UINT msg, WPARAM wprm, LPARAM lprm);
    #endif // defined(NT_PLATFORM_WINDOWS)
    };
} // namespace nt

#endif // _NT_CORE_PLATFORM_WINDOW_H_
