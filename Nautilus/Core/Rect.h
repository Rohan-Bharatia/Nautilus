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

#pragma once

#ifndef _NT_CORE_RECT_H_
    #define _NT_CORE_RECT_H_

#include "Vec2.h"

namespace Nt
{
    class NT_API Rect
    {
    public:
        NT_CLASS_DEFAULTS(Rect)
        Rect(void) = default;
        Rect(const Vec2f& position, const Vec2f& size);
        Rect(const Vec2f& position, float32 width, float32 height);
        Rect(float32 x, float32 y, float32 width, float32 height);

        // Arithmetic operators
        Rect operator+(const Rect& other) const;
        Rect operator+(float32 other) const;
        Rect operator-(const Rect& other) const;
        Rect operator-(float32 other) const;
        Rect operator*(const Rect& other) const;
        Rect operator*(float32 other) const;
        Rect operator/(const Rect& other) const;
        Rect operator/(float32 other) const;
        Rect operator%(const Rect& other) const;
        Rect operator%(float32 other) const;
        Rect operator++(void);
        Rect operator++(int);
        Rect operator--(void);
        Rect operator--(int);

        // Assignment operators
        Rect& operator+=(const Rect& other);
        Rect& operator+=(float32 other);
        Rect& operator-=(const Rect& other);
        Rect& operator-=(float32 other);
        Rect& operator*=(const Rect& other);
        Rect& operator*=(float32 other);
        Rect& operator/=(const Rect& other);
        Rect& operator/=(float32 other);
        Rect& operator%=(const Rect& other);
        Rect& operator%=(float32 other);

        // Relational operators
        bool operator>(const Rect& other) const;
        bool operator>(float32 other) const;
        bool operator>=(const Rect& other) const;
        bool operator>=(float32 other) const;
        bool operator<(const Rect& other) const;
        bool operator<(float32 other) const;
        bool operator<=(const Rect& other) const;
        bool operator<=(float32 other) const;
        bool operator==(const Rect& other) const;
        bool operator==(float32 other) const;
        bool operator!=(const Rect& other) const;
        bool operator!=(float32 other) const;

        // Methods
        void Resize(const Vec2f& other);
        void Resize(float32 width, float32 height);
        void MoveTo(const Vec2f& other);
        void MoveTo(float32 x, float32 y);
        void Move(const Vec2f& offset);
        void Move(float32 offsetX, float32 offsetY);

        Vec2f position;
        Vec2f size;
    };
} // namespace Nt

#endif // _NT_CORE_RECT_H_
