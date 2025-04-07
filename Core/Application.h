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

#ifndef _NT_CORE_APPLICATION_H_
    #define _NT_CORE_APPLICATION_H_

#include "Platform/Platform.h"

namespace nt
{
    class NT_API Application
    {
    public:
        virtual void run() = 0;
    };
} // namespace nt

#endif // _NT_CORE_APPLICATION_H_
