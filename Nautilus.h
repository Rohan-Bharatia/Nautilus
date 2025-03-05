//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#pragma once

#ifndef _NT_NAUTILUS_h_
    #define _NT_NAUTILUS_h_

// Source files
#include "Nautilus/Core.h"
#include "Nautilus/Math.h"
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

// Color constants
#define NT_COLOR_GRAYSCALEA(v, a) nt::Color((nt::uint8)v, a)
#define NT_COLOR_RGBA(r, g, b, a) nt::Color((nt::uint8)r, g, b, a)
#define NT_COLOR_HSLA(h, s, l, a) nt::Color((float)h, s, l, a)
#define NT_COLOR_HSVA(h, s, v, a) nt::Color((float)h, s, v, a)
#define NT_COLOR_CMYKA(c, m, y, k, a) nt::Color(c, m, y, k, a)
#define NT_COLOR_HEXA(hex, a) nt::Color((nt::uint32)hex, a)
#define NT_COLOR_RED NT_COLOR_RGBA(255, 0, 0, 1.0f)
#define NT_COLOR_GREEN NT_COLOR_RGBA(0, 255, 0, 1.0f)
#define NT_COLOR_BLUE NT_COLOR_RGBA(0, 0, 255, 1.0f)
#define NT_COLOR_CYAN NT_COLOR_RGBA(0, 255, 255, 1.0f)
#define NT_COLOR_YELLOW NT_COLOR_RGBA(255, 255, 0, 1.0f)
#define NT_COLOR_BLACK NT_COLOR_RGBA(0, 0, 0, 1.0f)
#define NT_COLOR_MAGENTA NT_COLOR_RGBA(255, 0, 255, 1.0f)
#define NT_COLOR_GRAY NT_COLOR_RGBA(128, 128, 128, 1.0f)
#define NT_COLOR_WHITE NT_COLOR_RGBA(255, 255, 255, 1.0f)
#define NT_COLOR_BEIGE NT_COLOR_RGBA(245, 245, 220, 1.0f)
#define NT_COLOR_BROWN NT_COLOR_RGBA(165, 42, 42, 1.0f)
#define NT_COLOR_LIGHT_BLUE NT_COLOR_RGBA(173, 216, 230, 1.0f)
#define NT_COLOR_TAN NT_COLOR_RGBA(210, 180, 140, 1.0f)
#define NT_COLOR_BABY_BLUE NT_COLOR_RGBA(137, 207, 240, 1.0f)
#define NT_COLOR_PINK NT_COLOR_RGBA(255, 192, 203, 1.0f)
#define NT_COLOR_ORANGE NT_COLOR_RGBA(255, 165, 0, 1.0f)
#define NT_COLOR_MINT NT_COLOR_RGBA(152, 255, 152, 1.0f)
#define NT_COLOR_TEAL NT_COLOR_RGBA(0, 128, 128, 1.0f)
#define NT_COLOR_PURPLE NT_COLOR_RGBA(128, 0, 128, 1.0f)
#define NT_COLOR_DARK_BROWN NT_COLOR_RGBA(101, 67, 33, 1.0f)
#define NT_COLOR_DARK_GRAY NT_COLOR_RGBA(64, 64, 64, 1.0f)
#define NT_COLOR_GOLD NT_COLOR_RGBA(255, 215, 0, 1.0f)
#define NT_COLOR_NAVY_BLUE NT_COLOR_RGBA(0, 0, 128, 1.0f)
#define NT_COLOR_COPPER NT_COLOR_RGBA(184, 115, 51, 1.0f)
#define NT_COLOR_SILVER NT_COLOR_RGBA(192, 192, 192, 1.0f)

#endif // _NT_NAUTILUS_h_