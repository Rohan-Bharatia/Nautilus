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

#ifndef _NT_CORE_POINTER_H_
    #define _NT_CORE_POINTER_H_

#include "PCH.h"

namespace Nt
{
    template<typename T>
    using Scope = std::unique_ptr<T>;

    template<typename T, typename... Args>
    const Scope<T> CreateScope(Args&&... args);

    template<typename T>
    using Ref = std::shared_ptr<T>;

    template<typename T, typename... Args>
    const Ref<T> CreateRef(Args&&... args);
} // namespace Nt

#include "Pointer.inl"

#endif // _NT_CORE_POINTER_H_
