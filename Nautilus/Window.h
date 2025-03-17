#pragma once

#ifndef _NT_WINDOW_h_
    #define _NT_WINDOW_h_

// Source files
#include "window/WindowBase.h"
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
    using WindowPtr = std::unique_ptr<WindowBase>;
} // namespace nt

#endif // _NT_WINDOW_h_