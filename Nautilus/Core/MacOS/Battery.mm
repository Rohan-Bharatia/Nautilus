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
        int cur, maxcap;

        [CFNumberGetValue:level, kCFNumberIntType, &cur];
        [CFNumberGetValue:max, kCFNumberIntType, &maxcap];

        [CFRelease:list];
        [CFRelease:info];

        return (maxcap > 0) ? cur / maxcap : -1.0f;
    }
} // namespace Nt
