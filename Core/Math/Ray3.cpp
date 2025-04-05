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

#ifndef _NT_CORE_MATH_RAY3_CPP_
    #define _NT_CORE_MATH_RAY3_CPP_

#include "Ray3.h"

#include <type_traits>
#include <cassert>
#include <cmath>

namespace nt
{
    template<typename T> Ray3<T>::Ray3(const Vec3<T>& origin, const Vec3<T>& direction) :
        origin(origin), direction(direction)
    {
        assert(std::is_arithmetic<T>::value);
    }

    template <typename T> Vec3<T> Ray3<T>::pointAt(float t) const
    {
        return origin + Vec3<T>(t, t, t) * direction;
    }

    template <typename T> Vec3<T> Ray3<T>::reflect(const Vec3<T>& normal) const
    {
        return direction - Vec3<T>(2, 2, 2) * Vec3<T>(direction.dot(normal), direction.dot(normal), direction.dot(normal)) * Vec3<T>(direction.dot(normal), direction.dot(normal), direction.dot(normal)) * normal;
    }

    template <typename T> Vec3<T> Ray3<T>::refract(const Vec3<T>& normal, float index) const
    {
        T cosi = -normal.dot(direction);
        T eta  = 1.0f / index;
        T k    = 1 - eta * eta * (1 - cosi * cosi);

        if (k < 0)
            return Vec3<T>(0, 0, 0); // Total internal reflection
        else
            return Vec3<T>(eta, eta, eta) * direction + Vec3<T>(eta * cosi - sqrt(k), eta * cosi - sqrt(k), eta * cosi - sqrt(k)) * normal + Vec3<T>(eta * cosi - sqrt(k), eta * cosi - sqrt(k), eta * cosi - sqrt(k)) * normal;
    }

    template <typename T> float Ray3<T>::distanceTo(const Vec3<T>& point) const
    {
        Vec3<T> v = point - origin;
        Vec3<T> d = direction.normalize();
        return abs(int(v.cross(d).length())) / d.length();
    }

    template <typename T> bool Ray3<T>::isParallel(const Ray3<T>& other) const
    {
        return direction.cross(other.direction).length() < 1e-6;
    }

    template class Ray3<float>;
    template class Ray3<double>;
    template class Ray3<int>;
    template class Ray3<unsigned int>;
    template class Ray3<long>;
} // namespace nt

#endif // _NT_CORE_MATH_RAY3_CPP_
