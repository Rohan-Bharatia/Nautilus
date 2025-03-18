//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#pragma once

#ifndef _NT_WINDOW_WINDOW_BASE_h_
    #define _NT_WINDOW_WINDOW_BASE_h_

#include "WindowDesc.h"

#include <memory>

namespace nt
{
    class WindowBase
    {
    public:
        virtual void initialize() = 0;
        virtual bool pollEvents() = 0;
        virtual void update()     = 0;
        virtual void destroy()    = 0;
        virtual void* getHandle() = 0;
        virtual WindowDesc getDescription() = 0;
    };

    std::shared_ptr<WindowBase> createWindow(const WindowDesc& desc);
} // namespace nt

#endif // _NT_WINDOW_WINDOW_BASE_h_