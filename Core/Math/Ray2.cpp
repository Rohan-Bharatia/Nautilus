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

#ifndef _NT_CORE_MATH_RAY2_CPP_
    #define _NT_CORE_MATH_RAY2_CPP_

#include "Ray2.h"

#include <type_traits>
#include <cassert>
#include <cmath>

namespace nt
{
    template<typename T> Ray2<T>::Ray2(const Vec2<T>& origin, const Vec2<T>& direction) :
        origin(origin), direction(direction)
    {
        assert(std::is_arithmetic<T>::value);
    }

    template <typename T> Vec2<T> Ray2<T>::pointAt(float t) const
    {
        return origin + Vec2<T>(t, t) * direction;
    }

    template <typename T> Vec2<T> Ray2<T>::reflect(const Vec2<T>& normal) const
    {
        return direction - Vec2<T>(2, 2) * Vec2<T>(direction.dot(normal), direction.dot(normal)) * normal;
    }

    template <typename T> Vec2<T> Ray2<T>::refract(const Vec2<T>& normal, float index) const
    {
        T cosi = -normal.dot(direction);
        T eta  = 1.0f / index;
        T k    = 1 - eta * eta * (1 - cosi * cosi);

        if (k < 0)
            return Vec2<T>(0, 0); // Total internal reflection
        else
            return Vec2<T>(eta, eta) * direction + Vec2<T>(eta * cosi - sqrt(k), eta * cosi - sqrt(k)) * normal;
    }

    template <typename T> float Ray2<T>::distanceTo(const Vec2<T>& point) const
    {
        Vec2<T> v = point - origin;
        Vec2<T> d = direction.normalize();
        float cross = v.x * d.y - v.y * d.x; // 2D cross product doesnt exist
        return abs(cross) / d.length();
    }

    template class Ray2<float>;
    template class Ray2<double>;
    template class Ray2<int>;
    template class Ray2<unsigned int>;
    template class Ray2<long>;
} // namespace nt

#endif // _NT_CORE_MATH_RAY2_CPP_
