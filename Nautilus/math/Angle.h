//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#pragma once

#ifndef _NT_MATH_ANGLE_h_
    #define _NT_MATH_ANGLE_h_

namespace nt
{
    class Angle
    {
    public:
        // Constructors/destructors
        Angle()                              = default;
        explicit Angle(float radians);
        ~Angle()                             = default;
        Angle(const Angle& other)            = default;
        Angle& operator=(const Angle& other) = default;

        // Conversion types
        float inRadians() const;
        float inDegrees() const;
        float inTurns() const;

    private:
        friend Angle radians(float radians);
        friend Angle degrees(float degrees);
        friend Angle turns(float turns);

        float m_radians;
    };

    Angle radians(float radians);
    Angle degrees(float degrees);
    Angle turns(float turns);

    // Sign operations
    Angle operator+(Angle lhs);
    Angle operator-(Angle lhs);

    // Arithmetic operations
    Angle operator+(Angle lhs, Angle rhs);
    Angle operator-(Angle lhs, Angle rhs);
    Angle operator*(Angle lhs, Angle rhs);
    Angle operator/(Angle lhs, Angle rhs);
    Angle operator%(Angle lhs, Angle rhs);

    // Assignment operations
    Angle operator+=(Angle& lhs, Angle rhs);
    Angle operator-=(Angle& lhs, Angle rhs);
    Angle operator*=(Angle& lhs, Angle rhs);
    Angle operator/=(Angle& lhs, Angle rhs);
    Angle operator%=(Angle& lhs, Angle rhs);

    // Relation operations
    bool operator==(Angle lhs, Angle rhs);
    bool operator!=(Angle lhs, Angle rhs);
    bool operator<(Angle lhs, Angle rhs);
    bool operator>(Angle lhs, Angle rhs);
    bool operator<=(Angle lhs, Angle rhs);
    bool operator>=(Angle lhs, Angle rhs);

    namespace literals
    {
        Angle operator""_rads(long double radians);
        Angle operator""_rads(unsigned long long int radians);
        Angle operator""_degs(long double radians);
        Angle operator""_degs(unsigned long long int radians);
        Angle operator""_trns(long double radians);
        Angle operator""_trns(unsigned long long int radians);
    } // namespace literals
} // namespace nt

#endif // _NT_MATH_ANGLE_h_