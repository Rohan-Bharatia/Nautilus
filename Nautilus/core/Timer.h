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

#pragma once

#ifndef _NT_CORE_TIMER_h_
    #define _NT_CORE_TIMER_h_

#include "Types.h"

#include <chrono>

namespace nt
{
    class Timer
    {
    public:
        void start();
        void stop();
        bool isRunning();
        uint32 getElapsedTime();

        static void sleep(uint32 ms);

    private:
        std::chrono::steady_clock::time_point m_startTime;
        bool m_isRunning = false;
    };
}

#endif // _NT_CORE_TIMER_h_
