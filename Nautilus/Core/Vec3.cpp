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

#ifndef _NT_CORE_MATH_VEC3_CPP_
    #define _NT_CORE_MATH_VEC3_CPP_

#include "Vec3.h"

#include "Assertion.h"

namespace Nt
{
    template<typename T>
    Vec3<T>::Vec3(T x, T y, T z) :
        x(x), y(y), z(z)
    {
        NT_ASSERT(std::is_arithmetic<T>::value, "T must be numeric!");
    }

    template<typename T>
    Vec3<T>::Vec3(const Vec2<T>& xy, T z) :
        x(xy.x), y(xy.y), z(z)
    {
        NT_ASSERT(std::is_arithmetic<T>::value, "T must be numeric!");
    }

    template<typename T>
    float32 Vec3<T>::Length(void) const
    {
        return sqrt(LengthSquared());
    }

    template<typename T>
    float32 Vec3<T>::LengthSquared(void) const
    {
        return (x * x) + (y * y) + (z * z);
    }

    template<typename T>
    float32 Vec3<T>::Distance(const Vec3<T>& other) const
    {
        return sqrt((*this - other).Length());
    }

    template<typename T>
    Vec3<T> Vec3<T>::Normalize(void) const
    {
        return *this / Length();
    }

    template<typename T>
    T Vec3<T>::Dot(const Vec3<T>& other) const
    {
        return (x * other.x) + (y * other.y) + (z * other.z);
    }

    template<typename T>
    Vec3<T> Vec3<T>::Cross(const Vec3<T>& other) const
    {
        return Vec3<T>((y * other.z) - (z * other.y), (z * other.x) - (x * other.z), (x * other.y) - (y * other.x));
    }

    template<typename T>
    Vec3<T> Vec3<T>::Project(const Vec3<T>& other) const
    {
        return other * (Dot(other) / other.LengthSquared());
    }

    template<typename T>
    Vec3<T> Vec3<T>::Rotate(const Angle& other) const
    {
        return Vec3<T>(x * other.Cos() - y * other.Sin(), x * other.Sin() + y * other.Cos(), z);
    }

    template<typename T>
    Vec3<T> Vec3<T>::Scale(T other) const
    {
        return *this * other;
    }

    template<typename T>
    Vec3<T> Vec3<T>::Reflect(const Vec3<T>& normal) const
    {
        return *this - (normal * normal.Dot(*this) * 2);
    }

    template<typename T>
    Vec3<T> Vec3<T>::Midpoint(const Vec3<T>& other) const
    {
        return (*this + other) / 2;
    }

    template<typename T>
    Vec3<T> Vec3<T>::Min(const Vec3<T>& other) const
    {
        if (*this < other)
            return *this;
        else
            return other;
    }

    template<typename T>
    Vec3<T> Vec3<T>::Max(const Vec3<T>& other) const
    {
        if (*this > other)
            return *this;
        else
            return other;
    }

    template<typename T>
    Vec3<T> Vec3<T>::Clamp(const Vec3<T>& min, const Vec3<T>& max) const
    {
        return Vec3<T>(NT_CLAMP(x, min.x, max.x), NT_CLAMP(y, min.y, max.y), NT_CLAMP(z, min.z, max.z));
    }

    template class NT_API Vec3<float32>;
    template class NT_API Vec3<int32>;
    template class NT_API Vec3<uint32>;
    template class NT_API Vec3<float64>;
}

#endif // _NT_CORE_MATH_VEC3_CPP_
