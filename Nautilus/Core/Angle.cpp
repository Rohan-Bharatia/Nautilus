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

#ifndef _NT_CORE_ANGLE_CPP_
    #define _NT_CORE_ANGLE_CPP_

#include "Angle.h"

#include "Assertion.h"

namespace Nt
{
    Angle::Angle(float32 radians) :
        m_radians(radians)
    {}

    Angle Angle::operator+(const Angle& other) const
    {
        return Angle(m_radians + other.InRadians());
    }

    Angle Angle::operator+(float32 other) const
    {
        return Angle(m_radians + other);
    }

    Angle Angle::operator-(const Angle& other) const
    {
        return Angle(m_radians - other.InRadians());
    }

    Angle Angle::operator-(float32 other) const
    {
        return Angle(m_radians - other);
    }

    Angle Angle::operator*(const Angle& other) const
    {
        return Angle(m_radians * other.InRadians());
    }

    Angle Angle::operator*(float32 other) const
    {
        return Angle(m_radians * other);
    }

    Angle Angle::operator/(const Angle& other) const
    {
        NT_ASSERT(other.InRadians() == 0.0f, "Cannot divide by zero!");
        return Angle(m_radians / other.InRadians());
    }

    Angle Angle::operator/(float32 other) const
    {
        NT_ASSERT(other == 0.0f, "Cannot divide by zero!");
        return Angle(m_radians / other);
    }

    Angle Angle::operator%(const Angle& other) const
    {
        NT_ASSERT(other.InRadians() == 0.0f, "Cannot modulus by zero!");
        return Angle(NT_MODULUS(float32, m_radians, other.InRadians()));
    }

    Angle Angle::operator%(float32 other) const
    {
        NT_ASSERT(other == 0.0f, "Cannot modulus by zero!");
        return Angle(NT_MODULUS(float32, m_radians, other));
    }

    Angle Angle::operator++(void)
    {
        ++m_radians;
        return *this;
    }

    Angle Angle::operator++(int)
    {
        Angle temp = *this;
        ++m_radians;
        return temp;
    }

    Angle Angle::operator--(void)
    {
        --m_radians;
        return *this;
    }

    Angle Angle::operator--(int)
    {
        Angle temp = *this;
        --m_radians;
        return temp;
    }

    Angle& Angle::operator+=(const Angle& other)
    {
        return *this = *this + other;
    }

    Angle& Angle::operator+=(float32 other)
    {
        return *this = *this + other;
    }

    Angle& Angle::operator-=(const Angle& other)
    {
        return *this = *this - other;
    }

    Angle& Angle::operator-=(float32 other)
    {
        return *this = *this - other;
    }

    Angle& Angle::operator*=(const Angle& other)
    {
        return *this = *this * other;
    }

    Angle& Angle::operator*=(float32 other)
    {
        return *this = *this * other;
    }

    Angle& Angle::operator/=(const Angle& other)
    {
        NT_ASSERT(other.InRadians() == 0.0f, "Cannot divide by zero!");
        return *this = *this / other;
    }

    Angle& Angle::operator/=(float32 other)
    {
        NT_ASSERT(other == 0.0f, "Cannot divide by zero!");
        return *this = *this / other;
    }

    Angle& Angle::operator%=(const Angle& other)
    {
        NT_ASSERT(other.InRadians() == 0.0f, "Cannot modulus by zero!");
        return *this = *this % other;
    }

    Angle& Angle::operator%=(float32 other)
    {
        NT_ASSERT(other == 0.0f, "Cannot modulus by zero!");
        return *this = *this % other;
    }

    bool Angle::operator>(const Angle& other) const
    {
        return m_radians > other.InRadians();
    }

    bool Angle::operator>(float32 other) const
    {
        return m_radians > other;
    }

    bool Angle::operator>=(const Angle& other) const
    {
        return m_radians >= other.InRadians();
    }

    bool Angle::operator>=(float32 other) const
    {
        return m_radians >= other;
    }

    bool Angle::operator<(const Angle& other) const
    {
        return m_radians < other.InRadians();
    }

    bool Angle::operator<(float32 other) const
    {
        return m_radians < other;
    }

    bool Angle::operator<=(const Angle& other) const
    {
        return m_radians <= other.InRadians();
    }

    bool Angle::operator<=(float32 other) const
    {
        return m_radians <= other;
    }

    bool Angle::operator==(const Angle& other) const
    {
        return m_radians == other.InRadians();
    }

    bool Angle::operator==(float32 other) const
    {
        return m_radians == other;
    }

    bool Angle::operator!=(const Angle& other) const
    {
        return m_radians != other.InRadians();
    }

    bool Angle::operator!=(float32 other) const
    {
        return m_radians != other;
    }

    float32 Angle::InRadians(void) const
    {
        return m_radians;
    }

    float32 Angle::InDegrees(void) const
    {
        return m_radians * (180.0f / NT_PI);
    }

    float32 Angle::InTurns(void) const
    {
        return m_radians / (2.0f * NT_PI);
    }

    float32 Angle::InGradians(void) const
    {
        return m_radians * (200.0f / NT_PI);
    }

    float32 Angle::Sin(void) const
    {
        return sinf(m_radians);
    }

    float32 Angle::Cos(void) const
    {
        return cosf(m_radians);
    }

    float32 Angle::Tan(void) const
    {
        return tanf(m_radians);
    }
} // namespace Nt

#endif // _NT_CORE_ANGLE_CPP_
