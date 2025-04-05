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

#pragma once

#ifndef _NT_CORE_MATH_VEC4_H_
    #define _NT_CORE_MATH_VEC4_H_

#include "../Platform/Platform.h"

namespace nt
{
    template<typename T> class NT_API Vec4
    {
    public:
        Vec4()                             = default;
        Vec4(T w, T x, T y, T z);
        ~Vec4()                            = default;
        Vec4(const Vec4& other)            = default;
        Vec4& operator=(const Vec4& other) = default;

        // 4D vector methods
        T length() const;
        T lengthSquared() const;
        T dot(const Vec4& other) const;
        Vec4 normalize() const;
        Vec4 perpendicular() const;
        Vec4 reflect(const Vec4& normal) const;
        Vec4 rotate(float angle) const;
        Vec4 lerp(const Vec4& other, float t) const;
        Vec4 slerp(const Vec4& other, float t) const;

        T w, x, y, z;
    };

    // Sign operations
    template<typename T> Vec4<T> operator+(Vec4<T> lhs);
    template<typename T> Vec4<T> operator-(Vec4<T> lhs);

    // Arithmetic operations
    template<typename T> Vec4<T> operator+(Vec4<T> lhs, Vec4<T> rhs);
    template<typename T> Vec4<T> operator-(Vec4<T> lhs, Vec4<T> rhs);
    template<typename T> Vec4<T> operator*(Vec4<T> lhs, Vec4<T> rhs);
    template<typename T> Vec4<T> operator/(Vec4<T> lhs, Vec4<T> rhs);
    template<typename T> Vec4<T> operator%(Vec4<T> lhs, Vec4<T> rhs);

    // Increment/decrement operations
    template<typename T> Vec4<T> operator++(Vec4<T>& lhs);
    template<typename T> Vec4<T> operator--(Vec4<T>& lhs);
    template<typename T> Vec4<T> operator++(Vec4<T>& lhs, int);
    template<typename T> Vec4<T> operator--(Vec4<T>& lhs, int);

    // Assignment operations
    template<typename T> Vec4<T>& operator+=(Vec4<T>& lhs, Vec4<T> rhs);
    template<typename T> Vec4<T>& operator-=(Vec4<T>& lhs, Vec4<T> rhs);
    template<typename T> Vec4<T>& operator*=(Vec4<T>& lhs, Vec4<T> rhs);
    template<typename T> Vec4<T>& operator/=(Vec4<T>& lhs, Vec4<T> rhs);
    template<typename T> Vec4<T>& operator%=(Vec4<T>& lhs, Vec4<T> rhs);

    // Relational operations
    template<typename T> bool operator==(Vec4<T> lhs, Vec4<T> rhs);
    template<typename T> bool operator!=(Vec4<T> lhs, Vec4<T> rhs);
    template<typename T> bool operator<(Vec4<T> lhs, Vec4<T> rhs);
    template<typename T> bool operator>(Vec4<T> lhs, Vec4<T> rhs);
    template<typename T> bool operator<=(Vec4<T> lhs, Vec4<T> rhs);
    template<typename T> bool operator>=(Vec4<T> lhs, Vec4<T> rhs);

    // Template classes
    using Vec4f = Vec4<float>;
    using Vec4d = Vec4<double>;
    using Vec4i = Vec4<int>;
    using Vec4u = Vec4<unsigned int>;
    using Vec4l = Vec4<long>;
} // namespace nt

#include "Vec4.inl"

#endif // _NT_CORE_MATH_VEC4_H_
