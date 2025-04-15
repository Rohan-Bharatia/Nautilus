#pragma region LICENSE

//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                                 ...
//
//                  Copyright (c) Rohan Bharatia 2025

#pragma endregion LICENSE

#pragma once

#ifndef _NT_CORE_PLATFORM_NATIVE_HANDLE_H_
    #define _NT_CORE_PLATFORM_NATIVE_HANDLE_H_

#include "API.h"

namespace nt
{
    struct NativeHandle
    {
    #if defined(NT_PLATFORM_WINDOWS)
        // Win32
        HINSTANCE hinstance;
        HMENU hmenu;
        HWND hwnd;
    #elif defined(NT_PLATFORM_UNIX)
        // XLib
        Display* display;
        Window window;
    #elif defined(NT_PLATFORM_MACOS)
        // Cocoa
        #ifdef __OBJC__
            NSWindow* window;
        #else // (NOT) __OBJC__
            void* window;
        #endif // __OBJC__
    #elif defined(NT_PLATFORM_IOS)
        // UIKit
        #ifdef __OBJC__
            UIWindow* window;
        #else // (NOT) __OBJC__
            void* window;
        #endif // __OBJC__
    #elif defined(NT_PLATFORM_ANDROID)
        // JNI
        ANativeWindow* native;
    #elif defined(NT_PLATFORM_WASM)
        // Emscripten
        emscripten::val canvas;
    #endif // defined(NT_PLATFORM_WINDOWS), defined(NT_PLATFORM_UNIX), defined(NT_PLATFORM_MACOS), defined(NT_PLATFORM_IOS), defined(NT_PLATFORM_ANDROID), defined(NT_PLATFORM_WASM)
    };
};

#endif // _NT_CORE_PLATFORM_NATIVE_HANDLE_H_
