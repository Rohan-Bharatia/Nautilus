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

#ifndef _CORE_DEVICE_INFO_CPP_
    #define _CORE_DEVICE_INFO_CPP_

#include "DeviceInfo.h"

namespace Nt
{
        uint32 CPUInfo::GetLogicalCoreCount(void)
        {
        #if defined(NT_PLATFORM_WINDOWS)
            SYSTEM_INFO sysInfo;
            GetSystemInfo(&sysInfo);
            return NT_STATIC_CAST(uint32, sysInfo.dwNumberOfProcessors);
        #elif defined(NT_PLATFORM_LINUX)
            return NT_STATIC_CAST(uint32, sysconf(_SC_NPROCESSORS_ONLN));
        #elif defined(NT_PLATFORM_MACOS)
            return NT_STATIC_CAST(uint32, sysconf(_SC_NPROCESSORS_ONLN));
        #elif defined(NT_PLATFORM_ANDROID)
            return NT_STATIC_CAST(uint32, sysconf(_SC_NPROCESSORS_ONLN));
        #elif defined(NT_PLATFORM_WASM)
            return EM_ASM_INT({ return navigator.hardwareConcurrency || 1; });
        #endif // defined(NT_PLATFORM_WINDOWS), defined(NT_PLATFORM_LINUX), defined(NT_PLATFORM_MACOS), defined(NT_PLATFORM_ANDROID), defined(NT_PLATFORM_WASM)
        }

        uint32 CPUInfo::GetCacheLineSize(void)
        {
        #if defined(NT_PLATFORM_WINDOWS)
            DWORD bufferSize                             = 0;
            DWORD i                                      = 0;
            SYSTEM_LOGICAL_PROCESSOR_INFORMATION* buffer = nullptr;

            GetLogicalProcessorInformation(nullptr, &bufferSize);
            buffer = (SYSTEM_LOGICAL_PROCESSOR_INFORMATION *)malloc(bufferSize);
            GetLogicalProcessorInformation(buffer, &bufferSize);

            for (i = 0; i < bufferSize / sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION); ++i)
            {
                if (buffer[i].Relationship == RelationCache && buffer[i].Cache.Level == 1)
                {
                    uint32 lineSize = buffer[i].Cache.LineSize;
                    NT_SAFE_DELETE(buffer);
                    return lineSize;
                }
            }

            NT_SAFE_DELETE(buffer);
            return 64;
        #elif defined(NT_PLATFORM_LINUX)
            std::ifstream cacheInfo("/sys/devices/system/cpu/cpu0/cache/index0/coherency_line_size");
            uint32 lineSize = 64;
            if (cacheInfo.is_open())
            {
                cacheInfo >> lineSize;
            }
            return lineSize;
        #elif defined(NT_PLATFORM_MACOS) || defined(NT_PLATFORM_IOS)
            uint32 lineSize;
            size_t size = sizeof(lineSize);
            sysctlbyname("hw.cachelinesize", &lineSize, &size, 0, 0);
            return lineSize;
        #elif defined(NT_PLATFORM_ANDROID)
            return 64; // Default cache line size for Android
        #elif defined(NT_PLATFORM_WASM)
            return 64; // WebAssembly does not have access to cache line size
        #endif // defined(NT_PLATFORM_WINDOWS), defined(NT_PLATFORM_LINUX), defined(NT_PLATFORM_MACOS), defined(NT_PLATFORM_ANDROID), defined(NT_PLATFORM_WASM)
        }

        uint32 CPUInfo::GetSystemRAM(void)
        {
        #if defined(NT_PLATFORM_WINDOWS)
            MEMORYSTATUSEX status;
            status.dwLength = sizeof(status);
            GlobalMemoryStatusEx(&status);
            return NT_STATIC_CAST(uint32, status.ullTotalPhys / (1024 * 1024));
        #elif defined(NT_PLATFORM_LINUX)
            long pages = sysconf(_SC_PHYS_PAGES);
            long page_size = sysconf(_SC_PAGE_SIZE);
            return NT_STATIC_CAST(uint32, (pages * page_size) / (1024 * 1024));
        #elif defined(NT_PLATFORM_MACOS) || defined(NT_PLATFORM_IOS)
            int64_t memSize;
            size_t size = sizeof(memSize);
            sysctlbyname("hw.memsize", &memSize, &size, 0, 0);
            return NT_STATIC_CAST(uint32, memSize / (1024 * 1024));
        #elif defined(NT_PLATFORM_ANDROID)
            struct sysinfo info;
            sysinfo(&info);
            return NT_STATIC_CAST(uint32, (info.totalram * info.mem_unit) / (1024 * 1024));
        #elif defined(NT_PLATFORM_WASM)
            return 64; // WebAssembly does not have access to system RAM size
        #endif // defined(NT_PLATFORM_WINDOWS), defined(NT_PLATFORM_LINUX), defined(NT_PLATFORM_MACOS), defined(NT_PLATFORM_ANDROID), defined(NT_PLATFORM_WASM)
        }

        uint32 CPUInfo::GetSIMDAlignment(void)
        {
        #if defined(__AVX512F__)
            return 64;
        #elif defined(__AVX__)
            return 32;
        #elif defined(__SSE__)
            return 16;
        #else // (NOT) defined(__AVX512F__), defined(__AVX__), defined(__SSE__)
            return 8;
        #endif // defined(__AVX512F__), defined(__AVX__), defined(__SSE__)
        }

        bool CPUInfo::HasAltiVec(void)
        {
    #if defined(__VEC__) || defined(__ALTIVEC__)
        return true;
    #else // (NOT) defined(__VEC__), defined(__ALTIVEC__)
            return false;
    #endif // defined(__VEC__), defined(__ALTIVEC__)
        }

        bool CPUInfo::HasMMX(void)
        {
            return CheckX86Feature(3, 23);
        }

        bool CPUInfo::HasSSE(void)
        {
            return CheckX86Feature(3, 25);
        }

        bool CPUInfo::HasSSE2(void)
        {
            return CheckX86Feature(3, 26);
        }

        bool CPUInfo::HasSSE3(void)
        {
            return CheckX86Feature(2, 0);
        }

        bool CPUInfo::HasSSE41(void)
        {
            return CheckX86Feature(2, 19);
        }

        bool CPUInfo::HasSSE42(void)
        {
            return CheckX86Feature(2, 20);
        }

        bool CPUInfo::HasAVX(void)
        {
            int32 info[4]           = { 0 };
            CPUID(info, 1);
            bool osUsesXSaveXRStore = (info[2] & (1 << 27)) != 0;
            bool avxSupported       = (info[2] & (1 << 28)) != 0;
            return osUsesXSaveXRStore && avxSupported;
        }

        bool CPUInfo::HasAVX2(void)
        {
            int32 info[4] = { 0 };
            CPUID(info, 7);
            return (info[1] & (1 << 5)) != 0;
        }

        bool CPUInfo::HasAVX512(void)
        {
            int32 info[4] = { 0 };
            CPUID(info, 7);
            return (info[1] & (1 << 16)) != 0;
        }

        bool CPUInfo::HasARMSIMD(void)
        {
        #if defined(__ARM_NEON) || defined(__ARM_FEATURE_SIMD32)
            return true;
        #else // (NOT) defined(__ARM_NEON), defined(__ARM_FEATURE_SIMD32)
            return false;
        #endif // defined(__ARM_NEON), defined(__ARM_FEATURE_SIMD32)
        }

        bool CPUInfo::HasNEON(void)
        {
        #if defined(__ARM_NEON) || defined(__ARM_NEON__)
            return true;
        #else // (NOT) defined(__ARM_NEON), defined(__ARM_NEON__)
            return false;
        #endif // defined(__ARM_NEON), defined(__ARM_NEON__)
        }

        bool CPUInfo::HasLSX(void)
        {
        #if defined(__loongarch__) && defined(__loongarch_sx)
            return true;
        #else // (NOT) defined(__loongarch__), defined(__loongarch_sx)
            return false;
        #endif // defined(__loongarch__), defined(__loongarch_sx__)
        }

        bool CPUInfo::HasLASX(void)
        {
        #if defined(__loongarch__) && defined(__loongarch_asx)
            return true;
        #else // (NOT) defined(__loongarch__), defined(__loongarch_asx)
            return false;
        #endif // defined(__loongarch__), defined(__loongarch_asx__)
        }

        void CPUInfo::CPUID(int32 info[4], uint32 id)
        {
        #ifndef NT_PLATFORM_WASM
            #if defined(NT_PLATFORM_WINDOWS)
                __cpuid((int*)info, id);
            #elif defined(NT_COMPILER_GCC) || defined(NT_COMPILER_CLANG)
                __cpuid(id, info[0], info[1], info[2], info[3]);
            #endif // defined(NT_PLATFORM_WINDOWS), defined(NT_COMPILER_GCC) || defined(NT_COMPILER_CLANG)
        #endif // NT_PLATFORM_WASM
        }

        bool CPUInfo::CheckX86Feature(uint32 reg, uint32 bit)
        {
            int32 info[4] = { 0 };
            CPUID(info, 1);
            return (info[reg] & (1 << bit)) != 0;
        }
} // namespace Nt

#endif // _CORE_DEVICE_INFO_CPP_
