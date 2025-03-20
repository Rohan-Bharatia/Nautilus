#pragma once

#ifndef _NT_WINDOW_h_
    #define _NT_WINDOW_h_

// Source files
#include "window/WindowBase.h"
#if defined(NT_PLATFORM_WINDOWS)
    #include "window/WindowWin32.h"
#elif defined(NT_PLATFORM_LINUX) || defined(NT_PLATFORM_FREEBSD)
    #include "window/WindowX11.h"
#elif defined(NT_PLATFORM_MACOS)
    #include "window/WindowCocoa.h"
#elif defined(NT_PLATFORM_IOS)
    #include "window/WindowUIKit.h"
#elif defined(NT_PLATFORM_ANDROID)
    #include "window/WindowAndroid.h"
#endif // defined(NT_PLATFORM_WINDOWS), defined(NT_PLATFORM_LINUX) || defined(NT_PLATFORM_FREEBSD), defined(NT_PLATFORM_MACOS), defined(NT_PLATFORM_IOS), defined(NT_PLATFORM_ANDROID)

namespace nt
{
    using WindowPtr = std::shared_ptr<WindowBase>;
} // namespace nt

#endif // _NT_WINDOW_h_
