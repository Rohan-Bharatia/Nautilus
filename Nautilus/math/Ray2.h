//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#pragma once

#ifndef _NT_MATH_RAY2_h_
    #define _NT_MATH_RAY2_h_

#include "../core/Types.h"
#include "Vec2.h"

namespace nt
{
    template<typename T>
    class Ray2
    {
    public:
        Ray2()                             = default;
        Ray2(Vec2<T> origin, Vec2<T> direction);
        ~Ray2()                            = default;
        Ray2(const Ray2& other)            = default;
        Ray2& operator=(const Ray2& other) = default;

        Vec2<T> origin;
        Vec2<T> direction;
    };

    // Sign operations
    template<typename T>
    Ray2<T> operator+(Ray2<T> lhs);
    template<typename T>
    Ray2<T> operator-(Ray2<T> lhs);

    // Arithmetic operations
    template<typename T>
    Ray2<T> operator+(Ray2<T> lhs, Ray2<T> rhs);
    template<typename T>
    Ray2<T> operator-(Ray2<T> lhs, Ray2<T> rhs);
    template<typename T>
    Ray2<T> operator*(Ray2<T> lhs, Ray2<T> rhs);
    template<typename T>
    Ray2<T> operator/(Ray2<T> lhs, Ray2<T> rhs);
    template<typename T>
    Ray2<T> operator%(Ray2<T> lhs, Ray2<T> rhs);

    // Assignment operations
    template<typename T>
    Ray2<T> operator+=(Ray2<T>& lhs, Ray2<T> rhs);
    template<typename T>
    Ray2<T> operator-=(Ray2<T>& lhs, Ray2<T> rhs);
    template<typename T>
    Ray2<T> operator*=(Ray2<T>& lhs, Ray2<T> rhs);
    template<typename T>
    Ray2<T> operator/=(Ray2<T>& lhs, Ray2<T> rhs);
    template<typename T>
    Ray2<T> operator%=(Ray2<T>& lhs, Ray2<T> rhs);

    // Relation operations
    template <typename T>
    bool operator==(Ray2<T> lhs, Ray2<T> rhs);
    template <typename T>
    bool operator!=(Ray2<T> lhs, Ray2<T> rhs);
    template <typename T>
    bool operator<(Ray2<T> lhs, Ray2<T> rhs);
    template <typename T>
    bool operator>(Ray2<T> lhs, Ray2<T> rhs);
    template <typename T>
    bool operator<=(Ray2<T> lhs, Ray2<T> rhs);
    template <typename T>
    bool operator>=(Ray2<T> lhs, Ray2<T> rhs);

    using Ray2f = Ray2<float>;
    using Ray2i = Ray2<int>;
    using Ray2d = Ray2<double>;
    using Ray2u = Ray2<uint>;
    using Ray2l = Ray2<long double>;
}

#include "Ray2.inl"

#endif // _NT_MATH_RAY2_h_