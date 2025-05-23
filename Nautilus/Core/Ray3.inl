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

#ifndef _NT_CORE_MATH_RAY3_INL_
    #define _NT_CORE_MATH_RAY3_INL_

#include "Ray3.h"

namespace Nt
{
    template<typename T>
    Ray3<T> Ray3<T>::operator+(const Ray3<T>& other) const
    {
        return Ray3<T>(origin + other, direction + other);
    }

    template<typename T>
    Ray3<T> Ray3<T>::operator+(const T& other) const
    {
        return Ray3<T>(origin + other, direction + other);
    }

    template<typename T>
    Ray3<T> Ray3<T>::operator-(const Ray3<T>& other) const
    {
        return Ray3<T>(origin - other, direction - other);
    }

    template<typename T>
    Ray3<T> Ray3<T>::operator-(const T& other) const
    {
        return Ray3<T>(origin - other, direction - other);
    }

    template<typename T>
    Ray3<T> Ray3<T>::operator*(const Ray3<T>& other) const
    {
        return Ray3<T>(origin * other, direction * other);
    }

    template<typename T>
    Ray3<T> Ray3<T>::operator*(const T& other) const
    {
        return Ray3<T>(origin * other, direction * other);
    }

    template<typename T>
    Ray3<T> Ray3<T>::operator/(const Ray3<T>& other) const
    {
        NT_ASSERT(other == (T)0, "Cannot divide by zero!");
        return Ray3<T>(origin / other, direction / other);
    }

    template<typename T>
    Ray3<T> Ray3<T>::operator/(const T& other) const
    {
        NT_ASSERT(other == (T)0, "Cannot divide by zero!");
        return Ray3<T>(origin / other, direction / other);
    }

    template<typename T>
    Ray3<T> Ray3<T>::operator%(const Ray3<T>& other) const
    {
        NT_ASSERT(other == (T)0, "Cannot modulus by zero!");
        return Ray3<T>(origin % other, direction % other);
    }

    template<typename T>
    Ray3<T> Ray3<T>::operator%(const T& other) const
    {
        NT_ASSERT(other == (T)0, "Cannot modulus by zero!");
        return Ray3<T>(origin % other, direction % other);
    }

    template<typename T>
    Ray3<T> Ray3<T>::operator++(void)
    {
        ++origin;
        ++direction;
        return *this;
    }

    template<typename T>
    Ray3<T> Ray3<T>::operator++(int)
    {
        Ray3<T> temp = *this;
        ++*this;
        return temp;
    }

    template<typename T>
    Ray3<T> Ray3<T>::operator--(void)
    {
        --origin;
        --direction;
        return *this;
    }

    template<typename T>
    Ray3<T> Ray3<T>::operator--(int)
    {
        Ray3<T> temp = *this;
        --*this;
        return temp;
    }

    template<typename T>
    Ray3<T>& Ray3<T>::operator+=(const Ray3<T>& other)
    {
        return *this = *this + other;
    }

    template<typename T>
    Ray3<T>& Ray3<T>::operator+=(const T& other)
    {
        return *this = *this + other;
    }

    template<typename T>
    Ray3<T>& Ray3<T>::operator-=(const Ray3<T>& other)
    {
        return *this = *this - other;
    }

    template<typename T>
    Ray3<T>& Ray3<T>::operator-=(const T& other)
    {
        return *this = *this - other;
    }

    template<typename T>
    Ray3<T>& Ray3<T>::operator*=(const Ray3<T>& other)
    {
        return *this = *this * other;
    }

    template<typename T>
    Ray3<T>& Ray3<T>::operator*=(const T& other)
    {
        return *this = *this * other;
    }

    template<typename T>
    Ray3<T>& Ray3<T>::operator/=(const Ray3<T>& other)
    {
        NT_ASSERT(other == (T)0, "Cannot divide by zero!");
        return *this = *this / other;
    }

    template<typename T>
    Ray3<T>& Ray3<T>::operator/=(const T& other)
    {
        NT_ASSERT(other == (T)0, "Cannot divide by zero!");
        return *this = *this / other;
    }

    template<typename T>
    Ray3<T>& Ray3<T>::operator%=(const Ray3<T>& other)
    {
        NT_ASSERT(other == (T)0, "Cannot modulus by zero!");
        return *this = *this % other;
    }

    template<typename T>
    Ray3<T>& Ray3<T>::operator%=(const T& other)
    {
        NT_ASSERT(other == (T)0, "Cannot modulus by zero!");
        return *this = *this % other;
    }

    template<typename T>
    bool Ray3<T>::operator>(const Ray3<T>& other) const
    {
        return origin > other.origin;
    }

    template<typename T>
    bool Ray3<T>::operator>(const T& other) const
    {
        return origin > other;
    }

    template<typename T>
    bool Ray3<T>::operator>=(const Ray3<T>& other) const
    {
        return origin >= other.origin;
    }

    template<typename T>
    bool Ray3<T>::operator>=(const T& other) const
    {
        return origin >= other;
    }

    template<typename T>
    bool Ray3<T>::operator<(const Ray3<T>& other) const
    {
        return origin < other.origin;
    }

    template<typename T>
    bool Ray3<T>::operator<(const T& other) const
    {
        return origin < other;
    }

    template<typename T>
    bool Ray3<T>::operator<=(const Ray3<T>& other) const
    {
        return origin <= other.origin;
    }

    template<typename T>
    bool Ray3<T>::operator<=(const T& other) const
    {
        return origin <= other;
    }

    template<typename T>
    bool Ray3<T>::operator==(const Ray3<T>& other) const
    {
        return origin == other.origin && direction == other.direction;
    }

    template<typename T>
    bool Ray3<T>::operator==(const T& other) const
    {
        return origin == other && direction == other;
    }

    template<typename T>
    bool Ray3<T>::operator!=(const Ray3<T>& other) const
    {
        return origin != other.origin || direction != other.direction;
    }

    template<typename T>
    bool Ray3<T>::operator!=(const T& other) const
    {
        return origin != other || direction != other;
    }
} // namespace Nt

#endif // _NT_CORE_MATH_RAY3_INL_
