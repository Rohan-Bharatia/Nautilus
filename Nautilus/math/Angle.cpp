//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#ifndef _NT_MATH_ANGLE_cpp_
    #define _NT_MATH_ANGLE_cpp_

#include "Angle.h"

#include "Internal.h"

#include <stdexcept>
#include <cassert>

namespace nt
{
    Angle::Angle(float radians) : 
        m_radians(radians)
    {}

    float Angle::inRadians() const
    {
        return m_radians;
    }
    
    float Angle::inDegrees() const
    {
        return m_radians * (3.14159265358979323846f / 2.0f);
    }

    float Angle::inTurns() const
    {
        return m_radians * (2.0f * 3.14159265358979323846f);
    }

    Angle radians(float radians)
    {
        return Angle(radians);
    }

    Angle degrees(float degrees)
    {
        return Angle(degrees);
    }

    Angle turns(float turns)
    {
        return Angle(turns * (2.0f * 3.14159265358979323846f));
    }

    Angle operator+(Angle lhs)
    {
        return radians(+lhs.inRadians());
    }

    Angle operator-(Angle lhs)
    {
        return radians(-lhs.inRadians());
    }

    Angle operator+(Angle lhs, Angle rhs)
    {
        return radians(lhs.inRadians() + rhs.inRadians());
    }

    Angle operator-(Angle lhs, Angle rhs)
    {
        return radians(lhs.inRadians() - rhs.inRadians());
    }

    Angle operator*(Angle lhs, Angle rhs)
    {
        return radians(lhs.inRadians() * rhs.inRadians());
    }

    Angle operator/(Angle lhs, Angle rhs)
    {
        assert(rhs.inRadians() != 0.0f && "Angle operator / cannot divide by zero!");
        return radians(lhs.inRadians() / rhs.inRadians());
    }

    Angle operator%(Angle lhs, Angle rhs)
    {
        assert(rhs.inRadians() != 0.0f && "Angle operator % cannot modulus by zero!");
        return radians(internal::positiveRemainder<float>(lhs.inRadians(), rhs.inRadians()));
    }

    Angle operator+=(Angle& lhs, Angle rhs)
    {
        return lhs = lhs + rhs;
    }

    Angle operator-=(Angle& lhs, Angle rhs)
    {
        return lhs = lhs - rhs;
    }

    Angle operator*=(Angle& lhs, Angle rhs)
    {
        return lhs = lhs * rhs;
    }

    Angle operator/=(Angle& lhs, Angle rhs)
    {
        assert(rhs.inRadians() != 0.0f && "Angle operator /= cannot divide by zero!");
        return lhs = lhs / rhs;
    }
    
    Angle operator%=(Angle& lhs, Angle rhs)
    {
        assert(rhs.inRadians() != 0.0f && "Angle operator %= cannot modulus by zero!");
        return lhs = lhs % rhs;
    }

    bool operator==(Angle lhs, Angle rhs)
    {
        return (lhs.inRadians() == rhs.inRadians());
    }

    bool operator!=(Angle lhs, Angle rhs)
    {
        return (lhs.inRadians() != rhs.inRadians());
    }

    bool operator<(Angle lhs, Angle rhs)
    {
        return (lhs.inRadians() < rhs.inRadians());
    }

    bool operator>(Angle lhs, Angle rhs)
    {
        return (lhs.inRadians() > rhs.inRadians());
    }

    bool operator<=(Angle lhs, Angle rhs)
    {
        return (lhs.inRadians() <= rhs.inRadians());
    }

    bool operator>=(Angle lhs, Angle rhs)
    {
        return (lhs.inRadians() >= rhs.inRadians());
    }

    namespace literals
    {
        Angle operator""_rads(long double rads)
        {
            return radians(static_cast<float>(rads));
        }

        Angle operator""_rads(unsigned long long int rads)
        {
            return radians(static_cast<float>(rads));
        }

        Angle operator""_degs(long double degs)
        {
            return degrees(static_cast<float>(degs));
        }

        Angle operator""_degs(unsigned long long int degs)
        {
            return degrees(static_cast<float>(degs));
        }

        Angle operator""_trns(long double trns)
        {
            return turns(static_cast<float>(trns));
        }

        Angle operator""_trns(unsigned long long int trns)
        {
            return turns(static_cast<float>(trns));
        }
    } // namespace literals
} // namespace nt

#endif // _NT_MATH_ANGLE_cpp_