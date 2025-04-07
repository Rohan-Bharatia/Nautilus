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

#ifndef _NT_CORE_MATH_VERTEX_H_
    #define _NT_CORE_MATH_VERTEX_H_

#include "../Platform/Platform.h"
#include "Vec3.h"
#include "Vec2.h"
#include "Color.h"

namespace nt
{
    class NT_API Vertex
    {
    public:
        Vertex()                        = default;
        Vertex(Vec3f pos, Vec2f uv, Color col);
        ~Vertex()                       = default;
        Vertex(const Vertex&)            = default;
        Vertex& operator=(const Vertex&) = default;

        Vec3f pos;
        Vec2f uv;
        Color col;
    };

    // Sign operations
    Vertex operator+(Vertex lhs);
    Vertex operator-(Vertex lhs);

    // Arithmetic operations
    Vertex operator+(Vertex lhs, Vertex rhs);
    Vertex operator-(Vertex lhs, Vertex rhs);
    Vertex operator*(Vertex lhs, Vertex rhs);
    Vertex operator/(Vertex lhs, Vertex rhs);
    Vertex operator%(Vertex lhs, Vertex rhs);

    // Increment/decrement operations
    Vertex operator++(Vertex& lhs);
    Vertex operator--(Vertex& lhs);
    Vertex operator++(Vertex& lhs, int);
    Vertex operator--(Vertex& lhs, int);

    // Assignment operations
    Vertex& operator+=(Vertex& lhs, Vertex rhs);
    Vertex& operator-=(Vertex& lhs, Vertex rhs);
    Vertex& operator*=(Vertex& lhs, Vertex rhs);
    Vertex& operator/=(Vertex& lhs, Vertex rhs);
    Vertex& operator%=(Vertex& lhs, Vertex rhs);

    // Relational operations
    bool operator==(Vertex lhs, Vertex rhs);
    bool operator!=(Vertex lhs, Vertex rhs);
    bool operator<(Vertex lhs, Vertex rhs);
    bool operator>(Vertex lhs, Vertex rhs);
    bool operator<=(Vertex lhs, Vertex rhs);
    bool operator>=(Vertex lhs, Vertex rhs);
} // namespace nt

#endif // _NT_CORE_MATH_VERTEX_H_
