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

#ifndef _CORE_TIMER_H_
    #define _CORE_TIMER_H_

#include "PCH.h"

namespace Nt
{
    class NT_API Timer
    {
    public:
        NT_CLASS_DEFAULTS(Timer)
        Timer(void);
        ~Timer(void);

        void Start(void);
        void Stop(void);
        void Reset(void);

        float64 GetElapsedMillis(void);
        float64 GetElapsedSeconds(void);

        static std::string GetDate(void);
        static std::string GetTime(void);
        static std::string GetDateTime(void);

        static void Sleep(uint32 ms);

    private:
        std::chrono::high_resolution_clock::time_point m_startTime;
        std::chrono::high_resolution_clock::time_point m_endTime;
        bool m_isRunning;
    };
} // namespace Nt

#endif // _CORE_TIMER_H_
