#pragma region LICENSE

//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2025 Rohan Bharatia

#pragma endregion LICENSE

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
        void frame(std::vector<ReadableVertex>& vertices) override;
        void clear(const Color& color) override;
        void swapBuffers() override;
        void translate(float x, float y, float z) override;
        void scale(float x, float y, float z) override;
        void rotateX(float x) override;
        void rotateY(float y) override;
        void rotateZ(float z) override;
        void destroy() override;

        void* getHandle() override;
        WindowDesc getDescription() override;

    private:
        WindowDesc m_desc;
        Vec3f m_translation;
        Vec3f m_scale;
        Angle m_pitch; // X-axis
        Angle m_roll; // Y-axis
        Angle m_yaw; // Z-axis
        HWND m_hwnd;
        HINSTANCE m_hinstance;

        static LRESULT CALLBACK wndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
    };
} // namespace nt

#endif // _NT_WINDOW_WINDOW_WIN32_h_
