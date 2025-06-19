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

#ifndef _PCH_H_
    #define _PCH_H_

#include "Core/Preprocessor.h"

#if __has_include(<algorithm>)
    #include <algorithm>
#endif // __has_include(<algorithm>)

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
    #if __has_include(<any>)
    #include <any>
#endif // __has_include(<any>)

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
    #if __has_include(<array>)
    #include <array>
#endif // __has_include(<array>)

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
    #if __has_include(<atomic>)
    #include <atomic>
#endif // __has_include(<atomic>)

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
    #if __has_include(<barrier>)
    #include <barrier>
#endif // __has_include(<barrier>)

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
    #if __has_include(<bitset>)
    #include <bitset>
#endif // __has_include(<bitset>)

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
    #if __has_include(<cassert>)
    #include <cassert>
#endif // __has_include(<cassert>)

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
    #if __has_include(<cctype>)
    #include <cctype>
#endif // __has_include(<cctype>)

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
    #if __has_include(<cerrno>)
    #include <cerrno>
#endif // __has_include(<cerrno>)

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
    #if __has_include(<cfenv>)
    #include <cfenv>
#endif // __has_include(<cfenv>)

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
    #if __has_include(<cfloat>)
    #include <cfloat>
#endif // __has_include(<cfloat>)

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
    #if __has_include(<cinttypes>)
    #include <cinttypes>
#endif // __has_include(<cinttypes>)

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
    #if __has_include(<climits>)
    #include <climits>
#endif // __has_include(<climits>)

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
    #if __has_include(<clocale>)
    #include <clocale>
#endif // __has_include(<clocale>)

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
    #if __has_include(<cmath>)
    #include <cmath>
#endif // __has_include(<cmath>)

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
    #if __has_include(<csetjmp>)
    #include <csetjmp>
#endif // __has_include(<csetjmp>)

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
    #if __has_include(<csignal>)
    #include <csignal>
#endif // __has_include(<csignal>)

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
    #if __has_include(<cstdarg>)
    #include <cstdarg>
#endif // __has_include(<cstdarg>)

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
    #if __has_include(<cstddef>)
    #include <cstddef>
#endif // __has_include(<cstddef>)

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
    #if __has_include(<cstdio>)
    #include <cstdio>
#endif // __has_include(<cstdio>)

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
    #if __has_include(<cstdlib>)
    #include <cstdlib>
#endif // __has_include(<cstdlib>)

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
    #if __has_include(<cstring>)
    #include <cstring>
#endif // __has_include(<cstring>)

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
    #if __has_include(<ctime>)
    #include <ctime>
#endif // __has_include(<ctime>)

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
    #if __has_include(<cwchar>)
    #include <cwchar>
#endif // __has_include(<cwchar>)

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
    #if __has_include(<cwctype>)
    #include <cwctype>
#endif // __has_include(<cwctype>)

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
    #if __has_include(<charconv>)
    #include <charconv>
#endif // __has_include(<charconv>)

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
    #if __has_include(<chrono>)
    #include <chrono>
#endif // __has_include(<chrono>)

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
    #if __has_include(<codecvt>)
    #include <codecvt>
#endif // __has_include(<codecvt>)

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
    #if __has_include(<compare>)
    #include <compare>
#endif // __has_include(<compare>)

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
    #if __has_include(<complex>)
    #include <complex>
#endif // __has_include(<complex>)

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
    #if __has_include(<concepts>)
    #include <concepts>
#endif // __has_include(<concepts>)

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
    #if __has_include(<condition_variable>)
    #include <condition_variable>
#endif // __has_include(<condition_variable>)

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
    #if __has_include(<cstdint>)
    #include <cstdint>
#endif // __has_include(<cstdint>)

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
    #if __has_include(<cstdio>)
    #include <cstdio>
#endif // __has_include(<cstdio>)

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
    #if __has_include(<cstdlib>)
    #include <cstdlib>
#endif // __has_include(<cstdlib>)

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
    #if __has_include(<cstring>)
    #include <cstring>
#endif // __has_include(<cstring>)

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
    #if __has_include(<ctime>)
    #include <ctime>
#endif // __has_include(<ctime>)

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
    #if __has_include(<cuchar>)
    #include <cuchar>
#endif // __has_include(<cuchar>)

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
    #if __has_include(<deque>)
    #include <deque>
#endif // __has_include(<deque>)

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
    #if __has_include(<exception>)
    #include <exception>
#endif // __has_include(<exception>)

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
    #if __has_include(<execution>)
    #include <execution>
#endif // __has_include(<execution>)

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
    #if __has_include(<expected>)
    #include <expected>
#endif // __has_include(<expected>)

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
    #if __has_include(<filesystem>)
    #include <filesystem>
#endif // __has_include(<filesystem>)

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
    #if __has_include(<cfloatformat>)
    #include <cfloatformat>
#endif // __has_include(<cfloatformat>)

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
    #if __has_include(<forward_list>)
    #include <forward_list>
#endif // __has_include(<forward_list>)

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
    #if __has_include(<fstream>)
    #include <fstream>
#endif // __has_include(<fstream>)

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
    #if __has_include(<functional>)
    #include <functional>
#endif // __has_include(<functional>)

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
    #if __has_include(<future>)
    #include <future>
#endif // __has_include(<future>)

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
    #if __has_include(<generator>)
    #include <generator>
#endif // __has_include(<generator>)

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
    #if __has_include(<initializer_list>)
    #include <initializer_list>
#endif // __has_include(<initializer_list>)

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
    #if __has_include(<iomanip>)
    #include <iomanip>
#endif // __has_include(<iomanip>)

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
    #if __has_include(<ios>)
    #include <ios>
#endif // __has_include(<ios>)

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
    #if __has_include(<iosfwd>)
    #include <iosfwd>
#endif // __has_include(<iosfwd>)

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
    #if __has_include(<iostream>)
    #include <iostream>
#endif // __has_include(<iostream>)

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
    #if __has_include(<istream>)
    #include <istream>
#endif // __has_include(<istream>)

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
    #if __has_include(<iterator>)
    #include <iterator>
#endif // __has_include(<iterator>)

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
    #if __has_include(<latch>)
    #include <latch>
#endif // __has_include(<latch>)

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
    #if __has_include(<limits>)
    #include <limits>
#endif // __has_include(<limits>)

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
    #if __has_include(<list>)
    #include <list>
#endif // __has_include(<list>)

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
    #if __has_include(<locale>)
    #include <locale>
#endif // __has_include(<locale>)

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
    #if __has_include(<map>)
    #include <map>
#endif // __has_include(<map>)

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
    #if __has_include(<cmathmemory>)
    #include <cmathmemory>
#endif // __has_include(<cmathmemory>)

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
    #if __has_include(<memory_resource>)
    #include <memory_resource>
#endif // __has_include(<memory_resource>)

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
    #if __has_include(<mutex>)
    #include <mutex>
#endif // __has_include(<mutex>)

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
    #if __has_include(<new>)
    #include <new>
#endif // __has_include(<new>)

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
    #if __has_include(<numbers>)
    #include <numbers>
#endif // __has_include(<numbers>)

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
    #if __has_include(<numeric>)
    #include <numeric>
#endif // __has_include(<numeric>)

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
    #if __has_include(<optional>)
    #include <optional>
#endif // __has_include(<optional>)

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
    #if __has_include(<ostream>)
    #include <ostream>
#endif // __has_include(<ostream>)

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
    #if __has_include(<print>)
    #include <print>
#endif // __has_include(<print>)

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
    #if __has_include(<queue>)
    #include <queue>
#endif // __has_include(<queue>)

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
    #if __has_include(<random>)
    #include <random>
#endif // __has_include(<random>)

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
    #if __has_include(<ranges>)
    #include <ranges>
#endif // __has_include(<ranges>)

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
    #if __has_include(<ratio>)
    #include <ratio>
#endif // __has_include(<ratio>)

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
    #if __has_include(<regex>)
    #include <regex>
#endif // __has_include(<regex>)

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
    #if __has_include(<scoped_allocator>)
    #include <scoped_allocator>
#endif // __has_include(<scoped_allocator>)

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
    #if __has_include(<semaphore>)
    #include <semaphore>
#endif // __has_include(<semaphore>)

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
    #if __has_include(<set>)
    #include <set>
#endif // __has_include(<set>)

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
    #if __has_include(<shared_mutex>)
    #include <shared_mutex>
#endif // __has_include(<shared_mutex>)

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
    #if __has_include(<source_location>)
    #include <source_location>
#endif // __has_include(<source_location>)

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
    #if __has_include(<span>)
    #include <span>
#endif // __has_include(<span>)

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
    #if __has_include(<spanstream>)
    #include <spanstream>
#endif // __has_include(<spanstream>)

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
    #if __has_include(<stack>)
    #include <stack>
#endif // __has_include(<stack>)

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
    #if __has_include(<stacktrace>)
    #include <stacktrace>
#endif // __has_include(<stacktrace>)

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
    #if __has_include(<stdexcept>)
    #include <stdexcept>
#endif // __has_include(<stdexcept>)

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
    #if __has_include(<streambuf>)
    #include <streambuf>
#endif // __has_include(<streambuf>)

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
    #if __has_include(<string>)
    #include <string>
#endif // __has_include(<string>)

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
    #if __has_include(<string_view>)
    #include <string_view>
#endif // __has_include(<string_view>)

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
    #if __has_include(<syncstream>)
    #include <syncstream>
#endif // __has_include(<syncstream>)

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
    #if __has_include(<system_error>)
    #include <system_error>
#endif // __has_include(<system_error>)

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
    #if __has_include(<text_encoding>)
    #include <text_encoding>
#endif // __has_include(<text_encoding>)

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
    #if __has_include(<thread>)
    #include <thread>
#endif // __has_include(<thread>)

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
    #if __has_include(<tuple>)
    #include <tuple>
#endif // __has_include(<tuple>)

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
    #if __has_include(<type_traits>)
    #include <type_traits>
#endif // __has_include(<type_traits>)

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
    #if __has_include(<typeindex>)
    #include <typeindex>
#endif // __has_include(<typeindex>)

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
    #if __has_include(<typeinfo>)
    #include <typeinfo>
#endif // __has_include(<typeinfo>)

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
    #if __has_include(<unordered_map>)
    #include <unordered_map>
#endif // __has_include(<unordered_map>)

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
    #if __has_include(<unordered_set>)
    #include <unordered_set>
#endif // __has_include(<unordered_set>)

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
    #if __has_include(<utility>)
    #include <utility>
#endif // __has_include(<utility>)

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
    #if __has_include(<valarray>)
    #include <valarray>
#endif // __has_include(<valarray>)

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
    #if __has_include(<variant>)
    #include <variant>
#endif // __has_include(<variant>)

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
    #if __has_include(<vector>)
    #include <vector>
#endif // __has_include(<vector>)

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
    #if __has_include(<version>)
    #include <version>
#endif // __has_include(<version>)

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