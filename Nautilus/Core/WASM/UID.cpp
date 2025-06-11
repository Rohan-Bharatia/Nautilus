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

#ifndef _NT_CORE_WASM_UID_CPP_
    #define _NT_CORE_WASM_UID_CPP_

#include "../UID.h"

namespace Nt
{
    Guid Guid::Generate(void)
    {
        std::array<uint8, 16> bytes;
        std::random_device rd;

        for (uint8& b : bytes)
            b = rd();

        // Set UUIDv4 bits
        bytes[6] = (bytes[6] & 0x0F) | 0x40;
        bytes[8] = (bytes[8] & 0x3F) | 0x80;

        return Guid(bytes);
    }

    Uuid Uuid::Generate(void)
    {
        std::array<uint8, 16> bytes;
        std::random_device rd;

        for (uint8& b : bytes)
            b = rd();

        // Set version to 4 --- random UUID
        bytes[6] = (bytes[6] & 0x0F) | 0x40;
        // Set variant to 10xxxxxx
        bytes[8] = (bytes[8] & 0x3F) | 0x80;

        return Uuid(bytes);
    }
} // namespace Nt

#endif // _NT_CORE_WASM_UID_CPP_