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

#ifndef _NT_CORE_MATH_VEC3_H_
    #define _NT_CORE_MATH_VEC3_H_

#include "Vec2.h"

namespace Nt
{
    template<typename T>
    class NT_API Vec3
    {
    public:
        NT_CLASS_DEFAULTS(Vec3)
        Vec3(T x, T y, T z);
        Vec3(const Vec2<T>& xy, T z);

        // Arithmetic operators
        Vec3<T> operator+(const Vec3<T>& other) const;
        Vec3<T> operator+(const T& other) const;
        Vec3<T> operator-(const Vec3<T>& other) const;
        Vec3<T> operator-(const T& other) const;
        Vec3<T> operator*(const Vec3<T>& other) const;
        Vec3<T> operator*(const T& other) const;
        Vec3<T> operator/(const Vec3<T>& other) const;
        Vec3<T> operator/(const T& other) const;
        Vec3<T> operator%(const Vec3<T>& other) const;
        Vec3<T> operator%(const T& other) const;
        Vec3<T> operator++(void);
        Vec3<T> operator++(int);
        Vec3<T> operator--(void);
        Vec3<T> operator--(int);

        // Assignment operators
        Vec3<T>& operator+=(const Vec3<T>& other);
        Vec3<T>& operator+=(const T& other);
        Vec3<T>& operator-=(const Vec3<T>& other);
        Vec3<T>& operator-=(const T& other);
        Vec3<T>& operator*=(const Vec3<T>& other);
        Vec3<T>& operator*=(const T& other);
        Vec3<T>& operator/=(const Vec3<T>& other);
        Vec3<T>& operator/=(const T& other);
        Vec3<T>& operator%=(const Vec3<T>& other);
        Vec3<T>& operator%=(const T& other);

        // Relational operators
        bool operator>(const Vec3<T>& other) const;
        bool operator>(const T& other) const;
        bool operator>=(const Vec3<T>& other) const;
        bool operator>=(const T& other) const;
        bool operator<(const Vec3<T>& other) const;
        bool operator<(const T& other) const;
        bool operator<=(const Vec3<T>& other) const;
        bool operator<=(const T& other) const;
        bool operator==(const Vec3<T>& other) const;
        bool operator==(const T& other) const;
        bool operator!=(const Vec3<T>& other) const;
        bool operator!=(const T& other) const;

        // Methods
        float32 Length(void) const;
        float32 LengthSquared(void) const;
        float32 Distance(const Vec3<T>& other) const;
        Vec3<T> Normalize(void) const;
        T Dot(const Vec3<T>& other) const;
        Vec3<T> Cross(const Vec3<T>& other) const;
        Vec3<T> Project(const Vec3<T>& other) const;
        Vec3<T> Rotate(const Angle& other) const;
        Vec3<T> Scale(T other) const;
        Vec3<T> Reflect(const Vec3<T>& normal) const;
        Vec3<T> Midpoint(const Vec3<T>& other) const;
        Vec3<T> Min(const Vec3<T>& other) const;
        Vec3<T> Max(const Vec3<T>& other) const;
        Vec3<T> Clamp(const Vec3<T>& min, const Vec3<T>& max) const;

        T x, y, z;
    };

    using Vec3f = Vec3<float32>;
    using Vec3i = Vec3<int32>;
    using Vec3u = Vec3<uint32>;
    using Vec3d = Vec3<float64>;
}

#include "Vec3.inl"

#endif // _NT_CORE_MATH_VEC3_H_
