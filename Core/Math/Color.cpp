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

#ifndef _NT_CORE_MATH_COLOR_CPP_
    #define _NT_CORE_MATH_COLOR_CPP_

#include "Color.h"

#include <cassert>

namespace nt
{
    Color::Color(uint8_t r, uint8_t g, uint8_t b) :
        r(r), g(g), b(b), a(1.0f)
    {}

    Color::Color(uint8_t r, uint8_t g, uint8_t b, float a) :
        r(r), g(g), b(b), a(a)
    {}

    Color::Color(uint64_t hex) :
        r((hex >> 32) & 0xFF), g((hex >> 16) & 0xFF), b((hex >> 8) & 0xFF), a(hex & 0xFF)
    {}

    Color operator+(Color lhs, Color rhs)
    {
        return Color(lhs.r + rhs.r, lhs.g + rhs.g, lhs.b + rhs.b, lhs.a + rhs.a);
    }

    Color operator-(Color lhs, Color rhs)
    {
        return Color(lhs.r - rhs.r, lhs.g - rhs.g, lhs.b - rhs.b, lhs.a - rhs.a);
    }

    Color operator*(Color lhs, Color rhs)
    {
        return Color(lhs.r * rhs.r, lhs.g * rhs.g, lhs.b * rhs.b, lhs.a * rhs.a);
    }

    Color operator/(Color lhs, Color rhs)
    {
        assert(rhs.r != 0 && rhs.g != 0 && rhs.b != 0 && rhs.a != 0);
        return Color(lhs.r / rhs.r, lhs.g / rhs.g, lhs.b / rhs.b, lhs.a / rhs.a);
    }

    Color operator%(Color lhs, Color rhs)
    {
        assert(rhs.r != 0 && rhs.g != 0 && rhs.b != 0 && rhs.a != 0);
        return Color(lhs.r % rhs.r, lhs.g % rhs.g, lhs.b % rhs.b, NT_MODULUS(lhs.a, rhs.a));
    }

    Color operator++(Color& lhs)
    {
        ++lhs.r;
        ++lhs.g;
        ++lhs.b;
        ++lhs.a;
        return lhs;
    }

    Color operator--(Color& lhs)
    {
        --lhs.r;
        --lhs.g;
        --lhs.b;
        --lhs.a;
        return lhs;
    }

    Color operator++(Color& lhs, int)
    {
        Color temp = lhs;
        ++lhs.r;
        ++lhs.g;
        ++lhs.b;
        ++lhs.a;
        return temp;
    }

    Color operator--(Color& lhs, int)
    {
        Color temp = lhs;
        --lhs.r;
        --lhs.g;
        --lhs.b;
        --lhs.a;
        return temp;
    }

    Color& operator+=(Color& lhs, Color rhs)
    {
        return lhs = lhs + rhs;
    }

    Color& operator-=(Color& lhs, Color rhs)
    {
        return lhs = lhs - rhs;
    }

    Color& operator*=(Color& lhs, Color rhs)
    {
        return lhs = lhs * rhs;
    }

    Color& operator/=(Color& lhs, Color rhs)
    {
        assert(rhs.r != 0 && rhs.g != 0 && rhs.b != 0 && rhs.a != 0);
        return lhs = lhs / rhs;
    }

    Color& operator%=(Color& lhs, Color rhs)
    {
        assert(rhs.r != 0 && rhs.g != 0 && rhs.b != 0 && rhs.a != 0);
        return lhs = lhs % rhs;
    }

    bool operator==(Color lhs, Color rhs)
    {
        return lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b && lhs.a == rhs.a;
    }

    bool operator!=(Color lhs, Color rhs)
    {
        return !(lhs == rhs);
    }

    bool operator<(Color lhs, Color rhs)
    {
        return lhs.r < rhs.r && lhs.g < rhs.g && lhs.b < rhs.b && lhs.a < rhs.a;
    }

    bool operator>(Color lhs, Color rhs)
    {
        return lhs.r > rhs.r && lhs.g > rhs.g && lhs.b > rhs.b && lhs.a > rhs.a;
    }

    bool operator<=(Color lhs, Color rhs)
    {
        return !(lhs > rhs);
    }

    bool operator>=(Color lhs, Color rhs)
    {
        return !(lhs < rhs);
    }
} // namespace nt

#endif // _NT_CORE_MATH_COLOR_CPP_
