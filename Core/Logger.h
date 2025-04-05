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

#ifndef _NT_CORE_LOGGER_H_
    #define _NT_CORE_LOGGER_H_

#include "Platform/Platform.h"

#include <string>
#include <unordered_map>

namespace nt
{
    enum LogLevel
    {
        LOG_TRACE,
        LOG_DEBUG,
        LOG_INFO,
        LOG_WARNING,
        LOG_ERROR,
        LOG_FATAL,
        LOG_CRITICAL,
    };

    class NT_API Logger
    {
    public:
        static void log(const LogLevel& level, const std::string& message, ...);
        static void trace(const std::string& message, ...);
        static void debug(const std::string& message, ...);
        static void info(const std::string& message, ...);
        static void warning(const std::string& message, ...);
        static void error(const std::string& message, ...);
        static void fatal(const std::string& message, ...);
        static void critical(const std::string& message, ...);

    private:
        static std::unordered_map<LogLevel, std::string> logLevelNames;
        static std::unordered_map<LogLevel, std::string> logLevelColors;

        static std::string getTimestamp();
    };
} // namespace nt

#endif // _NT_CORE_LOGGER_H_
