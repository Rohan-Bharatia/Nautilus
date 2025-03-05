//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#pragma once

#ifndef _NT_CORE_API_h_
    #define _NT_CORE_API_h_

#include "Config.h"
#include "Types.h"

#if defined(NT_PLATFORM_WINDOWS)
#define NT_DISCRETE_GPU_PREFERENCE                                                     \
    extern "C" NT_EXPORT nt::uint32 NvOptimusEnablement                  = 0x00000001; \
    extern "C" NT_EXPORT nt::uint32 AMDPowerXpressRequestHighPerformance = 0x00000001;
#else // (NOT) defined(NT_PLATFORM_WINDOWS)
#define NT_DISCRETE_GPU_PREFERENCE
#endif // defined(NT_PLATFORM_WINDOWS)

// OpenGL header(s) inclusion
#if defined(NT_OPENGL)
    #if defined(NT_PLATFORM_WINDOWS)
        #if defined(_MSC_VER)
            #ifndef WIN32_LEAN_AND_MEAN
                #define WIN32_LEAN_AND_MEAN
            #endif // WIN32_LEAN_AND_MEAN
            #include <Windows.h>
        #endif // defined(_MSC_VER)
        #include <GL/gl.h>
    #elif defined(NT_PLATFORM_LINUX) || defined(NT_PLATFORM_FREEBSD) || defined(NT_PLATFORM_OPENBSD) || defined(NT_PLATFORM_NETBSD)
        #if defined(NT_OPENGL_ES)
            #include <GLES/gl.h>
            #include <GLES/glext.h>
        #else // (NOT) defined(NT_OPENGL_ES)
            #include <GL/gl.h>
        #endif // defined(NT_OPENGL_ES)
    #elif defined(NT_SYSTEM_MACOS)
        #include <OpenGL/gl.h>
    #elif defined(NT_SYSTEM_IOS)
        #include <OpenGLES/ES1/gl.h>
        #include <OpenGLES/ES1/glext.h>
    #elif defined(NT_SYSTEM_ANDROID)
        #include <GLES/gl.h>
        #include <GLES/glext.h>
        #include <GLES2/gl2ext.h>
        #include <GLES2/gl2platform.h>
    #endif /* defined(NT_PLATFORM_WINDOWS), defined(NT_PLATFORM_LINUX) || defined(NT_PLATFORM_FREEBSD) || defined(NT_PLATFORM_OPENBSD) || defined(NT_PLATFORM_NETBSD), 
              defined(NT_SYSTEM_MACOS), defined(NT_SYSTEM_IOS), defined(NT_SYSTEM_ANDROID) */
#endif // defined(NT_OPENGL)

// Vulkan header inclusion
#if defined(NT_VULKAN)
    #if defined(NT_PLATFORM_WINDOWS)
        #define VK_USE_PLATFORM_WIN32_KHR
    #elif defined(NT_PLATFORM_LINUX) || defined(NT_PLATFORM_FREEBSD) || defined(NT_PLATFORM_OPENBSD) || defined(NT_PLATFORM_NETBSD)
        #define VK_USE_PLATFORM_XLIB_KHR
        #define VK_USE_PLATFORM_XLIB_XRANDR_EXT
    #elif defined(NT_SYSTEM_MACOS)
        #define VK_USE_PLATFORM_MACOS_MVK
    #elif defined(NT_SYSTEM_IOS)
        #define VK_USE_PLATFORM_IOS_MVK
    #elif defined(NT_SYSTEM_ANDROID)
        #define VK_USE_PLATFORM_ANDROID_KHR
    #endif /* defined(NT_PLATFORM_WINDOWS), defined(NT_PLATFORM_LINUX) || defined(NT_PLATFORM_FREEBSD) || defined(NT_PLATFORM_OPENBSD) || defined(NT_PLATFORM_NETBSD), 
              defined(NT_SYSTEM_MACOS), defined(NT_SYSTEM_IOS), defined(NT_SYSTEM_ANDROID) */
    #define VK_ENABLE_BETA_EXTENSIONS
    #include <vulkan/vulkan.h>
#endif // defined(NT_VULKAN)

// DirectX 11 header inclusion
#if defined(NT_DIRECTX11)
    #if defined(NT_PLATFORM_WINDOWS)
        #include <d3d11.h>
    #else // (NOT) defined(NT_PLATFORM_WINDOWS)
        #error DirextX 11 is only supported by Windows!
    #endif // defined(NT_PLATFORM_WINDOWS)
#endif // defined(NT_DIRECTX11)

// DirectX 12 header inclusion
#if defined(NT_DIRECTX12)
    #if defined(NT_PLATFORM_WINDOWS)
        #include <d3d12.h>
    #else // (NOT) defined(NT_PLATFORM_WINDOWS)
        #error DirextX 12 is only supported by Windows!
    #endif // defined(NT_PLATFORM_WINDOWS)
#endif // defined(NT_DIRECTX12)

// Metal header inclusion
#if defined(NT_METAL)
    #if defined(NT_SYSTEM_MACOS) || defined(NT_SYSTEM_IOS)
        #include <Metal/Metal.h>
    #else // (NOT) defined(NT_SYSTEM_MACOS) || defined(NT_SYSTEM_IOS)
        #error Metal is only supported by macOS and iOS!
    #endif // defined(NT_SYSTEM_MACOS) || defined(NT_SYSTEM_IOS)
#endif // defined(NT_METAL)

// WebGPU header inclusion
#if defined(NT_WEBGPU)
    #if defined(NT_PLATFORM_WEB)
        #include <webgpu/webgpu.h>
    #else // (NOT) defined(NT_PLATFORM_WEB)
        #error WebGPU is only supported by WASM/Emscripten!
    #endif // defined(NT_PLATFORM_WEB)
#endif // defined(NT_WEBGPU)

#endif // _NT_CORE_API_h_