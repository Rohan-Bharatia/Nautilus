#pragma region LICENSE

//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2025 Rohan Bharatia

#pragma endregion LICENSE

#ifndef _NT_CORE_TIMER_cpp_
    #define _NT_CORE_TIMER_cpp_

#include "Timer.h"

#include <thread>

namespace nt
{
    void Timer::start()
    {
        if (!m_isRunning)
        {
            m_startTime = std::chrono::steady_clock::now();
            m_isRunning = true;
        }
    }

    void Timer::stop()
    {
        if (m_isRunning)
        {
            m_isRunning = false;
        }
    }

    bool Timer::isRunning()
    {
        return m_isRunning;
    }

    uint32 Timer::getElapsedTime()
    {
        auto currentTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - m_startTime);
        return static_cast<uint32>(elapsedTime.count());
    }

    void Timer::sleep(uint32 ms)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }
}

#endif // _NT_CORE_TIMER_cpp_
