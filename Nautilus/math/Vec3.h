//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#pragma once

#ifndef _NT_MATH_VEC3_h_
    #define _NT_MATH_VEC3_h_

#include "../core/Types.h"
#include "Vec2.h"

namespace nt
{
    template<typename T>
    class Vec3
    {
    public:
        Vec3()                             = default;
        Vec3(T x, T y, T z);
        Vec3(Vec2<T> xy, T z);
        ~Vec3()                            = default;
        Vec3(const Vec3& other)            = default;
        Vec3& operator=(const Vec3& other) = default;

        T magnitude() const;
        T dot(const Vec3& other) const;
        Vec3 cross(const Vec3& other) const;
        Angle angleBetween(const Vec3& other) const;
        Vec3 normal() const;
        Vec3 projection(const Vec3& axis) const;

        T x;
        T y;
        T z;
    };

    // Sign operations
    template<typename T>
    Vec3<T> operator+(Vec3<T> lhs);
    template<typename T>
    Vec3<T> operator-(Vec3<T> lhs);

    // Arithmetic operations
    template<typename T>
    Vec3<T> operator+(Vec3<T> lhs, Vec3<T> rhs);
    template<typename T>
    Vec3<T> operator-(Vec3<T> lhs, Vec3<T> rhs);
    template<typename T>
    Vec3<T> operator*(Vec3<T> lhs, Vec3<T> rhs);
    template<typename T>
    Vec3<T> operator/(Vec3<T> lhs, Vec3<T> rhs);
    template<typename T>
    Vec3<T> operator%(Vec3<T> lhs, Vec3<T> rhs);

    // Assignment operations
    template<typename T>
    Vec3<T> operator+=(Vec3<T>& lhs, Vec3<T> rhs);
    template<typename T>
    Vec3<T> operator-=(Vec3<T>& lhs, Vec3<T> rhs);
    template<typename T>
    Vec3<T> operator*=(Vec3<T>& lhs, Vec3<T> rhs);
    template<typename T>
    Vec3<T> operator/=(Vec3<T>& lhs, Vec3<T> rhs);
    template<typename T>
    Vec3<T> operator%=(Vec3<T>& lhs, Vec3<T> rhs);

    // Relation operations
    template <typename T>
    bool operator==(Vec3<T> lhs, Vec3<T> rhs);
    template <typename T>
    bool operator!=(Vec3<T> lhs, Vec3<T> rhs);
    template <typename T>
    bool operator<(Vec3<T> lhs, Vec3<T> rhs);
    template <typename T>
    bool operator>(Vec3<T> lhs, Vec3<T> rhs);
    template <typename T>
    bool operator<=(Vec3<T> lhs, Vec3<T> rhs);
    template <typename T>
    bool operator>=(Vec3<T> lhs, Vec3<T> rhs);

    using Vec3f = Vec3<float>;
    using Vec3i = Vec3<int>;
    using Vec3d = Vec3<double>;
    using Vec3u = Vec3<uint>;
    using Vec3l = Vec3<long double>;
} // namespace nt

#include "Vec3.inl"

#endif // _NT_MATH_VEC3_h_