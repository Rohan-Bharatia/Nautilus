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

#ifndef _NT_CORE_POINTER_INL_
    #define _NT_CORE_POINTER_INL_

#include "Pointer.h"

namespace Nt
{
    template<typename T, typename... Args>
    Scope<T> CreateScope(Args&&... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T, typename... Args>
    Ref<T> CreateRef(Args&&... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    T* Buffer::As(void)
    {
        return NT_STATIC_CAST(T*, m_data);
    }

    template<typename T>
    T* ScopedBuffer::As(void)
    {
        return m_buffer.As<T>();
    }
} // namespace Nt

#endif // _NT_CORE_POINTER_INL_
