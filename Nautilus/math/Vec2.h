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

#ifndef _NT_MATH_VEC2_h_
    #define _NT_MATH_VEC2_h_

#include "../core/Types.h"
#include "Angle.h"

namespace nt
{
    template<typename T>
    class Vec2
    {
    public:
        Vec2()                             = default;
        Vec2(T x, T y);
        ~Vec2()                            = default;
        Vec2(const Vec2& other)            = default;
        Vec2& operator=(const Vec2& other) = default;

        T magnitude() const;
        T dot(const Vec2& other) const;
        Angle angleBetween(const Vec2& other) const;
        Vec2 normal() const;
        Vec2 projection(const Vec2& axis) const;

        T x;
        T y;
    };

    // Sign operations
    template<typename T>
    Vec2<T> operator+(Vec2<T> lhs);
    template<typename T>
    Vec2<T> operator-(Vec2<T> lhs);

    // Arithmetic operations
    template<typename T>
    Vec2<T> operator+(Vec2<T> lhs, Vec2<T> rhs);
    template<typename T>
    Vec2<T> operator-(Vec2<T> lhs, Vec2<T> rhs);
    template<typename T>
    Vec2<T> operator*(Vec2<T> lhs, Vec2<T> rhs);
    template<typename T>
    Vec2<T> operator/(Vec2<T> lhs, Vec2<T> rhs);
    template<typename T>
    Vec2<T> operator%(Vec2<T> lhs, Vec2<T> rhs);

    // Assignment operations
    template<typename T>
    Vec2<T> operator+=(Vec2<T>& lhs, Vec2<T> rhs);
    template<typename T>
    Vec2<T> operator-=(Vec2<T>& lhs, Vec2<T> rhs);
    template<typename T>
    Vec2<T> operator*=(Vec2<T>& lhs, Vec2<T> rhs);
    template<typename T>
    Vec2<T> operator/=(Vec2<T>& lhs, Vec2<T> rhs);
    template<typename T>
    Vec2<T> operator%=(Vec2<T>& lhs, Vec2<T> rhs);

    // Relation operations
    template<typename T>
    bool operator==(Vec2<T> lhs, Vec2<T> rhs);
    template<typename T>
    bool operator!=(Vec2<T> lhs, Vec2<T> rhs);
    template<typename T>
    bool operator<(Vec2<T> lhs, Vec2<T> rhs);
    template<typename T>
    bool operator>(Vec2<T> lhs, Vec2<T> rhs);
    template<typename T>
    bool operator<=(Vec2<T> lhs, Vec2<T> rhs);
    template<typename T>
    bool operator>=(Vec2<T> lhs, Vec2<T> rhs);

    using Vec2f = Vec2<float>;
    using Vec2i = Vec2<int>;
    using Vec2d = Vec2<double>;
    using Vec2u = Vec2<uint>;
    using Vec2l = Vec2<long double>;
} // namespace nt

#include "Vec2.inl"

#endif // _NT_MATH_VEC2_h_
