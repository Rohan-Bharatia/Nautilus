//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#pragma once

#ifndef _NT_MATH_MAT4X4_h_
    #define _NT_MATH_MAT4X4_h_

#include "../core/Types.h"
#include "Vec3.h"

#include <array>

namespace nt
{
    template<typename T>
    class Mat4x4
    {
    public:
        Mat4x4();
        ~Mat4x4()                        = default;
        Mat4x4(const Mat4x4&)            = default;
        Mat4x4& operator=(const Mat4x4&) = default;

        Mat4x4 identity() const;
        Mat4x4 getMinor(int row, int col) const;
        T determinant() const;
        Mat4x4 inverse() const;
        Mat4x4 transpose() const;
        Mat4x4 orthogonalize() const;
        Mat4x4 translate(const Vec3<T>& other) const;
        Mat4x4 rotateX(Angle roll) const;
        Mat4x4 rotateY(Angle pitch) const;
        Mat4x4 rotateZ(Angle yaw) const;
        Mat4x4 scale(const Vec3<T>& other) const;
        Mat4x4 lookAt(const Vec3<T>& eye, const Vec3<T>& center, const Vec3<T>& up) const;
        Mat4x4 perspective(T fov, T aspect, T near, T far) const;
        Mat4x4 orthographic(T left, T right, T bottom, T top, T near, T far) const;
        Mat4x4 frustum(T left, T right, T bottom, T top, T near, T far) const;

        std::array<std::array<T, 4>, 4> mat;
    };

    template<typename T>
    Mat4x4<T> operator+(Mat4x4<T> lhs);
    template<typename T>
    Mat4x4<T> operator-(Mat4x4<T> lhs);

    // Arithmetic operations
    template<typename T>
    Mat4x4<T> operator+(Mat4x4<T> lhs, Mat4x4<T> rhs);
    template<typename T>
    Mat4x4<T> operator-(Mat4x4<T> lhs, Mat4x4<T> rhs);
    template<typename T>
    Mat4x4<T> operator*(Mat4x4<T> lhs, Mat4x4<T> rhs);
    template<typename T>
    Mat4x4<T> operator/(Mat4x4<T> lhs, Mat4x4<T> rhs);
    template<typename T>
    Mat4x4<T> operator%(Mat4x4<T> lhs, Mat4x4<T> rhs);

    // Assignment operations
    template<typename T>
    Mat4x4<T> operator+=(Mat4x4<T>& lhs, Mat4x4<T> rhs);
    template<typename T>
    Mat4x4<T> operator-=(Mat4x4<T>& lhs, Mat4x4<T> rhs);
    template<typename T>
    Mat4x4<T> operator*=(Mat4x4<T>& lhs, Mat4x4<T> rhs);
    template<typename T>
    Mat4x4<T> operator/=(Mat4x4<T>& lhs, Mat4x4<T> rhs);
    template<typename T>
    Mat4x4<T> operator%=(Mat4x4<T>& lhs, Mat4x4<T> rhs);

    // Relation operations
    template <typename T>
    bool operator==(Mat4x4<T> lhs, Mat4x4<T> rhs);
    template <typename T>
    bool operator!=(Mat4x4<T> lhs, Mat4x4<T> rhs);
    template <typename T>
    bool operator<(Mat4x4<T> lhs, Mat4x4<T> rhs);
    template <typename T>
    bool operator>(Mat4x4<T> lhs, Mat4x4<T> rhs);
    template <typename T>
    bool operator<=(Mat4x4<T> lhs, Mat4x4<T> rhs);
    template <typename T>
    bool operator>=(Mat4x4<T> lhs, Mat4x4<T> rhs);

    // Vector operations
    template<typename T>
    Vec3<T> operator*(Mat4x4<T> lhs, Vec3<T> rhs);
    template<typename T>
    Vec3<T> operator*=(Mat4x4<T>& lhs, Vec3<T> rhs);

    using Mat4x4f = Mat4x4<float>;
    using Mat4x4i = Mat4x4<int>;
    using Mat4x4d = Mat4x4<double>;
    using Mat4x4u = Mat4x4<uint>;
    using Mat4x4l = Mat4x4<long double>;
} // namespace nt

#include "Mat4x4.inl"

#endif // _NT_MATH_MAT4X4_h_