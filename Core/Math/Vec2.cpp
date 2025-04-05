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

#ifndef _NT_CORE_MATH_VEC2_CPP_
    #define _NT_CORE_MATH_VEC2_CPP_

#include "Vec2.h"

#include <type_traits>
#include <cassert>
#include <cmath>

namespace nt
{
    template<typename T> Vec2<T>::Vec2(T x, T y) :
        x(x), y(y)
    {
        assert(std::is_arithmetic<T>::value);
    }

    template<typename T> T Vec2<T>::length() const
    {
        return sqrt(x * x + y * y);
    }

    template<typename T> T Vec2<T>::lengthSquared() const
    {
        return x * x + y * y;
    }

    template<typename T> T Vec2<T>::dot(const Vec2& other) const
    {
        return x * other.x + y * other.y;
    }

    template<typename T> Vec2<T> Vec2<T>::normalize() const
    {
        T len = length();
        if (len == 0)
            return Vec2(0, 0);
        return Vec2(x / len, y / len);
    }

    template<typename T> Vec2<T> Vec2<T>::perpendicular() const
    {
        return Vec2(-y, x);
    }

    template<typename T> Vec2<T> Vec2<T>::reflect(const Vec2<T>& normal) const
    {
        T d = dot(normal);
        return Vec2(x - 2 * d * normal.x, y - 2 * d * normal.y);
    }

    template<typename T> Vec2<T> Vec2<T>::rotate(float angle) const
    {
        float cosAngle = cos(angle);
        float sinAngle = sin(angle);
        return Vec2(x * cosAngle - y * sinAngle, x * sinAngle + y * cosAngle);
    }

    template<typename T> Vec2<T> Vec2<T>::lerp(const Vec2<T>& other, float t) const
    {
        assert(t >= 0 && t <= 1);
        return Vec2(x + (other.x - x) * t, y + (other.y - y) * t);
    }

    template<typename T> Vec2<T> Vec2<T>::slerp(const Vec2<T>& other, float t) const
    {
        assert(t >= 0 && t <= 1);
        T acosDot = acos(dot(other));
        return Vec2(sin((1 - t) * acosDot) / sin(acosDot) * x + sin(t * acosDot) / sin(acosDot) * other.x,
                    sin((1 - t) * acosDot) / sin(acosDot) * y + sin(t * acosDot) / sin(acosDot) * other.y);
    }

    template class Vec2<float>;
    template class Vec2<double>;
    template class Vec2<int>;
    template class Vec2<unsigned int>;
    template class Vec2<long>;
} // namespace nt

#endif // _NT_CORE_MATH_VEC2_CPP_
