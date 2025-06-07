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

#ifndef _CORE_WINDOWS_BATTERY_CPP_
    #define _CORE_WINDOWS_BATTERY_CPP_

#include "../DeviceInfo.h"

namespace Nt
{
    uint32 DeviceInfo::GetLogicalCoreCount(void)
    {
        SYSTEM_INFO sysInfo;
        GetSystemInfo(&sysInfo);
        return NT_STATIC_CAST(uint32, sysInfo.dwNumberOfProcessors);
    }

    uint32 DeviceInfo::GetCacheLineSize(void)
    {
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
    }

    uint32 DeviceInfo::GetSystemRAM(void)
    {
        MEMORYSTATUSEX status;
        status.dwLength = sizeof(status);
        GlobalMemoryStatusEx(&status);
        return NT_STATIC_CAST(uint32, status.ullTotalPhys / (1024 * 1024));
    }

    float32 DeviceInfo::GetAvailableDiskSpace(void)
    {
        ULARGE_INTEGER total, free;
        GetDiskFreeSpaceEx(NULL, NULL, &total, &free);
        return NT_STATIC_CAST(float32, free);
    }
    
    float32 DeviceInfo::GetBatteryLevel(void)
    {
        SYSTEM_POWER_STATUS sps;

        if (GetSystemPowerStatus(&sps))
        {
            float32 batteryLevel = NT_STATIC_CAST(float32, sps.BatteryLifePercent);

            if (batteryLevel != 255.0f) // 255 indicates battery unavailable
                return batteryLevel;
            else
                return -1.0f;
        }
        else
            return -1.0f;
    }
} // namespace Nt

#endif // _CORE_WINDOWS_BATTERY_CPP_
