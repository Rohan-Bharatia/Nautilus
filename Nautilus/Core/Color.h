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

#ifndef _NT_CORE_COLOR_H_
    #define _NT_CORE_COLOR_H_

#include "Vec4.h"

namespace Nt
{
    enum class ColorSpace
    {
        ColorSpaceNone = 0,
        RGB,
        HSV,
        HSL,
        CMYK,
        LCH,
        PQ,
        HLG,
    };

    class NT_API Color
    {
    public:
        NT_CLASS_DEFAULTS(Color)
        Color(void) = default;
        Color(float32 r, float32 g, float32 b, float32 a=1.0f);
        Color(const Vec3f& other, float32 a=1.0f);
        Color(const Vec4f& other);
        template<typename... Args>
        Color(ColorSpace c, Args&&... args);

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

        // Conversion operators
        operator float32*(void) const;

        // Methods
        Color hsv2rgb(float32 h, float32 s, float32 v, float32 a=1.0f);
        Color hslrgb(float32 h, float32 s, float32 l, float32 a=1.0f);
        Color cmyk2rgb(float32 c, float32 m, float32 y, float32 k, float32 a=1.0f);
        Color lch2rgb(float32 l, float32 c, float32 h, float32 a=1.0f);
        Color pq2rgb(float32 r, float32 g, float32 b, float32 n, float32 a=1.0f);
        Color hlg2rgb(float32 r, float32 g, float32 b, float32 n, float32 a=1.0f);

        float32 r, g, b, a;
    };
} // namespace Nt

#endif // _NT_CORE_COLOR_H_
