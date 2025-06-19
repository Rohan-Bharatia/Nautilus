import os

# A list of standard library headers to include in the precompiled header
includes = [
    'algorithm',
    'any',
    'array',
    'atomic',
    'barrier',
    'bitset',
    'cassert',
    'cctype',
    'cerrno',
    'cfenv',
    'cfloat',
    'cinttypes',
    'climits',
    'clocale',
    'cmath',
    'csetjmp',
    'csignal',
    'cstdarg',
    'cstddef',
    'cstdio',
    'cstdlib',
    'cstring',
    'ctime',
    'cwchar',
    'cwctype',
    'charconv',
    'chrono',
    'codecvt',
    'compare',
    'complex',
    'concepts',
    'condition_variable',
    'cstdint',
    'cuchar',
    'deque',
    'exception',
    'execution',
    'expected',
    'filesystem',
    'format',
    'forward_list',
    'fstream',
    'functional',
    'future',
    'generator',
    'initializer_list',
    'iomanip',
    'ios',
    'iosfwd',
    'iostream',
    'istream',
    'iterator',
    'latch',
    'limits',
    'list',
    'locale',
    'map',
    'memory',
    'memory_resource',
    'mutex',
    'new',
    'numbers',
    'numeric',
    'optional',
    'ostream',
    'print',
    'queue',
    'random',
    'ranges',
    'ratio',
    'regex',
    'scoped_allocator',
    'semaphore',
    'set',
    'shared_mutex',
    'source_location',
    'span',
    'spanstream',
    'stack',
    'stacktrace',
    'stdexcept',
    'streambuf',
    'string',
    'string_view',
    'syncstream',
    'system_error',
    'text_encoding',
    'thread',
    'tuple',
    'type_traits',
    'typeindex',
    'typeinfo',
    'unordered_map',
    'unordered_set',
    'utility',
    'valarray',
    'variant',
    'vector',
    'version'
]

input_file = os.path.join(os.path.dirname(__file__), '..', 'Nautilus', 'PCH.h')

with open(input_file, 'w') as f:
    f.write('''#pragma region LICENSE

//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//
//                  Copyright (c) Rohan Bharatia 2025

#pragma endregion LICENSE

#pragma once

#ifndef _PCH_H_
    #define _PCH_H_

#include "Core/Preprocessor.h"

''')

    for include in includes:
        f.write(f'#if __has_include(<{include}>)\n')
        f.write(f'#   include <{include}>\n')
        f.write(f'#endif // __has_include(<{include}>)\n')

    f.write('''
#if defined(NT_PLATFORM_WINDOWS)
    #ifndef UNICODE
        #define UNICODE
    #endif // UNICODE
    #ifndef NOMINMAX
        #define NOMINMAX
    #endif // NOMINMAX 
    #ifndef WIN32_LEAN_AND_MEAN
        #define WIN32_LEAN_AND_MEAN
    #endif // WIN32_LEAN_AND_MEAN
    #include <Windows.h>
    #include <intrin.h>
    #include <rpc.h>
    #include <d3d12.h>
    #include <dxgi1_6.h>
    #include <d3dcompiler.h>
    #include <wrl.h>
    #include <DirectXMath.h>
    using namespace Microsoft::WRL;
#elif defined(NT_PLATFORM_LINUX)
    #ifndef VK_USE_PLATFORM_X11_KHR
        #define VK_USE_PLATFORM_X11_KHR
    #endif // VK_USE_PLATFORM_X11_KHR
    #include <unistd.h>
    #include <fstream>
    #include <cstring>
    #include <cpuid.h>
    #include <sys/statfs.h>
    #include <uuid/uuid.h>
    #include <X11/Xlib.h>
    #include <X11/Xutil.h>
    #include <X11/Xatom.h>
    #include <vulkan/vulkan.h>
#elif defined(NT_PLATFORM_MACOS)
    #ifdef __OBJC__
        #import <Cocoa/Cocoa.h>
        #import <QuartzCore/QuartzCore.h>
        #import <IOKit/IOKit.h>
        #import <Metal/Metal.h>
        #import <MetalKit/MetalKit.h>
    #endif // __OBJC__
    #include <sys/sysctl.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <cpuid.h>
    #include <uuid/uuid.h>
#elif defined(NT_PLATFORM_IOS)
    #ifdef __OBJC__
        #import <UIKit/UIKit.h>
        #import <QuartzCore/QuartzCore.h>
        #import <IOKit/IOKit.h>
        #import <Metal/Metal.h>
        #import <MetalKit/MetalKit.h>
    #endif // __OBJC__
    #include <sys/sysctl.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <cpuid.h>
    #include <uuid/uuid.h>
#elif defined(NT_PLATFORM_ANDROID)
    #ifndef VK_USE_PLATFORM_ANDROID_KHR
        #define VK_USE_PLATFORM_ANDROID_KHR
    #endif // VK_USE_PLATFORM_ANDROID_KHR
    #include <android/log.h>
    #include <android/native_activity.h>
    #include <android/native_window.h>
    #include <android/asset_manager.h>
    #include <android/api-level.h>
    #include <unistd.h>
    #include <sys/sysinfo.h>
    #include <cpu-features.h>
    #include <uuid/uuid.h>
    #include <vulkan/vulkan.h>
#elif defined(NT_PLATFORM_WASM)
    #include <emscripten/emscripten.h>
    #include <emscripten/html5.h>
    #include <emscripten/html5_webgpu.h>
#endif // defined(NT_PLATFORM_WINDOWS), defined(NT_PLATFORM_LINUX), defined(NT_PLATFORM_MACOS), defined(NT_PLATFORM_IOS), defined(NT_PLATFORM_ANDROID), defined(NT_PLATFORM_WASM)

#endif // _PCH_H_
''')
