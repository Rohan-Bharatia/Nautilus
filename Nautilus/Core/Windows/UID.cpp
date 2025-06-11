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

#ifndef _NT_CORE_WINDOWS_UID_CPP_
    #define _NT_CORE_WINDOWS_UID_CPP_

#include "../UID.h"

namespace Nt
{
    Guid Guid::Generate(void)
    {
        GUID guid;
        CoCreateGuid(&guid);

        std::array<uint8, 16> bytes;
        memcpy(bytes.data(), &guid, bytes.size());
        return Guid(bytes);
    }

    Uuid Uuid::Generate(void)
    {
        UUID uuid;
        UuidCreate(&uuid);

        std::array<uint8, 16> bytes;
        memcpy(bytes.data(), &uuid, bytes.size());
        return Uuid(bytes);
    }
} // namespace Nt

#endif // _NT_CORE_WINDOWS_UID_CPP_