#pragma region LICENSE

//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2025 Rohan Bharatia

#pragma endregion LICENSE

#pragma once

#ifndef _NT_MATH_VERTEX_h_
    #define _NT_MATH_VERTEX_h_

#include "../core/Types.h"
#include "Vec2.h"
#include "Vec3.h"
#include "Color.h"

#include <vector>

namespace nt
{
    struct ReadableVertex
    {
        float x, y, z;    // Position
        float u, v;       // Texture
        float r, g, b, a; // Color
    };

    class Vertex
    {
    public:
        Vertex()                               = default;
        Vertex(const Vec3f& position, const Vec2f& uv, const Color& color);
        ~Vertex()                              = default;
        Vertex(const Vertex& other)            = default;
        Vertex& operator=(const Vertex& other) = default;

        ReadableVertex readable();

        Vertex to2D();
        Vertex to3D();

        Vec3f position;
        Vec2f uv;
        Color color;
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

    // Assignment operations
    Vertex operator+=(Vertex& lhs, Vertex rhs);
    Vertex operator-=(Vertex& lhs, Vertex rhs);
    Vertex operator*=(Vertex& lhs, Vertex rhs);
    Vertex operator/=(Vertex& lhs, Vertex rhs);
    Vertex operator%=(Vertex& lhs, Vertex rhs);

    // Relation operations
    bool operator==(Vertex lhs, Vertex rhs);
    bool operator!=(Vertex lhs, Vertex rhs);
    bool operator<(Vertex lhs, Vertex rhs);
    bool operator>(Vertex lhs, Vertex rhs);
    bool operator<=(Vertex lhs, Vertex rhs);
    bool operator>=(Vertex lhs, Vertex rhs);

    using VertexList = std::vector<ReadableVertex>;
} // namespace nt

#endif // _NT_MATH_VERTEX_h_
