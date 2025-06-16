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

#ifndef _NT_CORE_POINTER_CPP_
    #define _NT_CORE_POINTER_CPP_

#include "Pointer.h"

namespace Nt
{
    Buffer::Buffer(void) :
        m_data(nullptr), m_size(0)
    {}

    Buffer::Buffer(uint64 size)
    {
        Allocate(size);
    }

    Buffer Buffer::Copy(Buffer other)
    {
        Buffer result(other.GetSize());
        memcpy(result.m_data, other.m_data, other.m_size);
        return result;
    }

    void Buffer::Allocate(uint64 size)
    {
        Release();
        m_data = new uint8[size];
        m_size = size;
    }

    void Buffer::Release(void)
    {
        NT_SAFE_DELETE_ARRAY(m_data);
        m_size = 0;
    }

    Buffer::operator bool(void) const
    {
        return NT_STATIC_CAST(bool, m_data);
    }

    uint8* Buffer::GetData(void) const
    {
        return m_data;
    }

    uint64 Buffer::GetSize(void) const
    {
        return m_size;
    }

    ScopedBuffer::ScopedBuffer(Buffer buffer) :
        m_buffer(buffer)
    {}

    ScopedBuffer::ScopedBuffer(uint64 size) :
        m_buffer(size)
    {}

    ScopedBuffer::~ScopedBuffer(void)
    {
        m_buffer.Release();
    }

    ScopedBuffer::operator bool(void) const
    {
        return NT_STATIC_CAST(bool, m_buffer);
    }

    uint8* ScopedBuffer::GetData(void) const
    {
        return m_buffer.GetData();
    }

    uint64 ScopedBuffer::GetSize(void) const
    {
        return m_buffer.GetSize();
    }
} // namespace Nt

#endif // _NT_CORE_POINTER_CPP_
