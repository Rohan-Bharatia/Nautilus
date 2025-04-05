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

#ifndef _NT_CORE_THREADING_CPP_
    #define _NT_CORE_THREADING_CPP_

#include "Threading.h"

#include <chrono>

namespace nt
{
    void Threading::sleep(int ms)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }

    void Threading::yield()
    {
        std::this_thread::yield();
    }

    Mutex::Mutex() :
        m_mutex(std::mutex())
    {}

    Mutex::~Mutex()
    {
        m_mutex.~mutex();
    }

    void Mutex::lock()
    {
        m_mutex.lock();
    }

    void Mutex::unlock()
    {
        m_mutex.unlock();
    }

    Thread::Thread() :
        m_thread(std::thread())
    {}

    Thread::~Thread()
    {
        m_thread.~thread();
    }

    void Thread::start(std::function<void()> func)
    {
        m_thread = std::thread([func, this] { func(); });
    }

    void Thread::join()
    {
        m_thread.join();
    }

    void Thread::detach()
    {
        m_thread.detach();
    }
} // namespace nt

#endif // _NT_CORE_THREADING_CPP_
