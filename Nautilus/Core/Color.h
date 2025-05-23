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

#include "Vec4.h"

namespace Nt
{
    class NT_API Color
    {
    public:
        NT_CLASS_DEFAULTS(Color)
        Color(float32 r, float32 g, float32 b, float32 a=1.0f);
        Color(const Vec3f& other, float32 a=1.0f);
        Color(const Vec4f& other);

        // Arithmetic operators
        Color operator+(const Color& other) const;
        Color operator+(float32 other) const;
        Color operator-(const Color& other) const;
        Color operator-(float32 other) const;
        Color operator*(const Color& other) const;
        Color operator*(float32 other) const;
        Color operator/(const Color& other) const;
        Color operator/(float32 other) const;
        Color operator%(const Color& other) const;
        Color operator%(float32 other) const;
        Color operator++(void);
        Color operator++(int);
        Color operator--(void);
        Color operator--(int);

        // Assignment operators
        Color& operator+=(const Color& other);
        Color& operator+=(float32 other);
        Color& operator-=(const Color& other);
        Color& operator-=(float32 other);
        Color& operator*=(const Color& other);
        Color& operator*=(float32 other);
        Color& operator/=(const Color& other);
        Color& operator/=(float32 other);
        Color& operator%=(const Color& other);
        Color& operator%=(float32 other);

        // Relational operators
        bool operator>(const Color& other) const;
        bool operator>(float32 other) const;
        bool operator>=(const Color& other) const;
        bool operator>=(float32 other) const;
        bool operator<(const Color& other) const;
        bool operator<(float32 other) const;
        bool operator<=(const Color& other) const;
        bool operator<=(float32 other) const;
        bool operator==(const Color& other) const;
        bool operator==(float32 other) const;
        bool operator!=(const Color& other) const;
        bool operator!=(float32 other) const;

        float32 r, g, b, a;
    };
} // namespace Nt

#endif // _NT_CORE_MATH_COLOR_H_
