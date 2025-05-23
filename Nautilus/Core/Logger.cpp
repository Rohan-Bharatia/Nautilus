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

#ifndef _CORE_LOGGER_CPP_
    #define _CORE_LOGGER_CPP_

#include "Logger.h"

#include "Timer.h"

namespace Nt
{
    void Logger::Log(LogLevel level, const std::string& message, ...)
    {
        std::string colorStr, timeStr, levelStr, messageStr;

        // Get the level color and string representation
        switch (level)
        {
            case LogLevel::Trace:
                colorStr = "\x1B[1;36m"; // Cyan
                levelStr = "TRACE";
                break;
            case LogLevel::Debug:
                colorStr = "\x1B[1;34m"; // Blue
                levelStr = "DEBUG";
                break;
            case LogLevel::Info:
                colorStr = "\x1B[1;32m"; // Green
                levelStr = "INFO";
                break;
            case LogLevel::Warn:
                colorStr = "\x1B[1;33m"; // Yellow
                levelStr = "WARN";
                break;
            case LogLevel::Error:
                colorStr = "\x1B[1;31m"; // Red
                levelStr = "ERROR";
                break;
            case LogLevel::Critical:
                colorStr = "\x1B[1;35m"; // Magenta
                levelStr = "CRITICAL";
                break;
            default:
                colorStr = "\x1B[0m"; // Reset
                levelStr = "NONE";
        }

        // Get the current time
        timeStr = Timer::GetDateTime();

        // Format the message
        va_list args;
        va_start(args, message);
        char formattedMessage[1024];
        std::vsnprintf(formattedMessage, sizeof(formattedMessage), message.c_str(), args);
        va_end(args);
        messageStr = std::string(formattedMessage);

        // Print the log message
        std::cout << colorStr << "[" << timeStr << "][" << levelStr << "]:\x1B[0m " << messageStr << std::endl;
    }

    void Logger::Trace(const std::string& message, ...)
    {
        va_list args;
        va_start(args, message);
        char formattedMessage[1024];
        std::vsnprintf(formattedMessage, sizeof(formattedMessage), message.c_str(), args);
        va_end(args);
        Log(LogLevel::Trace, formattedMessage);
    }

    void Logger::Debug(const std::string& message, ...)
    {
        va_list args;
        va_start(args, message);
        char formattedMessage[1024];
        std::vsnprintf(formattedMessage, sizeof(formattedMessage), message.c_str(), args);
        va_end(args);
        Log(LogLevel::Debug, formattedMessage);
    }

    void Logger::Info(const std::string& message, ...)
    {
        va_list args;
        va_start(args, message);
        char formattedMessage[1024];
        std::vsnprintf(formattedMessage, sizeof(formattedMessage), message.c_str(), args);
        va_end(args);
        Log(LogLevel::Info, formattedMessage);
    }

    void Logger::Warn(const std::string& message, ...)
    {
        va_list args;
        va_start(args, message);
        char formattedMessage[1024];
        std::vsnprintf(formattedMessage, sizeof(formattedMessage), message.c_str(), args);
        va_end(args);
        Log(LogLevel::Warn, formattedMessage);
    }

    void Logger::Error(const std::string& message, ...)
    {
        va_list args;
        va_start(args, message);
        char formattedMessage[1024];
        std::vsnprintf(formattedMessage, sizeof(formattedMessage), message.c_str(), args);
        va_end(args);
        Log(LogLevel::Error, formattedMessage);
    }

    void Logger::Critical(const std::string& message, ...)
    {
        va_list args;
        va_start(args, message);
        char formattedMessage[1024];
        std::vsnprintf(formattedMessage, sizeof(formattedMessage), message.c_str(), args);
        va_end(args);
        Log(LogLevel::Critical, formattedMessage);
    }
} // namespace Nt

#endif // _CORE_LOGGER_CPP_
