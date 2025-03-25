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
    #if defined(NT_PLATFORM_DESKTOP)
        Vec2u position;
        uint width;
        uint height;
        std::string title;
    #endif // defined(NT_PLATFORM_DESKTOP)
        Color backgroundColor;

        // Window properties
    #if defined(NT_PLATFORM_DESKTOP)
        bool centered      = true;
        bool resizable     = true;
        bool canFullscreen = true;
        bool movable       = true;
        bool closable      = true;
        bool maximizable   = true;
        bool minimizable   = true;
    #endif // defined(NT_PLATFORM_DESKTOP)

        // Window states
        bool visible    = true;
    #if defined(NT_PLATFORM_DESKTOP)
        bool fullscreen = false;
        bool maximized  = false;
        bool minimized  = false;
        bool focused    = true;
    #endif // defined(NT_PLATFORM_DESKTOP)
        bool modal      = false;
        
        // Window events
        std::function<void()> onCreate  = nullptr;
        std::function<void()> onUpdate  = nullptr;
        std::function<void()> onDestroy = nullptr;
    };
} // namespace nt

#endif // _NT_WINDOW_WINDOW_DESCRIPTION_h_
