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
#if defined(NT_PLATFORM_WINDOWS)
    // Win32
    #include <Windows.h>
    #include <WindowsX.h>
    #include <Winuser.h>

    // OpenGL
    #include <GL/gl.h>
    #include <GL/wgl.h>
    #include <GL/wglext.h>
    #include <GL/glext.h>
#elif defined(NT_PLATFORM_UNIX)
    // XLib
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <X11/Xlib.h>
    #include <X11/Xutil.h>
    #include <X11/Xatom.h>
    #include <X11/keysym.h>

    // OpenGL
    #include <GL/gl.h>
    #include <GL/glx.h>
    #include <GL/glxext.h>
    #include <GL/glext.h>
#elif defined(NT_PLATFORM_MACOS)
    // Cocoa
    #ifdef __OBJC__
        #include <Cocoa/Cocoa.h>
    #endif // __OBJC__

    // OpenGL
    #include <OpenGL/gl.h>
    #include <OpenGL/OpenGL.h>
    #ifdef __OBJC__
        #include <QuartzCore/CAMetalLayer.h>
    #endif // __OBJC__
#elif defined(NT_PLATFORM_IOS)
    // UIKit
    #ifdef __OBJC__
        #include <UIKit/UIKit.h>
    #endif // __OBJC__

    // OpenGL
    #include <OpenGL/gl.h>
    #include <OpenGL/OpenGL.h>
    #ifdef __OBJC__
        #include <QuartzCore/CAMetalLayer.h>
    #endif // __OBJC__
#elif defined(NT_PLATFORM_ANDROID)
    // JNI
    #include <jni.h>
    #include <android/native_window_jni.h>
    #include <android/native_activity.h>
    #include <android/input.h>
    #include <android/keycodes.h>

    // OpenGL
    #include <GLES3/gl3.h>
    #include <GLES3/gl3ext.h>
    #include <EGL/egl.h>
    #include <EGL/eglext.h>
#elif defined(NT_PLATFORM_WASM)
    // Emscripten
    #include <emscripten.h>
    #include <emscripten/html5.h>
    #include <emscripten/val.h>

    // OpenGL
    #include <GLES3/gl3.h>
    #include <GLES3/gl3ext.h>
    #include <EGL/egl.h>
    #include <EGL/eglext.h>
#endif // defined(NT_PLATFORM_WINDOWS), defined(NT_PLATFORM_UNIX), defined(NT_PLATFORM_MACOS), defined(NT_PLATFORM_IOS), defined(NT_PLATFORM_ANDROID), defined(NT_PLATFORM_WASM)

#endif // _NT_PLATFORM_API_H_
