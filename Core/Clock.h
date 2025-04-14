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

#ifndef _NT_CORE_CLOCK_H_
    #define _NT_CORE_CLOCK_H_

#include "Platform/Platform.h"

#include <chrono>

namespace nt
{
    class NT_API Clock
    {
    public:
        void start();
        void stop();
        double getElapsedTime();

    private:
        std::chrono::high_resolution_clock::time_point m_startTime;
        std::chrono::high_resolution_clock::time_point m_endTime;
        bool m_isRunning = false;
    };
} // namespace nt

#endif // _NT_CORE_CLOCK_H_
