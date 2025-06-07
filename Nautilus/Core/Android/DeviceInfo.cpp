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

#ifndef _CORE_ANDROID_BATTERY_CPP_
    #define _CORE_ANDROID_BATTERY_CPP_

#include "../DeviceInfo.h"

namespace Nt
{
    uint32 DeviceInfo::GetLogicalCoreCount(void)
    {
        return NT_STATIC_CAST(uint32, sysconf(_SC_NPROCESSORS_ONLN));
    }

    uint32 DeviceInfo::GetCacheLineSize(void)
    {
        return 64; // Default cache line size for Android
    }

    uint32 DeviceInfo::GetSystemRAM(void)
    {
        struct sysinfo info;
        sysinfo(&info);
        return NT_STATIC_CAST(uint32, (info.totalram * info.mem_unit) / (1024 * 1024));
    }

    float32 DeviceInfo::GetAvailableDiskSpace(void)
    {
        StatFs statFs = new StatFs(Environment.getDataDirectory().getPath());
        return NT_STATIC_CAST(float32, statFs.getBlockCount() * statFs.getBlockSize());
    }

    float32 DeviceInfo::GetBatteryLevel(void)
    {
        BatteryManager bm = (BatteryManager)Context::Get().GetSystemService(Context::BATTERY_SERVICE);

        if (bm == nullptr)
            return -1.0f;

        int32 level = bm->GetIntProperty(BatteryManager::BATTERY_PROPERTY_CAPACITY);

        return level < 0 ? -1.0f : NT_STATIC_CAST(float32, level);
    }
} // namespace Nt

#endif // _CORE_ANDROID_BATTERY_CPP_
