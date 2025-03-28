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

#ifndef _NT_WINDOW_WINDOW_UIKIT_h_
    #define _NT_WINDOW_WINDOW_UIKIT_h_

#include "WindowBase.h"

#import <UIKit/UIKit.h>

namespace nt
{
    class WindowUIKit :
        public WindowBase
    {
    public:
        WindowUIKit()                                  = default;
        WindowUIKit(const WindowDesc& desc);
        ~WindowUIKit()                                 = default;
        WindowUIKit(const WindowUIKit& other)            = default;
        WindowUIKit& operator=(const WindowUIKit& other) = default;

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
        UIWindow* m_window;
    };
} // namespace nt

#endif // _NT_WINDOW_WINDOW_UIKIT_h_
