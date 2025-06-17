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
    Scope<T> CreateScope(Args&&... args);

    template<typename T>
    using Ref = std::shared_ptr<T>;

    template<typename T, typename... Args>
    Ref<T> CreateRef(Args&&... args);

    class NT_API Buffer
    {
    public:
        NT_CLASS_DEFAULTS(Buffer)
        Buffer(void);
        Buffer(uint64 size);

        static Buffer Copy(Buffer other);

        void Allocate(uint64 size);
        void Release(void);

        template<typename T>
        T* As(void);

        operator bool(void) const;

        uint8* GetData(void) const;
        uint64 GetSize(void) const;

    private:
        uint8* m_data;
        uint64 m_size;
    };

    class NT_API ScopedBuffer
    {
    public:
        NT_CLASS_DEFAULTS(ScopedBuffer)
        ScopedBuffer(Buffer buffer);
        ScopedBuffer(uint64 size);
        ~ScopedBuffer(void);

        template<typename T>
        T* As(void);

        operator bool(void) const;

        uint8* GetData(void) const;
        uint64 GetSize(void) const;

    private:
        Buffer m_buffer;
    };
} // namespace Nt

#include "Pointer.inl"

#endif // _NT_CORE_POINTER_H_
