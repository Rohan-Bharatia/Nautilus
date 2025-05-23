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

#ifndef _NT_CORE_MATH_VEC2_CPP_
    #define _NT_CORE_MATH_VEC2_CPP_

#include "Vec2.h"

#include "Assertion.h"

namespace Nt
{
    template<typename T>
    Vec2<T>::Vec2(T x, T y) :
        x(x), y(y)
    {
        NT_ASSERT(std::is_arithmetic<T>::value, "T must be numeric!");
    }

    template<typename T>
    float32 Vec2<T>::Length(void) const
    {
        return sqrt(LengthSquared());
    }

    template<typename T>
    float32 Vec2<T>::LengthSquared(void) const
    {
        return (x * x) + (y * y);
    }

    template<typename T>
    float32 Vec2<T>::Distance(const Vec2<T>& other) const
    {
        return sqrt((*this - other).Length());
    }

    template<typename T>
    Vec2<T> Vec2<T>::Normalize(void) const
    {
        return *this / Length();
    }

    template<typename T>
    T Vec2<T>::Dot(const Vec2<T>& other) const
    {
        return (x * other.x) + (y * other.y);
    }

    template<typename T>
    Vec2<T> Vec2<T>::Cross(const Vec2<T>& other) const
    {
        return Vec2<T>(x * other.y - y * other.x, y * other.x - x * other.y);
    }

    template<typename T>
    Vec2<T> Vec2<T>::Project(const Vec2<T>& other) const
    {
        return other * (Dot(other) / other.LengthSquared());
    }

    template<typename T>
    Vec2<T> Vec2<T>::Rotate(const Angle& other) const
    {
        return Vec2<T>(x * other.Cos() - y * other.Sin(), x * other.Sin() + y * other.Cos());
    }

    template<typename T>
    Vec2<T> Vec2<T>::Scale(T other) const
    {
        return *this * other;
    }

    template<typename T>
    Vec2<T> Vec2<T>::Reflect(const Vec2<T>& normal) const
    {
        return *this - (normal * normal.Dot(*this) * 2);
    }

    template<typename T>
    Vec2<T> Vec2<T>::Midpoint(const Vec2<T>& other) const
    {
        return (*this + other) / 2;
    }

    template<typename T>
    Vec2<T> Vec2<T>::Min(const Vec2<T>& other) const
    {
        if (x < other.x)
            return *this;
        else
            return other;
    }

    template<typename T>
    Vec2<T> Vec2<T>::Max(const Vec2<T>& other) const
    {
        if (x > other.x)
            return *this;
        else
            return other;
    }

    template<typename T>
    Vec2<T> Vec2<T>::Clamp(const Vec2<T>& min, const Vec2<T>& max) const
    {
        return Vec2<T>(NT_CLAMP(x, min.x, max.x), NT_CLAMP(y, min.y, max.y));
    }

    template class NT_API Vec2<float32>;
    template class NT_API Vec2<int32>;
    template class NT_API Vec2<uint32>;
    template class NT_API Vec2<float64>;
}

#endif // _NT_CORE_MATH_VEC2_CPP_
