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

#ifndef _CORE_ASSERTION_H_
    #define _CORE_ASSERTION_H_

#include "Logger.h"

#ifdef NT_DEBUG
    #ifdef NT_PLATFORM_WINDOWS
        #define NT_ASSERT(condition, message) { if(!(condition)) { Nt::Logger::Critical(message); __debugbreak(); } }
    #else // (NOT) NT_PLATFORM_WINDOWS
        #define NT_ASSERT(condition, message) { if(!(condition)) { Nt::Logger::Critical(message); __builtin_trap(); } }
    #endif // NT_PLATFORM_WINDOWS
#else // (NOT) NT_DEBUG
    #define NT_ASSERT(condition, message)
#endif // NT_DEBUG

#endif // _CORE_ASSERTION_H_
