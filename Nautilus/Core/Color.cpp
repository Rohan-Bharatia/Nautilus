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

#include "Assertion.h"

namespace Nt
{
    Color::Color(float32 r, float32 g, float32 b, float32 a) :
        r(r), g(g), b(b), a(a)
    {}

    Color::Color(const Vec3f& other, float32 a) :
        r(other.x), g(other.y), b(other.z), a(a)
    {}

    Color::Color(const Vec4f& other) :
        r(other.x), g(other.y), b(other.z), a(other.w)
    {}

    Color Color::operator+(const Color& other) const
    {
        return Color(r + other.r, g + other.g, b + other.b, a + other.a);
    }

    Color Color::operator+(float32 other) const
    {
        return Color(r + other, g + other, b + other, a + other);
    }

    Color Color::operator-(const Color& other) const
    {
        return Color(r - other.r, g - other.g, b - other.b, a - other.a);
    }

    Color Color::operator-(float32 other) const
    {
        return Color(r - other, g - other, b - other, a - other);
    }

    Color Color::operator*(const Color& other) const
    {
        return Color(r * other.r, g * other.g, b * other.b, a * other.a);
    }

    Color Color::operator*(float32 other) const
    {
        return Color(r * other, g * other, b * other, a * other);
    }

    Color Color::operator/(const Color& other) const
    {
        NT_ASSERT(other == 0.0f, "Cannot divide by zero!");
        return Color(r / other.r, g / other.g, b / other.b, a / other.a);
    }

    Color Color::operator/(float32 other) const
    {
        NT_ASSERT(other == 0.0f, "Cannot divide by zero!");
        return Color(r / other, g / other, b / other, a / other);
    }

    Color Color::operator%(const Color& other) const
    {
        NT_ASSERT(other == 0.0f, "Cannot modulus by zero!");
        return Color(NT_MODULUS(float32, r, other.r), NT_MODULUS(float32, g, other.g), NT_MODULUS(float32, b, other.b), NT_MODULUS(float32, a, other.a));
    }

    Color Color::operator%(float32 other) const
    {
        NT_ASSERT(other == 0.0f, "Cannot modulus by zero!");
        return Color(NT_MODULUS(float32, r, other), NT_MODULUS(float32, g, other), NT_MODULUS(float32, b, other), NT_MODULUS(float32, a, other));
    }

    Color Color::operator++(void)
    {
        ++r;
        ++g;
        ++b;
        ++a;
        return *this;
    }

    Color Color::operator++(int)
    {
        Color temp = *this;
        ++*this;
        return temp;
    }

    Color Color::operator--(void)
    {
        --r;
        --g;
        --b;
        --a;
        return *this;
    }

    Color Color::operator--(int)
    {
        Color temp = *this;
        --*this;
        return temp;
    }

    Color& Color::operator+=(const Color& other)
    {
        return *this = *this + other;
    }

    Color& Color::operator+=(float32 other)
    {
        return *this = *this + other;
    }

    Color& Color::operator-=(const Color& other)
    {
        return *this = *this - other;
    }

    Color& Color::operator-=(float32 other)
    {
        return *this = *this - other;
    }

    Color& Color::operator*=(const Color& other)
    {
        return *this = *this * other;
    }

    Color& Color::operator*=(float32 other)
    {
        return *this = *this * other;
    }

    Color& Color::operator/=(const Color& other)
    {
        NT_ASSERT(other == 0.0f, "Cannot divide by zero!");
        return *this = *this / other;
    }

    Color& Color::operator/=(float32 other)
    {
        NT_ASSERT(other == 0.0f, "Cannot divide by zero!");
        return *this = *this / other;
    }

    Color& Color::operator%=(const Color& other)
    {
        NT_ASSERT(other == 0.0f, "Cannot modulus by zero!");
        return *this = *this % other;
    }

    Color& Color::operator%=(float32 other)
    {
        NT_ASSERT(other == 0.0f, "Cannot modulus by zero!");
        return *this = *this % other;
    }

    bool Color::operator>(const Color& other) const
    {
        return (r > other.r && g > other.g && b > other.b && a > other.a);
    }

    bool Color::operator>(float32 other) const
    {
        return (r > other && g > other && b > other && a > other);
    }

    bool Color::operator>=(const Color& other) const
    {
        return (r >= other.r && g >= other.g && b >= other.b && a >= other.a);
    }

    bool Color::operator>=(float32 other) const
    {
        return (r >= other && g >= other && b >= other && a >= other);
    }

    bool Color::operator<(const Color& other) const
    {
        return (r < other.r && g < other.g && b < other.b && a < other.a);
    }

    bool Color::operator<(float32 other) const
    {
        return (r < other && g < other && b < other && a < other);
    }

    bool Color::operator<=(const Color& other) const
    {
        return (r <= other.r && g <= other.g && b <= other.b && a <= other.a);
    }

    bool Color::operator<=(float32 other) const
    {
        return (r <= other && g <= other && b <= other && a <= other);
    }

    bool Color::operator==(const Color& other) const
    {
        return (r == other.r && g == other.g && b == other.b && a == other.a);
    }

    bool Color::operator==(float32 other) const
    {
        return (r == other && g == other && b == other && a == other);
    }

    bool Color::operator!=(const Color& other) const
    {
        return (r != other.r || g != other.g || b != other.b || a != other.a);
    }

    bool Color::operator!=(float32 other) const
    {
        return (r != other || g != other || b != other || a != other);
    }
} // namespace Nt

#endif // _NT_CORE_MATH_COLOR_CPP_
