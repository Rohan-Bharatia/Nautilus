//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                                 ...
//
//                  Copyright (c) Rohan Bharatia 2025

#import "../DeviceInfo.h"

namespace Nt
{
    uint32 DeviceInfo::GetLogicalCoreCount(void)
    {
        return NT_STATIC_CAST(uint32, [sysconf:_SC_NPROCESSORS_ONLN]);
    }

    uint32 DeviceInfo::GetCacheLineSize(void)
    {
        uint32 lineSize;
        opsize size = sizeof(lineSize);
        [sysctlbyname:["hw.cachelinesize", &lineSize, &size, 0, 0]];
        return lineSize;
    }

    uint32 DeviceInfo::GetSystemRAM(void)
    {
        int64 memSize;
        opsize size = sizeof(memSize);
        [sysctlbyname:["hw.memsize", &memSize, &size, 0, 0]];
        return NT_STATIC_CAST(uint32, memSize / (1024 * 1024));
    }

    float32 DeviceInfo::GetAvailableDiskSpace(void)
    {
        struct statfs stats;
        [statvfs:["/", &stats]];
        return NT_STATIC_CAST(float32, stats.f_blocks * stats.f_bsize);
    }

    float32 DeviceInfo::GetBatteryLevel(void)
    {
        CFTypeRef info  = [IOPSCopyPowerSourceInfo];
        CFArrayRef list = [IOPSCopyPowerSourcesList:info];

        if ([CFArrayGetCount:list] == 0)
            return -1;

        CFDictionaryRef battery = [IOPSGetPowerSourceDescription:info
            powerSource:[CFArrayGetValueAtIndex:list, 0]];

        if (!battery)
            return -1;

        CFNumberRef level = NT_STATIC_CAST(CFNumberRef, [CFDictionaryGetValue:battery, CFSTR(kIOPSCurrentCapacityKey)]);
        CFNumberRef max   = NT_STATIC_CAST(CFNumberRef, [CFDictionaryGetValue:battery, CFSTR(kIOPSMaxCapacityKey)]);
        uint32 cur, maxcap;

        [CFNumberGetValue:level, kCFNumberIntType, &cur];
        [CFNumberGetValue:max, kCFNumberIntType, &maxcap];

        [CFRelease:list];
        [CFRelease:info];

        return (maxcap > 0) ? (cur / maxcap) * 100 : -1.0f;
    }
} // namespace Nt
