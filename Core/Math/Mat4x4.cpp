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

#ifndef _NT_CORE_MATH_MAT4X4_CPP_
    #define _NT_CORE_MATH_MAT4X4_CPP_

#include "Mat4x4.h"

#include <cmath>

namespace nt
{
    template<typename T> T Mat4x4<T>::determinant() const
    {
        T det = 0;
        for (int i = 0; i < 4; ++i)
            det += (i % 2 == 0 ? 1 : -1) * data[0][i] * minor(0, i).determinant();
        return det;
    }

    template<typename T> Mat4x4<T> Mat4x4<T>::transpose() const
    {
        Mat4x4<T> result;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                result.data[i][j] = data[j][i];
        return result;
    }

    template<typename T> Mat4x4<T> Mat4x4<T>::inverse() const
    {
        T det = determinant();
        assert(det != 0);  // Check for singular matrix
        Mat4x4<T> d;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                d.data[i][j] = det;
        return adjoint() / d;
    }

    template<typename T> Mat4x4<T> Mat4x4<T>::adjoint() const
    {
        Mat4x4<T> result;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                result.data[i][j] = minor(i, j).determinant() * ((i + j) % 2 == 0 ? 1 : -1);
        return result.transpose();
    }

    template<typename T> Mat4x4<T> Mat4x4<T>::cofactor() const
    {
        Mat4x4<T> result;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                result.data[i][j] = minor(i, j).determinant() * ((i + j) % 2 == 0 ? 1 : -1);
        return result;
    }

    template<typename T> Mat4x4<T> Mat4x4<T>::minor(int row, int col) const
    {
        Mat4x4<T> result;
        int r = 0;
        for (int i = 0; i < 4; ++i)
        {
            if (i == row)
                continue;
            int c = 0;
            for (int j = 0; j < 4; ++j)
            {
                if (j == col)
                    continue;
                result.data[r][c] = data[i][j];
                ++c;
            }
            ++r;
        }
        return result;
    }

    template<typename T> Mat4x4<T> Mat4x4<T>::identity() const
    {
        Mat4x4<T> result = zero();
        for (int i = 0; i < 4; ++i)
            result.data[i][i] = 1;
        return result;
    }

    template<typename T> Mat4x4<T> Mat4x4<T>::zero() const
    {
        Mat4x4<T> result;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                result.data[i][j] = 0;
        return result;
    }

    template<typename T> Mat4x4<T> Mat4x4<T>::rotate(float angle, const Vec3<T>& axis) const
    {
        Mat4x4<T> result;
        float rad = angle * (M_PI / 180.0f);  // Convert angle to radians
        float c   = cos(rad);
        float s   = sin(rad);
        float x   = axis.x, y = axis.y, z = axis.z;

        result.data[0][0] = c + (1 - c) * x * x;
        result.data[0][1] = (1 - c) * x * y - s * z;
        result.data[0][2] = (1 - c) * x * z + s * y;
        result.data[1][0] = (1 - c) * y * x + s * z;
        result.data[1][1] = c + (1 - c) * y * y;
        result.data[1][2] = (1 - c) * y * z - s * x;
        result.data[2][0] = (1 - c) * z * x - s * y;
        result.data[2][1] = (1 - c) * z * y + s * x;
        result.data[2][2] = c + (1 - c) * z * z;
        result.data[3][3] = 1;
        return result;
    }

    template<typename T> Mat4x4<T> Mat4x4<T>::lookAt(const Vec3<T>& eye, const Vec3<T>& target, const Vec3<T>& up) const
    {
        Vec3<T> zaxis = (eye - target).normalize();
        Vec3<T> xaxis = up.cross(zaxis).normalize();
        Vec3<T> yaxis = zaxis.cross(xaxis);

        Mat4x4<T> result  = identity();
        result.data[0][0] = xaxis.x;
        result.data[0][1] = xaxis.y;
        result.data[0][2] = xaxis.z;
        result.data[1][0] = yaxis.x;
        result.data[1][1] = yaxis.y;
        result.data[1][2] = yaxis.z;
        result.data[2][0] = -zaxis.x;
        result.data[2][1] = -zaxis.y;
        result.data[2][2] = -zaxis.z;
        result.data[3][0] = -xaxis.dot(eye);
        result.data[3][1] = -yaxis.dot(eye);
        result.data[3][2] = zaxis.dot(eye);
        return result;
    }

    template<typename T> Mat4x4<T> Mat4x4<T>::perspective(float fov, float aspect, float near, float far) const
    {
        Mat4x4<T> result  = zero();
        float tanHalfFov  = tan(fov / 2.0f);
        result.data[0][0] = 1.0f / (aspect * tanHalfFov);
        result.data[1][1] = 1.0f / tanHalfFov;
        result.data[2][2] = -(far + near) / (far - near);
        result.data[2][3] = -1;
        result.data[3][2] = -(2 * far * near) / (far - near);
        return result;
    }

    template<typename T> Mat4x4<T> Mat4x4<T>::orthographic(float left, float right, float bottom, float top, float near, float far) const
    {
        Mat4x4<T> result  = zero();
        result.data[0][0] = 2.0f / (right - left);
        result.data[1][1] = 2.0f / (top - bottom);
        result.data[2][2] = -2.0f / (far - near);
        result.data[3][0] = -(right + left) / (right - left);
        result.data[3][1] = -(top + bottom) / (top - bottom);
        result.data[3][2] = -(far + near) / (far - near);
        result.data[3][3] = 1;
        return result;
    }

    template<typename T> Mat4x4<T> Mat4x4<T>::frustum(float left, float right, float bottom, float top, float near, float far) const
    {
        Mat4x4<T> result  = zero();
        result.data[0][0] = (2 * near) / (right - left);
        result.data[1][1] = (2 * near) / (top - bottom);
        result.data[2][0] = (right + left) / (right - left);
        result.data[2][1] = (top + bottom) / (top - bottom);
        result.data[2][2] = -(far + near) / (far - near);
        result.data[2][3] = -(2 * far * near) / (far - near);
        result.data[3][2] = -1;
        return result;
    }

    template<typename T> Mat4x4<T> Mat4x4<T>::translate(const Vec3<T>& translation) const
    {
        Mat4x4<T> result  = identity();
        result.data[3][0] = translation.x;
        result.data[3][1] = translation.y;
        result.data[3][2] = translation.z;
        return result;
    }

    template<typename T> Mat4x4<T> Mat4x4<T>::scale(const Vec3<T>& scale) const
    {
        Mat4x4<T> result  = identity();
        result.data[0][0] = scale.x;
        result.data[1][1] = scale.y;
        result.data[2][2] = scale.z;
        return result;
    }

    template<typename T> Mat4x4<T> Mat4x4<T>::rotateX(float angle) const
    {
        float c = cos(angle);
        float s = sin(angle);

        Mat4x4<T> result  = identity();
        result.data[1][1] = c;
        result.data[1][2] = -s;
        result.data[2][1] = s;
        result.data[2][2] = c;
        return result;
    }

    template<typename T> Mat4x4<T> Mat4x4<T>::rotateY(float angle) const
    {
        float c = cos(angle);
        float s = sin(angle);

        Mat4x4<T> result  = identity();
        result.data[0][0] = c;
        result.data[0][2] = s;
        result.data[2][0] = -s;
        result.data[2][2] = c;
        return result;
    }

    template<typename T> Mat4x4<T> Mat4x4<T>::rotateZ(float angle) const
    {
        float c = cos(angle);
        float s = sin(angle);

        Mat4x4<T> result  = identity();
        result.data[0][0] = c;
        result.data[0][1] = -s;
        result.data[1][0] = s;
        result.data[1][1] = c;
        return result;
    }

    template class Mat4x4<float>;
    template class Mat4x4<double>;
    template class Mat4x4<int>;
    template class Mat4x4<unsigned int>;
    template class Mat4x4<long>;
} // namespace nt

#endif // _NT_CORE_MATH_MAT4X4_CPP_
