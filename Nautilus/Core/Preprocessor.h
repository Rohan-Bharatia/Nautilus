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

// Disable '#pragma once' for the python CMake platform generator
// #pragma once

#ifndef _CORE_PREPROCESSOR_H_
    #define _CORE_PREPROCESSOR_H_

// C++ standard version detection
#ifdef _MSC_VER
    #define NT_CPP_VERSION _MSVC_LANG
#else // (NOT) _MSC_VER
    #define NT_CPP_VERSION __cplusplus
#endif // _MSC_VER
#define NT_CPP98 199711L
#define NT_CPP11 201103L
#define NT_CPP14 201402L
#define NT_CPP17 201703L
#define NT_CPP20 202002L
#define NT_CPP23 202302L
#define NT_CHECK_CPP_VERSION(version) (NT_CPP_VERSION >= version)
// #if !NT_CHECK_CPP_VERSION(NT_CPP17)
//     #error Nautilus Engine requires C++17 or higher!
// #endif // !NT_CHECK_CPP_VERSION(NT_CPP17)

// Compiler detection
#if defined(__clang__)
    #define NT_COMPILER_CLANG
    #define NT_COMPILER_VERSION (__clang_major__ * 100 + __clang_minor__)
    #define NT_CHECK_COMPILER_VERSION(version) (NT_CLANG_VERSION >= version)
    #define NT_DEPRECATED(msg) __attribute__((__deprecated__(msg)))
    #define NT_PRETTY_FUNCTION __PRETTY_FUNCTION__
    #define NT_PRAGMA(x) _Pragma(#x)
    #define NT_WARNING_DISABLE(warn) NT_PRAGMA(clang diagnostic ignored warn)
    #define NT_WARNING_POP() NT_PRAGMA(clang diagnostic pop)
    #define NT_WARNING_PUSH() NT_PRAGMA(clang diagnostic push)
    #define NT_UNUSED __attribute__((unused))
    #define NT_INLINE __attribute__((always_inline)) inline
    #define NT_NORETURN __attribute__((noreturn))
    #define NT_ANALYZER_NORETURN __attribute__((analyzer_noreturn))
    #define NT_FALLTHROUGH __attribute__((fallthrough))
    #define NT_NODISCARD __attribute__((warn_unused_result))
    #define NT_MALLOC __attribute__((malloc))
    #define NT_ALLOC_SIZE(ptr) __attribute__((alloc_size(1)))
    #define NT_ALLOC_SIZE2(ptr1, ptr2) __attribute__((alloc_size(1, 2)))
    #ifdef __MINGW32__
		#define NT_COMPILER_MINGW
		#ifdef __MINGW64_VERSION_MAJOR
			#define NT_COMPILER_MINGW_W64
		#endif // __MINGW64_VERSION_MAJOR
	#endif // __MINGW32__
#elif defined(__GNUC__) || defined(__MINGW32__)
    #define NT_COMPILER_GCC
    #define NT_COMPILER_VERSION (__GNUC__ * 100 + __GNUC_MINOR__)
    #define NT_CHECK_COMPILER_VERSION(version) (NT_GCC_VERSION >= version)
    #define NT_DEPRECATED(msg) __attribute__((__deprecated__(msg)))
    #define NT_PRETTY_FUNCTION __PRETTY_FUNCTION__
    #define NT_PRAGMA(x) _Pragma(#x)
    #define NT_WARNING_DISABLE(warn) NT_PRAGMA(GCC diagnostic ignored warn)
    #define NT_WARNING_POP() NT_PRAGMA(GCC diagnostic pop)
    #define NT_WARNING_PUSH() NT_PRAGMA(GCC diagnostic push)
    #define NT_UNUSED __attribute__((unused))
    #define NT_INLINE __attribute__((always_inline)) inline
    #define NT_NORETURN __attribute__((noreturn))
    #define NT_ANALYZER_NORETURN __attribute__((analyzer_noreturn))
    #define NT_FALLTHROUGH __attribute__((fallthrough))
    #define NT_NODISCARD __attribute__((warn_unused_result))
    #define NT_MALLOC __attribute__((malloc))
    #define NT_ALLOC_SIZE(ptr) __attribute__((alloc_size(1)))
    #define NT_ALLOC_SIZE2(ptr1, ptr2) __attribute__((alloc_size(1, 2)))
    #ifdef __MINGW32__
		#define NT_COMPILER_MINGW
		#ifdef __MINGW64_VERSION_MAJOR
			#define NT_COMPILER_MINGW_W64
		#endif // __MINGW64_VERSION_MAJOR
	#endif // __MINGW32__
#elif defined(__INTEL_COMPILER) || defined(__ICL)
    #define NT_COMPILER_INTEL
    #define NT_COMPILER_VERSION (__INTEL_COMPILER)
    #define NT_CHECK_COMPILER_VERSION(version) (NT_INTEL_VERSION >= version)
    #define NT_DEPRECATED(msg) [[deprecated(msg)]]
    #define NT_PRETTY_FUNCTION __FUNCTION__
    #define NT_PRAGMA(x) _Pragma(#x)
    #define NT_WARNING_DISABLE(warn) NT_PRAGMA(warning(disable : warn))
    #define NT_WARNING_POP() NT_PRAGMA(warning(pop))
    #define NT_WARNING_PUSH() NT_PRAGMA(warning(push))
    #define NT_UNUSED
    #define NT_INLINE inline
    #define NT_NORETURN __declspec(noreturn)
    #define NT_ANALYZER_NORETURN
    #define NT_FALLTHROUGH
    #define NT_NODISCARD
    #define NT_MALLOC
    #define NT_ALLOC_SIZE(ptr)
    #define NT_ALLOC_SIZE2(ptr1, ptr2)
#elif defined(_MSC_VER)
    #define NT_COMPILER_MSVC
    #define NT_COMPILER_VERSION (_MSC_VER)
    #define NT_CHECK_COMPILER_VERSION(version) (NT_MSVC_VERSION >= version)
    #define NT_DEPRECATED(msg) __declspec(deprecated(msg))
    #define NT_PRETTY_FUNCTION __FUNCSIG__
    #define NT_PRAGMA(x) __pragma(x)
    #define NT_WARNING_DISABLE(warn) NT_PRAGMA(warning(disable : warn))
    #define NT_WARNING_POP() NT_PRAGMA(warning(pop))
    #define NT_WARNING_PUSH() NT_PRAGMA(warning(push))
    #define NT_UNUSED
    #define NT_INLINE __forceinline
    #define NT_NORETURN __declspec(noreturn)
    #define NT_ANALYZER_NORETURN
    #define NT_FALLTHROUGH
    #define NT_NODISCARD
    #define NT_MALLOC
    #define NT_ALLOC_SIZE(ptr)
    #define NT_ALLOC_SIZE2(ptr1, ptr2)
#elif defined(__BORLANDC__)
    #define NT_COMPILER_BORLAND
    #define NT_COMPILER_VERSION (__BORLANDC__)
    #define NT_CHECK_COMPILER_VERSION(version) (NT_BORLAND_VERSION >= version)
    #define NT_DEPRECATED(msg) __declspec(deprecated(msg))
    #define NT_PRETTY_FUNCTION __FUNC__
    #define NT_PRAGMA(x) _Pragma(#x)
    #define NT_WARNING_DISABLE(warn) NT_PRAGMA(warning(disable : warn))
    #define NT_WARNING_POP() NT_PRAGMA(warning(pop))
    #define NT_WARNING_PUSH() NT_PRAGMA(warning(push))
    #define NT_UNUSED
    #define NT_INLINE __inline
    #define NT_NORETURN __declspec(noreturn)
    #define NT_ANALYZER_NORETURN
    #define NT_FALLTHROUGH
    #define NT_NODISCARD
    #define NT_MALLOC
    #define NT_ALLOC_SIZE(ptr)
    #define NT_ALLOC_SIZE2(ptr1, ptr2)
#elif defined(__MWERKS__)
    #define NT_COMPILER_METROWERKS
    #define NT_COMPILER_VERSION (__MWERKS__)
    #define NT_CHECK_COMPILER_VERSION(version) (NT_METROWERKS_VERSION >= version)
    #define NT_DEPRECATED(msg) __declspec(deprecated(msg))
    #define NT_PRETTY_FUNCTION __FUNC__
    #define NT_PRAGMA(x) _Pragma(#x)
    #define NT_WARNING_DISABLE(warn) NT_PRAGMA(warning(disable : warn))
    #define NT_WARNING_POP() NT_PRAGMA(warning(pop))
    #define NT_WARNING_PUSH() NT_PRAGMA(warning(push))
    #define NT_UNUSED
    #define NT_INLINE __inline
    #define NT_NORETURN __declspec(noreturn)
    #define NT_ANALYZER_NORETURN
    #define NT_FALLTHROUGH
    #define NT_NODISCARD
    #define NT_MALLOC
    #define NT_ALLOC_SIZE(ptr)
    #define NT_ALLOC_SIZE2(ptr1, ptr2)
#else // (NOT) defined(__clang__), defined(__GNUC__) || defined(__MINGW32__), defined(__INTEL_COMPILER) || defined(__ICL), defined(_MSC_VER), defined(__BORLANDC__), defined(__MWERKS__)
    #define NT_COMPILER_UNKNOWN
    #define NT_COMPILER_VERSION 0
    #define NT_CHECK_COMPILER_VERSION(version) false
    #define NT_DEPRECATED(msg)
    #define NT_PRETTY_FUNCTION
    #define NT_PRAGMA(x)
    #define NT_WARNING_DISABLE(warn)
    #define NT_WARNING_POP()
    #define NT_WARNING_PUSH()
    #define NT_UNUSED
    #define NT_INLINE
    #define NT_NORETURN
    #define NT_ANALYZER_NORETURN
    #define NT_FALLTHROUGH
    #define NT_NODISCARD
    #define NT_MALLOC
    #define NT_ALLOC_SIZE(ptr)
    #define NT_ALLOC_SIZE2(ptr1, ptr2)
    #error Nautilus Engine does not support this compiler!
#endif // defined(__clang__), defined(__GNUC__) || defined(__MINGW32__), defined(__INTEL_COMPILER) || defined(__ICL), defined(_MSC_VER), defined(__BORLANDC__), defined(__MWERKS__)

#ifdef NT_COMPILER_MINGW
	#if defined(__USING_MCFGTHREAD__)
		#define NT_COMPILER_MINGW_THREADS_MCF
	#elif defined(_REENTRANT)
		#define NT_COMPILER_MINGW_THREADS_POSIX
	#else // (NOT) defined(__USING_MCFGTHREAD__), defined(_REENTRANT)
		#define NT_COMPILER_MINGW_THREADS_WIN32
	#endif // defined(__USING_MCFGTHREAD__), defined(_REENTRANT)
#endif // NT_COMPILER_MINGW

// Platform detection
#if defined(_WIN32) || defined(_WIN64)
    #ifndef WIN32_LEAN_AND_MEAN
        #define WIN32_LEAN_AND_MEAN
    #endif // WIN32_LEAN_AND_MEAN
    #ifndef NOMINMAX
        #define NOMINMAX
    #endif // NOMINMAX
    #ifndef UNICODE
        #define UNICODE
    #endif // UNICODE
    #include <winapifamily.h>
    #if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        #define NT_PLATFORM_WINDOWS
        #define NT_DEVICE_DESKTOP
        #define NT_EXPORT __declspec(dllexport)
        #define NT_IMPORT __declspec(dllimport)
    #else // (NOT) WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        #define NT_PLATFORM_UNKNOWN
        #define NT_DEVICE_UNKNOWN
        #define NT_EXPORT
        #define NT_IMPORT
        #error Nautilus Engine does not support this Microsoft platform!
    #endif // WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#elif defined(__APPLE__)
    #include <TargetConditionals.h>
    #if TARGET_OS_MAC
        #define NT_PLATFORM_MACOS
        #define NT_DEVICE_DESKTOP
        #define NT_EXPORT __attribute__((__visibility__("default")))
        #define NT_IMPORT __attribute__((__visibility__("default")))
    #elif TARGET_OS_IPHONE
        #define NT_PLATFORM_IOS
        #define NT_DEVICE_MOBILE
        #define NT_EXPORT __attribute__((__visibility__("default")))
        #define NT_IMPORT __attribute__((__visibility__("default")))
    #else // (NOT) TARGET_OS_MAC, TARGET_OS_IPHONE
        #define NT_PLATFORM_UNKNOWN
        #define NT_DEVICE_UNKNOWN
        #define NT_EXPORT
        #define NT_IMPORT
        #error Nautilus Engine does not support this Apple platform!
    #endif // TARGET_OS_MAC, TARGET_OS_IPHONE
#elif defined(__ANDROID__)
    #if !__has_include(<android/ndk-version.h>)
        #error Nautilus Engine requires a more recent Android NDK version, please update!
    #endif
    #define NT_PLATFORM_ANDROID
    #define NT_DEVICE_MOBILE
    #define NT_EXPORT __attribute__((__visibility__("default")))
    #define NT_IMPORT __attribute__((__visibility__("default")))
#elif defined(__EMSCRIPTEN__)
    #define NT_PLATFORM_WASM
    #define NT_DEVICE_BROWSER
    #define NT_EXPORT __attribute__((__visibility__("default")))
    #define NT_IMPORT __attribute__((__visibility__("default")))
#elif defined(__unix__) // Do linux last so that it doesn't catch other platforms
    #define NT_PLATFORM_LINUX
    #define NT_DEVICE_DESKTOP
    #define NT_EXPORT __attribute__((__visibility__("default")))
    #define NT_IMPORT __attribute__((__visibility__("default")))
#else // (NOT) defined(_WIN32) || defined(_WIN64), defined(__APPLE__), defined(__ANDROID__), defined(__EMSCRIPTEN__), defined(__unix__)
    #define NT_PLATFORM_UNKNOWN
    #define NT_DEVICE_UNKNOWN
    #define NT_EXPORT
    #define NT_IMPORT
    #error Nautilus Engine does not support this platform!
#endif // defined(_WIN32) || defined(_WIN64), defined(__APPLE__), defined(__ANDROID__), defined(__EMSCRIPTEN__), defined(__unix__)

// Nautilus API macro
#ifdef NT_STATIC
    #define NT_API static
#else // (NOT) NT_STATIC
    #ifndef NT_LINKED_LIB
        #define NT_API NT_EXPORT
    #else // (NOT) NT_LINKED_LIB
        #define NT_API NT_IMPORT
    #endif // NT_LINKED_LIB
#endif // NT_STATIC

// Build modes
#if defined(_DEBUG) || defined(DEBUG)
    #define NT_DEBUG
#else // (NOT) defined(_DEBUG) || defined(DEBUG)
    #define NT_RELEASE
#endif // defined(_DEBUG) || defined(DEBUG)

// Miscellaneous macros
#define __NT_PREFIX__(a, prefix) prefix##a
#define NT_PREFIX(a, prefix) __NT_PREFIX__(a, prefix)
#define __NT_SUFFIX__(a, suffix) a##suffix
#define NT_SUFFIX(a, suffix) __NT_SUFFIX__(a, suffix)
#define __NT_CONCAT__(a, b) a##b
#define NT_CONCAT(a, b) __NT_CONCAT__(a, b)
#define __NT_STRINGIFY__(x) #x
#define NT_STRINGIFY(x) __NT_STRINGIFY__(x)
#define NT_EXPAND(x) x
#define NT_DISCARD(x) (void)x
#define NT_CLEAR(x) memset(&x, 0, sizeof(x))
#define NT_ARRAY_COUNT(x) (sizeof(x) / sizeof(x[0]))
#define NT_SAFE_DELETE(ptr) free(ptr); delete ptr; ptr = nullptr
#define NT_SAFE_DELETE_ARRAY(ptr) free(ptr); delete[] ptr; ptr = nullptr
#define NT_CLASS_DEFAULTS(classname)                  \
    classname(const classname&)            = default; \
    classname(classname&&)                 = default; \
    classname& operator=(const classname&) = default; \
    classname& operator=(classname&&)      = default; \

// C++ primitive types
namespace Nt
{
    using int8    = signed char;
    using int16   = signed short;
    using int32   = signed long;
    using int64   = signed long long;
    using uint8   = unsigned char;
    using byte    = unsigned char;
    using uint16  = unsigned short;
    using uint32  = unsigned long;
    using opsize  = unsigned long;
    using uint64  = unsigned long long;
    using float32 = float;
    using float64 = double;
} // namespace Nt

// Type casting macros
#ifdef NT_CPP_VERSION
    #define NT_STATIC_CAST(type, value) static_cast<type>(value)
    #define NT_REINTERPRET_CAST(type, value) reinterpret_cast<type>(value)
    #define NT_CONST_CAST(type, value) const_cast<type>(value)
    #define NT_DYNAMIC_CAST(type, value) dynamic_cast<type>(value)
#else // (NOT) NT_CPP_VERSION
    #define NT_STATIC_CAST(type, value) (type)(value)
    #define NT_REINTERPRET_CAST(type, value) (type)(value)
    #define NT_CONST_CAST(type, value) (type)(value)
    #define NT_DYNAMIC_CAST(type, value) (type)(value)
#endif // NT_CPP_VERSION

// Min/max macros
#define NT_INT8_MIN NT_STATIC_CAST(signed char, ~0x7F)
#define NT_INT8_MAX NT_STATIC_CAST(signed char, 0x7F)
#define NT_INT8_EPSILON NT_STATIC_CAST(signed char, 1)
#define NT_INT16_MIN NT_STATIC_CAST(signed short, ~0x7FFF)
#define NT_INT16_MAX NT_STATIC_CAST(signed short, 0x7FFF)
#define NT_INT16_EPSILON NT_STATIC_CAST(signed short, 1)
#define NT_INT32_MIN NT_STATIC_CAST(signed long, ~0x7FFFFFFF)
#define NT_INT32_MAX NT_STATIC_CAST(signed long, 0x7FFFFFFF)
#define NT_INT32_EPSILON NT_STATIC_CAST(signed long, 1)
#define NT_INT64_MIN NT_STATIC_CAST(signed long long, ~0x7FFFFFFFFFFFFFFF)
#define NT_INT64_MAX NT_STATIC_CAST(signed long long, 0x7FFFFFFFFFFFFFFF)
#define NT_INT64_EPSILON NT_STATIC_CAST(signed long long, 1)
#define NT_UINT8_MIN NT_STATIC_CAST(unsigned char, 0)
#define NT_UINT8_MAX NT_STATIC_CAST(unsigned char, 0xFF)
#define NT_UINT8_EPSILON NT_STATIC_CAST(unsigned char, 1)
#define NT_UINT16_MIN NT_STATIC_CAST(unsigned short, 0)
#define NT_UINT16_MAX NT_STATIC_CAST(unsigned short, 0xFFFF)
#define NT_UINT16_EPSILON NT_STATIC_CAST(unsigned short, 1)
#define NT_UINT32_MIN NT_STATIC_CAST(unsigned long, 0)
#define NT_UINT32_MAX NT_STATIC_CAST(unsigned long, 0xFFFFFFFF)
#define NT_UINT32_EPSILON NT_STATIC_CAST(unsigned long, 1)
#define NT_UINT64_MIN NT_STATIC_CAST(unsigned long long, 0)
#define NT_UINT64_MAX NT_STATIC_CAST(unsigned long long, 0xFFFFFFFFFFFFFFFF)
#define NT_UINT64_EPSILON NT_STATIC_CAST(unsigned long long, 1)
#define NT_FLOAT32_MIN NT_STATIC_CAST(float, 1.175494351e-38F)
#define NT_FLOAT32_MAX NT_STATIC_CAST(float, 3.402823466e+38F)
#define NT_FLOAT32_EPSILON NT_STATIC_CAST(float, 1.192092896e-07F)
#define NT_FLOAT64_MIN NT_STATIC_CAST(double, 2.2250738585072014e-308)
#define NT_FLOAT64_MAX NT_STATIC_CAST(double, 1.7976931348623158e+308)
#define NT_FLOAT64_EPSILON NT_STATIC_CAST(double, 2.2204460492503131e-16)

#endif // _CORE_PREPROCESSOR_H_
