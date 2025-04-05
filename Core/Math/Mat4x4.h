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

#include "../Platform/Platform.h"
#include "Vec3.h"

namespace nt
{
    template<typename T> class NT_API Mat4x4
    {
    public:
        Mat4x4()                               = default;
        ~Mat4x4()                              = default;
        Mat4x4(const Mat4x4& other)            = default;
        Mat4x4& operator=(const Mat4x4& other) = default;

        // Index operation
        T* operator[](int index);
        const T* operator[](int index) const;

        // 4x4 matrix methods
        T determinant() const;
        Mat4x4 transpose() const;
        Mat4x4 inverse() const;
        Mat4x4 adjoint() const;
        Mat4x4 cofactor() const;
        Mat4x4 minor(int row, int col) const;
        Mat4x4 identity() const;
        Mat4x4 zero() const;
        Mat4x4 rotate(float angle, const Vec3<T>& axis) const;
        Mat4x4 lookAt(const Vec3<T>& eye, const Vec3<T>& target, const Vec3<T>& up) const;
        Mat4x4 perspective(float fov, float aspect, float near, float far) const;
        Mat4x4 orthographic(float left, float right, float bottom, float top, float near, float far) const;
        Mat4x4 frustum(float left, float right, float bottom, float top, float near, float far) const;
        Mat4x4 translate(const Vec3<T>& translation) const;
        Mat4x4 scale(const Vec3<T>& scale) const;
        Mat4x4 rotateX(float angle) const;
        Mat4x4 rotateY(float angle) const;
        Mat4x4 rotateZ(float angle) const;

        T data[4][4];
    };

    // Sign operations
    template<typename T> Mat4x4<T> operator+(Mat4x4<T> lhs);
    template<typename T> Mat4x4<T> operator-(Mat4x4<T> lhs);

    // Arithmetic operations
    template<typename T> Mat4x4<T> operator+(Mat4x4<T> lhs, Mat4x4<T> rhs);
    template<typename T> Mat4x4<T> operator-(Mat4x4<T> lhs, Mat4x4<T> rhs);
    template<typename T> Mat4x4<T> operator*(Mat4x4<T> lhs, Mat4x4<T> rhs);
    template<typename T> Mat4x4<T> operator/(Mat4x4<T> lhs, Mat4x4<T> rhs);
    template<typename T> Mat4x4<T> operator%(Mat4x4<T> lhs, Mat4x4<T> rhs);

    // Increment/decrement operations
    template<typename T> Mat4x4<T> operator++(Mat4x4<T>& lhs);
    template<typename T> Mat4x4<T> operator--(Mat4x4<T>& lhs);
    template<typename T> Mat4x4<T> operator++(Mat4x4<T>& lhs, int);
    template<typename T> Mat4x4<T> operator--(Mat4x4<T>& lhs, int);

    // Assignment operations
    template<typename T> Mat4x4<T>& operator+=(Mat4x4<T>& lhs, Mat4x4<T> rhs);
    template<typename T> Mat4x4<T>& operator-=(Mat4x4<T>& lhs, Mat4x4<T> rhs);
    template<typename T> Mat4x4<T>& operator*=(Mat4x4<T>& lhs, Mat4x4<T> rhs);
    template<typename T> Mat4x4<T>& operator/=(Mat4x4<T>& lhs, Mat4x4<T> rhs);
    template<typename T> Mat4x4<T>& operator%=(Mat4x4<T>& lhs, Mat4x4<T> rhs);

    // Relational operations
    template<typename T> bool operator==(Mat4x4<T> lhs, Mat4x4<T> rhs);
    template<typename T> bool operator!=(Mat4x4<T> lhs, Mat4x4<T> rhs);
    template<typename T> bool operator<(Mat4x4<T> lhs, Mat4x4<T> rhs);
    template<typename T> bool operator>(Mat4x4<T> lhs, Mat4x4<T> rhs);
    template<typename T> bool operator<=(Mat4x4<T> lhs, Mat4x4<T> rhs);
    template<typename T> bool operator>=(Mat4x4<T> lhs, Mat4x4<T> rhs);

    // Template classes
    using Mat4x4f = Mat4x4<float>;
    using Mat4x4d = Mat4x4<double>;
    using Mat4x4i = Mat4x4<int>;
    using Mat4x4u = Mat4x4<unsigned int>;
    using Mat4x4l = Mat4x4<long>;
} // namespace nt

#include "Mat4x4.inl"

#endif // _NT_CORE_MATH_MAT4X4_H_
