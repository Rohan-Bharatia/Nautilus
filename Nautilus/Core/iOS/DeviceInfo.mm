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
        size_t size = sizeof(lineSize);
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
        NSProcessInfo* info = [NSProcessInfo processInfo];
        return NT_STATIC_CAST(float32, [info physicalMemory]);
    }

    float32 DeviceInfo::GetBatteryLevel(void)
    {
        [UIDevice currentDevice].batteryMonitoringEnabled = YES;
        float32 level                                     = [UIDevice currentDevice].batteryLevel;
        return (level < 0.0f) ? -1.0f : level * 100.0f;
    }
} // namespace Nt
