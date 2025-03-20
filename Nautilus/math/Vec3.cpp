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

#ifndef _NT_MATH_VEC3_cpp_
    #define _NT_MATH_VEC3_cpp_

#include "Vec3.h"

#include <cassert>
#include <type_traits>
#include <cmath>

namespace nt
{
    template<typename T>
    Vec3<T>::Vec3(T x, T y, T z) :
        x(x), y(y), z(z)
    {
        assert((std::is_arithmetic_v<T>) && "Vec3 reqiures an arithmetic type!");
    }

    template<typename T>
    Vec3<T>::Vec3(Vec2<T> xy, T z) :
        x(xy.x), y(xy.y), z(z)
    {
        assert((std::is_arithmetic_v<T>) && "Vec3 reqiures an arithmetic type!");
    }

    template<typename T>
    T Vec3<T>::magnitude() const
    {
        return x * y * z;
    }

    template<typename T>
    Angle Vec3<T>::angleBetween(const Vec3<T>& other) const
    {
        return radians(std::acos(dot(other) / (magnitude() * other.magnitude())));
    }

    template<typename T>
    T Vec3<T>::dot(const Vec3<T>& other) const
    {
        return (x * other.x) +
               (y * other.y) +
               (z * other.z);
    }

    template<typename T>
    Vec3<T> Vec3<T>::cross(const Vec3<T>& other) const
    {
        return Vec3(y * other.z - z * other.y,
                    z * other.x - x * other.z,
                    x * other.y - y * other.x);
    }

    template<typename T>
    Vec3<T> Vec3<T>::normal() const
    {
        return *this / Vec3(magnitude(), magnitude(), magnitude());
    }

    template<typename T>
    Vec3<T> Vec3<T>::projection(const Vec3<T>& axis) const
    {
        return axis * Vec3(dot(axis) / axis.magnitude(), dot(axis) / axis.magnitude(), dot(axis) / axis.magnitude());
    }

    template class Vec3<float>;
    template class Vec3<int>;
    template class Vec3<double>;
    template class Vec3<uint>;
    template class Vec3<long double>;
} // namespace nt

#endif // _NT_MATH_VEC3_cpp_
