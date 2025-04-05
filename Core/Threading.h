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

#ifndef _NT_CORE_THREADING_H_
    #define _NT_CORE_THREADING_H_

#include "Platform/Platform.h"

#include <thread>
#include <mutex>
#include <functional>

namespace nt
{
    class NT_API Threading
    {
    public:
        static void sleep(int ms);
        static void yield();
    };

    class NT_API Mutex
    {
    public:
        Mutex();
        ~Mutex();

        void lock();
        void unlock();

    private:
        std::mutex m_mutex;
    };

    class NT_API Thread
    {
    public:
        Thread();
        ~Thread();

        void start(std::function<void()> func);
        void join();
        void detach();

    private:
        std::thread m_thread;
    };
} // namespace nt

#endif // _NT_CORE_THREADING_H_
