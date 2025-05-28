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

namespace Nt
{
    float32 GetBatteryLevel(void)
    {
        std::ifstream file("/sys/class/power_supply/BAT0/capacity");
        int level = -1;

        if (file.is_open())
        {
            file >> level;
            file.close();
        }

        return NT_STATIC_CAST(float32, level);
    }
} // namespace Nt

#endif // _CORE_LINUX_BATTERY_CPP_
