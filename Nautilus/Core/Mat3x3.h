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

#ifndef _NT_CORE_MATH_MAT3X3_H_
    #define _NT_CORE_MATH_MAT3X3_H_

#include "PCH.h"
#include "Vec2.h"

namespace Nt
{
    template<typename T>
    class NT_API Mat3x3
    {
    public:
        NT_CLASS_DEFAULTS(Mat3x3)
        Mat3x3(T val);
        Mat3x3(T** data);

        // Access operators
        T& operator()(uint32 row, uint32 col);
        const T& operator()(uint32 row, uint32 col) const;
        T* operator[](uint32 index);
        const T* operator[](uint32 index) const;

        // Arithmetic operators
        Mat3x3<T> operator+(const Mat3x3<T>& other) const;
        Mat3x3<T> operator+(const T& other) const;
        Mat3x3<T> operator-(const Mat3x3<T>& other) const;
        Mat3x3<T> operator-(const T& other) const;
        Mat3x3<T> operator*(const Mat3x3<T>& other) const;
        Mat3x3<T> operator*(const T& other) const;
        Mat3x3<T> operator/(const Mat3x3<T>& other) const;
        Mat3x3<T> operator/(const T& other) const;
        Mat3x3<T> operator%(const Mat3x3<T>& other) const;
        Mat3x3<T> operator%(const T& other) const;
        Mat3x3<T> operator++(void);
        Mat3x3<T> operator++(int);
        Mat3x3<T> operator--(void);
        Mat3x3<T> operator--(int);

        // Assignment operators
        Mat3x3<T>& operator+=(const Mat3x3<T>& other);
        Mat3x3<T>& operator+=(const T& other);
        Mat3x3<T>& operator-=(const Mat3x3<T>& other);
        Mat3x3<T>& operator-=(const T& other);
        Mat3x3<T>& operator*=(const Mat3x3<T>& other);
        Mat3x3<T>& operator*=(const T& other);
        Mat3x3<T>& operator/=(const Mat3x3<T>& other);
        Mat3x3<T>& operator/=(const T& other);
        Mat3x3<T>& operator%=(const Mat3x3<T>& other);
        Mat3x3<T>& operator%=(const T& other);

        // Relational operators
        bool operator>(const Mat3x3<T>& other) const;
        bool operator>(const T& other) const;
        bool operator>=(const Mat3x3<T>& other) const;
        bool operator>=(const T& other) const;
        bool operator<(const Mat3x3<T>& other) const;
        bool operator<(const T& other) const;
        bool operator<=(const Mat3x3<T>& other) const;
        bool operator<=(const T& other) const;
        bool operator==(const Mat3x3<T>& other) const;
        bool operator==(const T& other) const;
        bool operator!=(const Mat3x3<T>& other) const;
        bool operator!=(const T& other) const;

        // Conversion operators
        operator T**(void) const;

        // Methods
        static Mat3x3<T> Identity(void);
        static Mat3x3<T> Perspective(T fovy, T aspect);
        T Determinant(void) const;
        T MinorDeterminant(T minor[2][2]) const;
        Mat3x3<T> Inverse(void);
        static void SwapRows(T mat[3][3], uint32 row1, uint32 row2);
        static void SwapColumns(T mat[3][3], uint32 col1, uint32 col2);
        Mat3x3<T> Transpose(void) const;
        void Orthogonalize(void);
        Vec2<T> Translate(const Vec2<T>& other) const;
        static Mat3x3<T> Translation(const Vec2<T>& other);
        Vec2<T> Rotate(const Vec2<T>& other) const;
        static Mat3x3<T> Rotation(Angle angle);
        static Mat3x3<T> Rotation(const Quaternion<T>& quaternion);
        static Mat3x3<T> Rotation(Angle angle, const Vec2<T>& axis);
        static Mat3x3<T> Orthographic(T left, T right, T bottom, T top);

        T mat[3][3];
    };

    using Mat3x3f = Mat3x3<float32>;
    using Mat3x3i = Mat3x3<int32>;
    using Mat3x3u = Mat3x3<uint32>;
    using Mat3x3d = Mat3x3<float64>;
} // namespace Nt

#include "Mat3x3.inl"

#endif // _NT_CORE_MATH_MAT3X3_H_
