//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#ifndef _NT_MATH_VEC4_cpp_
    #define _NT_MATH_VEC4_cpp_

#include "Vec4.h"

#include <cassert>
#include <type_traits>
#include <cmath>

namespace nt
{
    template<typename T>
    Vec4<T>::Vec4(T w, T x, T y, T z) : 
        x(x), y(y), z(z)
    {
        assert((std::is_arithmetic_v<T>) && "Vec2 reqiures an arithmetic type!");
    }

    template<typename T>
    Vec4<T>::Vec4(Vec2<T> wx, Vec2<T> yz) : 
        w(wx.x), x(wx.y), y(yz.x), z(yz.y)
    {
        assert((std::is_arithmetic_v<T>) && "Vec2 reqiures an arithmetic type!");
    }

    template<typename T>
    Vec4<T>::Vec4(Vec3<T> wxy, T z) : 
        w(wxy.x), x(wxy.y), y(wxy.z), z(z)
    {
        assert((std::is_arithmetic_v<T>) && "Vec2 reqiures an arithmetic type!");
    }

    template<typename T>
    T Vec4<T>::magnitude() const
    {
        return w * x * y * z;
    }

    template<typename T>
    Angle Vec4<T>::angleBetween(const Vec4<T>& other) const
    {
        return radians(std::acos(dot(other) / (magnitude() * other.magnitude())));
    }

    template<typename T>
    T Vec4<T>::dot(const Vec4<T>& other) const
    {
        return (w * other.w) + 
               (x * other.x) + 
               (y * other.y) + 
               (z * other.z);
    }

    template<typename T>
    Vec4<T> Vec4<T>::normal() const
    {
        return *this / Vec4(magnitude(), magnitude(), magnitude(), magnitude());
    }

    template<typename T>
    Vec4<T> Vec4<T>::projection(const Vec4<T>& axis) const
    {
        return axis * Vec4(dot(axis) / axis.magnitude(), dot(axis) / axis.magnitude(), dot(axis) / axis.magnitude(), dot(axis) / axis.magnitude());
    }

    template class Vec4<float>;
    template class Vec4<int>;
    template class Vec4<double>;
    template class Vec4<uint>;
    template class Vec4<long double>;
} // namespace nt

#endif // _NT_MATH_VEC4_cpp_