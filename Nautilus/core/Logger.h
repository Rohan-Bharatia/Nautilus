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
        NT_OFF      = 6,
    };

    class Logger
    {
    public:
        Logger();
        ~Logger();
        
        void setLogLevel(LogLevel level);
        void enableFileLogging(const std::string& filename);
        
        void trace(const std::string& message);
        void debug(const std::string& message);
        void info(const std::string& message);
        void warn(const std::string& message);
        void error(const std::string& message);
        void critical(const std::string& message);
    
    private:
        void log(LogLevel level, const std::string& message);
        std::string levelToString(LogLevel level);
        std::string levelToEffects(LogLevel level);
    
        LogLevel m_currentLevel;
        std::ofstream m_logFile;
        std::mutex m_logMutex;
    };
}

#endif // _NT_CORE_LOGGER_h_