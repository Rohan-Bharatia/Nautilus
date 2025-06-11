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

#ifndef _NT_CORE_UID_H_
    #define _NT_CORE_UID_H_

#include "PCH.h"

namespace Nt
{
    class NT_API Guid
    {
    public:
        NT_CLASS_DEFAULTS(Guid)
        Guid(void);
        Guid(std::array<uint8, 16>& bytes);

        static Guid Generate(void);
        static Guid FromString(const std::string& str);

        std::string ToString(void) const;
        const std::array<uint8, 16>& GetBytes(void) const;

    private:
        std::array<uint8, 16> m_bytes;
    };

    class NT_API Uuid
    {
    public:
        NT_CLASS_DEFAULTS(Uuid)
        Uuid(void);
        Uuid(std::array<uint8, 16>& bytes);

        static Uuid Generate(void);
        static Uuid FromString(const std::string& str);

        std::string ToString(void) const;
        const std::array<uint8, 16>& GetBytes(void) const;

    private:
        std::array<uint8, 16> m_bytes;
    };
} // namespace Nt

#endif // _NT_CORE_UID_H_