//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#pragma once

#ifndef _NT_CORE_TYPES_h_
    #define _NT_CORE_TYPES_h_

#include "Config.h"

namespace nt
{
    using uint    = unsigned int;
    using int8    = char;
    using uint8   = unsigned char;
    using int16   = short;
    using uint16  = unsigned short;
    using int32   = long;
    using uint32  = unsigned long;
    using int64   = long long;
    using uint64  = unsigned long long;
#if defined(__int128)
    using int128  = __int128;
    using uint128 = unsigned __int128;
#endif // defined(__int128)
    using byte    = unsigned char;
    using opsize  = unsigned long long;
} // namespace nt

// Make sure the types are of the correct size
static_assert(__CHAR_BIT__       == 8, "CHAR_BIT is expected to be 8");
static_assert(sizeof(nt::int8)   == 1, "int8_t is not of the correct size" );
static_assert(sizeof(nt::int16)  == 2, "int16_t is not of the correct size");
static_assert(sizeof(nt::int32)  == 4, "int32_t is not of the correct size");
static_assert(sizeof(nt::int64)  == 8, "int64_t is not of the correct size");
static_assert(sizeof(nt::uint8)  == 1, "uint8_t is not of the correct size" );
static_assert(sizeof(nt::uint16) == 2, "uint16_t is not of the correct size");
static_assert(sizeof(nt::uint32) == 4, "uint32_t is not of the correct size");
static_assert(sizeof(nt::uint64) == 8, "uint64_t is not of the correct size");
    
#endif // _NT_CORE_TYPES_h_