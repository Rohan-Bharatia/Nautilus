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

#ifndef _NT_CORE_UID_CPP_
    #define _NT_CORE_UID_CPP_

#include "PCH.h"

namespace Nt
{
    Guid::Guid(void) :
        m_bytes()
    {}

    Guid::Guid(std::array<uint8, 16>& bytes) :
        m_bytes(bytes)
    {}

    Guid Guid::FromString(const std::string& str)
    {
        std::array<uint8_t, 16> bytes{};
        sscanf(str.c_str(), "%2hhx%2hhx%2hhx%2hhx-%2hhx%2hhx-%2hhx%2hhx-%2hhx%2hhx-%2hhx%2hhx%2hhx%2hhx%2hhx%2hhx",
            &bytes[0], &bytes[1], &bytes[2], &bytes[3], &bytes[4], &bytes[5], &bytes[6], &bytes[7],
            &bytes[8], &bytes[9], &bytes[10], &bytes[11], &bytes[12], &bytes[13], &bytes[14], &bytes[15]
        );
        return Guid(bytes);
    }

    std::string Guid::ToString(void) const
    {
        std::ostringstream oss;
        oss << std::hex << std::setfill('0');
        for (opsize i = 0; i < 16; ++i)
        {
            oss << std::setw(2) << NT_STATIC_CAST(int32, m_bytes[i]);
            if (i == 3 || i == 5 || i == 7 || i == 9)
                oss << "-";
        }
        return oss.str();
    }

    const std::array<uint8, 16>& Guid::GetBytes(void) const
    {
        return m_bytes;
    }

    Uuid::Uuid(void) :
        m_bytes()
    {}

    Uuid::Uuid(std::array<uint8, 16>& bytes) :
        m_bytes(bytes)
    {}

    Uuid Uuid::FromString(const std::string& str)
    {
        std::array<uint8_t, 16> bytes{};
        sscanf(str.c_str(), "%2hhx%2hhx%2hhx%2hhx-%2hhx%2hhx-%2hhx%2hhx-%2hhx%2hhx-%2hhx%2hhx%2hhx%2hhx%2hhx%2hhx",
            &bytes[0], &bytes[1], &bytes[2], &bytes[3], &bytes[4], &bytes[5], &bytes[6], &bytes[7],
            &bytes[8], &bytes[9], &bytes[10], &bytes[11], &bytes[12], &bytes[13], &bytes[14], &bytes[15]
        );
        return Uuid(bytes);
    }

    std::string Uuid::ToString(void) const
    {
        std::ostringstream oss;
        oss << std::hex << std::setfill('0');
        for (opsize i = 0; i < 16; ++i)
        {
            oss << std::setw(2) << NT_STATIC_CAST(int32, m_bytes[i]);
            if (i == 3 || i == 5 || i == 7 || i == 9)
                oss << "-";
        }
        return oss.str();
    }

    const std::array<uint8, 16>& Uuid::GetBytes(void) const
    {
        return m_bytes;
    }
} // namespace Nt

#endif // _NT_CORE_UID_CPP_