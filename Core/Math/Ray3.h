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

namespace nt
{
    template<typename T> class Ray3
    {
    public:
        Ray3()                             = default;
        Ray3(const Vec3<T>& origin, const Vec3<T>& direction);
        ~Ray3()                            = default;
        Ray3(const Ray3& other)            = default;
        Ray3& operator=(const Ray3& other) = default;

        // 3D ray methods
        Vec3<T> pointAt(float t) const;
        Vec3<T> reflect(const Vec3<T>& normal) const;
        Vec3<T> refract(const Vec3<T>& normal, float index) const;
        float distanceTo(const Vec3<T>& point) const;
        bool isParallel(const Ray3<T>& other) const;

        Vec3<T> origin;
        Vec3<T> direction;
    };

    // Sign operations
    template<typename T> Ray3<T> operator+(Ray3<T> lhs);
    template<typename T> Ray3<T> operator-(Ray3<T> lhs);

    // Arithmetic operations
    template<typename T> Ray3<T> operator+(Ray3<T> lhs, Ray3<T> rhs);
    template<typename T> Ray3<T> operator-(Ray3<T> lhs, Ray3<T> rhs);
    template<typename T> Ray3<T> operator*(Ray3<T> lhs, Ray3<T> rhs);
    template<typename T> Ray3<T> operator/(Ray3<T> lhs, Ray3<T> rhs);
    template<typename T> Ray3<T> operator%(Ray3<T> lhs, Ray3<T> rhs);

    // Increment/decrement operations
    template<typename T> Ray3<T> operator++(Ray3<T>& lhs);
    template<typename T> Ray3<T> operator--(Ray3<T>& lhs);
    template<typename T> Ray3<T> operator++(Ray3<T>& lhs, int);
    template<typename T> Ray3<T> operator--(Ray3<T>& lhs, int);

    // Assignment operations
    template<typename T> Ray3<T>& operator+=(Ray3<T>& lhs, Ray3<T> rhs);
    template<typename T> Ray3<T>& operator-=(Ray3<T>& lhs, Ray3<T> rhs);
    template<typename T> Ray3<T>& operator*=(Ray3<T>& lhs, Ray3<T> rhs);
    template<typename T> Ray3<T>& operator/=(Ray3<T>& lhs, Ray3<T> rhs);
    template<typename T> Ray3<T>& operator%=(Ray3<T>& lhs, Ray3<T> rhs);

    // Relational operations
    template<typename T> bool operator==(Ray3<T> lhs, Ray3<T> rhs);
    template<typename T> bool operator!=(Ray3<T> lhs, Ray3<T> rhs);
    template<typename T> bool operator<(Ray3<T> lhs, Ray3<T> rhs);
    template<typename T> bool operator>(Ray3<T> lhs, Ray3<T> rhs);
    template<typename T> bool operator<=(Ray3<T> lhs, Ray3<T> rhs);
    template<typename T> bool operator>=(Ray3<T> lhs, Ray3<T> rhs);

    // Template classes
    using Ray3f = Ray3<float>;
    using Ray3d = Ray3<double>;
    using Ray3i = Ray3<int>;
    using Ray3u = Ray3<unsigned int>;
    using Ray3l = Ray3<long>;
} // namespace nt

#include "Ray3.inl"

#endif // _NT_CORE_MATH_RAY3_H_
