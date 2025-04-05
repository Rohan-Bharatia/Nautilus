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

#ifndef _NT_CORE_MATH_PLANE_H_
    #define _NT_CORE_MATH_PLANE_H_

#include "../Platform/Platform.h"

namespace nt
{
    class NT_API Plane
    {
    public:
        Plane()                              = default;
        Plane(float a, float b, float c, float d);
        ~Plane()                             = default;
        Plane(const Plane& other)            = default;
        Plane& operator=(const Plane& other) = default;

        // Plane methods
        float distanceTo(float x, float y, float z) const;
        bool intersects(const Plane& other) const;
        bool contains(float x, float y, float z) const;
        Plane normalize();

        float a, b, c, d; // Plane equation: ax + by + cz + d = 0
    };

    // Sign operations
    Plane operator+(Plane lhs);
    Plane operator-(Plane lhs);

    // Arithmetic operations
    Plane operator+(Plane lhs, Plane rhs);
    Plane operator-(Plane lhs, Plane rhs);
    Plane operator*(Plane lhs, Plane rhs);
    Plane operator/(Plane lhs, Plane rhs);
    Plane operator%(Plane lhs, Plane rhs);

    // Increment/decrement operations
    Plane operator++(Plane& lhs);
    Plane operator--(Plane& lhs);
    Plane operator++(Plane& lhs, int);
    Plane operator--(Plane& lhs, int);

    // Assignment operations
    Plane& operator+=(Plane& lhs, Plane rhs);
    Plane& operator-=(Plane& lhs, Plane rhs);
    Plane& operator*=(Plane& lhs, Plane rhs);
    Plane& operator/=(Plane& lhs, Plane rhs);
    Plane& operator%=(Plane& lhs, Plane rhs);

    // Relational operations
    bool operator==(Plane lhs, Plane rhs);
    bool operator!=(Plane lhs, Plane rhs);
    bool operator<(Plane lhs, Plane rhs);
    bool operator>(Plane lhs, Plane rhs);
    bool operator<=(Plane lhs, Plane rhs);
    bool operator>=(Plane lhs, Plane rhs);
} // namespace nt

#endif // _NT_CORE_MATH_PLANE_H_
