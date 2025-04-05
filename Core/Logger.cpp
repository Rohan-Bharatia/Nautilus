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

#ifndef _NT_CORE_LOGGER_CPP_
    #define _NT_CORE_LOGGER_CPP_

#include "Logger.h"

#include <cstdarg>
#include <cstdio>
#include <ctime>

namespace nt
{
    std::unordered_map<LogLevel, std::string> Logger::logLevelNames =
    {
        { LogLevel::LOG_TRACE,    "TRACE" },
        { LogLevel::LOG_DEBUG,    "DEBUG" },
        { LogLevel::LOG_INFO,     "INFO" },
        { LogLevel::LOG_WARNING,  "WARNING" },
        { LogLevel::LOG_ERROR,    "ERROR" },
        { LogLevel::LOG_FATAL,    "FATAL" },
        { LogLevel::LOG_CRITICAL, "CRITICAL" },
    };

    std::unordered_map<LogLevel, std::string> Logger::logLevelColors =
    {
        { LogLevel::LOG_TRACE,    "\033[37m" },    // Gray text
        { LogLevel::LOG_DEBUG,    "\033[36m" },    // Cyan text
        { LogLevel::LOG_INFO,     "\033[32m" },    // Green text
        { LogLevel::LOG_WARNING,  "\033[33m" },    // Yellow text
        { LogLevel::LOG_ERROR,    "\033[31m" },    // Red text
        { LogLevel::LOG_FATAL,    "\033[35m" },    // Magenta text
        { LogLevel::LOG_CRITICAL, "\033[37;41m" }, // White text & red background
    };

    void Logger::log(const LogLevel& level, const std::string& message, ...)
    {
        va_list args;
        va_start(args, message);

        char formattedMessage[1024];
        vsnprintf(formattedMessage, sizeof(formattedMessage), message.c_str(), args);
        std::string formattedString = logLevelColors[level] + "[" + getTimestamp() + "][" + logLevelNames[level] + "]: " + formattedMessage + "\033[0m";
        printf("%s\n", formattedString.c_str());

        va_end(args);
    }

    void Logger::trace(const std::string& message, ...)
    {
        va_list args;
        va_start(args, message);

        char formattedMessage[1024];
        vsnprintf(formattedMessage, sizeof(formattedMessage), message.c_str(), args);
        std::string formattedString = logLevelColors[LogLevel::LOG_TRACE] + "[" + getTimestamp() + "][TRACE]: " + formattedMessage + "\033[0m";
        printf("%s\n", formattedString.c_str());

        va_end(args);
    }

    void Logger::debug(const std::string& message, ...)
    {
        va_list args;
        va_start(args, message);

        char formattedMessage[1024];
        vsnprintf(formattedMessage, sizeof(formattedMessage), message.c_str(), args);
        std::string formattedString = logLevelColors[LogLevel::LOG_DEBUG] + "[" + getTimestamp() + "][DEBUG]: " + formattedMessage + "\033[0m";
        printf("%s\n", formattedString.c_str());

        va_end(args);
    }

    void Logger::info(const std::string& message, ...)
    {
        va_list args;
        va_start(args, message);

        char formattedMessage[1024];
        vsnprintf(formattedMessage, sizeof(formattedMessage), message.c_str(), args);
        std::string formattedString = logLevelColors[LogLevel::LOG_INFO] + "[" + getTimestamp() + "][INFO]: " + formattedMessage + "\033[0m";
        printf("%s\n", formattedString.c_str());

        va_end(args);
    }

    void Logger::warning(const std::string& message, ...)
    {
        va_list args;
        va_start(args, message);

        char formattedMessage[1024];
        vsnprintf(formattedMessage, sizeof(formattedMessage), message.c_str(), args);
        std::string formattedString = logLevelColors[LogLevel::LOG_WARNING] + "[" + getTimestamp() + "][WARNING]: " + formattedMessage + "\033[0m";
        printf("%s\n", formattedString.c_str());

        va_end(args);
    }

    void Logger::error(const std::string& message, ...)
    {
        va_list args;
        va_start(args, message);

        char formattedMessage[1024];
        vsnprintf(formattedMessage, sizeof(formattedMessage), message.c_str(), args);
        std::string formattedString = logLevelColors[LogLevel::LOG_ERROR] + "[" + getTimestamp() + "][ERROR]: " + formattedMessage + "\033[0m";
        printf("%s\n", formattedString.c_str());

        va_end(args);
    }

    void Logger::fatal(const std::string& message, ...)
    {
        va_list args;
        va_start(args, message);

        char formattedMessage[1024];
        vsnprintf(formattedMessage, sizeof(formattedMessage), message.c_str(), args);
        std::string formattedString = logLevelColors[LogLevel::LOG_FATAL] + "[" + getTimestamp() + "][FATAL]: " + formattedMessage + "\033[0m";
        printf("%s\n", formattedString.c_str());

        va_end(args);
    }

    void Logger::critical(const std::string& message, ...)
    {
        va_list args;
        va_start(args, message);

        char formattedMessage[1024];
        vsnprintf(formattedMessage, sizeof(formattedMessage), message.c_str(), args);
        std::string formattedString = logLevelColors[LogLevel::LOG_CRITICAL] + "[" + getTimestamp() + "][CRITICAL]: " + formattedMessage + "\033[0m";
        printf("%s\n", formattedString.c_str());

        va_end(args);
    }

    std::string Logger::getTimestamp()
    {
        std::time_t now    = std::time(nullptr);
        std::tm* localTime = std::localtime(&now);
        char buffer[20];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
        return std::string(buffer);
    }
} // namespace nt

#endif // _NT_CORE_LOGGER_CPP_
