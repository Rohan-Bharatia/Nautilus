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

#ifndef _NT_CORE_MATH_RAY2_INL_
    #define _NT_CORE_MATH_RAY2_INL_

#include "Ray2.h"

namespace Nt
{
    template<typename T>
    Ray2<T>::Ray2(const Vec2<T>& origin, const Vec2<T>& direction) :
        origin(origin), direction(direction)
    {
        NT_ASSERT(std::is_arithmetic<T>::value, "T must be numeric!");
    }

    template<typename T>
    Ray2<T>::Ray2(T originX, T originY, T directionX, T directionY) :
        origin(originX, originY), direction(directionX, directionY)
    {
        NT_ASSERT(std::is_arithmetic<T>::value, "T must be numeric!");
    }

    template<typename T>
    Ray2<T> Ray2<T>::operator+(const Ray2<T>& other) const
    {
        return Ray2<T>(origin + other, direction + other);
    }

    template<typename T>
    Ray2<T> Ray2<T>::operator+(const T& other) const
    {
        return Ray2<T>(origin + other, direction + other);
    }

    template<typename T>
    Ray2<T> Ray2<T>::operator-(const Ray2<T>& other) const
    {
        return Ray2<T>(origin - other, direction - other);
    }

    template<typename T>
    Ray2<T> Ray2<T>::operator-(const T& other) const
    {
        return Ray2<T>(origin - other, direction - other);
    }

    template<typename T>
    Ray2<T> Ray2<T>::operator*(const Ray2<T>& other) const
    {
        return Ray2<T>(origin * other, direction * other);
    }

    template<typename T>
    Ray2<T> Ray2<T>::operator*(const T& other) const
    {
        return Ray2<T>(origin * other, direction * other);
    }

    template<typename T>
    Ray2<T> Ray2<T>::operator/(const Ray2<T>& other) const
    {
        NT_ASSERT(other == (T)0, "Cannot divide by zero!");
        return Ray2<T>(origin / other, direction / other);
    }

    template<typename T>
    Ray2<T> Ray2<T>::operator/(const T& other) const
    {
        NT_ASSERT(other == (T)0, "Cannot divide by zero!");
        return Ray2<T>(origin / other, direction / other);
    }

    template<typename T>
    Ray2<T> Ray2<T>::operator%(const Ray2<T>& other) const
    {
        NT_ASSERT(other == (T)0, "Cannot modulus by zero!");
        return Ray2<T>(origin % other, direction % other);
    }

    template<typename T>
    Ray2<T> Ray2<T>::operator%(const T& other) const
    {
        NT_ASSERT(other == (T)0, "Cannot modulus by zero!");
        return Ray2<T>(origin % other, direction % other);
    }

    template<typename T>
    Ray2<T> Ray2<T>::operator++(void)
    {
        ++origin;
        ++direction;
        return *this;
    }

    template<typename T>
    Ray2<T> Ray2<T>::operator++(int)
    {
        Ray2<T> temp = *this;
        ++*this;
        return temp;
    }

    template<typename T>
    Ray2<T> Ray2<T>::operator--(void)
    {
        --origin;
        --direction;
        return *this;
    }

    template<typename T>
    Ray2<T> Ray2<T>::operator--(int)
    {
        Ray2<T> temp = *this;
        --*this;
        return temp;
    }

    template<typename T>
    Ray2<T>& Ray2<T>::operator+=(const Ray2<T>& other)
    {
        return *this = *this + other;
    }

    template<typename T>
    Ray2<T>& Ray2<T>::operator+=(const T& other)
    {
        return *this = *this + other;
    }

    template<typename T>
    Ray2<T>& Ray2<T>::operator-=(const Ray2<T>& other)
    {
        return *this = *this - other;
    }

    template<typename T>
    Ray2<T>& Ray2<T>::operator-=(const T& other)
    {
        return *this = *this - other;
    }

    template<typename T>
    Ray2<T>& Ray2<T>::operator*=(const Ray2<T>& other)
    {
        return *this = *this * other;
    }

    template<typename T>
    Ray2<T>& Ray2<T>::operator*=(const T& other)
    {
        return *this = *this * other;
    }

    template<typename T>
    Ray2<T>& Ray2<T>::operator/=(const Ray2<T>& other)
    {
        NT_ASSERT(other == (T)0, "Cannot divide by zero!");
        return *this = *this / other;
    }

    template<typename T>
    Ray2<T>& Ray2<T>::operator/=(const T& other)
    {
        NT_ASSERT(other == (T)0, "Cannot divide by zero!");
        return *this = *this / other;
    }

    template<typename T>
    Ray2<T>& Ray2<T>::operator%=(const Ray2<T>& other)
    {
        NT_ASSERT(other == (T)0, "Cannot modulus by zero!");
        return *this = *this % other;
    }

    template<typename T>
    Ray2<T>& Ray2<T>::operator%=(const T& other)
    {
        NT_ASSERT(other == (T)0, "Cannot modulus by zero!");
        return *this = *this % other;
    }

    template<typename T>
    bool Ray2<T>::operator>(const Ray2<T>& other) const
    {
        return origin > other.origin;
    }

    template<typename T>
    bool Ray2<T>::operator>(const T& other) const
    {
        return origin > other;
    }

    template<typename T>
    bool Ray2<T>::operator>=(const Ray2<T>& other) const
    {
        return origin >= other.origin;
    }

    template<typename T>
    bool Ray2<T>::operator>=(const T& other) const
    {
        return origin >= other;
    }

    template<typename T>
    bool Ray2<T>::operator<(const Ray2<T>& other) const
    {
        return origin < other.origin;
    }

    template<typename T>
    bool Ray2<T>::operator<(const T& other) const
    {
        return origin < other;
    }

    template<typename T>
    bool Ray2<T>::operator<=(const Ray2<T>& other) const
    {
        return origin <= other.origin;
    }

    template<typename T>
    bool Ray2<T>::operator<=(const T& other) const
    {
        return origin <= other;
    }

    template<typename T>
    bool Ray2<T>::operator==(const Ray2<T>& other) const
    {
        return origin == other.origin && direction == other.direction;
    }

    template<typename T>
    bool Ray2<T>::operator==(const T& other) const
    {
        return origin == other && direction == other;
    }

    template<typename T>
    bool Ray2<T>::operator!=(const Ray2<T>& other) const
    {
        return origin != other.origin || direction != other.direction;
    }

    template<typename T>
    bool Ray2<T>::operator!=(const T& other) const
    {
        return origin != other || direction != other;
    }

    template<typename T>
    Ray2<T>::operator float32*(void) const
    {
        return new T[4]{ origin.x, origin.y, direction.x, direction.y };
    }

    template<typename T>
    bool Ray2<T>::Intersects(const Ray2<T>& other) const
    {
        return IntersectionPoint(other) != 0;
    }

    template<typename T>
    Vec2<T> Ray2<T>::IntersectionPoint(const Ray2<T>& other) const
    {
        return origin + direction * (other.origin - origin) / (other.direction - direction);
    }

    template<typename T>
    float32 Ray2<T>::Distance(const Vec2<T>& point) const
    {
        return (point - origin).Length();
    }

    template<typename T>
    float32 Ray2<T>::Distance(const Ray2<T>& other) const
    {
        return (IntersectionPoint(other) - origin).Length();
    }

    template<typename T>
    Ray2<T> Ray2<T>::Normalize(void) const
    {
        return Ray2<T>(origin, direction.Normalized());
    }

    template<typename T>
    Vec2<T> Ray2<T>::Project(const Vec2<T>& other) const
    {
        return origin + direction * (other - origin).Dot(direction) / direction.Dot(direction);
    }

    template<typename T>
    Vec2<T> Ray2<T>::Project(const Ray2<T>& other) const
    {
        return origin + direction * (other.origin - origin).Dot(direction) / direction.Dot(direction);
    }

    template<typename T>
    Vec2<T> Ray2<T>::Reflect(const Vec2<T>& other) const
    {
        return (Project(other) * 2) - other;
    }

    template<typename T>
    Vec2<T> Ray2<T>::Reflect(const Ray2<T>& other) const
    {
        return (Project(other) * 2) - other;
    }
} // namespace Nt

#endif // _NT_CORE_MATH_RAY2_INL_
