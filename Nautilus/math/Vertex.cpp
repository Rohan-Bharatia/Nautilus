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

#ifndef _NT_MATH_VERTEX_cpp_
    #define _NT_MATH_VERTEX_cpp_

#include "Vertex.h"

namespace nt
{
    Vertex::Vertex(const Vec3f& position, const Vec2f& tex, const Color& color) :
        position(position), uv(tex), color(color)
    {}

    ReadableVertex Vertex::readable()
    {
        return ReadableVertex{ position.x, position.y, position.z,
                               uv.x, uv.y,
                               color.red / 255.0f, color.green / 255.0f, color.blue / 255.0f, color.alpha };
    }

    Vertex Vertex::to2D()
    {
        position.z = 0.0f;
        return *this;
    }

    Vertex Vertex::to3D()
    {
        return *this;
    }

    Vertex operator+(Vertex lhs)
    {
        return Vertex(+lhs.position, +lhs.uv, +lhs.color);
    }

    Vertex operator-(Vertex lhs)
    {
        return Vertex(-lhs.position, -lhs.uv, -lhs.color);
    }

    Vertex operator+(Vertex lhs, Vertex rhs)
    {
        return Vertex(lhs.position + rhs.position, lhs.uv + rhs.uv, lhs.color + rhs.color);
    }

    Vertex operator-(Vertex lhs, Vertex rhs)
    {
        return Vertex(lhs.position + rhs.position, lhs.uv + rhs.uv, lhs.color - rhs.color);
    }

    Vertex operator*(Vertex lhs, Vertex rhs)
    {
        return Vertex(lhs.position + rhs.position, lhs.uv + rhs.uv, lhs.color * rhs.color);
    }

    Vertex operator/(Vertex lhs, Vertex rhs)
    {
        return Vertex(lhs.position + rhs.position, lhs.uv + rhs.uv, lhs.color / rhs.color);
    }

    Vertex operator%(Vertex lhs, Vertex rhs)
    {
        return Vertex(lhs.position + rhs.position, lhs.uv + rhs.uv, lhs.color % rhs.color);
    }

    Vertex operator+=(Vertex& lhs, Vertex rhs)
    {
        return lhs = lhs + rhs;
    }

    Vertex operator-=(Vertex& lhs, Vertex rhs)
    {
        return lhs = lhs - rhs;
    }

    Vertex operator*=(Vertex& lhs, Vertex rhs)
    {
        return lhs = lhs * rhs;
    }

    Vertex operator/=(Vertex& lhs, Vertex rhs)
    {
        return lhs = lhs / rhs;
    }

    Vertex operator%=(Vertex& lhs, Vertex rhs)
    {
        return lhs = lhs % rhs;
    }

    bool operator==(Vertex lhs, Vertex rhs)
    {
        return (lhs.position == rhs.position) && (lhs.uv == rhs.uv) && (lhs.color == rhs.color);
    }

    bool operator!=(Vertex lhs, Vertex rhs)
    {
        return (lhs.position != rhs.position) && (lhs.uv != rhs.uv) && (lhs.color != rhs.color);
    }

    bool operator<(Vertex lhs, Vertex rhs)
    {
        return (lhs.position < rhs.position) && (lhs.uv < rhs.uv) && (lhs.color < rhs.color);
    }

    bool operator>(Vertex lhs, Vertex rhs)
    {
        return (lhs.position > rhs.position) && (lhs.uv > rhs.uv) && (lhs.color > rhs.color);
    }

    bool operator<=(Vertex lhs, Vertex rhs)
    {
        return (lhs.position <= rhs.position) && (lhs.uv <= rhs.uv) && (lhs.color <= rhs.color);
    }

    bool operator>=(Vertex lhs, Vertex rhs)
    {
        return (lhs.position >= rhs.position) && (lhs.uv >= rhs.uv) && (lhs.color >= rhs.color);
    }
} // namespace nt

#endif // _NT_MATH_VERTEX_cpp_
