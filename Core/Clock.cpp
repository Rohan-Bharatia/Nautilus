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

#ifndef _NT_CORE_CLOCK_CPP_
    #define _NT_CORE_CLOCK_CPP_

#include "Clock.h"

namespace nt
{
    void Clock::start()
    {
        m_isRunning = true;
        m_startTime = std::chrono::high_resolution_clock::now();
    }

    void Clock::stop()
    {
        m_isRunning = false;
        m_endTime = std::chrono::high_resolution_clock::now();
    }

    double Clock::getElapsedTime()
    {
        if (m_isRunning)
            return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - m_startTime).count() / 1000.0;
        else
            return std::chrono::duration_cast<std::chrono::milliseconds>(m_endTime - m_startTime).count() / 1000.0;
    }
} // namespace nt

#endif // _NT_CORE_CLOCK_CPP_
