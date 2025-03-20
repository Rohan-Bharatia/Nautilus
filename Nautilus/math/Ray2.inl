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

#ifndef _NT_MATH_RAY2_inl_
    #define _NT_MATH_RAY2_inl_

#include "Ray2.h"

#include <cassert>

namespace nt
{
    template<typename T>
    Ray2<T> operator+(Ray2<T> lhs)
    {
        return Ray2(+lhs.origin, +lhs.origin);
    }

    template<typename T>
    Ray2<T> operator-(Ray2<T> lhs)
    {
        return Ray2(+lhs.origin, +lhs.origin);
    }

    template<typename T>
    Ray2<T> operator+(Ray2<T> lhs, Ray2<T> rhs)
    {
        return Ray2(lhs.origin + rhs.origin, lhs.origin + rhs.direction);
    }

    template<typename T>
    Ray2<T> operator-(Ray2<T> lhs, Ray2<T> rhs)
    {
        return Ray2(lhs.origin - rhs.origin, lhs.origin - rhs.direction);
    }

    template<typename T>
    Ray2<T> operator*(Ray2<T> lhs, Ray2<T> rhs)
    {
        return Ray2(lhs.origin * rhs.origin, lhs.origin * rhs.direction);
    }

    template<typename T>
    Ray2<T> operator/(Ray2<T> lhs, Ray2<T> rhs)
    {
        assert(rhs.origin.x != 0.0f && "Ray2 operator / cannot divide by zero!");
        assert(rhs.origin.y != 0.0f && "Ray2 operator / cannot divide by zero!");
        assert(rhs.direction.x != 0.0f && "Ray2 operator / cannot divide by zero!");
        assert(rhs.direction.y != 0.0f && "Ray2 operator / cannot divide by zero!");
        return Ray2(lhs.origin / rhs.origin, lhs.origin / rhs.direction);
    }

    template<typename T>
    Ray2<T> operator%(Ray2<T> lhs, Ray2<T> rhs)
    {
        assert(rhs.origin.x != 0.0f && "Ray2 operator % cannot modulus by zero!");
        assert(rhs.origin.y != 0.0f && "Ray2 operator % cannot modulus by zero!");
        assert(rhs.direction.x != 0.0f && "Ray2 operator % cannot modulus by zero!");
        assert(rhs.direction.y != 0.0f && "Ray2 operator % cannot modulus by zero!");
        return Ray2(lhs.origin % rhs.origin, lhs.origin % rhs.direction);
    }

    template<typename T>
    Ray2<T> operator+=(Ray2<T>& lhs, Ray2<T> rhs)
    {
        return lhs = lhs + rhs;
    }

    template<typename T>
    Ray2<T> operator-=(Ray2<T>& lhs, Ray2<T> rhs)
    {
        return lhs = lhs - rhs;
    }

    template<typename T>
    Ray2<T> operator*=(Ray2<T>& lhs, Ray2<T> rhs)
    {
        return lhs = lhs * rhs;
    }

    template<typename T>
    Ray2<T> operator/=(Ray2<T>& lhs, Ray2<T> rhs)
    {
        assert(rhs.origin.x != 0.0f && "Ray2 operator /= cannot divide by zero!");
        assert(rhs.origin.y != 0.0f && "Ray2 operator /= cannot divide by zero!");
        assert(rhs.direction.x != 0.0f && "Ray2 operator /= cannot divide by zero!");
        assert(rhs.direction.y != 0.0f && "Ray2 operator /= cannot divide by zero!");
        return lhs = lhs / rhs;
    }

    template<typename T>
    Ray2<T> operator%=(Ray2<T>& lhs, Ray2<T> rhs)
    {
        assert(rhs.origin.x != 0.0f && "Ray2 operator %= cannot modulus by zero!");
        assert(rhs.origin.y != 0.0f && "Ray2 operator %= cannot modulus by zero!");
        assert(rhs.direction.x != 0.0f && "Ray2 operator %= cannot modulus by zero!");
        assert(rhs.direction.y != 0.0f && "Ray2 operator %= cannot modulus by zero!");
        return lhs = lhs % rhs;
    }

    template <typename T>
    bool operator==(Ray2<T> lhs, Ray2<T> rhs)
    {
        return (lhs.origin == rhs.origin) && (lhs.direction == rhs.direction);
    }

    template <typename T>
    bool operator!=(Ray2<T> lhs, Ray2<T> rhs)
    {
        return (lhs.origin != rhs.origin) && (lhs.direction != rhs.direction);
    }

    template <typename T>
    bool operator<(Ray2<T> lhs, Ray2<T> rhs)
    {
        return (lhs.origin < rhs.origin) && (lhs.direction < rhs.direction);
    }

    template <typename T>
    bool operator>(Ray2<T> lhs, Ray2<T> rhs)
    {
        return (lhs.origin > rhs.origin) && (lhs.direction > rhs.direction);
    }

    template <typename T>
    bool operator<=(Ray2<T> lhs, Ray2<T> rhs)
    {
        return (lhs.origin <= rhs.origin) && (lhs.direction <= rhs.direction);
    }

    template <typename T>
    bool operator>=(Ray2<T> lhs, Ray2<T> rhs)
    {
        return (lhs.origin >= rhs.origin) && (lhs.direction >= rhs.direction);
    }

} // namespace nt

#endif // _NT_MATH_RAY2_inl_
