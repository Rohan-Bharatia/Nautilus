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

#ifndef _NT_WINDOW_WINDOW_BASE_h_
    #define _NT_WINDOW_WINDOW_BASE_h_

#include "WindowDesc.h"

#include "../backends/include/glad/gl.h"
#if defined(NT_PLATFORM_WINDOWS)
    #include "../backends/include/glad/wgl.h"
#elif defined(NT_PLATFORM_LINUX) || defined(NT_PLATFORM_FREEBSD)
    #include "../backends/include/glad/glx.h"
#elif defined(NT_PLATFORM_MACOS)
    #include "../backends/include/glad/egl.h"
#elif defined(NT_PLATFORM_IOS)
    #include "../backends/include/glad/gles2.h"
#elif defined(NT_PLATFORM_ANDROID)
    #include "../backends/backends/include/glad/gles2.h"
#endif // defined(NT_PLATFORM_WINDOWS), defined(NT_PLATFORM_LINUX) || defined(NT_PLATFORM_FREEBSD), defined(NT_PLATFORM_MACOS), defined(NT_PLATFORM_IOS), defined(NT_PLATFORM_ANDROID)

#include <memory>

namespace nt
{
    class WindowBase
    {
    public:
        virtual void initialize()                                        = 0;
        virtual bool pollEvents()                                        = 0;
        virtual void useShader(std::string vertex, std::string fragment) = 0;
        virtual void update()                                            = 0;
        virtual void clear(const Color& color)                           = 0;
        virtual void swapBuffers()                                       = 0;
        virtual void destroy()                                           = 0;

        virtual void* getHandle()           = 0;
        virtual WindowDesc getDescription() = 0;
    };

    std::shared_ptr<WindowBase> createWindow(const WindowDesc& desc);
} // namespace nt

#endif // _NT_WINDOW_WINDOW_BASE_h_
