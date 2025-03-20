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

#ifndef _NT_CORE_LOGGER_cpp_
    #define _NT_CORE_LOGGER_cpp_

#include "Logger.h"

#include <iostream>
#include <iomanip>
#include <ctime>
#include <time.h>
#include <cstdarg>

namespace
{
    static std::mutex logMutex;
} // namespace
namespace nt
{
    void Logger::log(LogLevel level, const std::string& message, ...)
    {
        std::lock_guard<std::mutex> lock(::logMutex);

        va_list args;
        va_start(args, message);
        char buffer[1024];
        vsnprintf(buffer, sizeof(buffer), message.c_str(), args);

        std::string effects, lvl;

        switch (level)
        {
            case LogLevel::NT_TRACE:    effects = "\033[90m"; break; // Gray text
            case LogLevel::NT_DEBUG:    effects = "\033[34m"; break; // Blue text
            case LogLevel::NT_INFO:     effects = "\033[32m"; break; // Green text
            case LogLevel::NT_WARN:     effects = "\033[33m"; break; // Yellow text
            case LogLevel::NT_ERROR:    effects = "\033[31m"; break; // Red text
            case LogLevel::NT_CRITICAL: effects = "\033[41m"; break; // Red background
            default:                    effects = "\033[0m";  break; // Reset
        }

        switch (level)
        {
            case LogLevel::NT_TRACE:    lvl = "TRACE";    break;
            case LogLevel::NT_DEBUG:    lvl = "DEBUG";    break;
            case LogLevel::NT_INFO:     lvl = "INFO";     break;
            case LogLevel::NT_WARN:     lvl = "WARN";     break;
            case LogLevel::NT_ERROR:    lvl = "ERROR";    break;
            case LogLevel::NT_CRITICAL: lvl = "CRITICAL"; break;
            default:                    lvl = "UNKNOWN";  break;
        }

        time_t now = time(0);
        char* dt = ctime(&now);
        tm *gmtm = gmtime(&now);
        dt = asctime(gmtm);
        std::string timeStr(dt);
        timeStr.erase(timeStr.find('\n'));
        std::string logEntry = effects + "[" + timeStr + "][" + lvl + "] " + buffer + "\033[0m";

        std::cout << logEntry << std::endl;

        va_end(args);
    }

    void Logger::trace(const std::string& message, ...)
    {
        va_list args;
        va_start(args, message);
        char buffer[1024];
        vsnprintf(buffer, sizeof(buffer), message.c_str(), args);

        log(LogLevel::NT_TRACE, buffer);

        va_end(args);
    }

    void Logger::debug(const std::string& message, ...)
    {
        va_list args;
        va_start(args, message);
        char buffer[1024];
        vsnprintf(buffer, sizeof(buffer), message.c_str(), args);

        log(LogLevel::NT_DEBUG, buffer);

        va_end(args);
    }

    void Logger::info(const std::string& message, ...)
    {
        va_list args;
        va_start(args, message);
        char buffer[1024];
        vsnprintf(buffer, sizeof(buffer), message.c_str(), args);

        log(LogLevel::NT_INFO, buffer);

        va_end(args);
    }

    void Logger::warn(const std::string& message, ...)
    {
        va_list args;
        va_start(args, message);
        char buffer[1024];
        vsnprintf(buffer, sizeof(buffer), message.c_str(), args);

        log(LogLevel::NT_WARN, buffer);

        va_end(args);
    }

    void Logger::error(const std::string& message, ...)
    {
        va_list args;
        va_start(args, message);
        char buffer[1024];
        vsnprintf(buffer, sizeof(buffer), message.c_str(), args);

        log(LogLevel::NT_ERROR, buffer);

        va_end(args);
    }

    void Logger::critical(const std::string& message, ...)
    {
        va_list args;
        va_start(args, message);
        char buffer[1024];
        vsnprintf(buffer, sizeof(buffer), message.c_str(), args);

        log(LogLevel::NT_CRITICAL, buffer);

        va_end(args);
    }
}

#endif // _NT_CORE_LOGGER_cpp_
