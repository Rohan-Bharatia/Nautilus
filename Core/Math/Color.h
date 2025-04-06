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

#ifndef _NT_CORE_MATH_COLOR_H_
    #define _NT_CORE_MATH_COLOR_H_

#include "../Platform/Platform.h"

#include <cstdint>

namespace nt
{
    class NT_API Color
    {
    public:
        Color()                        = default;
        Color(uint8_t r, uint8_t g, uint8_t b); // RGB
        Color(uint8_t r, uint8_t g, uint8_t b, float a); // RGBA
        Color(uint64_t hex); // Hex
        ~Color()                       = default;
        Color(const Color&)            = default;
        Color& operator=(const Color&) = default;

        uint8_t r, g, b;
        float a;
    };

    // Sign operations (Don't apply to colors)
    // Color operator+(Color lhs);
    // Color operator-(Color lhs);

    // Arithmetic operations
    Color operator+(Color lhs, Color rhs);
    Color operator-(Color lhs, Color rhs);
    Color operator*(Color lhs, Color rhs);
    Color operator/(Color lhs, Color rhs);
    Color operator%(Color lhs, Color rhs);

    // Increment/decrement operations
    Color operator++(Color& lhs);
    Color operator--(Color& lhs);
    Color operator++(Color& lhs, int);
    Color operator--(Color& lhs, int);

    // Assignment operations
    Color& operator+=(Color& lhs, Color rhs);
    Color& operator-=(Color& lhs, Color rhs);
    Color& operator*=(Color& lhs, Color rhs);
    Color& operator/=(Color& lhs, Color rhs);
    Color& operator%=(Color& lhs, Color rhs);

    // Relational operations
    bool operator==(Color lhs, Color rhs);
    bool operator!=(Color lhs, Color rhs);
    bool operator<(Color lhs, Color rhs);
    bool operator>(Color lhs, Color rhs);
    bool operator<=(Color lhs, Color rhs);
    bool operator>=(Color lhs, Color rhs);
} // namespace nt

#endif // _NT_CORE_MATH_COLOR_H_
