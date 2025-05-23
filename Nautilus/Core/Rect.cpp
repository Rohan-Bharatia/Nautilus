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

#ifndef _NT_CORE_MATH_RECT_CPP_
    #define _NT_CORE_MATH_RECT_CPP_

#include "Rect.h"

#include "Assertion.h"

namespace Nt
{
    Rect::Rect(const Vec2f& position, const Vec2f& size) :
        position(position), size(size)
    {}

    Rect::Rect(const Vec2f& position, float32 width, float32 height) :
        position(position), size(width, height)
    {}

    Rect::Rect(float32 x, float32 y, float32 width, float32 height) :
        position(x, y), size(width, height)
    {}

    Rect Rect::operator+(const Rect& other) const
    {
        return Rect(position + other.position, size + other.size);
    }

    Rect Rect::operator+(float32 other) const
    {
        return Rect(position + other, size + other);
    }

    Rect Rect::operator-(const Rect& other) const
    {
        return Rect(position - other.position, size - other.size);
    }

    Rect Rect::operator-(float32 other) const
    {
        return Rect(position - other, size - other);
    }

    Rect Rect::operator*(const Rect& other) const
    {
        return Rect(position * other.position, size * other.size);
    }

    Rect Rect::operator*(float32 other) const
    {
        return Rect(position * other, size * other);
    }

    Rect Rect::operator/(const Rect& other) const
    {
        NT_ASSERT(other == 0.0f, "Cannot divide by zero!");
        return Rect(position / other.position, size / other.size);
    }

    Rect Rect::operator/(float32 other) const
    {
        NT_ASSERT(other == 0.0f, "Cannot divide by zero!");
        return Rect(position / other, size / other);
    }

    Rect Rect::operator%(const Rect& other) const
    {
        NT_ASSERT(other == 0.0f, "Cannot modulus by zero!");
        return Rect(position % other.position, size % other.size);
    }

    Rect Rect::operator%(float32 other) const
    {
        NT_ASSERT(other == 0.0f, "Cannot modulus by zero!");
        return Rect(position % other, size % other);
    }

    Rect Rect::operator++(void)
    {
        ++position;
        ++size;
        return *this;
    }

    Rect Rect::operator++(int)
    {
        Rect temp = *this;
        ++position;
        ++size;
        return temp;
    }

    Rect Rect::operator--(void)
    {
        --position;
        --size;
        return *this;
    }

    Rect Rect::operator--(int)
    {
        Rect temp = *this;
        --position;
        --size;
        return temp;
    }

    Rect& Rect::operator+=(const Rect& other)
    {
        return *this = *this + other;
    }

    Rect& Rect::operator+=(float32 other)
    {
        return *this = *this + other;
    }

    Rect& Rect::operator-=(const Rect& other)
    {
        return *this = *this - other;
    }

    Rect& Rect::operator-=(float32 other)
    {
        return *this = *this - other;
    }

    Rect& Rect::operator*=(const Rect& other)
    {
        return *this = *this * other;
    }

    Rect& Rect::operator*=(float32 other)
    {
        return *this = *this * other;
    }

    Rect& Rect::operator/=(const Rect& other)
    {
        NT_ASSERT(other == 0.0f, "Cannot divide by zero!");
        return *this = *this / other;
    }

    Rect& Rect::operator/=(float32 other)
    {
        NT_ASSERT(other == 0.0f, "Cannot divide by zero!");
        return *this = *this / other;
    }

    Rect& Rect::operator%=(const Rect& other)
    {
        NT_ASSERT(other == 0.0f, "Cannot modulus by zero!");
        return *this = *this % other;
    }

    Rect& Rect::operator%=(float32 other)
    {
        NT_ASSERT(other == 0.0f, "Cannot modulus by zero!");
        return *this = *this % other;
    }

    bool Rect::operator>(const Rect& other) const
    {
        return (position > other.position && size > other.size);
    }

    bool Rect::operator>(float32 other) const
    {
        return (position > other && size > other);
    }

    bool Rect::operator>=(const Rect& other) const
    {
        return (position >= other.position && size >= other.size);
    }

    bool Rect::operator>=(float32 other) const
    {
        return (position >= other && size >= other);
    }

    bool Rect::operator<(const Rect& other) const
    {
        return (position < other.position && size < other.size);
    }

    bool Rect::operator<(float32 other) const
    {
        return (position < other && size < other);
    }

    bool Rect::operator<=(const Rect& other) const
    {
        return (position <= other.position && size <= other.size);
    }

    bool Rect::operator<=(float32 other) const
    {
        return (position <= other && size <= other);
    }

    bool Rect::operator==(const Rect& other) const
    {
        return (position == other.position && size == other.size);
    }

    bool Rect::operator==(float32 other) const
    {
        return (position == other && size == other);
    }

    bool Rect::operator!=(const Rect& other) const
    {
        return (position != other.position || size != other.size);
    }

    bool Rect::operator!=(float32 other) const
    {
        return (position != other || size != other);
    }

    void Rect::Resize(const Vec2f& other)
    {
        size = other;
    }

    void Rect::Resize(float32 width, float32 height)
    {
        size = Vec2f(width, height);
    }

    void Rect::MoveTo(const Vec2f& other)
    {
        position = other;
    }

    void Rect::MoveTo(float32 x, float32 y)
    {
        position = Vec2f(x, y);
    }

    void Rect::Move(const Vec2f& offset)
    {
        position += offset;
    }

    void Rect::Move(float32 offsetX, float32 offsetY)
    {
        position += Vec2f(offsetX, offsetY);
    }
} // namespace Nt

#endif // _NT_CORE_MATH_RECT_CPP_
