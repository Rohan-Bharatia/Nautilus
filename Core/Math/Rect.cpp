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

#include "../Platform/Platform.h"

#include <cassert>

namespace nt
{
    Rect::Rect(float x, float y, float width, float height)
        : x(x), y(y), width(width), height(height)
    {
        assert(width >= x && height >= y);
    }

    float Rect::area() const
    {
        return width * height;
    }

    float Rect::perimeter() const
    {
        return 2 * (width + height);
    }

    bool Rect::contains(float x, float y) const
    {
        return (x >= this->x && x <= this->x + width && y >= this->y && y <= this->y + height);
    }

    bool Rect::intersects(const Rect& other) const
    {
        return (x < other.x + other.width && x + width > other.x && y < other.y + other.height && y + height > other.y);
    }

    Rect operator+(Rect lhs)
    {
        return Rect(+lhs.x, +lhs.y, +lhs.width, +lhs.height);
    }

    Rect operator-(Rect lhs)
    {
        return Rect(-lhs.x, -lhs.y, -lhs.width, -lhs.height);
    }

    Rect operator+(Rect lhs, Rect rhs)
    {
        return Rect(lhs.x + rhs.x, lhs.y + rhs.y, lhs.width + rhs.width, lhs.height + rhs.height);
    }

    Rect operator-(Rect lhs, Rect rhs)
    {
        return Rect(lhs.x - rhs.x, lhs.y - rhs.y, lhs.width - rhs.width, lhs.height - rhs.height);
    }

    Rect operator*(Rect lhs, Rect rhs)
    {
        return Rect(lhs.x * rhs.x, lhs.y * rhs.y, lhs.width * rhs.width, lhs.height * rhs.height);
    }

    Rect operator/(Rect lhs, Rect rhs)
    {
        assert(rhs.x != 0 && rhs.y != 0 && rhs.width != 0 && rhs.height != 0);
        return Rect(lhs.x / rhs.x, lhs.y / rhs.y, lhs.width / rhs.width, lhs.height / rhs.height);
    }

    Rect operator%(Rect lhs, Rect rhs)
    {
        assert(rhs.x != 0 && rhs.y != 0 && rhs.width != 0 && rhs.height != 0);
        return Rect(NT_MODULUS(lhs.x, rhs.x), NT_MODULUS(lhs.y, rhs.y), NT_MODULUS(lhs.width, rhs.width), NT_MODULUS(lhs.height, rhs.height));
    }

    Rect operator++(Rect& lhs)
    {
        ++lhs.x;
        ++lhs.y;
        ++lhs.width;
        ++lhs.height;
        return lhs;
    }

    Rect operator--(Rect& lhs)
    {
        ++lhs.x;
        ++lhs.y;
        ++lhs.width;
        ++lhs.height;
        return lhs;
    }

    Rect operator++(Rect& lhs, int)
    {
        Rect temp = lhs;
        ++lhs.x;
        ++lhs.y;
        ++lhs.width;
        ++lhs.height;
        return temp;
    }

    Rect operator--(Rect& lhs, int)
    {
        Rect temp = lhs;
        ++lhs.x;
        ++lhs.y;
        ++lhs.width;
        ++lhs.height;
        return temp;
    }

    Rect& operator+=(Rect& lhs, Rect rhs)
    {
        return lhs = lhs + rhs;
    }

    Rect& operator-=(Rect& lhs, Rect rhs)
    {
        return lhs = lhs - rhs;
    }

    Rect& operator*=(Rect& lhs, Rect rhs)
    {
        return lhs = lhs * rhs;
    }

    Rect& operator/=(Rect& lhs, Rect rhs)
    {
        assert(rhs.x != 0 && rhs.y != 0 && rhs.width != 0 && rhs.height != 0);
        return lhs = lhs / rhs;
    }

    Rect& operator%=(Rect& lhs, Rect rhs)
    {
        assert(rhs.x != 0 && rhs.y != 0 && rhs.width != 0 && rhs.height != 0);
        return lhs = lhs % rhs;
    }

    bool operator==(Rect lhs, Rect rhs)
    {
        return (lhs.x == rhs.x && lhs.y == rhs.y && lhs.width == rhs.width && lhs.height == rhs.height);
    }

    bool operator!=(Rect lhs, Rect rhs)
    {
        return !(lhs == rhs);
    }

    bool operator<(Rect lhs, Rect rhs)
    {
        return (lhs.x < rhs.x && lhs.y < rhs.y && lhs.width < rhs.width && lhs.height < rhs.height);
    }

    bool operator>(Rect lhs, Rect rhs)
    {
        return (lhs.x > rhs.x && lhs.y > rhs.y && lhs.width > rhs.width && lhs.height > rhs.height);
    }

    bool operator<=(Rect lhs, Rect rhs)
    {
        return !(lhs > rhs);
    }

    bool operator>=(Rect lhs, Rect rhs)
    {
        return !(lhs < rhs);
    }
} // namespace nt

#endif // _NT_CORE_MATH_RECT_CPP_
