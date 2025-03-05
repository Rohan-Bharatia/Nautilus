//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#pragma once

#ifndef _NT_MATH_VEC4_h_
    #define _NT_MATH_VEC4_h_

#include "../core/Types.h"
#include "Vec2.h"
#include "Vec3.h"

namespace nt
{
    template<typename T>
    class Vec4
    {
    public:
        Vec4()                             = default;
        Vec4(T w, T x, T y, T z);
        Vec4(Vec2<T> wx, Vec2<T> yz);
        Vec4(Vec3<T> wxy, T z);
        ~Vec4()                            = default;
        Vec4(const Vec4& other)            = default;
        Vec4& operator=(const Vec4& other) = default;

        T magnitude() const;
        T dot(const Vec4& other) const;
        Angle angleBetween(const Vec4& other) const;
        Vec4 normal() const;
        Vec4 projection(const Vec4& axis) const;

        T w;
        T x;
        T y;
        T z;
    };

    // Sign operations
    template<typename T>
    Vec4<T> operator+(Vec4<T> lhs);
    template<typename T>
    Vec4<T> operator-(Vec4<T> lhs);

    // Arithmetic operations
    template<typename T>
    Vec4<T> operator+(Vec4<T> lhs, Vec4<T> rhs);
    template<typename T>
    Vec4<T> operator-(Vec4<T> lhs, Vec4<T> rhs);
    template<typename T>
    Vec4<T> operator*(Vec4<T> lhs, Vec4<T> rhs);
    template<typename T>
    Vec4<T> operator/(Vec4<T> lhs, Vec4<T> rhs);
    template<typename T>
    Vec4<T> operator%(Vec4<T> lhs, Vec4<T> rhs);

    // Assignment operations
    template<typename T>
    Vec4<T> operator+=(Vec4<T>& lhs, Vec4<T> rhs);
    template<typename T>
    Vec4<T> operator-=(Vec4<T>& lhs, Vec4<T> rhs);
    template<typename T>
    Vec4<T> operator*=(Vec4<T>& lhs, Vec4<T> rhs);
    template<typename T>
    Vec4<T> operator/=(Vec4<T>& lhs, Vec4<T> rhs);
    template<typename T>
    Vec4<T> operator%=(Vec4<T>& lhs, Vec4<T> rhs);

    // Relation operations
    template <typename T>
    bool operator==(Vec4<T> lhs, Vec4<T> rhs);
    template <typename T>
    bool operator!=(Vec4<T> lhs, Vec4<T> rhs);
    template <typename T>
    bool operator<(Vec4<T> lhs, Vec4<T> rhs);
    template <typename T>
    bool operator>(Vec4<T> lhs, Vec4<T> rhs);
    template <typename T>
    bool operator<=(Vec4<T> lhs, Vec4<T> rhs);
    template <typename T>
    bool operator>=(Vec4<T> lhs, Vec4<T> rhs);

    using Vec4f      = Vec4<float>;
    using Vec4i      = Vec4<int>;
    using Vec4d      = Vec4<double>;
    using Vec4u      = Vec4<uint>;
    using Vec4l      = Vec4<long double>;
    template<typename T>
    using Quaternion = Vec4<T>;
} // namespace nt

#include "Vec4.inl"

#endif // _NT_MATH_VEC4_h_