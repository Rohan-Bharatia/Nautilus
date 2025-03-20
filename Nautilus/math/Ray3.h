#pragma region LICENSE

//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2025 Rohan Bharatia

#pragma endregion LICENSE

#pragma once

#ifndef _NT_MATH_RAY3_h_
    #define _NT_MATH_RAY3_h_

#include "../core/Types.h"
#include "Vec3.h"

namespace nt
{
    template<typename T>
    class Ray3
    {
    public:
        Ray3()                             = default;
        Ray3(Vec3<T> origin, Vec3<T> direction);
        ~Ray3()                            = default;
        Ray3(const Ray3& other)            = default;
        Ray3& operator=(const Ray3& other) = default;

        Vec3<T> origin;
        Vec3<T> direction;
    };

    // Sign operations
    template<typename T>
    Ray3<T> operator+(Ray3<T> lhs);
    template<typename T>
    Ray3<T> operator-(Ray3<T> lhs);

    // Arithmetic operations
    template<typename T>
    Ray3<T> operator+(Ray3<T> lhs, Ray3<T> rhs);
    template<typename T>
    Ray3<T> operator-(Ray3<T> lhs, Ray3<T> rhs);
    template<typename T>
    Ray3<T> operator*(Ray3<T> lhs, Ray3<T> rhs);
    template<typename T>
    Ray3<T> operator/(Ray3<T> lhs, Ray3<T> rhs);
    template<typename T>
    Ray3<T> operator%(Ray3<T> lhs, Ray3<T> rhs);

    // Assignment operations
    template<typename T>
    Ray3<T> operator+=(Ray3<T>& lhs, Ray3<T> rhs);
    template<typename T>
    Ray3<T> operator-=(Ray3<T>& lhs, Ray3<T> rhs);
    template<typename T>
    Ray3<T> operator*=(Ray3<T>& lhs, Ray3<T> rhs);
    template<typename T>
    Ray3<T> operator/=(Ray3<T>& lhs, Ray3<T> rhs);
    template<typename T>
    Ray3<T> operator%=(Ray3<T>& lhs, Ray3<T> rhs);

    // Relation operations
    template <typename T>
    bool operator==(Ray3<T> lhs, Ray3<T> rhs);
    template <typename T>
    bool operator!=(Ray3<T> lhs, Ray3<T> rhs);
    template <typename T>
    bool operator<(Ray3<T> lhs, Ray3<T> rhs);
    template <typename T>
    bool operator>(Ray3<T> lhs, Ray3<T> rhs);
    template <typename T>
    bool operator<=(Ray3<T> lhs, Ray3<T> rhs);
    template <typename T>
    bool operator>=(Ray3<T> lhs, Ray3<T> rhs);

    using Ray3f = Ray3<float>;
    using Ray3i = Ray3<int>;
    using Ray3d = Ray3<double>;
    using Ray3u = Ray3<uint>;
    using Ray3l = Ray3<long double>;
}

#include "Ray3.inl"

#endif // _NT_MATH_RAY3_h_
