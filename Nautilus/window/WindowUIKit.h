//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

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
        void destroy() override;

        void* getHandle() override;
        WindowDesc getDescription() override;

    private:
        UIWindow* m_window;
        WindowDesc m_desc;
    };
} // namespace nt

#endif // _NT_WINDOW_WINDOW_UIKIT_h_