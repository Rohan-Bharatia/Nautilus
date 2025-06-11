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

#ifndef _NT_CORE_MATH_MAT4X4_H_
    #define _NT_CORE_MATH_MAT4X4_H_

#include "PCH.h"
#include "Vec3.h"

namespace Nt
{
    template<typename T>
    class NT_API Mat4x4
    {
    public:
        NT_CLASS_DEFAULTS(Mat4x4)
        Mat4x4(T val);
        Mat4x4(T** data);

        // Access operators
        T& operator()(uint32 row, uint32 col);
        const T& operator()(uint32 row, uint32 col) const;
        T* operator[](uint32 index);
        const T* operator[](uint32 index) const;

        // Arithmetic operators
        Mat4x4<T> operator+(const Mat4x4<T>& other) const;
        Mat4x4<T> operator+(const T& other) const;
        Mat4x4<T> operator-(const Mat4x4<T>& other) const;
        Mat4x4<T> operator-(const T& other) const;
        Mat4x4<T> operator*(const Mat4x4<T>& other) const;
        Mat4x4<T> operator*(const T& other) const;
        Mat4x4<T> operator/(const Mat4x4<T>& other) const;
        Mat4x4<T> operator/(const T& other) const;
        Mat4x4<T> operator%(const Mat4x4<T>& other) const;
        Mat4x4<T> operator%(const T& other) const;
        Mat4x4<T> operator++(void);
        Mat4x4<T> operator++(int);
        Mat4x4<T> operator--(void);
        Mat4x4<T> operator--(int);

        // Assignment operators
        Mat4x4<T>& operator+=(const Mat4x4<T>& other);
        Mat4x4<T>& operator+=(const T& other);
        Mat4x4<T>& operator-=(const Mat4x4<T>& other);
        Mat4x4<T>& operator-=(const T& other);
        Mat4x4<T>& operator*=(const Mat4x4<T>& other);
        Mat4x4<T>& operator*=(const T& other);
        Mat4x4<T>& operator/=(const Mat4x4<T>& other);
        Mat4x4<T>& operator/=(const T& other);
        Mat4x4<T>& operator%=(const Mat4x4<T>& other);
        Mat4x4<T>& operator%=(const T& other);

        // Relational operators
        bool operator>(const Mat4x4<T>& other) const;
        bool operator>(const T& other) const;
        bool operator>=(const Mat4x4<T>& other) const;
        bool operator>=(const T& other) const;
        bool operator<(const Mat4x4<T>& other) const;
        bool operator<(const T& other) const;
        bool operator<=(const Mat4x4<T>& other) const;
        bool operator<=(const T& other) const;
        bool operator==(const Mat4x4<T>& other) const;
        bool operator==(const T& other) const;
        bool operator!=(const Mat4x4<T>& other) const;
        bool operator!=(const T& other) const;

        // Conversion operators
        operator T**(void) const;

        // Methods
        static Mat4x4<T> Identity(void);
        static Mat4x4<T> Perspective(T fovy, T aspect, T zNear, T zFar);
        T Determinant(void) const;
        T MinorDeterminant(T minor[3][3]) const;
        Mat4x4<T> Inverse(void);
        static void SwapRows(T mat[4][4], uint32 row1, uint32 row2);
        static void SwapColumns(T mat[4][4], uint32 col1, uint32 col2);
        Mat4x4<T> Transpose(void) const;
        void Orthogonalize(void);
        Vec3<T> Translate(const Vec3<T>& other) const;
        static Mat4x4<T> Translation(const Vec3<T>& other);
        Vec3<T> Rotate(const Vec3<T>& other) const;
        static Mat4x4<T> Rotation(Angle angle);
        static Mat4x4<T> Rotation(const Quaternion<T>& quaternion);
        static Mat4x4<T> Rotation(Angle angle, const Vec3<T>& axis);
        static Mat4x4<T> Orthographic(T left, T right, T bottom, T top, T _near, T _far);

        T mat[4][4];
    };

    using Mat4x4f = Mat4x4<float32>;
    using Mat4x4i = Mat4x4<int32>;
    using Mat4x4u = Mat4x4<uint32>;
    using Mat4x4d = Mat4x4<float64>;
} // namespace Nt

#include "Mat4x4.inl"

#endif // _NT_CORE_MATH_MAT4X4_H_
