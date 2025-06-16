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

#ifndef _NT_CORE_MATH_RAY3_H_
    #define _NT_CORE_MATH_RAY3_H_

#include "Vec3.h"
#include "Ray2.h"

namespace Nt
{
    template<typename T>
    class NT_API Ray3
    {
    public:
        NT_CLASS_DEFAULTS(Ray3)
        Ray3(const Vec3<T>& origin, const Vec3<T>& direction);
        Ray3(T originX, T originY, T originZ, T directionX, T directionY , T directionZ);
        Ray3(const Ray3<T>& other, T originZ, T directionZ);

        // Arithmetic operators
        Ray3<T> operator+(const Ray3<T>& other) const;
        Ray3<T> operator+(const T& other) const;
        Ray3<T> operator-(const Ray3<T>& other) const;
        Ray3<T> operator-(const T& other) const;
        Ray3<T> operator*(const Ray3<T>& other) const;
        Ray3<T> operator*(const T& other) const;
        Ray3<T> operator/(const Ray3<T>& other) const;
        Ray3<T> operator/(const T& other) const;
        Ray3<T> operator%(const Ray3<T>& other) const;
        Ray3<T> operator%(const T& other) const;
        Ray3<T> operator++(void);
        Ray3<T> operator++(int);
        Ray3<T> operator--(void);
        Ray3<T> operator--(int);

        // Assignment operators
        Ray3<T>& operator+=(const Ray3<T>& other);
        Ray3<T>& operator+=(const T& other);
        Ray3<T>& operator-=(const Ray3<T>& other);
        Ray3<T>& operator-=(const T& other);
        Ray3<T>& operator*=(const Ray3<T>& other);
        Ray3<T>& operator*=(const T& other);
        Ray3<T>& operator/=(const Ray3<T>& other);
        Ray3<T>& operator/=(const T& other);
        Ray3<T>& operator%=(const Ray3<T>& other);
        Ray3<T>& operator%=(const T& other);

        // Relational operators
        bool operator>(const Ray3<T>& other) const;
        bool operator>(const T& other) const;
        bool operator>=(const Ray3<T>& other) const;
        bool operator>=(const T& other) const;
        bool operator<(const Ray3<T>& other) const;
        bool operator<(const T& other) const;
        bool operator<=(const Ray3<T>& other) const;
        bool operator<=(const T& other) const;
        bool operator==(const Ray3<T>& other) const;
        bool operator==(const T& other) const;
        bool operator!=(const Ray3<T>& other) const;
        bool operator!=(const T& other) const;

        // Conversion operators
        operator T*(void) const;

        // Methods
        bool Intersects(const Ray3<T>& other) const;
        Vec3<T> IntersectionPoint(const Ray3<T>& other) const;
        float32 Distance(const Vec3<T>& point) const;
        float32 Distance(const Ray3<T>& other) const;
        Ray3<T> Normalize(void) const;
        Vec3<T> Project(const Vec3<T>& other) const;
        Vec3<T> Project(const Ray3<T>& other) const;
        Vec3<T> Reflect(const Vec3<T>& other) const;
        Vec3<T> Reflect(const Ray3<T>& other) const;

        Vec3<T> origin;
        Vec3<T> direction;
    };
} // namespace Nt

#include "Ray3.inl"

#endif // _NT_CORE_MATH_RAY3_H_
