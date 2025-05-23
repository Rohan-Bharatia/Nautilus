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

#ifndef _NT_CORE_MATH_VERTEX_CPP_
    #define _NT_CORE_MATH_VERTEX_CPP_

#include "Vertex.h"

#include "Assertion.h"

namespace Nt
{
    Vertex::Vertex(const Vec3f& position, const Color& color) :
        position(position), color(color)
    {}

    Vertex Vertex::operator+(const Vertex& other) const
    {
        return Vertex(position + other.position, color + other.color);
    }

    Vertex Vertex::operator+(float32 other) const
    {
        return Vertex(position + other, color);
    }

    Vertex Vertex::operator-(const Vertex& other) const
    {
        return Vertex(position - other.position, color - other.color);
    }

    Vertex Vertex::operator-(float32 other) const
    {
        return Vertex(position - other, color);
    }

    Vertex Vertex::operator*(const Vertex& other) const
    {
        return Vertex(position * other.position, color * other.color);
    }

    Vertex Vertex::operator*(float32 other) const
    {
        return Vertex(position * other, color);
    }

    Vertex Vertex::operator/(const Vertex& other) const
    {
        NT_ASSERT(other.position == 0.0f && other.color == 0.0f, "Cannot divide by zero!");
        return Vertex(position / other.position, color / other.color);
    }

    Vertex Vertex::operator/(float32 other) const
    {
        NT_ASSERT(other == 0.0f, "Cannot divide by zero!");
        return Vertex(position / other, color);
    }

    Vertex Vertex::operator%(const Vertex& other) const
    {
        NT_ASSERT(other.position == 0.0f && other.color == 0.0f, "Cannot modulus by zero!");
        return Vertex(position % other.position, color % other.color);
    }

    Vertex Vertex::operator%(float32 other) const
    {
        NT_ASSERT(other == 0.0f, "Cannot modulus by zero!");
        return Vertex(position % other, color);
    }

    Vertex Vertex::operator++(void)
    {
        ++position;
        ++color;
        return *this;
    }

    Vertex Vertex::operator++(int)
    {
        Vertex temp = *this;
        ++*this;
        return temp;
    }

    Vertex Vertex::operator--(void)
    {
        --position;
        --color;
        return *this;
    }

    Vertex Vertex::operator--(int)
    {
        Vertex temp = *this;
        --*this;
        return temp;
    }

    Vertex& Vertex::operator+=(const Vertex& other)
    {
        return *this = *this + other;
    }

    Vertex& Vertex::operator+=(float32 other)
    {
        return *this = *this + other;
    }

    Vertex& Vertex::operator-=(const Vertex& other)
    {
        return *this = *this - other;
    }

    Vertex& Vertex::operator-=(float32 other)
    {
        return *this = *this - other;
    }

    Vertex& Vertex::operator*=(const Vertex& other)
    {
        return *this = *this * other;
    }

    Vertex& Vertex::operator*=(float32 other)
    {
        return *this = *this * other;
    }

    Vertex& Vertex::operator/=(const Vertex& other)
    {
        NT_ASSERT(other.position == 0.0f && other.color == 0.0f, "Cannot divide by zero!");
        return *this = *this / other;
    }

    Vertex& Vertex::operator/=(float32 other)
    {
        NT_ASSERT(other == 0.0f, "Cannot divide by zero!");
        return *this = *this / other;
    }

    Vertex& Vertex::operator%=(const Vertex& other)
    {
        NT_ASSERT(other.position == 0.0f && other.color == 0.0f, "Cannot modulus by zero!");
        return *this = *this % other;
    }

    Vertex& Vertex::operator%=(float32 other)
    {
        NT_ASSERT(other == 0.0f, "Cannot modulus by zero!");
        return *this = *this % other;
    }

    bool Vertex::operator>(const Vertex& other) const
    {
        return (position > other.position && color > other.color);
    }

    bool Vertex::operator>(float32 other) const
    {
        return (position > other && color > other);
    }

    bool Vertex::operator>=(const Vertex& other) const
    {
        return (position >= other.position && color >= other.color);
    }

    bool Vertex::operator>=(float32 other) const
    {
        return (position >= other && color >= other);
    }

    bool Vertex::operator<(const Vertex& other) const
    {
        return (position < other.position && color < other.color);
    }

    bool Vertex::operator<(float32 other) const
    {
        return (position < other && color < other);
    }

    bool Vertex::operator<=(const Vertex& other) const
    {
        return (position <= other.position && color <= other.color);
    }

    bool Vertex::operator<=(float32 other) const
    {
        return (position <= other && color <= other);
    }

    bool Vertex::operator==(const Vertex& other) const
    {
        return (position == other.position && color == other.color);
    }

    bool Vertex::operator==(float32 other) const
    {
        return (position == other && color == other);
    }

    bool Vertex::operator!=(const Vertex& other) const
    {
        return (position != other.position || color != other.color);
    }

    bool Vertex::operator!=(float32 other) const
    {
        return (position != other || color != other);
    }

    Vertex::operator ReadableVertex(void) const
    {
        return ReadableVertex{ { position.x, position.y, position.z }, { color.r, color.g, color.b, color.a } };
    }

    ReadableVertex Vertex::ToReadableVertex(void) const
    {
        return (ReadableVertex)(*this);
    }
} // namespace Nt

#endif // _NT_CORE_MATH_VERTEX_CPP_
