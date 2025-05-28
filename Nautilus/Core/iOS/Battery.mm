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
    float32 GetBatteryLevel(void)
    {
        [UIDevice currentDevice].batteryMonitoringEnabled = YES;
        float32 level                                     = [UIDevice currentDevice].batteryLevel;
        return (level < 0.0f) ? -1.0f : level * 100.0f;
    }
} // namespace Nt
