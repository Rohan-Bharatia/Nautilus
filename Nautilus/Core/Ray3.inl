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
    Ray3<T>::Ray3(const Vec3<T>& origin, const Vec3<T>& direction) :
        origin(origin), direction(direction)
    {
        NT_ASSERT(std::is_arithmetic<T>::value, "T must be numeric!");
    }

    template<typename T>
    Ray3<T>::Ray3(T originX, T originY, T originZ, T directionX, T directionY , T directionZ) :
        origin(originX, originY, originZ), direction(directionX, directionY, directionZ)
    {
        NT_ASSERT(std::is_arithmetic<T>::value, "T must be numeric!");
    }

    template<typename T>
    Ray3<T>::Ray3(const Ray3<T>& other, T originZ, T directionZ) :
        origin(other.origin.x, other.origin.y, originZ), direction(other.direction.x, other.direction.y, directionZ)
    {
        NT_ASSERT(std::is_arithmetic<T>::value, "T must be numeric!");
    }

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

    template<typename T>
    Ray3<T>::operator T*(void) const
    {
        return new T[6]{ origin.x, origin.y, origin.z, direction.x, direction.y, direction.z };
    }

    template<typename T>
    bool Ray3<T>::Intersects(const Ray3<T>& other) const
    {
        return IntersectionPoint(other) != 0;
    }

    template<typename T>
    Vec3<T> Ray3<T>::IntersectionPoint(const Ray3<T>& other) const
    {
        return origin + direction * (other.origin - origin) / (other.direction - direction);
    }

    template<typename T>
    float32 Ray3<T>::Distance(const Vec3<T>& point) const
    {
        return (point - origin).Length();
    }

    template<typename T>
    float32 Ray3<T>::Distance(const Ray3<T>& other) const
    {
        return (IntersectionPoint(other) - origin).Length();
    }

    template<typename T>
    Ray3<T> Ray3<T>::Normalize(void) const
    {
        return Ray3<T>(origin, direction.Normalized());
    }

    template<typename T>
    Vec3<T> Ray3<T>::Project(const Vec3<T>& other) const
    {
        return origin + direction * (other - origin).Dot(direction) / direction.Dot(direction);
    }

    template<typename T>
    Vec3<T> Ray3<T>::Project(const Ray3<T>& other) const
    {
        return origin + direction * (other.origin - origin).Dot(direction) / direction.Dot(direction);
    }

    template<typename T>
    Vec3<T> Ray3<T>::Reflect(const Vec3<T>& other) const
    {
        return (Project(other) * 2) - other;
    }

    template<typename T>
    Vec3<T> Ray3<T>::Reflect(const Ray3<T>& other) const
    {
        return (Project(other) * 2) - other;
    }
} // namespace Nt

#endif // _NT_CORE_MATH_RAY3_INL_
