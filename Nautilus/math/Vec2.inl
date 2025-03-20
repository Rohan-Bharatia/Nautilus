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

#ifndef _NT_MATH_VEC2_inl_
    #define _NT_MATH_VEC2_inl_

#include "Vec2.h"

#include "Internal.h"

#include <cassert>

namespace nt
{
    template<typename T>
    Vec2<T> operator+(Vec2<T> lhs)
    {
        return Vec2(+lhs.x, +lhs.y);
    }

    template<typename T>
    Vec2<T> operator-(Vec2<T> lhs)
    {
        return Vec2(-lhs.x, -lhs.y);
    }

    template<typename T>
    Vec2<T> operator+(Vec2<T> lhs, Vec2<T> rhs)
    {
        return Vec2(lhs.x + rhs.x, lhs.y + rhs.y);
    }

    template<typename T>
    Vec2<T> operator-(Vec2<T> lhs, Vec2<T> rhs)
    {
        return Vec2(lhs.x - rhs.x, lhs.y - rhs.y);
    }

    template<typename T>
    Vec2<T> operator*(Vec2<T> lhs, Vec2<T> rhs)
    {
        return Vec2(lhs.x * rhs.x, lhs.y * rhs.y);
    }

    template<typename T>
    Vec2<T> operator/(Vec2<T> lhs, Vec2<T> rhs)
    {
        assert(rhs.x != 0.0f && "Vec2 operator / cannot divide by zero!");
        assert(rhs.y != 0.0f && "Vec2 operator / cannot divide by zero!");
        return Vec2(lhs.x / rhs.x, lhs.y / rhs.y);
    }

    template<typename T>
    Vec2<T> operator%(Vec2<T> lhs, Vec2<T> rhs)
    {
        assert(rhs.x != 0.0f && "Vec2 operator % cannot modulus by zero!");
        assert(rhs.y != 0.0f && "Vec2 operator % cannot modulus by zero!");
        return Vec2(internal::positiveRemainder<T>(lhs.x, rhs.x), internal::positiveRemainder<T>(lhs.y, rhs.y));
    }

    template<typename T>
    Vec2<T> operator+=(Vec2<T>& lhs, Vec2<T> rhs)
    {
        return lhs = lhs + rhs;
    }

    template<typename T>
    Vec2<T> operator-=(Vec2<T>& lhs, Vec2<T> rhs)
    {
        return lhs = lhs - rhs;
    }

    template<typename T>
    Vec2<T> operator*=(Vec2<T>& lhs, Vec2<T> rhs)
    {
        return lhs = lhs * rhs;
    }

    template<typename T>
    Vec2<T> operator/=(Vec2<T>& lhs, Vec2<T> rhs)
    {
        assert(rhs.x != 0.0f && "Vec2 operator /= cannot divide by zero!");
        assert(rhs.y != 0.0f && "Vec2 operator /= cannot divide by zero!");
        return lhs = lhs / rhs;
    }

    template<typename T>
    Vec2<T> operator%=(Vec2<T>& lhs, Vec2<T> rhs)
    {
        assert(rhs.x != 0.0f && "Vec2 operator %= cannot modulus by zero!");
        assert(rhs.y != 0.0f && "Vec2 operator %= cannot modulus by zero!");
        return lhs = lhs % rhs;
    }

    template <typename T>
    bool operator==(Vec2<T> lhs, Vec2<T> rhs)
    {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y);
    }

    template <typename T>
    bool operator!=(Vec2<T> lhs, Vec2<T> rhs)
    {
        return (lhs.x != rhs.x) && (lhs.y != rhs.y);
    }

    template <typename T>
    bool operator<(Vec2<T> lhs, Vec2<T> rhs)
    {
        return (lhs.x < rhs.x) && (lhs.y < rhs.y);
    }

    template <typename T>
    bool operator>(Vec2<T> lhs, Vec2<T> rhs)
    {
        return (lhs.x > rhs.x) && (lhs.y > rhs.y);
    }

    template <typename T>
    bool operator<=(Vec2<T> lhs, Vec2<T> rhs)
    {
        return (lhs.x <= rhs.x) && (lhs.y <= rhs.y);
    }

    template <typename T>
    bool operator>=(Vec2<T> lhs, Vec2<T> rhs)
    {
        return (lhs.x >= rhs.x) && (lhs.y >= rhs.y);
    }
} // namespace nt

#endif // _NT_MATH_VEC2_inl_
