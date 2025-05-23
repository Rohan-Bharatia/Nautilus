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
    float32 GetBatteryLevel(void)
    {
        SYSTEM_POWER_STATUS sps;

        if (GetSystemPowerStatus(&sps))
        {
            float32 batteryLevel = NT_STATIC_CAST(float32, sps.BatteryLifePercent);

            if (batteryLevel != 255.0f) // 255 indicates battery unavailable
                return batteryLevel / 100.0f;
            else
                return -1.0f;
        }
        else
            return -1.0f;
    }
} // namespace Nt

#endif // _CORE_WINDOWS_BATTERY_CPP_
