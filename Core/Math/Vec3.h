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

namespace nt
{
    template<typename T> class Vec3
    {
    public:
        Vec3()                             = default;
        Vec3(T x, T y, T z);
        ~Vec3()                            = default;
        Vec3(const Vec3& other)            = default;
        Vec3& operator=(const Vec3& other) = default;

        // 3D vector methods
        T length() const;
        T lengthSquared() const;
        T dot(const Vec3& other) const;
        Vec3 cross(const Vec3& other) const;
        Vec3 normalize() const;
        Vec3 perpendicular() const;
        Vec3 reflect(const Vec3& normal) const;
        Vec3 rotate(float angle) const;
        Vec3 lerp(const Vec3& other, float t) const;
        Vec3 slerp(const Vec3& other, float t) const;

        T x, y, z;
    };

    // Sign operations
    template<typename T> Vec3<T> operator+(Vec3<T> lhs);
    template<typename T> Vec3<T> operator-(Vec3<T> lhs);

    // Arithmetic operations
    template<typename T> Vec3<T> operator+(Vec3<T> lhs, Vec3<T> rhs);
    template<typename T> Vec3<T> operator-(Vec3<T> lhs, Vec3<T> rhs);
    template<typename T> Vec3<T> operator*(Vec3<T> lhs, Vec3<T> rhs);
    template<typename T> Vec3<T> operator/(Vec3<T> lhs, Vec3<T> rhs);
    template<typename T> Vec3<T> operator%(Vec3<T> lhs, Vec3<T> rhs);

    // Increment/decrement operations
    template<typename T> Vec3<T> operator++(Vec3<T>& lhs);
    template<typename T> Vec3<T> operator--(Vec3<T>& lhs);
    template<typename T> Vec3<T> operator++(Vec3<T>& lhs, int);
    template<typename T> Vec3<T> operator--(Vec3<T>& lhs, int);

    // Assignment operations
    template<typename T> Vec3<T>& operator+=(Vec3<T>& lhs, Vec3<T> rhs);
    template<typename T> Vec3<T>& operator-=(Vec3<T>& lhs, Vec3<T> rhs);
    template<typename T> Vec3<T>& operator*=(Vec3<T>& lhs, Vec3<T> rhs);
    template<typename T> Vec3<T>& operator/=(Vec3<T>& lhs, Vec3<T> rhs);
    template<typename T> Vec3<T>& operator%=(Vec3<T>& lhs, Vec3<T> rhs);

    // Relational operations
    template<typename T> bool operator==(Vec3<T> lhs, Vec3<T> rhs);
    template<typename T> bool operator!=(Vec3<T> lhs, Vec3<T> rhs);
    template<typename T> bool operator<(Vec3<T> lhs, Vec3<T> rhs);
    template<typename T> bool operator>(Vec3<T> lhs, Vec3<T> rhs);
    template<typename T> bool operator<=(Vec3<T> lhs, Vec3<T> rhs);
    template<typename T> bool operator>=(Vec3<T> lhs, Vec3<T> rhs);

    // Template classes
    using Vec3f = Vec3<float>;
    using Vec3d = Vec3<double>;
    using Vec3i = Vec3<int>;
    using Vec3u = Vec3<unsigned int>;
    using Vec3l = Vec3<long>;
} // namespace nt

#include "Vec3.inl"

#endif // _NT_CORE_MATH_VEC3_H_
