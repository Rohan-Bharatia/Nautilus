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

#ifndef _CORE_LINUX_BATTERY_CPP_
    #define _CORE_LINUX_BATTERY_CPP_

#include "../DeviceInfo.h"

#include "../Filesystem.h"

namespace Nt
{
    uint32 DeviceInfo::GetLogicalCoreCount(void)
    {
        return NT_STATIC_CAST(uint32, sysconf(_SC_NPROCESSORS_ONLN));
    }

    uint32 DeviceInfo::GetCacheLineSize(void)
    {
        Filesystem fs("");
        
        std::string cacheInfo = fs.Read("/sys/devices/system/cpu/cpu0/cache/index0/coherency_line_size");
        uint32 lineSize       = 64;

        int32 level	      = std::stoi(cacheInfo);

        return lineSize;
    }

    uint32 DeviceInfo::GetSystemRAM(void)
    {
        uint32 pages    = sysconf(_SC_PHYS_PAGES);
        uint32 pageSize = sysconf(_SC_PAGE_SIZE);
        return NT_STATIC_CAST(uint32, (pages * pageSize) / (1024 * 1024));
    }

    float32 DeviceInfo::GetAvailableDiskSpace(void)
    {
        struct statfs stats;
        statfs("/", &stats);
        return NT_STATIC_CAST(float32, stats.f_blocks * stats.f_bsize);
    }

    float32 DeviceInfo::GetBatteryLevel(void)
    {
        Filesystem fs("");

        std::string contents = fs.Read("/sys/class/power_supply/BAT0/capacity");
        int32 level          = level = contents.empty() ? -1.0f : std::stoi(contents);

        return NT_STATIC_CAST(float32, level);
    }
} // namespace Nt

#endif // _CORE_LINUX_BATTERY_CPP_
