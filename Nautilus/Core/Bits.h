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

#pragma once

#ifndef _CORE_BITS_H_
    #define _CORE_BITS_H_

#include "PCH.h"

// Bit manipulation macros
#define BIT(x) (1 << (x))
#define BIT_MASK(x) ((1 << (x)) - 1)
#define BIT_SET(x, y) ((x) | BIT(y))
#define BIT_CLEAR(x, y) ((x) & ~BIT(y))
#define BIT_TOGGLE(x, y) ((x) ^ BIT(y))
#define BIT_CHECK(x, y) ((x) & BIT(y))
#define BIT_IS_SET(x, y) (((x) & BIT(y)) != 0)
#define BIT_IS_CLEAR(x, y) (((x) & BIT(y)) == 0)
#define BIT_COUNT(x) __builtin_popcount(x)
#define BIT_COUNT8(x) __builtin_popcount((unsigned char)(x))
#define BIT_COUNT16(x) __builtin_popcount((unsigned short)(x))
#define BIT_COUNT32(x) __builtin_popcount((unsigned int)(x))
#define BIT_COUNT64(x) __builtin_popcountll((unsigned long long)(x))

#endif // _CORE_BITS_H_
