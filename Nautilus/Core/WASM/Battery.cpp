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

#ifndef _CORE_WASM_BATTERY_CPP_
    #define _CORE_WASM_BATTERY_CPP_

#include "../DeviceInfo.h"

namespace Nt
{
    float32 GetBatteryLevel(void)
    {
        float32 batteryLevel = -1.0f;

        EM_JS(void, getBatteryLevel, (),
        {
            navigator.getBattery().then(function(battery)
            {
                batteryLevel = NT_STATIC_CAST(float32, battery.level);
            });
        });

        return batteryLevel;
    }
} // namespace Nt

#endif // _CORE_WASM_BATTERY_CPP_
