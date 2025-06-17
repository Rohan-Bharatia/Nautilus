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

#ifndef _NT_CORE_RAY2_H_
    #define _NT_CORE_RAY2_H_

#include "Vec2.h"

namespace Nt
{
    template<typename T>
    class NT_API Ray2
    {
    public:
        NT_CLASS_DEFAULTS(Ray2)
        Ray2(void) = default;
        Ray2(const Vec2<T>& origin, const Vec2<T>& direction);
        Ray2(T originX, T originY, T directionX, T directionY);

        // Arithmetic operators
        Ray2<T> operator+(const Ray2<T>& other) const;
        Ray2<T> operator+(const T& other) const;
        Ray2<T> operator-(const Ray2<T>& other) const;
        Ray2<T> operator-(const T& other) const;
        Ray2<T> operator*(const Ray2<T>& other) const;
        Ray2<T> operator*(const T& other) const;
        Ray2<T> operator/(const Ray2<T>& other) const;
        Ray2<T> operator/(const T& other) const;
        Ray2<T> operator%(const Ray2<T>& other) const;
        Ray2<T> operator%(const T& other) const;
        Ray2<T> operator++(void);
        Ray2<T> operator++(int);
        Ray2<T> operator--(void);
        Ray2<T> operator--(int);

        // Assignment operators
        Ray2<T>& operator+=(const Ray2<T>& other);
        Ray2<T>& operator+=(const T& other);
        Ray2<T>& operator-=(const Ray2<T>& other);
        Ray2<T>& operator-=(const T& other);
        Ray2<T>& operator*=(const Ray2<T>& other);
        Ray2<T>& operator*=(const T& other);
        Ray2<T>& operator/=(const Ray2<T>& other);
        Ray2<T>& operator/=(const T& other);
        Ray2<T>& operator%=(const Ray2<T>& other);
        Ray2<T>& operator%=(const T& other);

        // Relational operators
        bool operator>(const Ray2<T>& other) const;
        bool operator>(const T& other) const;
        bool operator>=(const Ray2<T>& other) const;
        bool operator>=(const T& other) const;
        bool operator<(const Ray2<T>& other) const;
        bool operator<(const T& other) const;
        bool operator<=(const Ray2<T>& other) const;
        bool operator<=(const T& other) const;
        bool operator==(const Ray2<T>& other) const;
        bool operator==(const T& other) const;
        bool operator!=(const Ray2<T>& other) const;
        bool operator!=(const T& other) const;

        // Conversion operators
        operator T*(void) const;

        // Methods
        bool Intersects(const Ray2<T>& other) const;
        Vec2<T> IntersectionPoint(const Ray2<T>& other) const;
        float32 Distance(const Vec2<T>& point) const;
        float32 Distance(const Ray2<T>& other) const;
        Ray2<T> Normalize(void) const;
        Vec2<T> Project(const Vec2<T>& other) const;
        Vec2<T> Project(const Ray2<T>& other) const;
        Vec2<T> Reflect(const Vec2<T>& other) const;
        Vec2<T> Reflect(const Ray2<T>& other) const;

        Vec2<T> origin;
        Vec2<T> direction;
    };
} // namespace Nt

#include "Ray2.inl"

#endif // _NT_CORE_RAY2_H_
