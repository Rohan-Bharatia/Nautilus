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

#include <cassert>

namespace nt
{
    Vertex::Vertex(const Vec3f &position, const Vec2f &texCoord, const Color &color) :
        position(position), texCoord(texCoord), color(color)
    {}

    ReadableVertex Vertex::makeReadable() const
    {
        return { { position.x, position.y, position.z },
                 { texCoord.x, texCoord.y },
                 { color.red / 255.0f, color.green / 255.0f, color.blue / 255.0f, color.alpha } };
    }

    Vertex operator+(Vertex lhs)
    {
        return Vertex(+lhs.position, +lhs.texCoord, +lhs.color);
    }

    Vertex operator-(Vertex lhs)
    {
        return Vertex(-lhs.position, -lhs.texCoord, -lhs.color);
    }

    Vertex operator+(Vertex lhs, Vertex rhs)
    {
        return Vertex(lhs.position + rhs.position, lhs.texCoord + rhs.texCoord, lhs.color + rhs.color);
    }

    Vertex operator-(Vertex lhs, Vertex rhs)
    {
        return Vertex(lhs.position - rhs.position, lhs.texCoord - rhs.texCoord, lhs.color - rhs.color);
    }

    Vertex operator*(Vertex lhs, Vertex rhs)
    {
        return Vertex(lhs.position * rhs.position, lhs.texCoord * rhs.texCoord, lhs.color * rhs.color);
    }

    Vertex operator/(Vertex lhs, Vertex rhs)
    {
        assert(rhs.position.x != 0 && "Vertex operator / cannot divide by zero!");
        assert(rhs.position.y != 0 && "Vertex operator / cannot divide by zero!");
        assert(rhs.position.z != 0 && "Vertex operator / cannot divide by zero!");
        assert(rhs.texCoord.x != 0 && "Vertex operator / cannot divide by zero!");
        assert(rhs.texCoord.y != 0 && "Vertex operator / cannot divide by zero!");
        assert(rhs.color.red != 0 && "Vertex operator / cannot divide by zero!");
        assert(rhs.color.green != 0 && "Vertex operator / cannot divide by zero!");
        assert(rhs.color.blue != 0 && "Vertex operator / cannot divide by zero!");
        assert(rhs.color.alpha != 0 && "Vertex operator / cannot divide by zero!");
        return Vertex(lhs.position / rhs.position, lhs.texCoord / rhs.texCoord, lhs.color / rhs.color);
    }

    Vertex operator%(Vertex lhs, Vertex rhs)
    {
        assert(rhs.position.x != 0 && "Vertex operator % cannot modulus by zero!");
        assert(rhs.position.y != 0 && "Vertex operator % cannot modulus by zero!");
        assert(rhs.position.z != 0 && "Vertex operator % cannot modulus by zero!");
        assert(rhs.texCoord.x != 0 && "Vertex operator % cannot modulus by zero!");
        assert(rhs.texCoord.y != 0 && "Vertex operator % cannot modulus by zero!");
        assert(rhs.color.red != 0 && "Vertex operator % cannot modulus by zero!");
        assert(rhs.color.green != 0 && "Vertex operator % cannot modulus by zero!");
        assert(rhs.color.blue != 0 && "Vertex operator % cannot modulus by zero!");
        assert(rhs.color.alpha != 0 && "Vertex operator % cannot modulus by zero!");
        return Vertex(lhs.position % rhs.position, lhs.texCoord % rhs.texCoord, lhs.color % rhs.color);
    }

    Vertex operator+=(Vertex &lhs, Vertex rhs)
    {
        return lhs = lhs + rhs;
    }

    Vertex operator-=(Vertex &lhs, Vertex rhs)
    {
        return lhs = lhs - rhs;
    }

    Vertex operator*=(Vertex &lhs, Vertex rhs)
    {
        return lhs = lhs * rhs;
    }

    Vertex operator/=(Vertex &lhs, Vertex rhs)
    {
        assert(rhs.position.x != 0 && "Vertex operator /= cannot divide by zero!");
        assert(rhs.position.y != 0 && "Vertex operator /= cannot divide by zero!");
        assert(rhs.position.z != 0 && "Vertex operator /= cannot divide by zero!");
        assert(rhs.texCoord.x != 0 && "Vertex operator /= cannot divide by zero!");
        assert(rhs.texCoord.y != 0 && "Vertex operator /= cannot divide by zero!");
        assert(rhs.color.red != 0 && "Vertex operator /= cannot divide by zero!");
        assert(rhs.color.green != 0 && "Vertex operator /= cannot divide by zero!");
        assert(rhs.color.blue != 0 && "Vertex operator /= cannot divide by zero!");
        assert(rhs.color.alpha != 0 && "Vertex operator /= cannot divide by zero!");
        return lhs = lhs / rhs;
    }

    Vertex operator%=(Vertex& lhs, Vertex rhs)
    {
        assert(rhs.position.x != 0 && "Vertex operator %= cannot modulus by zero!");
        assert(rhs.position.y != 0 && "Vertex operator %= cannot modulus by zero!");
        assert(rhs.position.z != 0 && "Vertex operator %= cannot modulus by zero!");
        assert(rhs.texCoord.x != 0 && "Vertex operator %= cannot modulus by zero!");
        assert(rhs.texCoord.y != 0 && "Vertex operator %= cannot modulus by zero!");
        assert(rhs.color.red != 0 && "Vertex operator %= cannot modulus by zero!");
        assert(rhs.color.green != 0 && "Vertex operator %= cannot modulus by zero!");
        assert(rhs.color.blue != 0 && "Vertex operator %= cannot modulus by zero!");
        assert(rhs.color.alpha != 0 && "Vertex operator %= cannot modulus by zero!");
        return lhs = lhs % rhs;
    }

    bool operator==(Vertex lhs, Vertex rhs)
    {
        return (lhs.position == rhs.position) && (lhs.texCoord == rhs.texCoord) && (lhs.color == rhs.color);
    }

    bool operator!=(Vertex lhs, Vertex rhs)
    {
        return (lhs.position != rhs.position) && (lhs.texCoord != rhs.texCoord) && (lhs.color != rhs.color);
    }

    bool operator<(Vertex lhs, Vertex rhs)
    {
        return (lhs.position < rhs.position) && (lhs.texCoord < rhs.texCoord) && (lhs.color < rhs.color);
    }

    bool operator>(Vertex lhs, Vertex rhs)
    {
        return (lhs.position > rhs.position) && (lhs.texCoord > rhs.texCoord) && (lhs.color > rhs.color);
    }

    bool operator<=(Vertex lhs, Vertex rhs)
    {
        return (lhs.position <= rhs.position) && (lhs.texCoord <= rhs.texCoord) && (lhs.color <= rhs.color);
    }

    bool operator>=(Vertex lhs, Vertex rhs)
    {
        return (lhs.position >= rhs.position) && (lhs.texCoord >= rhs.texCoord) && (lhs.color >= rhs.color);
    }
} // namespace nt

#endif // _NT_MATH_VERTEX_cpp_
