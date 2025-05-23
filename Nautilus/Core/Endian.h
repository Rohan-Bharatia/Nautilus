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

#ifndef _CORE_ENDIAN_H_
    #define _CORE_ENDIAN_H_

#include "PCH.h"

#define NT_LITTLE_ENDIAN 1234
#define NT_BIG_ENDIAN 4321

#ifndef NT_BYTE_ORDER
    #if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        #define NT_BYTE_ORDER NT_LITTLE_ENDIAN
    #elif defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        #define NT_BYTE_ORDER NT_BIG_ENDIAN
    #else // (NOT) defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__, defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        #error "Unknown byte order!"
    #endif // defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__, defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#endif // NT_BYTE_ORDER
#ifndef NT_FLOAT_WORD_ORDER
    #if defined(__FLOAT_WORD_ORDER__) && __FLOAT_WORD_ORDER__ == __ORDER_LITTLE_ENDIAN__
        #define NT_FLOAT_WORD_ORDER NT_LITTLE_ENDIAN
    #elif defined(__FLOAT_WORD_ORDER__) && __FLOAT_WORD_ORDER__ == __ORDER_BIG_ENDIAN__
        #define NT_FLOAT_WORD_ORDER NT_BIG_ENDIAN
    #else // (NOT) defined(__FLOAT_WORD_ORDER__) && __FLOAT_WORD_ORDER__ == __ORDER_LITTLE_ENDIAN__, defined(__FLOAT_WORD_ORDER__) && __FLOAT_WORD_ORDER__ == __ORDER_BIG_ENDIAN__
        #error "Unknown float word order!"
    #endif // defined(__FLOAT_WORD_ORDER__) && __FLOAT_WORD_ORDER__ == __ORDER_LITTLE_ENDIAN__, defined(__FLOAT_WORD_ORDER__) && __FLOAT_WORD_ORDER__ == __ORDER_BIG_ENDIAN__
#endif // NT_FLOAT_WORD_ORDER

#if NT_BYTE_ORDER == NT_LITTLE_ENDIAN
    #define NT_SWAP16(x) (((x) >>  8) | ((x) << 8))
    #define NT_SWAP32(x) (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24))
    #define NT_SWAP64(x) (((x) >> 56) | (((x) & 0x00FF000000000000) >> 40) | (((x) & 0x0000FF0000000000) >> 24) | (((x) & 0x000000FF00000000) << 8) | (((x) & 0x00000000FF000000) << 24) | (((x) & 0x0000000000FF0000) << 40) | ((x) << 56))
#elif NT_BYTE_ORDER == NT_BIG_ENDIAN
    #define NT_SWAP16(x) (x)
    #define NT_SWAP32(x) (x)
    #define NT_SWAP64(x) (x)
#endif // NT_BYTE_ORDER == NT_LITTLE_ENDIAN, NT_BYTE_ORDER == NT_BIG_ENDIAN

#endif // _CORE_ENDIAN_H_
