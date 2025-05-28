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

#if defined(NT_PLATFORM_WINDOWS)
    #define NT_ASSERT(condition, message) { if(!(condition)) { Nt::Logger::Critical(message); __debugbreak(); } }
#else // (NOT) defined(NT_PLATFORM_WINDOWS)
    #define NT_ASSERT(condition, message) { if(!(condition)) { Nt::Logger::Critical(message); __builtin_trap(); } }
#endif // defined(NT_PLATFORM_WINDOWS)

#endif // _CORE_ASSERTION_H_
