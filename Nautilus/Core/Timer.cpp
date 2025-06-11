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

#ifndef _CORE_TIMER_CPP_
    #define _CORE_TIMER_CPP_

#include "Timer.h"

namespace Nt
{
    Timer::Timer(void)
    {
        m_startTime = std::chrono::high_resolution_clock::now();
        m_endTime   = std::chrono::high_resolution_clock::now();
        m_isRunning = false;
    }

    Timer::~Timer(void)
    {
        m_startTime = std::chrono::high_resolution_clock::now();
        m_endTime   = std::chrono::high_resolution_clock::now();
        m_isRunning = false;
    }

    void Timer::Start(void)
    {
        if (!m_isRunning)
        {
            m_startTime = std::chrono::high_resolution_clock::now();
            m_isRunning = true;
        }
    }

    void Timer::Stop(void)
    {
        if (m_isRunning)
        {
            m_endTime   = std::chrono::high_resolution_clock::now();
            m_isRunning = false;
        }
    }

    void Timer::Reset(void)
    {
        m_startTime = std::chrono::high_resolution_clock::time_point();
        m_endTime   = std::chrono::high_resolution_clock::time_point();
        m_isRunning = false;
    }

    float64 Timer::GetElapsedMillis(void)
    {
        if (m_isRunning)
            m_endTime = std::chrono::high_resolution_clock::now();

        std::chrono::duration<float64, std::milli> elapsedTime = m_endTime - m_startTime;
        return elapsedTime.count();
    }

    float64 Timer::GetElapsedSeconds(void)
    {
        if (m_isRunning)
            m_endTime = std::chrono::high_resolution_clock::now();

        std::chrono::duration<float64> elapsedTime = m_endTime - m_startTime;
        return elapsedTime.count();
    }

    std::string Timer::GetDate(void)
    {
        std::time_t now    = std::time(nullptr);
        std::tm* localTime = std::localtime(&now);
        char timeBuffer[20];
        std::strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d", localTime);
        return std::string(timeBuffer);
    }

    std::string Timer::GetTime(void)
    {
        std::time_t now    = std::time(nullptr);
        std::tm* localTime = std::localtime(&now);
        char timeBuffer[20];
        std::strftime(timeBuffer, sizeof(timeBuffer), "%H:%M:%S", localTime);
        return std::string(timeBuffer);
    }

    std::string Timer::GetDateTime(void)
    {
        std::time_t now    = std::time(nullptr);
        std::tm* localTime = std::localtime(&now);
        char timeBuffer[20];
        std::strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", localTime);
        return std::string(timeBuffer);
    }

    void Timer::Sleep(uint32 ms)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }
} // namespace Nt

#endif // _CORE_TIMER_CPP_
