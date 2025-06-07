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

#include "Vec3.h"

namespace Nt
{
    template<typename T>
    class NT_API Vec4
    {
    public:
        NT_CLASS_DEFAULTS(Vec4)
        Vec4(T x, T y, T z, T w);
        Vec4(const Vec2<T>& xy, T z, T w);
        Vec4(const Vec3<T>& xyz, T w);

        // Arithmetic operators
        Vec4<T> operator+(const Vec4<T>& other) const;
        Vec4<T> operator+(const T& other) const;
        Vec4<T> operator-(const Vec4<T>& other) const;
        Vec4<T> operator-(const T& other) const;
        Vec4<T> operator*(const Vec4<T>& other) const;
        Vec4<T> operator*(const T& other) const;
        Vec4<T> operator/(const Vec4<T>& other) const;
        Vec4<T> operator/(const T& other) const;
        Vec4<T> operator%(const Vec4<T>& other) const;
        Vec4<T> operator%(const T& other) const;
        Vec4<T> operator++(void);
        Vec4<T> operator++(int);
        Vec4<T> operator--(void);
        Vec4<T> operator--(int);

        // Assignment operators
        Vec4<T>& operator+=(const Vec4<T>& other);
        Vec4<T>& operator+=(const T& other);
        Vec4<T>& operator-=(const Vec4<T>& other);
        Vec4<T>& operator-=(const T& other);
        Vec4<T>& operator*=(const Vec4<T>& other);
        Vec4<T>& operator*=(const T& other);
        Vec4<T>& operator/=(const Vec4<T>& other);
        Vec4<T>& operator/=(const T& other);
        Vec4<T>& operator%=(const Vec4<T>& other);
        Vec4<T>& operator%=(const T& other);

        // Relational operators
        bool operator>(const Vec4<T>& other) const;
        bool operator>(const T& other) const;
        bool operator>=(const Vec4<T>& other) const;
        bool operator>=(const T& other) const;
        bool operator<(const Vec4<T>& other) const;
        bool operator<(const T& other) const;
        bool operator<=(const Vec4<T>& other) const;
        bool operator<=(const T& other) const;
        bool operator==(const Vec4<T>& other) const;
        bool operator==(const T& other) const;
        bool operator!=(const Vec4<T>& other) const;
        bool operator!=(const T& other) const;

        // Conversion operators
        operator T*(void) const;

        // Methods
        float32 Length(void) const;
        float32 LengthSquared(void) const;
        float32 Distance(const Vec4<T>& other) const;
        Vec4<T> Normalize(void) const;
        T Dot(const Vec4<T>& other) const;
        Vec4<T> Cross(const Vec4<T>& other) const;
        Vec4<T> Project(const Vec4<T>& other) const;
        Vec4<T> Rotate(const Angle& other) const;
        Vec4<T> Scale(T other) const;
        Vec4<T> Reflect(const Vec4<T>& normal) const;
        Vec4<T> Midpoint(const Vec4<T>& other) const;
        Vec4<T> Min(const Vec4<T>& other) const;
        Vec4<T> Max(const Vec4<T>& other) const;
        Vec4<T> Clamp(const Vec4<T>& min, const Vec4<T>& max) const;

        T x, y, z, w;
    };

    using Vec4f = Vec4<float32>;
    using Vec4i = Vec4<int32>;
    using Vec4u = Vec4<uint32>;
    using Vec4d = Vec4<float64>;

    template<typename T>
    using Quaternion  = Vec4<T>;
    using Quaternionf = Vec4f;
    using Quaternioni = Vec4i;
    using Quaternionu = Vec4u;
    using Quaterniond = Vec4d;
}

#include "Vec4.inl"

#endif // _NT_CORE_MATH_VEC4_H_
