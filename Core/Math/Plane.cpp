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

#ifndef _NT_CORE_MATH_PLANE_CPP_
    #define _NT_CORE_MATH_PLANE_CPP_

#include "Plane.h"

#include "../Platform/Platform.h"

#include <cassert>
#include <cmath>

namespace nt
{
    Plane::Plane(float a, float b, float c, float d)
        : a(a), b(b), c(c), d(d)
    {
        assert(a != 0 || b != 0 || c != 0); // Ensure at least one coefficient is non-zero
    }

    float Plane::distanceTo(float x, float y, float z) const
    {
        return (a * x + b * y + c * z + d) / sqrt(a * a + b * b + c * c);
    }

    bool Plane::intersects(const Plane& other) const
    {
        return (a * other.a + b * other.b + c * other.c + d * other.d) != 0;
    }

    bool Plane::contains(float x, float y, float z) const
    {
        return (a * x + b * y + c * z + d) == 0;
    }

    Plane Plane::normalize()
    {
        float length = sqrt(a * a + b * b + c * c);
        assert(length != 0); // Prevent division by zero
        return Plane(a / length, b / length, c / length, d / length);
    }

    Plane operator+(Plane lhs)
    {
        return Plane(+lhs.a, +lhs.b, +lhs.c, +lhs.d);
    }

    Plane operator-(Plane lhs)
    {
        return Plane(-lhs.a, -lhs.b, -lhs.c, -lhs.d);
    }

    Plane operator+(Plane lhs, Plane rhs)
    {
        return Plane(lhs.a + rhs.a, lhs.b + rhs.b, lhs.c + rhs.c, lhs.d + rhs.d);
    }

    Plane operator-(Plane lhs, Plane rhs)
    {
        return Plane(lhs.a - rhs.a, lhs.b - rhs.b, lhs.c - rhs.c, lhs.d - rhs.d);
    }

    Plane operator*(Plane lhs, Plane rhs)
    {
        return Plane(lhs.a * rhs.a, lhs.b * rhs.b, lhs.c * rhs.c, lhs.d * rhs.d);
    }

    Plane operator/(Plane lhs, Plane rhs)
    {
        assert(rhs.a != 0 && rhs.b != 0 && rhs.c != 0 && rhs.d != 0);
        return Plane(lhs.a / rhs.a, lhs.b / rhs.b, lhs.c / rhs.c, lhs.d / rhs.d);
    }

    Plane operator%(Plane lhs, Plane rhs)
    {
        assert(rhs.a != 0 && rhs.b != 0 && rhs.c != 0 && rhs.d != 0);
        return Plane(NT_MODULUS(lhs.a, rhs.a), NT_MODULUS(lhs.b, rhs.b), NT_MODULUS(lhs.c, rhs.c), NT_MODULUS(lhs.d, rhs.d));
    }

    Plane operator++(Plane& lhs)
    {
        ++lhs.a;
        ++lhs.b;
        ++lhs.c;
        ++lhs.d;
        return lhs;
    }

    Plane operator--(Plane& lhs)
    {
        --lhs.a;
        --lhs.b;
        --lhs.c;
        --lhs.d;
        return lhs;
    }

    Plane operator++(Plane& lhs, int)
    {
        Plane temp = lhs;
        ++lhs.a;
        ++lhs.b;
        ++lhs.c;
        ++lhs.d;
        return temp;
    }

    Plane operator--(Plane& lhs, int)
    {
        Plane temp = lhs;
        --lhs.a;
        --lhs.b;
        --lhs.c;
        --lhs.d;
        return temp;
    }

    Plane& operator+=(Plane& lhs, Plane rhs)
    {
        return lhs = lhs + rhs;
    }

    Plane& operator-=(Plane& lhs, Plane rhs)
    {
        return lhs = lhs - rhs;
    }

    Plane& operator*=(Plane& lhs, Plane rhs)
    {
        return lhs = lhs * rhs;
    }

    Plane& operator/=(Plane& lhs, Plane rhs)
    {
        assert(rhs.a != 0 && rhs.b != 0 && rhs.c != 0 && rhs.d != 0);
        return lhs = lhs / rhs;
    }

    Plane& operator%=(Plane& lhs, Plane rhs)
    {
        assert(rhs.a != 0 && rhs.b != 0 && rhs.c != 0 && rhs.d != 0);
        return lhs = lhs % rhs;
    }

    bool operator==(Plane lhs, Plane rhs)
    {
        return lhs.a == rhs.a && lhs.b == rhs.b && lhs.c == rhs.c && lhs.d == rhs.d;
    }

    bool operator!=(Plane lhs, Plane rhs)
    {
        return !(lhs == rhs);
    }

    bool operator<(Plane lhs, Plane rhs)
    {
        return lhs.a < rhs.a && lhs.b < rhs.b && lhs.c < rhs.c && lhs.d < rhs.d;
    }

    bool operator>(Plane lhs, Plane rhs)
    {
        return lhs.a > rhs.a && lhs.b > rhs.b && lhs.c > rhs.c && lhs.d > rhs.d;
    }

    bool operator<=(Plane lhs, Plane rhs)
    {
        return !(lhs > rhs);
    }

    bool operator>=(Plane lhs, Plane rhs)
    {
        return !(lhs < rhs);
    }
} // namespace nt

#endif // _NT_CORE_MATH_PLANE_CPP_
