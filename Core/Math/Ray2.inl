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

#ifndef _NT_CORE_MATH_RAY2_INL_
    #define _NT_CORE_MATH_RAY2_INL_

#include "Ray2.h"

#include <cassert>

namespace nt
{
    template<typename T> Ray2<T> operator+(Ray2<T> lhs)
    {
        return Ray2<T>(+lhs.origin, +lhs.direction);
    }

    template<typename T> Ray2<T> operator-(Ray2<T> lhs)
    {
        return Ray2<T>(-lhs.origin, -lhs.direction);
    }

    template<typename T> Ray2<T> operator+(Ray2<T> lhs, Ray2<T> rhs)
    {
        return Ray2<T>(lhs.origin + rhs.origin, lhs.direction + rhs.direction);
    }

    template<typename T> Ray2<T> operator-(Ray2<T> lhs, Ray2<T> rhs)
    {
        return Ray2<T>(lhs.origin - rhs.origin, lhs.direction - rhs.direction);
    }

    template<typename T> Ray2<T> operator*(Ray2<T> lhs, Ray2<T> rhs)
    {
        return Ray2<T>(lhs.origin * rhs.origin, lhs.direction * rhs.direction);
    }

    template<typename T> Ray2<T> operator/(Ray2<T> lhs, Ray2<T> rhs)
    {
        assert(rhs.origin.x != 0 && rhs.origin.y != 0 && rhs.direction.x != 0 && rhs.direction.y != 0);
        return Ray2<T>(lhs.origin / rhs.origin, lhs.direction / rhs.direction);
    }

    template<typename T> Ray2<T> operator%(Ray2<T> lhs, Ray2<T> rhs)
    {
        assert(rhs.origin.x != 0 && rhs.origin.y != 0 && rhs.direction.x != 0 && rhs.direction.y != 0);
        return Ray2<T>(lhs.origin % rhs.origin, lhs.direction % rhs.direction);
    }

    template<typename T> Ray2<T> operator++(Ray2<T>& lhs)
    {
        ++lhs.origin;
        ++lhs.direction;
        return lhs;
    }

    template<typename T> Ray2<T> operator--(Ray2<T>& lhs)
    {
        --lhs.origin;
        --lhs.direction;
        return lhs;
    }

    template<typename T> Ray2<T> operator++(Ray2<T>& lhs, int)
    {
        Ray2<T> temp = lhs;
        ++lhs.origin;
        ++lhs.direction;
        return temp;
    }

    template<typename T> Ray2<T> operator--(Ray2<T>& lhs, int)
    {
        Ray2<T> temp = lhs;
        ++lhs.origin;
        ++lhs.direction;
        return temp;
    }

    template<typename T> Ray2<T>& operator+=(Ray2<T>& lhs, Ray2<T> rhs)
    {
        return lhs = lhs + rhs;
    }

    template<typename T> Ray2<T>& operator-=(Ray2<T>& lhs, Ray2<T> rhs)
    {
        return lhs = lhs - rhs;
    }

    template<typename T> Ray2<T>& operator*=(Ray2<T>& lhs, Ray2<T> rhs)
    {
        return lhs = lhs * rhs;
    }

    template<typename T> Ray2<T>& operator/=(Ray2<T>& lhs, Ray2<T> rhs)
    {
        assert(rhs.origin.x != 0 && rhs.origin.y != 0 && rhs.direction.x != 0 && rhs.direction.y != 0);
        return lhs = lhs / rhs;
    }

    template<typename T> Ray2<T>& operator%=(Ray2<T>& lhs, Ray2<T> rhs)
    {
        assert(rhs.origin.x != 0 && rhs.origin.y != 0 && rhs.direction.x != 0 && rhs.direction.y != 0);
        return lhs = lhs % rhs;
    }

    template<typename T> bool operator==(Ray2<T> lhs, Ray2<T> rhs)
    {
        return lhs.origin == rhs.origin && lhs.direction == rhs.direction;
    }

    template<typename T> bool operator!=(Ray2<T> lhs, Ray2<T> rhs)
    {
        return !(lhs == rhs);
    }

    template<typename T> bool operator<(Ray2<T> lhs, Ray2<T> rhs)
    {
        return (lhs.origin < rhs.origin) || (lhs.origin == rhs.origin && lhs.direction < rhs.direction);
    }

    template<typename T> bool operator>(Ray2<T> lhs, Ray2<T> rhs)
    {
        return (lhs.origin > rhs.origin) || (lhs.origin == rhs.origin && lhs.direction > rhs.direction);
    }

    template<typename T> bool operator<=(Ray2<T> lhs, Ray2<T> rhs)
    {
        return !(lhs > rhs);
    }

    template<typename T> bool operator>=(Ray2<T> lhs, Ray2<T> rhs)
    {
        return !(lhs < rhs);
    }
} // namespace nt

#endif // _NT_CORE_MATH_RAY2_INL_
