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

#ifndef _NT_PLATFORM_API_H_
    #define _NT_PLATFORM_API_H_

// Get platform specific APIs
#if defined(NT_PLATFORM_WINDOWS) // Win32 & DirectX
    #include <Windows.h>
    #include <d3d12.h>
    #include <dxgi1_6.h>
    #include <d3dcompiler.h>
    #include <wrl.h>
    #include <wrl/client.h>
    #include <wrl/module.h>
    using namespace Microsoft::WRL;
#elif defined(NT_PLATFORM_UNIX) // X11
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <X11/Xlib.h>
    #include <X11/Xutil.h>
    #include <X11/Xatom.h>
    #include <X11/keysym.h>
    #include <GL/gl.h>
    #include <GL/glx.h>
    #include <GL/glxext.h>
    #include <GL/glext.h>
    #include <GL/glu.h>
#elif defined(NT_PLATFORM_MACOS) // Cocoa & Metal
    #include <Cocoa/Cocoa.h>
    #define NS_PRIVATE_IMPLEMENTATION
    #define CA_PRIVATE_IMPLEMENTATION
    #define MTL_PRIVATE_IMPLEMENTATION
    #include <Foundation/Foundation.hpp>
    #include <QuartzCore/QuartzCore.hpp>
    #include <Metal/Metal.hpp>
#elif defined(NT_PLATFORM_IOS) // UIKit & Metal
    #include <UIKit/UIKit.h>
    #define NS_PRIVATE_IMPLEMENTATION
    #define CA_PRIVATE_IMPLEMENTATION
    #define MTL_PRIVATE_IMPLEMENTATION
    #include <Foundation/Foundation.hpp>
    #include <Metal/Metal.hpp>
    #include <QuartzCore/QuartzCore.hpp>
#elif defined(NT_PLATFORM_ANDROID) // Android JNI
    #include <jni.h>
    #include <android/native_window_jni.h>
    #include <android/native_activity.h>
    #include <android/input.h>
    #include <android/keycodes.h>
    #include <GLES3/gl2.h>
    #include <GLES3/gl2ext.h>
    #include <EGL/egl.h>
#endif // defined(NT_PLATFORM_WINDOWS), defined(NT_PLATFORM_UNIX), defined(NT_PLATFORM_MACOS), defined(NT_PLATFORM_IOS), defined(NT_PLATFORM_ANDROID)

#endif // _NT_PLATFORM_API_H_
