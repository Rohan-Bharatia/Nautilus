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

#ifndef _NT_NAUTILUS_H_
    #define _NT_NAUTILUS_H_

// Include headers
#include "Core/Core.h"

// Version macros
#define NT_MAKE_VERSION(major, minor, patch) NT_STRINGIFY(major) "." NT_STRINGIFY(minor) "." NT_STRINGIFY(patch)
#define NT_VERSION_MAJOR 1
#define NT_VERSION_MINOR 0
#define NT_VERSION_PATCH 0
#define NT_VERSION_STR NT_MAKE_VERSION(NT_VERSION_MAJOR, NT_VERSION_MINOR, NT_VERSION_PATCH)
#define NT_VERSION_INT (NT_VERSION_MAJOR * 100) + (NT_VERSION_MINOR * 10) + NT_VERSION_PATCH

#define NT_VEC2F_ZERO nt::Vec2f(0.0f, 0.0f)
#define NT_VEC2F_ONE nt::Vec2f(1.0f, 1.0f)
#define NT_VEC2F_UP nt::Vec2f(0.0f, -1.0f)
#define NT_VEC2F_DOWN nt::Vec2f(0.0f, 1.0f)
#define NT_VEC2F_RIGHT nt::Vec2f(1.0f, 0.0f)
#define NT_VEC2F_LEFT nt::Vec2f(-1.0f, 0.0f)

#define NT_VEC3F_ZERO nt::Vec3f(0.0f, 0.0f, 0.0f)
#define NT_VEC3F_ONE nt::Vec3f(1.0f, 1.0f, 1.0f)
#define NT_VEC3F_UP nt::Vec3f(0.0f, -1.0f, 0.0f)
#define NT_VEC3F_DOWN nt::Vec3f(0.0f, 1.0f, 0.0f)
#define NT_VEC3F_RIGHT nt::Vec3f(1.0f, 0.0f, 0.0f)
#define NT_VEC3F_LEFT nt::Vec3f(-1.0f, 0.0f, 0.0f)
#define NT_VEC3F_FORWARD nt::Vec3f(0.0f, 0.0f, -1.0f)
#define NT_VEC3F_BACKWARD nt::Vec3f(0.0f, 0.0f, 1.0f)

#define NT_VEC4F_ZERO nt::Vec4f(0.0f, 0.0f, 0.0f, 0.0f)
#define NT_VEC4F_ONE nt::Vec4f(1.0f, 1.0f, 1.0f, 1.0f)
#define NT_VEC4F_UP nt::Vec4f(0.0f, -1.0f, 0.0f, 0.0f)
#define NT_VEC4F_DOWN nt::Vec4f(0.0f, 1.0f, 0.0f, 0.0f)
#define NT_VEC4F_RIGHT nt::Vec4f(1.0f, 0.0f, 0.0f, 0.0f)
#define NT_VEC4F_LEFT nt::Vec4f(-1.0f, 0.0f, 0.0f, 0.0f)
#define NT_VEC4F_FORWARD nt::Vec4f(0.0f, 0.0f, -1.0f, 0.0f)
#define NT_VEC4F_BACKWARD nt::Vec4f(0.0f, 0.0f, 1.0f, 0.0f)

#define NT_COLOR_DEFAULT nt::Color(51, 77, 77, 1.0f)
#define NT_COLOR_BLACK nt::Color(0, 0, 0, 1.0f)
#define NT_COLOR_WHITE nt::Color(255, 255, 255, 1.0f)
#define NT_COLOR_RED nt::Color(255, 0, 0, 1.0f)
#define NT_COLOR_GREEN nt::Color(0, 255, 0, 1.0f)
#define NT_COLOR_BLUE nt::Color(0, 0, 255, 1.0f)
#define NT_COLOR_YELLOW nt::Color(255, 255, 0, 1.0f)
#define NT_COLOR_MAGENTA nt::Color(255, 0, 255, 1.0f)
#define NT_COLOR_CYAN nt::Color(0, 255, 255, 1.0f)
#define NT_COLOR_GRAY nt::Color(128, 128, 128, 1.0f)
#define NT_COLOR_DARK_GRAY nt::Color(64, 64, 64, 1.0f)
#define NT_COLOR_LIGHT_GRAY nt::Color(192, 192, 192, 1.0f)

#endif // _NT_NAUTILUS_H_
