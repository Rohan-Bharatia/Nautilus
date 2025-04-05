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

#ifndef _NT_CORE_MATH_VEC3_INL_
    #define _NT_CORE_MATH_VEC3_INL_

#include "Vec3.h"

#include <cassert>

#include "../Platform/Platform.h"
namespace nt
{
    template<typename T> Vec3<T> operator+(Vec3<T> lhs)
    {
        return Vec3<T>(+lhs.x, +lhs.y, +lhs.z);
    }

    template<typename T> Vec3<T> operator-(Vec3<T> lhs)
    {
        return Vec3<T>(-lhs.x, -lhs.y, -lhs.z);
    }
    template<typename T> Vec3<T> operator+(Vec3<T> lhs, Vec3<T> rhs)
    {
        return Vec3<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
    }

    template<typename T> Vec3<T> operator-(Vec3<T> lhs, Vec3<T> rhs)
    {
        return Vec3<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
    }

    template<typename T> Vec3<T> operator*(Vec3<T> lhs, Vec3<T> rhs)
    {
        return Vec3<T>(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
    }
    template<typename T> Vec3<T> operator/(Vec3<T> lhs, Vec3<T> rhs)
    {
        assert(rhs.x != 0 && rhs.y != 0 && rhs.z != 0);
        return Vec3<T>(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z);
    }
    template<typename T> Vec3<T> operator%(Vec3<T> lhs, Vec3<T> rhs)
    {
        assert(rhs.x != 0 && rhs.y != 0 && rhs.z != 0);
        return Vec3<T>(NT_MODULUS(lhs.x, rhs.x), NT_MODULUS(lhs.y, rhs.y), NT_MODULUS(lhs.z, rhs.z));
    }

    template<typename T> Vec3<T> operator++(Vec3<T>& lhs)
    {
        ++lhs.x;
        ++lhs.y;
        ++lhs.z;
        return lhs;
    }

    template<typename T> Vec3<T> operator--(Vec3<T>& lhs)
    {
        --lhs.x;
        --lhs.y;
        --lhs.z;
        return lhs;
    }

    template<typename T> Vec3<T> operator++(Vec3<T>& lhs, int)
    {
        Vec3<T> temp = lhs;
        ++lhs.x;
        ++lhs.y;
        ++lhs.z;
        return temp;
    }

    template<typename T> Vec3<T> operator--(Vec3<T>& lhs, int)
    {
        Vec3<T> temp = lhs;
        --lhs.x;
        --lhs.y;
        --lhs.z;
        return temp;
    }

    template<typename T> Vec3<T>& operator+=(Vec3<T>& lhs, Vec3<T> rhs)
    {
        return lhs = lhs + rhs;
    }

    template<typename T> Vec3<T>& operator-=(Vec3<T>& lhs, Vec3<T> rhs)
    {
        return lhs = lhs - rhs;
    }
    template<typename T> Vec3<T>& operator*=(Vec3<T>& lhs, Vec3<T> rhs)
    {
        return lhs = lhs * rhs;
    }
    template<typename T> Vec3<T>& operator/=(Vec3<T>& lhs, Vec3<T> rhs)
    {
        assert(rhs.x != 0 && rhs.y != 0 && rhs.z != 0);
        return lhs = lhs / rhs;
    }
    template<typename T> Vec3<T>& operator%=(Vec3<T>& lhs, Vec3<T> rhs)
    {
        assert(rhs.x != 0 && rhs.y != 0 && rhs.z != 0);
        return lhs = lhs % rhs;
    }

    template<typename T> bool operator==(Vec3<T> lhs, Vec3<T> rhs)
    {
        return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
    }
    template<typename T> bool operator!=(Vec3<T> lhs, Vec3<T> rhs)
    {
        return !(lhs == rhs);
    }
    template<typename T> bool operator<(Vec3<T> lhs, Vec3<T> rhs)
    {
        return lhs.x < rhs.x && lhs.y < rhs.y && lhs.z < rhs.z;
    }
    template<typename T> bool operator>(Vec3<T> lhs, Vec3<T> rhs)
    {
        return lhs.x > rhs.x && lhs.y > rhs.y && lhs.z > rhs.z;
    }
    template<typename T> bool operator<=(Vec3<T> lhs, Vec3<T> rhs)
    {
        return !(lhs > rhs);
    }
    template<typename T> bool operator>=(Vec3<T> lhs, Vec3<T> rhs)
    {
        return !(lhs < rhs);
    }
} // namespace nt

#endif // _NT_CORE_MATH_VEC3_INL_
