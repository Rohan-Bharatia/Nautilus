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

#ifndef _NT_CORE_MATH_RECT_H_
    #define _NT_CORE_MATH_RECT_H_

#include "../Platform/Platform.h"

namespace nt
{
    class NT_API Rect
    {
    public:
        Rect()                             = default;
        Rect(float x, float y, float width, float height);
        ~Rect()                            = default;
        Rect(const Rect& other)            = default;
        Rect& operator=(const Rect& other) = default;

        // 2D rectangle methods
        float area() const;
        float perimeter() const;
        bool contains(float x, float y) const;
        bool intersects(const Rect& other) const;

        float x, y, width, height;
    };

    // Sign operations
    Rect operator+(Rect lhs);
    Rect operator-(Rect lhs);

    // Arithmetic operations
    Rect operator+(Rect lhs, Rect rhs);
    Rect operator-(Rect lhs, Rect rhs);
    Rect operator*(Rect lhs, Rect rhs);
    Rect operator/(Rect lhs, Rect rhs);
    Rect operator%(Rect lhs, Rect rhs);

    // Increment/decrement operations
    Rect operator++(Rect& lhs);
    Rect operator--(Rect& lhs);
    Rect operator++(Rect& lhs, int);
    Rect operator--(Rect& lhs, int);

    // Assignment operations
    Rect& operator+=(Rect& lhs, Rect rhs);
    Rect& operator-=(Rect& lhs, Rect rhs);
    Rect& operator*=(Rect& lhs, Rect rhs);
    Rect& operator/=(Rect& lhs, Rect rhs);
    Rect& operator%=(Rect& lhs, Rect rhs);

    // Relational operations
    bool operator==(Rect lhs, Rect rhs);
    bool operator!=(Rect lhs, Rect rhs);
    bool operator<(Rect lhs, Rect rhs);
    bool operator>(Rect lhs, Rect rhs);
    bool operator<=(Rect lhs, Rect rhs);
    bool operator>=(Rect lhs, Rect rhs);
} // namespace nt

#endif // _NT_CORE_MATH_RECT_H_
