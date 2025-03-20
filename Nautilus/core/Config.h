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

#ifndef _NT_CORE_CONFIG_h_
    #define _NT_CORE_CONFIG_h_

// Compiler indentification
#if defined(__clang__)
    #define NT_COMPILER_CLANG
    #define NT_COMPILER_CLANG_VER (__clang_major__ * 100 + __clang_minor__)
    #define NT_DEPRECATED(msg) __attribute__((__deprecated__(msg)))
    #define NT_PRETTY_FUNC(msg) __PRETTY_FUNCTION__
    #define NT_CHECK_CLANG_VERSION(ver) (NT_COMPILER_CLANG_VERSION >= ver)
    #define NT_PRAGMA(x) _Pragma(#x)
	#define NT_WARNING_CLANG_DISABLE(warn) NT_PRAGMA(clang diagnostic ignored warn)
	#define NT_WARNING_CLANG_GCC_DISABLE(warn) NT_PRAGMA(clang diagnostic ignored warn)
	#define NT_WARNING_POP() NT_PRAGMA(clang diagnostic pop)
	#define NT_WARNING_PUSH() NT_PRAGMA(clang diagnostic push)
    #if defined(__MINGW32__)
        #define NT_COMPILER_MINGW
        #if defined(__MINGW64_VERSION_MAJOR)
            #define NT_COMPILER_MINGW_64
        #endif // __MINGW64_VERSION_MAJOR
    #endif // defined(__MINGW32__)
#elif defined(__GNUC__) || defined(__MINGW32__)
    #define NT_COMPILER_GCC
    #define NT_COMPILER_GCC_VER (__GNUC__ * 100 + __GNUC_MINOR__)
    #define NT_DEPRECATED(txt) __attribute__((__deprecated__(txt)))
    #define NT_PRETTY_FUNCTION __PRETTY_FUNCTION__
    #define NT_CHECK_GCC_VER(ver) (NT_COMPILER_GCC_VER >= ver)
    #define NT_PRAGMA(x) _Pragma(#x)
    #define NT_WARNING_CLANG_GCC_DISABLE(warn) NT_PRAGMA(GCC diagnostic ignored warn)
    #define NT_WARNING_GCC_DISABLE(warn) NT_PRAGMA(GCC diagnostic ignored warn)
    #define NT_WARNING_POP() NT_PRAGMA(GCC diagnostic pop)
    #define NT_WARNING_PUSH() NT_PRAGMA(GCC diagnostic push)
    #if defined(__MINGW32__)
        #define NT_COMPILER_MINGW
        #if defined(__MINGW64_VERSION_MAJOR)
            #define NT_COMPILER_MINGW_64
        #endif // __MINGW64_VERSION_MAJOR
    #endif // defined(__MINGW32__)
#elif defined(__INTEL_COMPILER) || defined(__ICL)
	#define NT_COMPILER_ICC
	#define NT_COMPILER_ICC_VER __INTEL_COMPILER
	#define NT_DEPRECATED(txt) [[deprecated(txt)]]
	#define NT_PRETTY_FUNCTION __FUNCTION__
	#define NT_CHECK_ICC_VER(ver) (NT_COMPILER_ICC_VER >= ver)
	#define NT_PRAGMA(x) _Pragma(x)
	#define NT_WARNING_ICC_DISABLE(...) NT_PRAGMA(warning(disable: __VA_ARGS__))
	#define NT_WARNING_POP() NT_PRAGMA(warning(pop))
	#define NT_WARNING_PUSH() NT_PRAGMA(warning(push))
#elif defined(_MSC_VER)
	#define NT_COMPILER_MSVC
	#define NT_COMPILER_MSVC_VER _MSC_VER
	#define NT_DEPRECATED(txt) __declspec(deprecated(txt))
	#define NT_PRETTY_FUNCTION __FUNCSIG__
	#define NT_CHECK_MSVC_VER(ver) (NT_COMPILER_MSVC_VER >= ver)
	#define NT_PRAGMA(x) __pragma(x)
	#define NT_WARNING_MSVC_DISABLE(...) NT_PRAGMA(warning(disable: __VA_ARGS__))
	#define NT_WARNING_POP() NT_PRAGMA(warning(pop))
	#define NT_WARNING_PUSH() NT_PRAGMA(warning(push))
	#define NT_CPP_VER _MSVC_LANG // __cplusplus isn't respected on MSVC without /Zc:__cplusplus flag
#else
    #define NT_COMPILER_UNKNOWN
    #pragma message "This compiler is not supported by Nautilus Engine!"
#endif // defined(__clang__), defined(__GNUC__) || defined(__MINGW32__), defined(__INTEL_COMPILER) || defined(__ICL), defined(_MSC_VER)

// Detect MinGW thread model
#if defined(NT_COMPILER_MINGW)
	#if defined(__USING_MCFGTHREAD__)
		#define NT_COMPILER_MINGW_THREADS_MCF
	#elif defined(_REENTRANT)
		#define NT_COMPILER_MINGW_THREADS_POSIX
	#else // (NOT) defined(__USING_MCFGTHREAD__), defined(_REENTRANT)
		#define NT_COMPILER_MINGW_THREADS_WIN32
	#endif // defined(__USING_MCFGTHREAD__), defined(_REENTRANT)
#endif // defined(NT_COMPILER_MINGW)

#ifndef NT_CHECK_CLANG_VER
    #define NT_CHECK_CLANG_VER(ver) 0
#endif // NT_CHECK_CLANG_VER

#ifndef NT_CHECK_ICC_VER
    #define NT_CHECK_ICC_VER(ver) 0
#endif // NT_CHECK_ICC_VER

#ifndef NT_CHECK_GCC_VER
    #define NT_CHECK_GCC_VER(ver) 0
#endif // NT_CHECK_GCC_VER

#ifndef NT_CHECK_MSVC_VER
    #define NT_CHECK_MSVC_VER(ver) 0
#endif // NT_CHECK_MSVC_VER

#ifndef NT_CPP_VER
    #define NT_CPP_VER __cplusplus
#endif // NT_CPP_VER

#ifndef NT_DEPRECATED
    #define NT_DEPRECATED(txt) [[deprecated(txt)]]
#endif // NT_DEPRECATED

#ifndef NT_PRAGMA
    #define NT_PRAGMA(x) _Pragma(#x)
#endif // NT_PRAGMA

#ifndef NT_PRETTY_FUNCTION
    #define NT_PRETTY_FUNCTION __func__
#endif // NT_PRETTY_FUNCTION

#ifndef NT_WARNING_CLANG_DISABLE
    #define NT_WARNING_CLANG_DISABLE(warn)
#endif // NT_WARNING_CLANG_DISABLE

#ifndef NT_WARNING_CLANG_GCC_DISABLE
    #define NT_WARNING_CLANG_GCC_DISABLE(warn)
#endif // NT_WARNING_CLANG_GCC_DISABLE

#ifndef NT_WARNING_GCC_DISABLE
    #define NT_WARNING_GCC_DISABLE(warn)
#endif // NT_WARNING_GCC_DISABLE

#ifndef NT_WARNING_ICC_DISABLE
    #define NT_WARNING_ICC_DISABLE(warn)
#endif // NT_WARNING_ICC_DISABLE

#ifndef NT_WARNING_MSVC_DISABLE
    #define NT_WARNING_MSVC_DISABLE(...)
#endif // NT_WARNING_MSVC_DISABLE

#ifndef NT_WARNING_POP
    #define NT_WARNING_POP()
#endif // NT_WARNING_POP

#ifndef NT_WARNING_PUSH
    #define NT_WARNING_PUSH()
#endif // NT_WARNING_PUSH

// C++ version
#define NT_CPP98 199711L // 1998
#define NT_CPP11 201103L // 2011
#define NT_CPP14 201402L // 2014
#define NT_CPP17 201703L // 2017
#define NT_CPP20 202002L // 2020
#define NT_CPP23 202302L // 2023
#define NT_CPP_LATEST NT_CPP23

#define NT_CHECK_CPP_VER(ver) (NT_CPP_VER >= ver)

#if !NT_CHECK_CPP_VER(NT_CPP17)
	#error Nautilus Engine requires C++17 or higher!
#endif // !NT_CHECK_CPP_VER(NT_CPP17)

// Identify platform
#if defined(_WIN32)
    #define NT_PLATFORM_DESKTOP
    #define NT_PLATFORM_WINDOWS
    #define NT_EXPORT __declspec(dllexport)
    #define NT_IMPORT __declspec(dllimport)
    #if defined(NT_BUILD)
        #ifndef WIN32_LEAN_AND_MEAN
            #define WIN32_LEAN_AND_MEAN
        #endif // WIN32_LEAN_AND_MEAN
        #ifndef NOMINMAX
            #define NOMINMAX
        #endif // NOMINMAX
        #if NT_WINDOWS_NT6
            #define NT_WINNT 0x0600
        #else // (NOT) NT_WINDOWS_NT6
            #define NT_WINNT 0x0501
        #endif // NT_WINDOWS_NT6
        #if defined(_WIN32_WINNT)
            #if _WIN32_WINNT < NT_WINNT
                #undef _WIN32_WINNT
                #define _WIN32_WINNT NT_WINNT
            #endif // _WIN32_WINNT < NT_WINNT
        #else // (NOT) defined(_WIN32_WINNT)
            #define _WIN32_WINNT NT_WINNT
        #endif // defined(_WIN32_WINNT)
    #endif // defined(NT_BUILD)
#elif defined(__ANDROID__)
    // <android/ndk-version.h> was added with NDK 16, safeguard
	#if !__has_include(<android/ndk-version.h>)
        #error Nazara requires a more recent Android NDK version, please update Android NDK!
    #endif // !__has_include(<android/ndk-version.h>)
    #include <android/ndk-version.h>
	#define NT_PLATFORM_MOBILE
	#define NT_PLATFORM_ANDROID
	#define NT_PLATFORM_POSIX
	#define NT_PLATFORM_ANDROID_NDK_VER __NDK_MAJOR__
	#define NT_CHECK_NDK_VER(ver) (NT_PLATFORM_ANDROID_NDK_VER >= ver)
	#define NT_EXPORT __attribute__((visibility("default")))
	#define NT_IMPORT __attribute__((visibility("default")))
#elif defined(__linux__)
	#define NT_PLATFORM_DESKTOP
	#define NT_PLATFORM_LINUX
	#define NT_PLATFORM_POSIX
	#define NT_EXPORT __attribute__((visibility("default")))
	#define NT_IMPORT __attribute__((visibility("default")))
    #elif defined(__FreeBSD__)
	#define NT_PLATFORM_BSD
	#define NT_PLATFORM_FREEBSD
	#define NT_PLATFORM_POSIX
	#define NT_EXPORT __attribute__((visibility("default")))
	#define NT_IMPORT __attribute__((visibility("default")))
#elif defined(__APPLE__)
	#include <TargetConditionals.h>
	#if TARGET_OS_IPHONE
		#define NT_PLATFORM_MOBILE
		#define NT_PLATFORM_IOS
	#else // (NOT) TARGET_OS_IPHONE
		#define NT_PLATFORM_DESKTOP
		#define NT_PLATFORM_MACOS
	#endif // TARGET_OS_IPHONE
	#define NT_PLATFORM_BSD
	#define NT_PLATFORM_POSIX
	#define NT_EXPORT __attribute__((visibility("default")))
	#define NT_IMPORT __attribute__((visibility("default")))
#elif defined(__EMSCRIPTEN__)
	#define NT_PLATFORM_WEB
	#define NT_PLATFORM_POSIX
	#define NT_EXPORT __attribute__((visibility("default")))
	#define NT_IMPORT __attribute__((visibility("default")))
#else // (NOT) defined(_WIN32), defined(__ANDROID__), defined(__linux__), defined(__FreeBSD__), defined(__APPLE__), defined(__EMSCRIPTEN__)
	#pragma message "This operating system is not fully supported by Nautilus Engine!"
	#define NT_PLATFORM_UNKNOWN
	#define NT_EXPORT
	#define NT_IMPORT
#endif // defined(_WIN32), defined(__ANDROID__), defined(__linux__), defined(__FreeBSD__), defined(__APPLE__), defined(__EMSCRIPTEN__)

#ifndef NT_CHECK_NDK_VER
    #define NT_CHECK_NDK_VER(ver) 0
#endif // NT_CHECK_NDK_VER

// Feauture checking
#if __cpp_has_attribute
    #define NT_HAS_CPP_ATTRIBUTE(attr) __has_cpp_attribute(attr)
#else // (NOT) __cpp_has_attribute
    #define NT_HAS_CPP_ATTRIBUTE(attr) (0)
#endif // __cpp_has_attribute

// Assumption attribute
#ifndef NT_NO_ASSUME_ATTRIBUTE
    #if NT_CHECK_CPP_VER(NT_CPP23) || NT_HAS_CPP_ATTRIBUTE(assume)
        #define NT_ASSUME(expr) [[assume(expr)]]
    #endif // NT_CHECK_CPP_VER(NT_CPP23) || NT_HAS_CPP_ATTRIBUTE(assume)
    #ifndef NT_ASSUME
        #if defined(NT_COMPILER_CLANG)
            #define NT_ASSUME(expr) __builtin_assume(expr)
        #endif // defined(NT_COMPILER_CLANG)
        #if defined(NT_COMPILER_GCC)
            #if (__GNUC__ >= 13) // __attribute__(assume) is supported starting with GCC 13
                #define NT_ASSUME(expr) __attribute__(assume(expr))
            #endif // (__GNUC__ >= 13)
        #endif // defined(NT_COMPILER_GCC)
        #if defined(NT_COMPILER_MSVC)
            #define NT_ASSUME(expr) __assume(expr)
        #endif // defined(NT_COMPILER_MSVC)
    #endif // NT_ASSUME
#endif // NT_NO_ASSUME_ATTRIBUTE

// Force inline attribute
#ifndef NT_NO_FORCEINLINE_ATTRIBUTE
    #ifndef NT_FORCEINLINE
        #if defined(NT_COMPILER_CLANG) || defined(NT_COMPILER_GCC)
            #define NT_FORCEINLINE __attribute__((always_inline)) inline
        #endif // defined(NT_COMPILER_CLANG) || defined(NT_COMPILER_GCC)
        #if defined(NT_COMPILER_MSVC)
            #define NT_FORCEINLINE __forceinline
        #endif // defined(NT_COMPILER_MSVC)
    #endif // NT_FORCEINLINE
#endif // NT_NO_FORCEINLINE_ATTRIBUTE

// (Un)likely attributes
#ifndef NT_NO_LIKELY_ATTRIBUTE
    #if NT_CHECK_CPP_VER(NT_CPP20) || NT_HAS_CPP_ATTRIBUTE(likely)
        #define NT_LIKELY(expr) (expr) [[likely]]
    #endif // NT_CHECK_CPP_VER(NT_CPP20) || NT_HAS_CPP_ATTRIBUTE(likely)
    #if NT_CHECK_CPP_VER(NT_CPP20) || NT_HAS_CPP_ATTRIBUTE(unlikely)
        #define NT_UNLIKELY(expr) (expr) [[unlikely]]
    #endif // NT_CHECK_CPP_VER(NT_CPP20) || NT_HAS_CPP_ATTRIBUTE(unlikely)
    #if defined(NT_COMPILER_CLANG) || defined(NT_COMPILER_GCC) || defined(NT_COMPILER_ICC)
        #ifndef NT_LIKELY
            #define NT_LIKELY(expr) (__builtin_expect(!!(expr), 1))
        #endif // NT_LIKELY
        #ifndef NT_UNLIKELY
            #define NT_UNLIKELY(expr) (__builtin_expect(!!(expr), 0))
        #endif // NT_UNLIKELY
    #endif // defined(NT_COMPILER_CLANG) || defined(NT_COMPILER_GCC) || defined(NT_COMPILER_ICC)
#endif // NT_NO_LIKELY_ATTRIBUTE

// Unreachable macro
#ifndef NT_NO_UNREACHABLE_MACRO
    #if defined(NT_COMPILER_CLANG) || defined(NT_COMPILER_GCC) || defined(NT_COMPILER_ICC)
        #define NT_UNREACHABLE() __builtin_unreachable()
    #elif defined(NT_COMPILER_MSVC)
        #define NT_UNREACHABLE() __assume(false)
    #else // (NOT) defined(NT_COMPILER_CLANG) || defined(NT_COMPILER_GCC) || defined(NT_COMPILER_ICC), defined(NT_COMPILER_MSVC)
        #define NT_UNREACHABLE() (0)
    #endif // defined(NT_COMPILER_CLANG) || defined(NT_COMPILER_GCC) || defined(NT_COMPILER_ICC), defined(NT_COMPILER_MSVC)
#endif // NT_NO_UNREACHABLE_MACRO

// Fallbacks
#ifndef NT_ASSUME
	#define NT_ASSUME(expr)
#endif // NT_ASSUME
#ifndef NT_FORCEINLINE
	#define NT_FORCEINLINE inline
#endif // NT_FORCEINLINE
#ifndef NT_LIKELY
	#define NT_LIKELY(expr) (expr)
#endif // NT_LIKELY
#ifndef NT_UNLIKELY
	#define NT_UNLIKELY(expr) (expr)
#endif // NT_UNLIKELY
#ifndef NT_UNREACHABLE
	#define NT_UNREACHABLE() throw Nz::UnreachableError{};
#endif // NT_UNREACHABLE

// CPU Architecture detection
#ifndef NT_NO_CPU_ARCHITECTURE_DETECTED
    #if defined(__arm__) || defined(__thumb__) || defined(__ARM_ARCH_7__) || defined(_M_ARM)
        #define NT_ARCH_ARM
    #endif // defined(__arm__) || defined(__thumb__) || defined(__ARM_ARCH_7__) || defined(_M_ARM)
    #if defined(__aarch64__) || defined(_M_ARM64) || defined(_M_ARM64EC) || defined(__arm64__)
        #define NT_ARCH_AARCH64
    #endif // defined(__aarch64__) || defined(_M_ARM64) || defined(_M_ARM64EC) || defined(__arm64__)
    #if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_AMD64) || defined (_M_X64)
        #define NT_ARCH_X86_64
    #endif // defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_AMD64) || defined (_M_X64)
    #if defined(__i386__) || defined(_M_IX86) || defined(_X86_)
        #define NT_ARCH_X86
    #endif // defined(__i386__) || defined(_M_IX86) || defined(_X86_)
    #if defined(__wasm32__)
        #define NT_ARCH_WASM32
    #endif // defined(__wasm32__)
    #if defined(__wasm64__)
        #define NT_ARCH_WASM64
    #endif // defined(__wasm64__)
    #if defined(NT_ARCH_ARM)      \
	  + defined(NT_ARCH_AARCHh64) \
	  + defined(NT_ARCH_X86_64)   \
	  + defined(NT_ARCH_X86)      \
	  + defined(NT_ARCH_WASM32)   \
	  + defined(NT_ARCH_WASM64)   \
    != 1
	    #error No or multiple CPU architectures detected! Please open an issue with details about your target system. You can define NT_NO_CPU_ARCHITECTURE_DETECTED to bypass this error!
	#endif /* defined(NT_ARCH_ARM)    \
            + defined(NT_ARCH_AARCHh64) \
            + defined(NT_ARCH_X86_64  ) \
            + defined(NT_ARCH_X86)    \
            + defined(NT_ARCH_WASM32)  \
            + defined(NT_ARCH_WASM64)  \
          != 1 */
#endif // NT_NO_CPU_ARCHITECTURE_DETECTED

#ifdef NT_UNITY_ID
	#define NT_ANONYMOUS_NAMESPACE NT_UNITY_ID
	#define NT_USE_ANONYMOUS_NAMESPACE using namespace NT_UNITY_ID;
	#define NT_ANONYMOUS_NAMESPACE_PREFIX(a) NT_UNITY_ID::a
#else // (NOT) NT_UNITY_ID
	#define NT_ANONYMOUS_NAMESPACE
	#define NT_USE_ANONYMOUS_NAMESPACE
	#define NT_ANONYMOUS_NAMESPACE_PREFIX(a) a
#endif // NT_UNITY_ID

// Misc. macros
#define NT_PREFIX(a, prefix) prefix ## a
#define NT_PREFIX_MACRO(a, prefix) NT_PREFIX(a, prefix)
#define NT_SUFFIX(a, suffix) a ## suffix
#define NT_SUFFIX_MACRO(a, suffix) NT_SUFFIX(a, suffix)
#define NT_STRINGIFY(s) #s
#define NT_STRINGIFY_MACRO(s) NT_STRINGIFY(s) // http://gcc.gnu.org/onlinedocs/cpp/Stringification.html#Stringification
#define NT_UNUSED(a) (void) a

#endif // _NT_CORE_CONFIG_h_
