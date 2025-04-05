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

#ifndef _NT_CORE_MATH_VEC3_CPP_
    #define _NT_CORE_MATH_VEC3_CPP_

#include "Vec3.h"

#include <type_traits>
#include <cassert>
#include <cmath>

namespace nt
{
    template<typename T> Vec3<T>::Vec3(T x, T y, T z) :
        x(x), y(y), z(z)
    {
        assert(std::is_arithmetic<T>::value);
    }

    template<typename T> T Vec3<T>::length() const
    {
        return sqrt(x * x + y * y + z * z);
    }

    template<typename T> T Vec3<T>::lengthSquared() const
    {
        return x * x + y * y + z * z;
    }

    template<typename T> T Vec3<T>::dot(const Vec3& other) const
    {
        return x * other.x + y * other.y + z * other.z;
    }

    template<typename T> Vec3<T> Vec3<T>::cross(const Vec3& other) const
    {
        return Vec3(y * other.z - z * other.y,
                    z * other.x - x * other.z,
                    x * other.y - y * other.x);
    }

    template<typename T> Vec3<T> Vec3<T>::normalize() const
    {
        T len = length();
        if (len == 0)
            return Vec3(0, 0, 0);
        return Vec3(x / len, y / len, z / len);
    }

    template<typename T> Vec3<T> Vec3<T>::perpendicular() const
    {
        return Vec3(-y, x, 0);
    }

    template<typename T> Vec3<T> Vec3<T>::reflect(const Vec3<T>& normal) const
    {
        T d = dot(normal);
        return Vec3(x - 2 * d * normal.x, y - 2 * d * normal.y, z - 2 * d * normal.z);
    }

    template<typename T> Vec3<T> Vec3<T>::rotate(float angle) const
    {
        // Assuming XY plane rotation
        float cosAngle = cos(angle);
        float sinAngle = sin(angle);
        return Vec3(x * cosAngle - y * sinAngle, x * sinAngle + y * cosAngle, z);
    }

    template<typename T> Vec3<T> Vec3<T>::lerp(const Vec3<T>& other, float t) const
    {
        assert(t >= 0 && t <= 1);
        return Vec3(x + (other.x - x) * t, y + (other.y - y) * t, z + (other.z - z) * t);
    }

    template<typename T> Vec3<T> Vec3<T>::slerp(const Vec3<T>& other, float t) const
    {
        assert(t >= 0 && t <= 1);
        T acosDot = acos(dot(other));
        return Vec3(sin((1 - t) * acosDot) / sin(acosDot) * x + sin(t * acosDot) / sin(acosDot) * other.x,
                    sin((1 - t) * acosDot) / sin(acosDot) * y + sin(t * acosDot) / sin(acosDot) * other.y,
                    sin((1 - t) * acosDot) / sin(acosDot) * z + sin(t * acosDot) / sin(acosDot) * other.z);
    }

    template class Vec3<float>;
    template class Vec3<double>;
    template class Vec3<int>;
    template class Vec3<unsigned int>;
    template class Vec3<long>;
} // namespace nt

#endif // _NT_CORE_MATH_VEC3_CPP_
