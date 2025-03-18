//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#pragma once

#ifndef _NT_WINDOW_WINDOW_DESCRIPTION_h_
    #define _NT_WINDOW_WINDOW_DESCRIPTION_h_

#include "../core/Types.h"
#include "../math/Vec2.h"
#include "../math/Color.h"

#include <string>
#include <functional>

namespace nt
{
    struct WindowDesc
    {
        // Window properties
        Vec2u position;
        uint width;
        uint height;
        std::string title;
        Color backgroundColor;

        // Window events
        std::function<void()> onCreate  = nullptr;
        std::function<void()> onUpdate  = nullptr;
        std::function<void()> onDestroy = nullptr;
    };
} // namespace nt

#endif // _NT_WINDOW_WINDOW_DESCRIPTION_h_