//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#ifndef _NT_CORE_LOGGER_cpp_
    #define _NT_CORE_LOGGER_cpp_

#include "Logger.h"

#include <iostream>
#include <iomanip>
#include <ctime>
#include <time.h>

namespace nt
{
    Logger::Logger() : 
        m_currentLevel(LogLevel::NT_TRACE)
    {}

    Logger::~Logger()
    {
        if(m_logFile.is_open())
            m_logFile.close();
    }

    void Logger::setLogLevel(LogLevel level)
    {
        m_currentLevel = level;
    }

    void Logger::enableFileLogging(const std::string& filename)
    {
        m_logFile.open(filename, std::ios::out | std::ios::app);
    }
        
    void Logger::trace(const std::string& message)
    {
        log(LogLevel::NT_TRACE, message);
    }

    void Logger::debug(const std::string& message)
    {
        log(LogLevel::NT_DEBUG, message);
    }

    void Logger::info(const std::string& message)
    {
        log(LogLevel::NT_INFO, message);
    }

    void Logger::warn(const std::string& message)
    {
        log(LogLevel::NT_WARN, message);
    }

    void Logger::error(const std::string& message)
    {
        log(LogLevel::NT_ERROR, message);
    }

    void Logger::critical(const std::string& message)
    {
        log(LogLevel::NT_CRITICAL, message);
    }

    void Logger::log(LogLevel level, const std::string& message)
    {
        if (level < m_currentLevel || m_currentLevel == LogLevel::NT_OFF)
            return;

        std::lock_guard<std::mutex> lock(m_logMutex);

        time_t now = time(0);
        char* dt = ctime(&now);
        tm *gmtm = gmtime(&now);
        dt = asctime(gmtm);
        std::string timeStr(dt);
        timeStr.erase(timeStr.find('\n'));
        std::string logEntry = levelToEffects(level) + "[" + timeStr + "][" + levelToString(level) + "] " + message + "\033[0m";

        std::cout << logEntry << std::endl;
        if (m_logFile.is_open())
            m_logFile << logEntry << std::endl;
    }

    std::string Logger::levelToString(LogLevel level)
    {
        switch (level)
        {
            case LogLevel::NT_TRACE:    return "TRACE";
            case LogLevel::NT_DEBUG:    return "DEBUG";
            case LogLevel::NT_INFO:     return "INFO";
            case LogLevel::NT_WARN:     return "WARN";
            case LogLevel::NT_ERROR:    return "ERROR";
            case LogLevel::NT_CRITICAL: return "CRITICAL";
            case LogLevel::NT_OFF:      return "OFF";
            default:                    return "UNKNOWN";
        }
    }

    std::string Logger::levelToEffects(LogLevel level)
    {
        switch (level)
        {
            case LogLevel::NT_TRACE:    return "\033[90m"; // Gray text
            case LogLevel::NT_DEBUG:    return "\033[34m"; // Blue text
            case LogLevel::NT_INFO:     return "\033[32m"; // Green text
            case LogLevel::NT_WARN:     return "\033[33m"; // Yellow text
            case LogLevel::NT_ERROR:    return "\033[31m"; // Red text
            case LogLevel::NT_CRITICAL: return "\033[41m"; // Red background
            case LogLevel::NT_OFF:      return "\033[0m";  // Reset
            default:                    return "\033[0m";  // Reset
        }
    }
}

#endif // _NT_CORE_LOGGER_cpp_