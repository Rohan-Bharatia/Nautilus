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

#ifndef _NT_CORE_MATH_RAY2_H_
    #define _NT_CORE_MATH_RAY2_H_

#include "../Platform/Platform.h"
#include "Vec2.h"

namespace nt
{
    template<typename T> class NT_API Ray2
    {
    public:
        Ray2()                             = default;
        Ray2(const Vec2<T>& origin, const Vec2<T>& direction);
        ~Ray2()                            = default;
        Ray2(const Ray2& other)            = default;
        Ray2& operator=(const Ray2& other) = default;

        // 2D ray methods
        Vec2<T> pointAt(float t) const;
        Vec2<T> reflect(const Vec2<T>& normal) const;
        Vec2<T> refract(const Vec2<T>& normal, float index) const;
        float distanceTo(const Vec2<T>& point) const;

        Vec2<T> origin;
        Vec2<T> direction;
    };

    // Sign operations
    template<typename T> Ray2<T> operator+(Ray2<T> lhs);
    template<typename T> Ray2<T> operator-(Ray2<T> lhs);

    // Arithmetic operations
    template<typename T> Ray2<T> operator+(Ray2<T> lhs, Ray2<T> rhs);
    template<typename T> Ray2<T> operator-(Ray2<T> lhs, Ray2<T> rhs);
    template<typename T> Ray2<T> operator*(Ray2<T> lhs, Ray2<T> rhs);
    template<typename T> Ray2<T> operator/(Ray2<T> lhs, Ray2<T> rhs);
    template<typename T> Ray2<T> operator%(Ray2<T> lhs, Ray2<T> rhs);

    // Increment/decrement operations
    template<typename T> Ray2<T> operator++(Ray2<T>& lhs);
    template<typename T> Ray2<T> operator--(Ray2<T>& lhs);
    template<typename T> Ray2<T> operator++(Ray2<T>& lhs, int);
    template<typename T> Ray2<T> operator--(Ray2<T>& lhs, int);

    // Assignment operations
    template<typename T> Ray2<T>& operator+=(Ray2<T>& lhs, Ray2<T> rhs);
    template<typename T> Ray2<T>& operator-=(Ray2<T>& lhs, Ray2<T> rhs);
    template<typename T> Ray2<T>& operator*=(Ray2<T>& lhs, Ray2<T> rhs);
    template<typename T> Ray2<T>& operator/=(Ray2<T>& lhs, Ray2<T> rhs);
    template<typename T> Ray2<T>& operator%=(Ray2<T>& lhs, Ray2<T> rhs);

    // Relational operations
    template<typename T> bool operator==(Ray2<T> lhs, Ray2<T> rhs);
    template<typename T> bool operator!=(Ray2<T> lhs, Ray2<T> rhs);
    template<typename T> bool operator<(Ray2<T> lhs, Ray2<T> rhs);
    template<typename T> bool operator>(Ray2<T> lhs, Ray2<T> rhs);
    template<typename T> bool operator<=(Ray2<T> lhs, Ray2<T> rhs);
    template<typename T> bool operator>=(Ray2<T> lhs, Ray2<T> rhs);

    // Template classes
    using Ray2f = Ray2<float>;
    using Ray2d = Ray2<double>;
    using Ray2i = Ray2<int>;
    using Ray2u = Ray2<unsigned int>;
    using Ray2l = Ray2<long>;
} // namespace nt

#include "Ray2.inl"

#endif // _NT_CORE_MATH_RAY2_H_
