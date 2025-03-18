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
    class WindowIOS :
        public WindowBase
    {
    public:
        WindowIOS()                                  = default;
        WindowIOS(const WindowDesc& desc);
        ~WindowIOS()                                 = default;
        WindowIOS(const WindowIOS& other)            = default;
        WindowIOS& operator=(const WindowIOS& other) = default;

        void initialize() override;
        bool pollEvents() override;
        void update() override;
        void destroy() override;

        void* getHandle() override;

    private:
        UIWindow* m_window;
        WindowDesc m_desc;
    };
} // namespace nt

#endif // _NT_WINDOW_WINDOW_UIKIT_h_