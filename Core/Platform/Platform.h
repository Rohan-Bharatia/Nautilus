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

#ifndef _NT_CORE_PLATFORM_PLATFORM_H_
    #define _NT_CORE_PLATFORM_PLATFORM_H_

// Define operating system & API
#if defined(_WIN32) || defined(_WIN64)
    #define NT_PLATFORM_WINDOWS
    #define NT_API_DIRECTX
#elif defined(__unix__)
    #define NT_PLATFORM_UNIX
    #if defined(__linux__)
        #define NT_PLATFORM_LINUX
    #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
        #define NT_PLATFORM_FREEBSD
    #elif defined(__NetBSD__)
        #define NT_PLATFORM_NETBSD
    #elif defined(__OpenBSD__)
        #define NT_PLATFORM_OPENBSD
    #elif defined(__DragonFly__)
        #define NT_PLATFORM_DRAGONFLY
    #elif defined(__CYGWIN__)
        #define NT_PLATFORM_CYGWIN
    #else // (NOT) defined(__linux__), defined(__FreeBSD__) || defined(__FreeBSD_kernel__), defined(__NetBSD__), defined(__OpenBSD__), defined(__DragonFly__), defined(__CYGWIN__)
        #error "This Unix Operatning System is not supported by Nautilus Engine!"
    #endif // defined(__linux__), defined(__FreeBSD__) || defined(__FreeBSD_kernel__), defined(__NetBSD__), defined(__OpenBSD__), defined(__DragonFly__), defined(__CYGWIN__)
    #define NT_API_X11
#elif defined(__APPLE__) && defined(__MACH__)
    #include <TargetConditionals.h>
    #if TARGET_OS_IPHONE
        #define NT_PLATFORM_IOS
        #define NT_API_UIKIT
    #elif TARGET_OS_MAC
        #define NT_PLATFORM_MACOS
        #define NT_API_APPKIT
    #else // (NOT) TARGET_OS_IPHONE, TARGET_OS_MAC
        #error "This Apple Operating System is not supported by Nautilus Engine!"
    #endif // TARGET_OS_IPHONE, TARGET_OS_MAC
#elif defined(__ANDROID__)
    #define NT_PLATFORM_ANDROID
    #define NT_API_ANDROID
#else // (NOT) defined(_WIN32) || defined(_WIN64), defined(__unix__), defined(__APPLE__) && defined(__MACH__), defined(__ANDROID__)
    #error "This Operating System is not supported by Nautilus Engine!"
#endif // defined(_WIN32) || defined(_WIN64), defined(__unix__), defined(__APPLE__) && defined(__MACH__), defined(__ANDROID__)

// Define CPU architecture
#if defined(_M_X64) || defined(__x86_64__) || defined(__ppc64__)
    #define NT_ARCH_X64
#elif defined(_M_IX86) || defined(__i386__) || defined(__ppc__)
    #define NT_ARCH_X86
#elif defined(_M_ARM) || defined(__arm__) || defined(__aarch32__)
    #define NT_ARCH_ARM
#elif defined(_M_ARM64) || defined(__aarch64__)
    #define NT_ARCH_ARM64
#elif defined(__mips__) || defined(__mips64__)
    #define NT_ARCH_MIPS
#elif defined(__riscv) || defined(__riscv_xlen)
    #define NT_ARCH_RISCV
#else // (NOT) defined(_M_X64) || defined(__x86_64__) || defined(__ppc64__), defined(_M_IX86) || defined(__i386__) || defined(__ppc__), defined(_M_ARM) || defined(__arm__) || defined(__aarch32__), defined(_M_ARM64) || defined(__aarch64__), defined(__mips__) || defined(__mips64__), defined(__riscv) || defined(__riscv_xlen)
    #error "This Architecture is not supported by Nautilus Engine!"
#endif // defined(_M_X64) || defined(__x86_64__) || defined(__ppc64__), defined(_M_IX86) || defined(__i386__) || defined(__ppc__), defined(_M_ARM) || defined(__arm__) || defined(__aarch32__), defined(_M_ARM64) || defined(__aarch64__), defined(__mips__) || defined(__mips64__), defined(__riscv) || defined(__riscv_xlen__)

// Define compiler
#if defined(_MSC_VER)
    #define NT_COMPILER_MSVC
    #define NT_COMPILER_VERSION _MSC_VER
#elif defined(__clang__)
    #define NT_COMPILER_CLANG
    #define NT_COMPILER_VERSION __clang_major__ * 100 + __clang_minor__ * 10 + __clang_patchlevel__
#elif defined(__GNUC__)
    #define NT_COMPILER_GCC
    #define NT_COMPILER_VERSION __GNUC__ * 100 + __GNUC_MINOR__ * 10 + __GNUC_PATCHLEVEL__
#elif defined(__INTEL_COMPILER)
    #define NT_COMPILER_INTEL
    #define NT_COMPILER_VERSION __INTEL_COMPILER
#elif defined(__BORLANDC__)
    #define NT_COMPILER_BORLAND
    #define NT_COMPILER_VERSION __BORLANDC__
#elif defined(__MINGW32__) || defined(__MINGW64__)
    #define NT_COMPILER_MINGW
    #define NT_COMPILER_VERSION __MINGW32_MAJOR_VERSION * 100 + __MINGW32_MINOR_VERSION * 10 + __MINGW32_PATCHLEVEL__
#else // (NOT) defined(_MSC_VER), defined(__clang__), defined(__GNUC__), defined(__INTEL_COMPILER), defined(__BORLANDC__), defined(__MINGW32__) || defined(__MINGW64__)
    #error "This Compiler is not supported by Nautilus Engine!"
#endif // defined(_MSC_VER), defined(__clang__), defined(__GNUC__), defined(__INTEL_COMPILER), defined(__BORLANDC__), defined(__MINGW32__) || defined(__MINGW64__)

// Define build type
#if defined(NDEBUG)
    #define NT_RELEASE
#else // (NOT) defined(NDEBUG)
    #define NT_DEBUG
#endif // defined(NDEBUG)

#ifndef NT_STATIC
    #define NT_SHARED
#endif // NT_STATIC
#ifndef NT_SHARED
    #define NT_STATIC
#endif // NT_SHARED

// Define build configuration
#if defined(NT_STATIC) // Static library
    #define NT_IMPORT
    #define NT_EXPORT
    #define NT_API NT_IMPORT
#elif defined(NT_SHARED) // Shared library
    #if defined(NT_PLATFORM_WINDOWS)
        #define NT_IMPORT __declspec(dllimport)
        #define NT_EXPORT __declspec(dllexport)
    #else // (NOT) defined(NT_PLATFORM_WINDOWS)
        #define NT_IMPORT __attribute__((visibility("default")))
        #define NT_EXPORT __attribute__((visibility("default")))
    #endif // defined(NT_PLATFORM_WINDOWS)
    #define NT_API NT_EXPORT
#endif // defined(NT_STATIC), defined(NT_SHARED)

// Define calling conventions
#if defined(NT_PLATFORM_WINDOWS)
    #define NT_CALLBACK __stdcall
    #define NT_CDECL __cdecl
#else // (NOT) defined(NT_PLATFORM_WINDOWS)
    #define NT_CALLBACK __attribute__((stdcall))
    #define NT_CDECL __attribute__((cdecl))
#endif // defined(NT_PLATFORM_WINDOWS)

// Define other macros
#define NT_UNUSED(x) (void)(x)
#define NT_ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define NT_STRINGIFY(x) #x
#define NT_TOSTRING(x) NT_STRINGIFY(x)
#define NT_CONCATENATE(x, y) x##y
#define NT_TOCONCATENATE(x, y) NT_CONCATENATE(x, y)
#define NT_MODULUS(x, y) (x - (int)(x / y) * y) >= 0 ? (x - (int)(x / y) * y) : (x - (int)(x / y) * y) + y

#endif // _NT_CORE_PLATFORM_PLATFORM_H_
