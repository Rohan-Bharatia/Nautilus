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

#ifndef _NT_CORE_MATH_VEC4_CPP_
    #define _NT_CORE_MATH_VEC4_CPP_

#include "Vec4.h"

#include <type_traits>
#include <cassert>
#include <cmath>

namespace nt
{
    template<typename T> Vec4<T>::Vec4(T w, T x, T y, T z) :
        w(w), x(x), y(y), z(z)
    {
        assert(std::is_arithmetic<T>::value);
    }

    template<typename T> T Vec4<T>::length() const
    {
        return sqrt(w * w + x * x + y * y + z * z);
    }

    template<typename T> T Vec4<T>::lengthSquared() const
    {
        return w * w + x * x + y * y + z * z;
    }

    template<typename T> T Vec4<T>::dot(const Vec4& other) const
    {
        return w * other.w + x * other.x + y * other.y + z * other.z;
    }

    template<typename T> Vec4<T> Vec4<T>::normalize() const
    {
        T len = length();
        if (len == 0)
            return Vec4(0, 0, 0, 0);
        return Vec4(w / len, x / len, y / len, z / len);
    }

    template<typename T> Vec4<T> Vec4<T>::perpendicular() const
    {
        // Assuming 4D space, we can return a vector that is orthogonal to the current vector
        // by swapping two components and negating one of them.
        return Vec4(-y, x, -z, w);
    }

    template<typename T> Vec4<T> Vec4<T>::reflect(const Vec4<T>& normal) const
    {
        T d = dot(normal);
        return Vec4(w - 2 * d * normal.w, x - 2 * d * normal.x, y - 2 * d * normal.y, z - 2 * d * normal.z);
    }

    template<typename T> Vec4<T> Vec4<T>::rotate(float angle) const
    {
        // Assuming rotation in the XY plane
        float cosAngle = cos(angle);
        float sinAngle = sin(angle);
        return Vec4(x * cosAngle - y * sinAngle, x * sinAngle + y * cosAngle, z, w);
    }

    template<typename T> Vec4<T> Vec4<T>::lerp(const Vec4<T>& other, float t) const
    {
        assert(t >= 0 && t <= 1);
        return Vec4(w + (other.w - w) * t, x + (other.x - x) * t, y + (other.y - y) * t, z + (other.z - z) * t);
    }

    template<typename T> Vec4<T> Vec4<T>::slerp(const Vec4<T>& other, float t) const
    {
        assert(t >= 0 && t <= 1);
        T acosDot = acos(dot(other));
        return Vec4(sin((1 - t) * acosDot) / sin(acosDot) * w + sin(t * acosDot) / sin(acosDot) * other.w,
                    sin((1 - t) * acosDot) / sin(acosDot) * x + sin(t * acosDot) / sin(acosDot) * other.x,
                    sin((1 - t) * acosDot) / sin(acosDot) * y + sin(t * acosDot) / sin(acosDot) * other.y,
                    sin((1 - t) * acosDot) / sin(acosDot) * z + sin(t * acosDot) / sin(acosDot) * other.z);
    }

    template class Vec4<float>;
    template class Vec4<double>;
    template class Vec4<int>;
    template class Vec4<unsigned int>;
    template class Vec4<long>;
} // namespace nt

#endif // _NT_CORE_MATH_VEC4_CPP_
