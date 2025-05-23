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

#ifndef _NT_CORE_MATH_ANGLE_H_
    #define _NT_CORE_MATH_ANGLE_H_

#include "Preprocessor.h"

namespace Nt
{
    class NT_API Angle
    {
    public:
        NT_CLASS_DEFAULTS(Angle)
        Angle(float32 radians);

        // Arithmetic operators
        Angle operator+(const Angle& other) const;
        Angle operator+(float32 other) const;
        Angle operator-(const Angle& other) const;
        Angle operator-(float32 other) const;
        Angle operator*(const Angle& other) const;
        Angle operator*(float32 other) const;
        Angle operator/(const Angle& other) const;
        Angle operator/(float32 other) const;
        Angle operator%(const Angle& other) const;
        Angle operator%(float32 other) const;
        Angle operator++(void);
        Angle operator++(int);
        Angle operator--(void);
        Angle operator--(int);

        // Assignment operators
        Angle& operator+=(const Angle& other);
        Angle& operator+=(float32 other);
        Angle& operator-=(const Angle& other);
        Angle& operator-=(float32 other);
        Angle& operator*=(const Angle& other);
        Angle& operator*=(float32 other);
        Angle& operator/=(const Angle& other);
        Angle& operator/=(float32 other);
        Angle& operator%=(const Angle& other);
        Angle& operator%=(float32 other);

        // Relational operators
        bool operator>(const Angle& other) const;
        bool operator>(float32 other) const;
        bool operator>=(const Angle& other) const;
        bool operator>=(float32 other) const;
        bool operator<(const Angle& other) const;
        bool operator<(float32 other) const;
        bool operator<=(const Angle& other) const;
        bool operator<=(float32 other) const;
        bool operator==(const Angle& other) const;
        bool operator==(float32 other) const;
        bool operator!=(const Angle& other) const;
        bool operator!=(float32 other) const;

        // Methods
        float32 InRadians(void) const;
        float32 InDegrees(void) const;
        float32 InTurns(void) const;
        float32 InGradians(void) const;
        float32 Sin(void) const;
        float32 Cos(void) const;
        float32 Tan(void) const;

    private:
        float32 m_radians;
    };
} // namespace Nt

#endif // _NT_CORE_MATH_ANGLE_H_
