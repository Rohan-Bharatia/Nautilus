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

#ifndef _NT_CORE_MATH_VEC2_INL_
    #define _NT_CORE_MATH_VEC2_INL_

#include "Vec2.h"

#include <cassert>

#include "../Platform/Platform.h"
namespace nt
{
    template<typename T> Vec2<T> operator+(Vec2<T> lhs)
    {
        return Vec2<T>(+lhs.x, +lhs.y);
    }

    template<typename T> Vec2<T> operator-(Vec2<T> lhs)
    {
        return Vec2<T>(-lhs.x, -lhs.y);
    }
    template<typename T> Vec2<T> operator+(Vec2<T> lhs, Vec2<T> rhs)
    {
        return Vec2<T>(lhs.x + rhs.x, lhs.y + rhs.y);
    }

    template<typename T> Vec2<T> operator-(Vec2<T> lhs, Vec2<T> rhs)
    {
        return Vec2<T>(lhs.x - rhs.x, lhs.y - rhs.y);
    }

    template<typename T> Vec2<T> operator*(Vec2<T> lhs, Vec2<T> rhs)
    {
        return Vec2<T>(lhs.x * rhs.x, lhs.y * rhs.y);
    }
    template<typename T> Vec2<T> operator/(Vec2<T> lhs, Vec2<T> rhs)
    {
        assert(rhs.x != 0 && rhs.y != 0);
        return Vec2<T>(lhs.x / rhs.x, lhs.y / rhs.y);
    }
    template<typename T> Vec2<T> operator%(Vec2<T> lhs, Vec2<T> rhs)
    {
        assert(rhs.x != 0 && rhs.y != 0);
        return Vec2<T>(NT_MODULUS(lhs.x, rhs.x), NT_MODULUS(lhs.y, rhs.y));
    }

    template<typename T> Vec2<T> operator++(Vec2<T>& lhs)
    {
        ++lhs.x;
        ++lhs.y;
        return lhs;
    }

    template<typename T> Vec2<T> operator--(Vec2<T>& lhs)
    {
        --lhs.x;
        --lhs.y;
        return lhs;
    }

    template<typename T> Vec2<T> operator++(Vec2<T>& lhs, int)
    {
        Vec2<T> temp = lhs;
        ++lhs.x;
        ++lhs.y;
        return temp;
    }

    template<typename T> Vec2<T> operator--(Vec2<T>& lhs, int)
    {
        Vec2<T> temp = lhs;
        --lhs.x;
        --lhs.y;
        return temp;
    }

    template<typename T> Vec2<T>& operator+=(Vec2<T>& lhs, Vec2<T> rhs)
    {
        return lhs = lhs + rhs;
    }

    template<typename T> Vec2<T>& operator-=(Vec2<T>& lhs, Vec2<T> rhs)
    {
        return lhs = lhs - rhs;
    }
    template<typename T> Vec2<T>& operator*=(Vec2<T>& lhs, Vec2<T> rhs)
    {
        return lhs = lhs * rhs;
    }
    template<typename T> Vec2<T>& operator/=(Vec2<T>& lhs, Vec2<T> rhs)
    {
        assert(rhs.x != 0 && rhs.y != 0);
        return lhs = lhs / rhs;
    }
    template<typename T> Vec2<T>& operator%=(Vec2<T>& lhs, Vec2<T> rhs)
    {
        assert(rhs.x != 0 && rhs.y != 0);
        return lhs = lhs % rhs;
    }

    template<typename T> bool operator==(Vec2<T> lhs, Vec2<T> rhs)
    {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
    template<typename T> bool operator!=(Vec2<T> lhs, Vec2<T> rhs)
    {
        return !(lhs == rhs);
    }
    template<typename T> bool operator<(Vec2<T> lhs, Vec2<T> rhs)
    {
        return lhs.x < rhs.x && lhs.y < rhs.y;
    }
    template<typename T> bool operator>(Vec2<T> lhs, Vec2<T> rhs)
    {
        return lhs.x > rhs.x && lhs.y > rhs.y;
    }
    template<typename T> bool operator<=(Vec2<T> lhs, Vec2<T> rhs)
    {
        return !(lhs > rhs);
    }
    template<typename T> bool operator>=(Vec2<T> lhs, Vec2<T> rhs)
    {
        return !(lhs < rhs);
    }
} // namespace nt

#endif // _NT_CORE_MATH_VEC2_INL_
