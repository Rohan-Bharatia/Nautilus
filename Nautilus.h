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

#pragma once

#ifndef _NT_NAUTILUS_h_
    #define _NT_NAUTILUS_h_

// Source files
#include "Nautilus/Core.h"
#include "Nautilus/Math.h"
#include "Nautilus/Window.h"
#include "Nautilus/Event.h"

// Aliases
using namespace nt::literals;

// Version
#define NT_VERSION_MAJOR 1
#define NT_VERSION_MINOR 0
#define NT_VERSION_PATCH 0
#define NT_VERSION_STRING "1.0.0"

// C/C++ exit codes
#define NT_EXIT_SUCCESS 0
#define NT_EXIT_MINOR_ERROR 1
#define NT_EXIT_MAJOR_ERROR 2
#define NT_EXIT_CMD_NOT_FOUND 127
#define NT_EXIT_SIGILL 132
#define NT_EXIT_SIGTRAP 133
#define NT_EXIT_SIGABRT 134
#define NT_EXIT_SIGFPE 136
#define NT_EXIT_STACK_OVERFLOW 137
#define NT_EXIT_SIGBUS 138
#define NT_EXIT_SEGMENTATION_FAULT 139
#define NT_EXIT_SIGXCPU 152 | 158
#define NT_EXIT_SIGXFSZ 153 | 159

// Angle constants
#define NT_ANGLE_0_RADIANS 0.0_rads
#define NT_ANGLE_HALF_PI_RADIANS 1.57079632679489661923_rads
#define NT_ANGLE_PI_RADIANS 3.14159265358979323846_rads
#define NT_ANGLE_1_AND_HALF_PI_RADIANS 4.71238898038468985768_rads
#define NT_ANGLE_2_PI_RADIANS 6.28318530717958647692_rads
#define NT_ANGLE_0_DEGREES 0.0_degs
#define NT_ANGLE_90_DEGREES 90.0_degs
#define NT_ANGLE_180_DEGREES 180.0_degs
#define NT_ANGLE_270_DEGREES 270.0_degs
#define NT_ANGLE_360_DEGREES 360.0_degs
#define NT_ANGLE_0_TURNS 0.0_trns
#define NT_ANGLE_1_TURNS 1.0_trns

// Vector constants
// 2D vectors
#define NT_VEC2F_ZERO nt::Vec2f(0.0f, 0.0f)
#define NT_VEC2F_ONE nt::Vec2f(1.0f, 1.0f)
#define NT_VEC2F_UP nt::Vec2f(0.0f, -1.0f)
#define NT_VEC2F_DOWN nt::Vec2f(0.0f, 1.0f)
#define NT_VEC2F_RIGHT nt::Vec2f(1.0f, 0.0f)
#define NT_VEC2F_LEFT nt::Vec2f(-1.0f, 0.0f)
// 3D vectors
#define NT_VEC3F_ZERO nt::Vec3f(0.0f, 0.0f, 0.0f)
#define NT_VEC3F_ONE nt::Vec3f(1.0f, 1.0f, 1.0f)
#define NT_VEC3F_UP nt::Vec3f(0.0f, -1.0f, 0.0f)
#define NT_VEC3F_DOWN nt::Vec3f(0.0f, 1.0f, 0.0f)
#define NT_VEC3F_RIGHT nt::Vec3f(1.0f, 0.0f, 0.0f)
#define NT_VEC3F_LEFT nt::Vec3f(-1.0f, 0.0f, 0.0f)
#define NT_VEC3F_FORWARD nt::Vec3f(0.0f, 0.0f, -1.0f)
#define NT_VEC3F_BACKWARD nt::Vec3f(0.0f, 0.0f, 1.0f)
// 4D vectors
#define NT_VEC4F_ZERO nt::Vec4f(0.0f, 0.0f, 0.0f, 0.0f)
#define NT_VEC4F_ONE nt::Vec4f(1.0f, 1.0f, 1.0f, 1.0f)
#define NT_VEC4F_UP nt::Vec4f(0.0f, -1.0f, 0.0f, 0.0f)
#define NT_VEC4F_DOWN nt::Vec4f(0.0f, 1.0f, 0.0f, 0.0f)
#define NT_VEC4F_RIGHT nt::Vec4f(1.0f, 0.0f, 0.0f, 0.0f)
#define NT_VEC4F_LEFT nt::Vec4f(-1.0f, 0.0f, 0.0f, 0.0f)
#define NT_VEC4F_FORWARD nt::Vec4f(0.0f, 0.0f, -1.0f, 0.0f)
#define NT_VEC4F_BACKWARD nt::Vec4f(0.0f, 0.0f, 1.0f, 0.0f)

// Ray constants
// 2D rays
#define NT_RAY2F_ZERO nt::Ray2f(NT_VEC2F_ZERO, NT_VEC2F_ZERO)
#define NT_RAY2F_ONE nt::Ray2f(NT_VEC2F_ONE, NT_VEC2F_ONE)
#define NT_RAY2F_UP nt::Ray2f(NT_VEC2F_UP, NT_VEC2F_UP)
#define NT_RAY2F_DOWN nt::Ray2f(NT_VEC2F_DOWN, NT_VEC2F_DOWN)
#define NT_RAY2F_RIGHT nt::Ray2f(NT_VEC2F_RIGHT, NT_VEC2F_RIGHT)
#define NT_RAY2F_LEFT nt::Ray2f(NT_VEC2F_LEFT, NT_VEC2F_LEFT)
// 3D rays
#define NT_RAY3F_ZERO nt::Ray3f(NT_VEC3F_ZERO, NT_VEC3F_ZERO)
#define NT_RAY3F_ONE nt::Ray3f(NT_VEC3F_ONE, NT_VEC3F_ONE)
#define NT_RAY3F_UP nt::Ray3f(NT_VEC3F_UP, NT_VEC3F_UP)
#define NT_RAY3F_DOWN nt::Ray3f(NT_VEC3F_DOWN, NT_VEC3F_DOWN)
#define NT_RAY3F_RIGHT nt::Ray3f(NT_VEC3F_RIGHT, NT_VEC3F_RIGHT)
#define NT_RAY3F_LEFT nt::Ray3f(NT_VEC3F_LEFT, NT_VEC3F_LEFT)
#define NT_RAY3F_FORWARD nt::Ray3f(NT_VEC3F_FORWARD, NT_VEC3F_FORWARD)
#define NT_RAY3F_BACKWARD nt::Ray3f(NT_VEC3F_BACKWARD, NT_VEC3F_BACKWARD)

// Color macros
#define NT_COLOR_DEFAULT nt::Color(51, 77, 77, 1.0f)
#define NT_COLOR_RED nt::Color(255, 0, 0, 1.0f)
#define NT_COLOR_GREEN nt::Color(0, 255, 0, 1.0f)
#define NT_COLOR_BLUE nt::Color(0, 0, 255, 1.0f)
#define NT_COLOR_CYAN nt::Color(0, 255, 255, 1.0f)
#define NT_COLOR_YELLOW nt::Color(255, 255, 0, 1.0f)
#define NT_COLOR_BLACK nt::Color(0, 0, 0, 1.0f)
#define NT_COLOR_MAGENTA nt::Color(255, 0, 255, 1.0f)
#define NT_COLOR_GRAY nt::Color(128, 128, 128, 1.0f)
#define NT_COLOR_WHITE nt::Color(255, 255, 255, 1.0f)
#define NT_COLOR_BEIGE nt::Color(245, 245, 220, 1.0f)
#define NT_COLOR_BROWN nt::Color(165, 42, 42, 1.0f)
#define NT_COLOR_LIGHT_BLUE nt::Color(173, 216, 230, 1.0f)
#define NT_COLOR_TAN nt::Color(210, 180, 140, 1.0f)
#define NT_COLOR_BABY_BLUE nt::Color(137, 207, 240, 1.0f)
#define NT_COLOR_PINK nt::Color(255, 192, 203, 1.0f)
#define NT_COLOR_ORANGE nt::Color(255, 165, 0, 1.0f)
#define NT_COLOR_MINT nt::Color(152, 255, 152, 1.0f)
#define NT_COLOR_TEAL nt::Color(0, 128, 128, 1.0f)
#define NT_COLOR_PURPLE nt::Color(128, 0, 128, 1.0f)
#define NT_COLOR_DARK_BROWN nt::Color(101, 67, 33, 1.0f)
#define NT_COLOR_DARK_GRAY nt::Color(64, 64, 64, 1.0f)
#define NT_COLOR_GOLD nt::Color(255, 215, 0, 1.0f)
#define NT_COLOR_NAVY_BLUE nt::Color(0, 0, 128, 1.0f)
#define NT_COLOR_COPPER nt::Color(184, 115, 51, 1.0f)
#define NT_COLOR_SILVER nt::Color(192, 192, 192, 1.0f)

// Logger constants
#define NT_LOG_LEVEL_TRACE nt::LogLevel::NT_TRACE
#define NT_LOG_LEVEL_DEBUG nt::LogLevel::NT_DEBUG
#define NT_LOG_LEVEL_INFO nt::LogLevel::NT_INFO
#define NT_LOG_LEVEL_WARNING nt::LogLevel::NT_WARNING
#define NT_LOG_LEVEL_ERROR nt::LogLevel::NT_ERROR
#define NT_LOG_LEVEL_CRITICAL nt::LogLevel::NT_CRITICAL
#define NT_LOG_LEVEL_OFF nt::LogLevel::NT_OFF
// Logger macros
#define NT_LOG_TRACE(msg, ...) nt::Logger::trace(msg, ##__VA_ARGS__)
#define NT_LOG_DEBUG(msg, ...) nt::Logger::debug(msg, ##__VA_ARGS__)
#define NT_LOG_INFO(msg, ...) nt::Logger::info(msg, ##__VA_ARGS__)
#define NT_LOG_WARN(msg, ...) nt::Logger::warn(msg, ##__VA_ARGS__)
#define NT_LOG_ERROR(msg, ...) nt::Logger::error(msg, ##__VA_ARGS__)
#define NT_LOG_CRITICAL(msg, ...) nt::Logger::critical(msg, ##__VA_ARGS__)

#define NT_ASSERT(condition, msg, ...) assert(condition, msg, ##__VA_ARGS__)

// Timer macro
#define NT_WAIT_MICROS(ms) nt::Timer::sleep(ms / 10)
#define NT_WAIT_MILLIS(ms) nt::Timer::sleep(ms)
#define NT_WAIT_SECONDS(s) nt::Timer::sleep(s * 1000)
#define NT_WAIT(ms) nt::Timer::sleep(ms)

// GPU Preferences
#if defined(NT_PLATFORM_WINDOWS)
    #define NT_DISCRETE_GPU_PREFERENCE                                                     \
        extern "C" NT_EXPORT nt::uint32 NvOptimusEnablement                  = 0x00000001; \
        extern "C" NT_EXPORT nt::uint32 AMDPowerXpressRequestHighPerformance = 0x00000001;
#else // (NOT) defined(NT_PLATFORM_WINDOWS)
    #define NT_DISCRETE_GPU_PREFERENCE
#endif // defined(NT_PLATFORM_WINDOWS)

#endif // _NT_NAUTILUS_h_
