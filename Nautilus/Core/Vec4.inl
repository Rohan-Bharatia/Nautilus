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

#ifndef _NT_CORE_MATH_VEC4_INL_
    #define _NT_CORE_MATH_VEC4_INL_

#include "Vec4.h"

#include "Assertion.h"

namespace Nt
{
    template<typename T>
    Vec4<T> Vec4<T>::operator+(const Vec4<T>& other) const
    {
        return Vec4<T>(x + other.x, y + other.y, z + other.z, w + other.w);
    }

    template<typename T>
    Vec4<T> Vec4<T>::operator+(const T& other) const
    {
        return Vec4<T>(x + other, y + other, z + other, w + other);
    }

    template<typename T>
    Vec4<T> Vec4<T>::operator-(const Vec4<T>& other) const
    {
        return Vec4<T>(x - other.x, y - other.y, z - other.z, w - other.w);
    }

    template<typename T>
    Vec4<T> Vec4<T>::operator-(const T& other) const
    {
        return Vec4<T>(x - other, y - other, z - other, w - other);
    }

    template<typename T>
    Vec4<T> Vec4<T>::operator*(const Vec4<T>& other) const
    {
        return Vec4<T>(x * other.x, y * other.y, z * other.z, w * other.w);
    }

    template<typename T>
    Vec4<T> Vec4<T>::operator*(const T& other) const
    {
        return Vec4<T>(x * other, y * other, z * other, w * other);
    }

    template<typename T>
    Vec4<T> Vec4<T>::operator/(const Vec4<T>& other) const
    {
        NT_ASSERT(other.x != (T)0 && other.y != (T)0 && other.z != (T)0 && other.w != (T)0, "Cannot divide by zero!");
        return Vec4<T>(x / other.x, y / other.y, z / other.z, w / other.w);
    }

    template<typename T>
    Vec4<T> Vec4<T>::operator/(const T& other) const
    {
        NT_ASSERT(other != (T)0, "Cannot divide by zero!");
        return Vec4<T>(x / other, y / other, z / other, w / other);
    }

    template<typename T>
    Vec4<T> Vec4<T>::operator%(const Vec4<T>& other) const
    {
        NT_ASSERT(other.x != (T)0 && other.y != (T)0 && other.z != (T)0 && other.w != (T)0, "Cannot modulus by zero!");
        return Vec4<T>(NT_MODULUS(T, x, other.x), NT_MODULUS(T, y, other.y), NT_MODULUS(T, z, other.z), NT_MODULUS(T, w, other.w));
    }

    template<typename T>
    Vec4<T> Vec4<T>::operator%(const T& other) const
    {
        NT_ASSERT(other != (T)0, "Cannot modulus by zero!");
        return Vec4<T>(NT_MODULUS(T, x, other), NT_MODULUS(T, y, other), NT_MODULUS(T, z, other), NT_MODULUS(T, w, other));
    }

    template<typename T>
    Vec4<T> Vec4<T>::operator++(void)
    {
        ++x;
        ++y;
        ++z;
        ++w;
        return *this;
    }

    template<typename T>
    Vec4<T> Vec4<T>::operator++(int)
    {
        Vec4<T> temp = *this;
        ++*this;
        return temp;
    }

    template<typename T>
    Vec4<T> Vec4<T>::operator--(void)
    {
        --x;
        --y;
        --z;
        --w;
        return *this;
    }

    template<typename T>
    Vec4<T> Vec4<T>::operator--(int)
    {
        Vec4<T> temp = *this;
        --*this;
        return temp;
    }


    template<typename T>
    Vec4<T>& Vec4<T>::operator+=(const Vec4<T>& other)
    {
        return *this = *this + other;
    }

    template<typename T>
    Vec4<T>& Vec4<T>::operator+=(const T& other)
    {
        return *this = *this + other;
    }

    template<typename T>
    Vec4<T>& Vec4<T>::operator-=(const Vec4<T>& other)
    {
        return *this = *this - other;
    }

    template<typename T>
    Vec4<T>& Vec4<T>::operator-=(const T& other)
    {
        return *this = *this - other;
    }

    template<typename T>
    Vec4<T>& Vec4<T>::operator*=(const Vec4<T>& other)
    {
        return *this = *this * other;
    }

    template<typename T>
    Vec4<T>& Vec4<T>::operator*=(const T& other)
    {
        return *this = *this * other;
    }

    template<typename T>
    Vec4<T>& Vec4<T>::operator/=(const Vec4<T>& other)
    {
        NT_ASSERT(other.x != (T)0 && other.y != (T)0 && other.z != (T)0 && other.w != (T)0, "Cannot divide by zero!");
        return *this = *this / other;
    }

    template<typename T>
    Vec4<T>& Vec4<T>::operator/=(const T& other)
    {
        NT_ASSERT(other != (T)0, "Cannot divide by zero!");
        return *this = *this / other;
    }

    template<typename T>
    Vec4<T>& Vec4<T>::operator%=(const Vec4<T>& other)
    {
        NT_ASSERT(other.x != (T)0 && other.y != (T)0 && other.z != (T)0 && other.w != (T)0, "Cannot modulus by zero!");
        return *this = *this % other;
    }

    template<typename T>
    Vec4<T>& Vec4<T>::operator%=(const T& other)
    {
        NT_ASSERT(other != (T)0, "Cannot modulus by zero!");
        return *this = *this % other;
    }


    template<typename T>
    bool Vec4<T>::operator>(const Vec4<T>& other) const
    {
        return (x > other.x && y > other.y && z > other.z && w > other.w);
    }

    template<typename T>
    bool Vec4<T>::operator>(const T& other) const
    {
        return (x > other && y > other && z > other && w > other);
    }

    template<typename T>
    bool Vec4<T>::operator>=(const Vec4<T>& other) const
    {
        return (x >= other.x && y >= other.y && z >= other.z && w >= other.w);
    }

    template<typename T>
    bool Vec4<T>::operator>=(const T& other) const
    {
        return (x >= other && y >= other && z >= other && w >= other);
    }

    template<typename T>
    bool Vec4<T>::operator<(const Vec4<T>& other) const
    {
        return (x < other.x && y < other.y && z < other.z && w < other.w);
    }

    template<typename T>
    bool Vec4<T>::operator<(const T& other) const
    {
        return (x < other && y < other && z < other && w < other);
    }

    template<typename T>
    bool Vec4<T>::operator<=(const Vec4<T>& other) const
    {
        return (x <= other.x && y <= other.y && z <= other.z && w <= other.w);
    }

    template<typename T>
    bool Vec4<T>::operator<=(const T& other) const
    {
        return (x <= other && y <= other && z <= other && w <= other);
    }

    template<typename T>
    bool Vec4<T>::operator==(const Vec4<T>& other) const
    {
        return (x == other.x && y == other.y && z == other.z && w == other.w);
    }

    template<typename T>
    bool Vec4<T>::operator==(const T& other) const
    {
        return (x == other && y == other && z == other && w == other);
    }

    template<typename T>
    bool Vec4<T>::operator!=(const Vec4<T>& other) const
    {
        return (x != other.x || y != other.y || z != other.z || w != other.w);
    }

    template<typename T>
    bool Vec4<T>::operator!=(const T& other) const
    {
        return (x != other || y != other || z != other || w != other);
    }
}

#endif // _NT_CORE_MATH_VEC4_INL_
