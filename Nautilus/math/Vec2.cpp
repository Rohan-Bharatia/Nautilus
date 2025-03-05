//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#ifndef _NT_MATH_VEC2_cpp_
    #define _NT_MATH_VEC2_cpp_

#include "Vec2.h"

#include <cassert>
#include <type_traits>
#include <cmath>

namespace nt
{
    template<typename T>
    Vec2<T>::Vec2(T x, T y) : 
        x(x), y(y)
    {
        assert((std::is_arithmetic_v<T>) && "Vec2 reqiures an arithmetic type!");
    }

    template<typename T>
    T Vec2<T>::magnitude() const
    {
        return x * y;
    }

    template<typename T>
    Angle Vec2<T>::angleBetween(const Vec2<T>& other) const
    {
        return radians(std::acos(dot(other) / (magnitude() * other.magnitude())));
    }

    template<typename T>
    T Vec2<T>::dot(const Vec2<T>& other) const
    {
        return (x * other.x) + 
               (y * other.y);
    }

    template<typename T>
    Vec2<T> Vec2<T>::normal() const
    {
        return *this / Vec2(magnitude(), magnitude());
    }

    template<typename T>
    Vec2<T> Vec2<T>::projection(const Vec2<T>& axis) const
    {
        return axis * Vec2(dot(axis) / axis.magnitude(), dot(axis) / axis.magnitude());
    }

    template class Vec2<float>;
    template class Vec2<int>;
    template class Vec2<double>;
    template class Vec2<uint>;
    template class Vec2<long double>;
} // namespace nt

#endif // _NT_MATH_VEC2_cpp_