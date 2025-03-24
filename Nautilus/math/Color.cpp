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


#ifndef _NT_MATH_COLOR_cpp_
    #define _NT_MATH_COLOR_cpp_

#include "Color.h"

#include "Internal.h"

#include <cassert>
#include <cmath>

namespace nt
{
    Color::Color(uint8 red, uint8 green, uint8 blue, float alpha) :
        red(red), green(green), blue(blue), alpha(alpha)
    {}

    Color operator+(Color lhs)
    {
        return Color(+lhs.red, +lhs.green, +lhs.blue, +lhs.alpha);
    }

    Color operator-(Color lhs)
    {
        return Color(-lhs.red, -lhs.green, -lhs.blue, -lhs.alpha);
    }

    Color operator+(Color lhs, Color rhs)
    {
        return Color(lhs.red + rhs.red, lhs.green + rhs.green, lhs.blue + rhs.blue, lhs.alpha + rhs.alpha);
    }

    Color operator-(Color lhs, Color rhs)
    {
        return Color(lhs.red - rhs.red, lhs.green - rhs.green, lhs.blue - rhs.blue, lhs.alpha - rhs.alpha);
    }

    Color operator*(Color lhs, Color rhs)
    {
        return Color(lhs.red * rhs.red, lhs.green * rhs.green, lhs.blue * rhs.blue, lhs.alpha * rhs.alpha);
    }

    Color operator/(Color lhs, Color rhs)
    {
        assert(rhs.red != 0 && rhs.green != 0 && rhs.blue != 0 && rhs.alpha != 0 && "Color operator / cannot divide by zero!");
        return Color(lhs.red / rhs.red, lhs.green / rhs.green, lhs.blue / rhs.blue, lhs.alpha / rhs.alpha);
    }

    Color operator%(Color lhs, Color rhs)
    {
        assert(rhs.red != 0 && rhs.green != 0 && rhs.blue != 0 && rhs.alpha != 0 && "Color operator % cannot modulus by zero!");
        return Color(internal::positiveRemainder<float>(lhs.red, rhs.red), internal::positiveRemainder<float>(lhs.green, rhs.green), internal::positiveRemainder<float>(lhs.blue, rhs.blue), internal::positiveRemainder<float>(lhs.alpha, rhs.alpha));
    }

    Color operator+=(Color& lhs, Color rhs)
    {
        return lhs = lhs + rhs;
    }

    Color operator-=(Color& lhs, Color rhs)
    {
        return lhs = lhs - rhs;
    }

    Color operator*=(Color& lhs, Color rhs)
    {
        return lhs = lhs * rhs;
    }

    Color operator/=(Color& lhs, Color rhs)
    {
        assert(rhs.red != 0 && rhs.green != 0 && rhs.blue != 0 && rhs.alpha != 0 && "Color operator /= cannot divide by zero!");
        return lhs = lhs / rhs;
    }

    Color operator%=(Color& lhs, Color rhs)
    {
        assert(rhs.red != 0 && rhs.green != 0 && rhs.blue != 0 && rhs.alpha != 0 && "Color operator %= cannot modulus by zero!");
        return lhs = lhs % rhs;
    }

    bool operator==(Color lhs, Color rhs)
    {
        return (lhs.red == rhs.red) &&
               (lhs.green == rhs.green) &&
               (lhs.blue == rhs.blue) &&
               (lhs.alpha == rhs.alpha);
    }

    bool operator!=(Color lhs, Color rhs)
    {
        return (lhs.red != rhs.red) &&
               (lhs.green != rhs.green) &&
               (lhs.blue != rhs.blue) &&
               (lhs.alpha != rhs.alpha);
    }

    bool operator<(Color lhs, Color rhs)
    {
        return (lhs.red < rhs.red) &&
               (lhs.green < rhs.green) &&
               (lhs.blue < rhs.blue) &&
               (lhs.alpha < rhs.alpha);
    }

    bool operator>(Color lhs, Color rhs)
    {
        return (lhs.red > rhs.red) &&
               (lhs.green > rhs.green) &&
               (lhs.blue > rhs.blue) &&
               (lhs.alpha > rhs.alpha);
    }

    bool operator<=(Color lhs, Color rhs)
    {
        return (lhs.red <= rhs.red) &&
               (lhs.green <= rhs.green) &&
               (lhs.blue <= rhs.blue) &&
               (lhs.alpha <= rhs.alpha);
    }

    bool operator>=(Color lhs, Color rhs)
    {
        return (lhs.red >= rhs.red) &&
               (lhs.green >= rhs.green) &&
               (lhs.blue >= rhs.blue) &&
               (lhs.alpha >= rhs.alpha);
    }
} // namespace nt

#endif // _NT_MATH_COLOR_cpp_
