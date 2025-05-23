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

#ifndef _NT_CORE_MATH_VEC4_CPP_
    #define _NT_CORE_MATH_VEC4_CPP_

#include "Vec4.h"

#include "Assertion.h"

namespace Nt
{
    template<typename T>
    Vec4<T>::Vec4(T x, T y, T z, T w) :
        x(x), y(y), z(z), w(w)
    {
        NT_ASSERT(std::is_arithmetic<T>::value, "T must be numeric!");
    }

    template<typename T>
    Vec4<T>::Vec4(const Vec2<T>& xy, T z, T w) :
        x(xy.x), y(xy.y), z(z), w(w)
    {
        NT_ASSERT(std::is_arithmetic<T>::value, "T must be numeric!");
    }

    template<typename T>
    Vec4<T>::Vec4(const Vec3<T>& xyz, T w) :
        x(xyz.x), y(xyz.y), z(xyz.z), w(w)
    {
        NT_ASSERT(std::is_arithmetic<T>::value, "T must be numeric!");
    }

    template<typename T>
    float32 Vec4<T>::Length(void) const
    {
        return sqrt(LengthSquared());
    }

    template<typename T>
    float32 Vec4<T>::LengthSquared(void) const
    {
        return (x * x) + (y * y) + (z * z);
    }

    template<typename T>
    float32 Vec4<T>::Distance(const Vec4<T>& other) const
    {
        return sqrt((*this - other).Length());
    }

    template<typename T>
    Vec4<T> Vec4<T>::Normalize(void) const
    {
        return *this / Length();
    }

    template<typename T>
    T Vec4<T>::Dot(const Vec4<T>& other) const
    {
        return (x * other.x) + (y * other.y) + (z * other.z);
    }

    template<typename T>
    Vec4<T> Vec4<T>::Cross(const Vec4<T>& other) const
    {
        return Vec4<T>((y * other.z) - (z * other.y), (z * other.x) - (x * other.z), (x * other.y) - (y * other.x), (w * other.z) - (z * other.w));
    }

    template<typename T>
    Vec4<T> Vec4<T>::Project(const Vec4<T>& other) const
    {
        return other * (Dot(other) / other.LengthSquared());
    }

    template<typename T>
    Vec4<T> Vec4<T>::Rotate(const Angle& other) const
    {
        return Vec4<T>(x * other.Cos() - y * other.Sin(), x * other.Sin() + y * other.Cos(), z, w);
    }

    template<typename T>
    Vec4<T> Vec4<T>::Scale(T other) const
    {
        return *this * other;
    }

    template<typename T>
    Vec4<T> Vec4<T>::Reflect(const Vec4<T>& normal) const
    {
        return *this - (normal * normal.Dot(*this) * 2);
    }

    template<typename T>
    Vec4<T> Vec4<T>::Midpoint(const Vec4<T>& other) const
    {
        return (*this + other) / 2;
    }

    template<typename T>
    Vec4<T> Vec4<T>::Min(const Vec4<T>& other) const
    {
        if (*this < other)
            return *this;
        else
            return other;
    }

    template<typename T>
    Vec4<T> Vec4<T>::Max(const Vec4<T>& other) const
    {
        if (*this > other)
            return *this;
        else
            return other;
    }

    template<typename T>
    Vec4<T> Vec4<T>::Clamp(const Vec4<T>& min, const Vec4<T>& max) const
    {
        return Vec4<T>(NT_CLAMP(x, min.x, max.x), NT_CLAMP(y, min.y, max.y), NT_CLAMP(z, min.z, max.z), NT_CLAMP(w, min.w, max.w));
    }

    template class NT_API Vec4<float32>;
    template class NT_API Vec4<int32>;
    template class NT_API Vec4<uint32>;
    template class NT_API Vec4<float64>;
}

#endif // _NT_CORE_MATH_VEC4_CPP_
