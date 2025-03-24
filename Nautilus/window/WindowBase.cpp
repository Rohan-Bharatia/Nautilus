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

#ifndef _NT_WINDOW_WINDOW_BASE_cpp_
    #define _NT_WINDOW_WINDOW_BASE_cpp_

#include "WindowBase.h"

#include "../core/Config.h"

#if defined(NT_PLATFORM_WINDOWS)
    #include "WindowWin32.h"
#elif defined(NT_PLATFORM_LINUX) || defined(NT_PLATFORM_FREEBSD)
    #include "WindowX11.h"
#elif defined(NT_PLATFORM_MACOS)
    #include "WindowCocoa.h"
#elif defined(NT_PLATFORM_IOS)
    #include "WindowUIKit.h"
#elif defined(NT_PLATFORM_ANDROID)
    #include "WindowAndroid.h"
#endif // defined(NT_PLATFORM_WINDOWS), defined(NT_PLATFORM_LINUX) || defined(NT_PLATFORM_FREEBSD), defined(NT_PLATFORM_MACOS), defined(NT_PLATFORM_IOS), defined(NT_PLATFORM_ANDROID)

namespace nt
{
    std::shared_ptr<WindowBase> createWindow(const WindowDesc& desc, GraphicsAPI api)
    {
    #if defined(NT_PLATFORM_WINDOWS)
        return std::make_shared<WindowWin32>(desc, api);
    #elif defined(NT_PLATFORM_LINUX) || defined(NT_PLATFORM_FREEBSD)
        return std::make_shared<WindowX11>(desc, api);
    #elif defined(NT_PLATFORM_MACOS)
        return std::make_shared<WindowCocoa>(desc, api);
    #elif defined(NT_PLATFORM_IOS)
        return std::make_shared<WindowUIKit>(desc, api);
    #elif defined(NT_PLATFORM_ANDROID)
        return std::make_shared<WindowAndroid>(desc, api);
    #else // (NOT) defined(NT_PLATFORM_WINDOWS), defined(NT_PLATFORM_LINUX) || defined(NT_PLATFORM_FREEBSD), defined(NT_PLATFORM_MACOS), defined(NT_PLATFORM_IOS), defined(NT_PLATFORM_ANDROID)
        return nullptr;
    #endif // defined(NT_PLATFORM_WINDOWS), defined(NT_PLATFORM_LINUX) || defined(NT_PLATFORM_FREEBSD), defined(NT_PLATFORM_MACOS), defined(NT_PLATFORM_IOS), defined(NT_PLATFORM_ANDROID)
    }
} // namespace nt

#endif // _NT_WINDOW_WINDOW_BASE_cpp_
