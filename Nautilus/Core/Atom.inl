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
    Atomic<T>::Atomic(const T& value) :
        m_value(value), m_isLocked(false)
    {}
    
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

    template<typename T>
    T Atomic<T>::Load(void) const
    {
        return m_value.load(std::memory_order_seq_cst);
    }

    template<typename T>
    T Atomic<T>::LoadAcquire(void) const
    {
        return m_value.load(std::memory_order_acquire);
    }

    template<typename T>
    T Atomic<T>::LoadRelaxed(void) const
    {
        return m_value.load(std::memory_order_relaxed);
    }

    template<typename T>
    void Atomic<T>::Store(const T& value)
    {
        m_value.store(value, std::memory_order_seq_cst);
    }

    template<typename T>
    void Atomic<T>::StoreRelease(const T& value)
    {
        m_value.store(value, std::memory_order_release);
    }

    template<typename T>
    T Atomic<T>::Exchange(const T& value)
    {
        return m_value.exchange(value, std::memory_order_seq_cst);
    }

    template<typename T>
    T Atomic<T>::ExchangeWithCAS(T expected, T desired)
    {
        T oldValue = m_value.load(std::memory_order_relaxed);
        while (!m_value.compare_exchange_weak(expected, desired, std::memory_order_release, std::memory_order_relaxed))
        {
            expected = oldValue;
            oldValue = m_value.load(std::memory_order_relaxed);
        }
        return oldValue;
    }

    template<typename T>
    T Atomic<T>::TestAndSet(T value)
    {
        T oldValue = m_value.load(std::memory_order_relaxed);
        while (!m_value.compare_exchange_weak(oldValue, value, std::memory_order_acquire, std::memory_order_relaxed)); // Spin until the value is set
        return oldValue;
    }

    template<typename T>
    bool Atomic<T>::CompareExchangeWeak(T& expected, const T& value)
    {
        T oldValue = m_value.load(std::memory_order_relaxed);
        while (!m_value.compare_exchange_weak(expected, value, std::memory_order_acquire, std::memory_order_relaxed))
        {
            expected = oldValue;
            oldValue = m_value.load(std::memory_order_relaxed);
        }
        return (oldValue == expected);
    }

    template<typename T>
    bool Atomic<T>::CompareExchangeStrong(T& expected, const T& value)
    {
        T oldValue = m_value.load(std::memory_order_relaxed);
        while (!m_value.compare_exchange_strong(expected, value, std::memory_order_acquire, std::memory_order_relaxed))
        {
            expected = oldValue;
            oldValue = m_value.load(std::memory_order_relaxed);
        }
        return (oldValue == expected);
    }

    template<typename T>
    void Atomic<T>::Wait(T expected) const
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_condition.wait(lock, [&] { return m_value.load(std::memory_order_relaxed) != expected; });
        m_isLocked = true;
        m_condition.notify_all();
        m_isLocked = false;
    }

    template<typename T>
    void Atomic<T>::NotifyOne(void)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_condition.notify_one();
        m_isLocked = true;
        m_condition.notify_all();
        m_isLocked = false;
    }

    template<typename T>
    void Atomic<T>::NotifyAll(void)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_condition.notify_all();
        m_isLocked = true;
        m_condition.notify_all();
        m_isLocked = false;
    }

    template<typename T>
    T Atomic<T>::FetchADD(T value)
    {
        T oldValue = m_value.load(std::memory_order_relaxed);
        while (!m_value.compare_exchange_weak(oldValue, oldValue + value, std::memory_order_acquire, std::memory_order_relaxed));
        return oldValue;
    }

    template<typename T>
    T Atomic<T>::FetchSUB(T value)
    {
        T oldValue = m_value.load(std::memory_order_relaxed);
        while (!m_value.compare_exchange_weak(oldValue, oldValue - value, std::memory_order_acquire, std::memory_order_relaxed));
        return oldValue;
    }

    template<typename T>
    T Atomic<T>::FetchAND(T value)
    {
        T oldValue = m_value.load(std::memory_order_relaxed);
        while (!m_value.compare_exchange_weak(oldValue, oldValue & value, std::memory_order_acquire, std::memory_order_relaxed));
        return oldValue;
    }

    template<typename T>
    T Atomic<T>::FetchOR(T value)
    {
        T oldValue = m_value.load(std::memory_order_relaxed);
        while (!m_value.compare_exchange_weak(oldValue, oldValue | value, std::memory_order_acquire, std::memory_order_relaxed));
        return oldValue;
    }

    template<typename T>
    T Atomic<T>::FetchXOR(T value)
    {
        T oldValue = m_value.load(std::memory_order_relaxed);
        while (!m_value.compare_exchange_weak(oldValue, oldValue ^ value, std::memory_order_acquire, std::memory_order_relaxed));
        return oldValue;
    }

    template<typename T>
    bool Atomic<T>::IsLocked(void) const
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_isLocked;
    }
} // namespace Nt

#endif // _CORE_ATOM_INL_
