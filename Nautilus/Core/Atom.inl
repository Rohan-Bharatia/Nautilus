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

#ifndef _CORE_ATOM_INL_
    #define _CORE_ATOM_INL_

#include "Atom.h"

namespace Nt
{
    template<typename T>
    T Atomic<T>::operator=(const T& value)
    {
        m_value.store(value, std::memory_order_seq_cst);
        return value;
    }

    template<typename T>
    Atomic<T>::operator T() const
    {
        return m_value.load(std::memory_order_seq_cst);
    }
} // namespace Nt

#endif // _CORE_ATOM_INL_
