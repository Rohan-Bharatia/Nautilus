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

#ifndef _NT_CORE_VEC2_H_
    #define _NT_CORE_VEC2_H_

#include "PCH.h"
#include "Angle.h"

namespace Nt
{
    template<typename T>
    class NT_API Vec2
    {
    public:
        NT_CLASS_DEFAULTS(Vec2)
        Vec2(void) = default;
        Vec2(T x, T y);

        // Arithmetic operators
        Vec2<T> operator+(const Vec2<T>& other) const;
        Vec2<T> operator+(const T& other) const;
        Vec2<T> operator-(const Vec2<T>& other) const;
        Vec2<T> operator-(const T& other) const;
        Vec2<T> operator*(const Vec2<T>& other) const;
        Vec2<T> operator*(const T& other) const;
        Vec2<T> operator/(const Vec2<T>& other) const;
        Vec2<T> operator/(const T& other) const;
        Vec2<T> operator%(const Vec2<T>& other) const;
        Vec2<T> operator%(const T& other) const;
        Vec2<T> operator++(void);
        Vec2<T> operator++(int);
        Vec2<T> operator--(void);
        Vec2<T> operator--(int);

        // Assignment operators
        Vec2<T>& operator+=(const Vec2<T>& other);
        Vec2<T>& operator+=(const T& other);
        Vec2<T>& operator-=(const Vec2<T>& other);
        Vec2<T>& operator-=(const T& other);
        Vec2<T>& operator*=(const Vec2<T>& other);
        Vec2<T>& operator*=(const T& other);
        Vec2<T>& operator/=(const Vec2<T>& other);
        Vec2<T>& operator/=(const T& other);
        Vec2<T>& operator%=(const Vec2<T>& other);
        Vec2<T>& operator%=(const T& other);

        // Relational operators
        bool operator>(const Vec2<T>& other) const;
        bool operator>(const T& other) const;
        bool operator>=(const Vec2<T>& other) const;
        bool operator>=(const T& other) const;
        bool operator<(const Vec2<T>& other) const;
        bool operator<(const T& other) const;
        bool operator<=(const Vec2<T>& other) const;
        bool operator<=(const T& other) const;
        bool operator==(const Vec2<T>& other) const;
        bool operator==(const T& other) const;
        bool operator!=(const Vec2<T>& other) const;
        bool operator!=(const T& other) const;

        // Conversion operators
        operator T*(void) const;

        // Methods
        float32 Length(void) const;
        float32 LengthSquared(void) const;
        float32 Distance(const Vec2<T>& other) const;
        Vec2<T> Normalize(void) const;
        T Dot(const Vec2<T>& other) const;
        Vec2<T> Cross(const Vec2<T>& other) const;
        Vec2<T> Project(const Vec2<T>& other) const;
        Vec2<T> Rotate(const Angle& other) const;
        Vec2<T> Scale(T other) const;
        Vec2<T> Reflect(const Vec2<T>& normal) const;
        Vec2<T> Midpoint(const Vec2<T>& other) const;
        Vec2<T> Min(const Vec2<T>& other) const;
        Vec2<T> Max(const Vec2<T>& other) const;
        Vec2<T> Clamp(const Vec2<T>& min, const Vec2<T>& max) const;

        T x, y;
    };

    using Vec2f = Vec2<float32>;
    using Vec2i = Vec2<int32>;
    using Vec2u = Vec2<uint32>;
    using Vec2d = Vec2<float64>;
}

#include "Vec2.inl"

#endif // _NT_CORE_VEC2_H_
