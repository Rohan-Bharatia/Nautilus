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

#ifndef _NT_MATH_VEC3_inl_
    #define _NT_MATH_VEC3_inl_

#include "Vec3.h"

#include "Internal.h"

#include <cassert>

namespace nt
{
    template<typename T>
    Vec3<T> operator+(Vec3<T> lhs)
    {
        return Vec3(+lhs.x, +lhs.y, +lhs.z);
    }

    template<typename T>
    Vec3<T> operator-(Vec3<T> lhs)
    {
        return Vec3(-lhs.x, -lhs.y, -lhs.z);
    }

    template<typename T>
    Vec3<T> operator+(Vec3<T> lhs, Vec3<T> rhs)
    {
        return Vec3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
    }

    template<typename T>
    Vec3<T> operator-(Vec3<T> lhs, Vec3<T> rhs)
    {
        return Vec3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
    }

    template<typename T>
    Vec3<T> operator*(Vec3<T> lhs, Vec3<T> rhs)
    {
        return Vec3(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
    }

    template<typename T>
    Vec3<T> operator/(Vec3<T> lhs, Vec3<T> rhs)
    {
        assert(rhs.x != 0.0f && "Vec3 operator / cannot divide by zero!");
        assert(rhs.y != 0.0f && "Vec3 operator / cannot divide by zero!");
        assert(rhs.z != 0.0f && "Vec3 operator / cannot divide by zero!");
        return Vec3(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z);
    }

    template<typename T>
    Vec3<T> operator%(Vec3<T> lhs, Vec3<T> rhs)
    {
        assert(rhs.x != 0.0f && "Vec3 operator % cannot modulus by zero!");
        assert(rhs.y != 0.0f && "Vec3 operator % cannot modulus by zero!");
        assert(rhs.y != 0.0f && "Vec3 operator % cannot modulus by zero!");
        return Vec3(internal::positiveRemainder<T>(lhs.x, rhs.x), internal::positiveRemainder<T>(lhs.y, rhs.y), internal::positiveRemainder<T>(lhs.z, rhs.z));
    }

    template<typename T>
    Vec3<T> operator+=(Vec3<T>& lhs, Vec3<T> rhs)
    {
        return lhs = lhs + rhs;
    }

    template<typename T>
    Vec3<T> operator-=(Vec3<T>& lhs, Vec3<T> rhs)
    {
        return lhs = lhs - rhs;
    }

    template<typename T>
    Vec3<T> operator*=(Vec3<T>& lhs, Vec3<T> rhs)
    {
        return lhs = lhs * rhs;
    }

    template<typename T>
    Vec3<T> operator/=(Vec3<T>& lhs, Vec3<T> rhs)
    {
        assert(rhs.x != 0.0f && "Vec3 operator /= cannot divide by zero!");
        assert(rhs.y != 0.0f && "Vec3 operator /= cannot divide by zero!");
        assert(rhs.y != 0.0f && "Vec3 operator /= cannot divide by zero!");
        return lhs = lhs / rhs;
    }

    template<typename T>
    Vec3<T> operator%=(Vec3<T>& lhs, Vec3<T> rhs)
    {
        assert(rhs.x != 0.0f && "Vec3 operator %= cannot modulus by zero!");
        assert(rhs.y != 0.0f && "Vec3 operator %= cannot modulus by zero!");
        assert(rhs.y != 0.0f && "Vec3 operator %= cannot modulus by zero!");
        return lhs = lhs % rhs;
    }

    template<typename T>
    bool operator==(Vec3<T> lhs, Vec3<T> rhs)
    {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z);
    }

    template<typename T>
    bool operator!=(Vec3<T> lhs, Vec3<T> rhs)
    {
        return (lhs.x != rhs.x) && (lhs.y != rhs.y) && (lhs.z != rhs.z);
    }

    template<typename T>
    bool operator<(Vec3<T> lhs, Vec3<T> rhs)
    {
        return (lhs.x < rhs.x) && (lhs.y < rhs.y) && (lhs.z < rhs.z);
    }

    template<typename T>
    bool operator>(Vec3<T> lhs, Vec3<T> rhs)
    {
        return (lhs.x > rhs.x) && (lhs.y > rhs.y) && (lhs.z > rhs.z);
    }

    template<typename T>
    bool operator<=(Vec3<T> lhs, Vec3<T> rhs)
    {
        return (lhs.x <= rhs.x) && (lhs.y <= rhs.y) && (lhs.z <= rhs.z);
    }

    template<typename T>
    bool operator>=(Vec3<T> lhs, Vec3<T> rhs)
    {
        return (lhs.x >= rhs.x) && (lhs.y >= rhs.y) && (lhs.z >= rhs.z);
    }
} // namespace nt

#endif // _NT_MATH_VEC3_inl_
