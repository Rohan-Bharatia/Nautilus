//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#pragma once

#ifndef _NT_CORE_LOGGER_h_
    #define _NT_CORE_LOGGER_h_

#include <string>
#include <fstream>
#include <mutex>

namespace nt
{
    enum class LogLevel
    {
        NT_TRACE    = 0,
        NT_DEBUG    = 1,
        NT_INFO     = 2,
        NT_WARN     = 3,
        NT_ERROR    = 4,
        NT_CRITICAL = 5,
    };

    class Logger
    {
    public:
        Logger()                               = default;
        ~Logger()                              = default;
        Logger(const Logger& other)            = default;
        Logger& operator=(const Logger& other) = default;
        
        static void log(LogLevel level, const std::string& message, ...);
        static void trace(const std::string& message, ...);
        static void debug(const std::string& message, ...);
        static void info(const std::string& message, ...);
        static void warn(const std::string& message, ...);
        static void error(const std::string& message, ...);
        static void critical(const std::string& message, ...);
    };
}

#endif // _NT_CORE_LOGGER_h_