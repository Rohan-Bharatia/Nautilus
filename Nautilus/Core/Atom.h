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

#ifndef _CORE_ATOM_H_
    #define _CORE_ATOM_H_

#include "PCH.h"

namespace Nt
{
    template<typename T>
    class NT_API Atomic
    {
    public:
        NT_CLASS_DEFAULTS(Atomic)
        Atomic(const T& value);

        T operator=(const T& value);
        operator T() const;

        T Load(void) const;
        T LoadAcquire(void) const;
        T LoadRelaxed(void) const;
        void Store(const T& value);
        void StoreRelease(const T& value);
        T Exchange(const T& value);
        T ExchangeWithCAS(T expected, T desired);
        T TestAndSet(T value);
        bool CompareExchangeWeak(T& expected, const T& value);
        bool CompareExchangeStrong(T& expected, const T& value);
        void Wait(T expected) const;
        void NotifyOne(void);
        void NotifyAll(void);
        T FetchADD(T value);
        T FetchSUB(T value);
        T FetchAND(T value);
        T FetchOR(T value);
        T FetchXOR(T value);
        bool IsLocked(void) const;

    private:
        std::atomic<T> m_value;
        std::mutex m_mutex;
        mutable std::condition_variable m_condition;
        mutable bool m_isLocked;
    };
} // namespace Nt

#include "Atom.inl"

#endif // _CORE_ATOM_H_
