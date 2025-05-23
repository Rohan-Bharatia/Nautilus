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

#ifndef _CORE_LOGGER_H_
    #define _CORE_LOGGER_H_

#include "PCH.h"

namespace Nt
{
    enum class LogLevel
    {
        None = 0,
        Trace,
        Debug,
        Info,
        Warn,
        Error,
        Critical,
        Count,
    };

    class NT_API Logger
    {
    public:
        NT_CLASS_DEFAULTS(Logger)

        static void Log(LogLevel level, const std::string& message, ...);
        static void Trace(const std::string& message, ...);
        static void Debug(const std::string& message, ...);
        static void Info(const std::string& message, ...);
        static void Warn(const std::string& message, ...);
        static void Error(const std::string& message, ...);
        static void Critical(const std::string& message, ...);
    };
} // namespace Nt


#endif // _CORE_LOGGER_H_
