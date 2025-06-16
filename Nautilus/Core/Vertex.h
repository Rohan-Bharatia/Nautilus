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

#ifndef _NT_CORE_MATH_VERTEX_H_
    #define _NT_CORE_MATH_VERTEX_H_

#include "Vec3.h"
#include "Color.h"

namespace Nt
{
    struct NT_API ReadableVertex
    {
        float32 position[3];
        float32 texCoord[2];
        float32 color[4];
    };

    class NT_API Vertex
    {
    public:
        NT_CLASS_DEFAULTS(Vertex)
        Vertex(const Vec3f& position, const Vec2f& texCoord, const Color& color);

        // Arithmetic operators
        Vertex operator+(const Vertex& other) const;
        Vertex operator+(float32 other) const;
        Vertex operator-(const Vertex& other) const;
        Vertex operator-(float32 other) const;
        Vertex operator*(const Vertex& other) const;
        Vertex operator*(float32 other) const;
        Vertex operator/(const Vertex& other) const;
        Vertex operator/(float32 other) const;
        Vertex operator%(const Vertex& other) const;
        Vertex operator%(float32 other) const;
        Vertex operator++(void);
        Vertex operator++(int);
        Vertex operator--(void);
        Vertex operator--(int);

        // Assignment operators
        Vertex& operator+=(const Vertex& other);
        Vertex& operator+=(float32 other);
        Vertex& operator-=(const Vertex& other);
        Vertex& operator-=(float32 other);
        Vertex& operator*=(const Vertex& other);
        Vertex& operator*=(float32 other);
        Vertex& operator/=(const Vertex& other);
        Vertex& operator/=(float32 other);
        Vertex& operator%=(const Vertex& other);
        Vertex& operator%=(float32 other);

        // Relational operators
        bool operator>(const Vertex& other) const;
        bool operator>(float32 other) const;
        bool operator>=(const Vertex& other) const;
        bool operator>=(float32 other) const;
        bool operator<(const Vertex& other) const;
        bool operator<(float32 other) const;
        bool operator<=(const Vertex& other) const;
        bool operator<=(float32 other) const;
        bool operator==(const Vertex& other) const;
        bool operator==(float32 other) const;
        bool operator!=(const Vertex& other) const;
        bool operator!=(float32 other) const;

        // Conversion operators
        operator float32*(void) const;

        // Methods
        ReadableVertex ToReadableVertex(void) const;

        Vec3f position;
        Vec2f texCoord;
        Color color;
    };
} // namespace Nt

#endif // _NT_CORE_MATH_VERTEX_H_
