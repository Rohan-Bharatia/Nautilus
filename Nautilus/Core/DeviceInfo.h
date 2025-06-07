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

#ifndef _CORE_DEVICE_INFO_H_
    #define _CORE_DEVICE_INFO_H_

#include "PCH.h"

namespace Nt
{
    struct NT_API DeviceInfo
    {
        static uint32 GetSIMDAlignment(void);
        static bool HasAltiVec(void);
        static bool HasMMX(void);
        static bool HasSSE(void);
        static bool HasSSE2(void);
        static bool HasSSE3(void);
        static bool HasSSE41(void);
        static bool HasSSE42(void);
        static bool HasAVX(void);
        static bool HasAVX2(void);
        static bool HasAVX512(void);
        static bool HasARMSIMD(void);
        static bool HasNEON(void);
        static bool HasLSX(void);
        static bool HasLASX(void);

        static uint32 GetLogicalCoreCount(void);
        static uint32 GetCacheLineSize(void);
        static uint32 GetSystemRAM(void);
        static float32 GetAvailableDiskSpace(void);
        static float32 GetBatteryLevel(void);

        static void CPUID(int32 info[4], uint32 id);
        static bool CheckX86Feature(uint32 reg, uint32 bit);
    };
} // namespace Nt

#endif // _CORE_DEVICE_INFO_H_
