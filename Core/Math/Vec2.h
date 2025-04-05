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

#ifndef _NT_CORE_MATH_VEC2_H_
    #define _NT_CORE_MATH_VEC2_H_

namespace nt
{
    template<typename T> class Vec2
    {
    public:
        Vec2()                             = default;
        Vec2(T x, T y);
        ~Vec2()                            = default;
        Vec2(const Vec2& other)            = default;
        Vec2& operator=(const Vec2& other) = default;

        // 2D vector methods
        T length() const;
        T lengthSquared() const;
        T dot(const Vec2& other) const;
        Vec2 normalize() const;
        Vec2 perpendicular() const;
        Vec2 reflect(const Vec2& normal) const;
        Vec2 rotate(float angle) const;
        Vec2 lerp(const Vec2& other, float t) const;
        Vec2 slerp(const Vec2& other, float t) const;

        T x, y;
    };

    // Sign operations
    template<typename T> Vec2<T> operator+(Vec2<T> lhs);
    template<typename T> Vec2<T> operator-(Vec2<T> lhs);

    // Arithmetic operations
    template<typename T> Vec2<T> operator+(Vec2<T> lhs, Vec2<T> rhs);
    template<typename T> Vec2<T> operator-(Vec2<T> lhs, Vec2<T> rhs);
    template<typename T> Vec2<T> operator*(Vec2<T> lhs, Vec2<T> rhs);
    template<typename T> Vec2<T> operator/(Vec2<T> lhs, Vec2<T> rhs);
    template<typename T> Vec2<T> operator%(Vec2<T> lhs, Vec2<T> rhs);

    // Increment/decrement operations
    template<typename T> Vec2<T> operator++(Vec2<T>& lhs);
    template<typename T> Vec2<T> operator--(Vec2<T>& lhs);
    template<typename T> Vec2<T> operator++(Vec2<T>& lhs, int);
    template<typename T> Vec2<T> operator--(Vec2<T>& lhs, int);

    // Assignment operations
    template<typename T> Vec2<T>& operator+=(Vec2<T>& lhs, Vec2<T> rhs);
    template<typename T> Vec2<T>& operator-=(Vec2<T>& lhs, Vec2<T> rhs);
    template<typename T> Vec2<T>& operator*=(Vec2<T>& lhs, Vec2<T> rhs);
    template<typename T> Vec2<T>& operator/=(Vec2<T>& lhs, Vec2<T> rhs);
    template<typename T> Vec2<T>& operator%=(Vec2<T>& lhs, Vec2<T> rhs);

    // Relational operations
    template<typename T> bool operator==(Vec2<T> lhs, Vec2<T> rhs);
    template<typename T> bool operator!=(Vec2<T> lhs, Vec2<T> rhs);
    template<typename T> bool operator<(Vec2<T> lhs, Vec2<T> rhs);
    template<typename T> bool operator>(Vec2<T> lhs, Vec2<T> rhs);
    template<typename T> bool operator<=(Vec2<T> lhs, Vec2<T> rhs);
    template<typename T> bool operator>=(Vec2<T> lhs, Vec2<T> rhs);

    // Template classes
    using Vec2f = Vec2<float>;
    using Vec2d = Vec2<double>;
    using Vec2i = Vec2<int>;
    using Vec2u = Vec2<unsigned int>;
    using Vec2l = Vec2<long>;
} // namespace nt

#include "Vec2.inl"

#endif // _NT_CORE_MATH_VEC2_H_
