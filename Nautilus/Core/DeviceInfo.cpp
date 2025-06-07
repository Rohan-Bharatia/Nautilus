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
        uint32 DeviceInfo::GetSIMDAlignment(void)
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

        bool DeviceInfo::HasAltiVec(void)
        {
    #if defined(__VEC__) || defined(__ALTIVEC__)
        return true;
    #else // (NOT) defined(__VEC__), defined(__ALTIVEC__)
            return false;
    #endif // defined(__VEC__), defined(__ALTIVEC__)
        }

        bool DeviceInfo::HasMMX(void)
        {
            return CheckX86Feature(3, 23);
        }

        bool DeviceInfo::HasSSE(void)
        {
            return CheckX86Feature(3, 25);
        }

        bool DeviceInfo::HasSSE2(void)
        {
            return CheckX86Feature(3, 26);
        }

        bool DeviceInfo::HasSSE3(void)
        {
            return CheckX86Feature(2, 0);
        }

        bool DeviceInfo::HasSSE41(void)
        {
            return CheckX86Feature(2, 19);
        }

        bool DeviceInfo::HasSSE42(void)
        {
            return CheckX86Feature(2, 20);
        }

        bool DeviceInfo::HasAVX(void)
        {
            int32 info[4]           = { 0 };
            CPUID(info, 1);
            bool osUsesXSaveXRStore = (info[2] & (1 << 27)) != 0;
            bool avxSupported       = (info[2] & (1 << 28)) != 0;
            return osUsesXSaveXRStore && avxSupported;
        }

        bool DeviceInfo::HasAVX2(void)
        {
            int32 info[4] = { 0 };
            CPUID(info, 7);
            return (info[1] & (1 << 5)) != 0;
        }

        bool DeviceInfo::HasAVX512(void)
        {
            int32 info[4] = { 0 };
            CPUID(info, 7);
            return (info[1] & (1 << 16)) != 0;
        }

        bool DeviceInfo::HasARMSIMD(void)
        {
        #if defined(__ARM_NEON) || defined(__ARM_FEATURE_SIMD32)
            return true;
        #else // (NOT) defined(__ARM_NEON), defined(__ARM_FEATURE_SIMD32)
            return false;
        #endif // defined(__ARM_NEON), defined(__ARM_FEATURE_SIMD32)
        }

        bool DeviceInfo::HasNEON(void)
        {
        #if defined(__ARM_NEON) || defined(__ARM_NEON__)
            return true;
        #else // (NOT) defined(__ARM_NEON), defined(__ARM_NEON__)
            return false;
        #endif // defined(__ARM_NEON), defined(__ARM_NEON__)
        }

        bool DeviceInfo::HasLSX(void)
        {
        #if defined(__loongarch__) && defined(__loongarch_sx)
            return true;
        #else // (NOT) defined(__loongarch__), defined(__loongarch_sx)
            return false;
        #endif // defined(__loongarch__), defined(__loongarch_sx__)
        }

        bool DeviceInfo::HasLASX(void)
        {
        #if defined(__loongarch__) && defined(__loongarch_asx)
            return true;
        #else // (NOT) defined(__loongarch__), defined(__loongarch_asx)
            return false;
        #endif // defined(__loongarch__), defined(__loongarch_asx__)
        }

        void DeviceInfo::CPUID(int32 info[4], uint32 id)
        {
        #ifndef NT_PLATFORM_WASM
            #if defined(NT_PLATFORM_WINDOWS)
                __cpuid((int*)info, id);
            #elif defined(NT_COMPILER_GCC) || defined(NT_COMPILER_CLANG)
                __cpuid(id, info[0], info[1], info[2], info[3]);
            #endif // defined(NT_PLATFORM_WINDOWS), defined(NT_COMPILER_GCC) || defined(NT_COMPILER_CLANG)
        #endif // NT_PLATFORM_WASM
        }

        bool DeviceInfo::CheckX86Feature(uint32 reg, uint32 bit)
        {
            int32 info[4] = { 0 };
            CPUID(info, 1);
            return (info[reg] & (1 << bit)) != 0;
        }
} // namespace Nt

#endif // _CORE_DEVICE_INFO_CPP_
