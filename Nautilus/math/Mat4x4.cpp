#pragma region LICENSE

//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2025 Rohan Bharatia

#pragma endregion LICENSE

#ifndef _NT_MATH_MAT4X4_cpp_
    #define _NT_MATH_MAT4X4_cpp_

#include "Mat4x4.h"

#include <cmath>
#include <cassert>
#include <type_traits>

namespace nt
{
    template<typename T>
    Mat4x4<T>::Mat4x4()
    {
        assert((std::is_arithmetic_v<T>) && "Mat4x4 reqiures an arithmetic type!");
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::identity() const
    {
        Mat4x4 output;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                output.mat[i][j] = (T)(i == j);
        return output;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::getMinor(int row, int col) const
    {
        Mat4x4<T> minor;
        int p = 0;
        for (int i = 0; i < 4; ++i)
        {
            if (i == row)
                continue;
            int q = 0;
            for (int j = 0; j < 4; j++)
            {
                if (j == col) continue;
                minor.mat[p][q++] = mat[i][j];
            }
            p++;
        }
        return minor;
    }

    template<typename T>
    T Mat4x4<T>::determinant() const
    {
        Mat4x4 minor;
        T det = 0;
        for (int i = 0; i < 4; ++i)
        {
            minor = getMinor(0, i);
            det  += ((i % 2 == 0) ? 1 : -1) * mat[0][i] * minor.determinant();
        }
        return det;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::inverse() const
    {
        Mat4x4 output = *this;
        for (int i = 0; i < 4; ++i)
        {
            int max = i; // Partial pivoting
            for (int j = i + 1; j < 4; ++j)
                if (abs(static_cast<signed>(output.mat[j][i])) > abs(static_cast<signed>(output.mat[max][i])))
                    max = j;
            for (int j = 0; j < 4; ++j) // Swap rows
                std::swap(output.mat[i][j], output.mat[max][j]);
            T pivot = output.mat[i][i]; // Make pivot 1
            for (int j = 0; j < 4; ++j)
                output.mat[i][j] /= pivot;
            for (int j = 0; j < 4; ++j) // Eliminate
            {
                if (j != i)
                {
                    T factor = output.mat[j][i];
                    for (int k = 0; k < 4; k++)
                        output.mat[j][k] -= factor * output.mat[i][k];
                }
            }
        }
        return output;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::transpose() const
    {
        Mat4x4 output;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                output.mat[i][j] = mat[j][i];
        return output;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::orthogonalize() const
    {
        Mat4x4 output;
        for (int i = 0; i < 4; ++i)
        {
            Vec3<T> v = Vec3<T>(mat[i][0], mat[i][1], mat[i][2]);
            for (int j = 0; j < i; ++j)
            {
                Vec3<T> u = Vec3<T>(output.mat[j][0], output.mat[j][1], output.mat[j][2]);
                v -= u * Vec3<T>(v.dot(u) / u.dot(u), v.dot(u) / u.dot(u), v.dot(u) / u.dot(u));
            }
            v.normal();
            output.mat[i][0] = v.x;
            output.mat[i][1] = v.y;
            output.mat[i][2] = v.z;
        }
        return output;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::translate(const Vec3<T>& other) const
    {
        Mat4x4 output    = identity();
        output.mat[3][0] = other.x;
        output.mat[3][1] = other.y;
        output.mat[3][2] = other.z;
        return output;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::rotateX(Angle roll) const
    {
        Mat4x4 output    = identity();
        output.mat[1][1] = std::cos(roll.inRadians());
        output.mat[1][2] = -std::sin(roll.inRadians());
        output.mat[2][1] = std::sin(roll.inRadians());
        output.mat[2][2] = std::cos(roll.inRadians());
        return output;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::rotateY(Angle pitch) const
    {
        Mat4x4 output    = identity();
        output.mat[0][0] = std::cos(pitch.inRadians());
        output.mat[0][2] = std::sin(pitch.inRadians());
        output.mat[2][0] = -std::sin(pitch.inRadians());
        output.mat[2][2] = std::cos(pitch.inRadians());
        return output;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::rotateZ(Angle yaw) const
    {
        Mat4x4 output    = identity();
        output.mat[0][0] = std::cos(yaw.inRadians());
        output.mat[0][1] = -std::sin(yaw.inRadians());
        output.mat[1][0] = std::sin(yaw.inRadians());
        output.mat[1][1] = std::cos(yaw.inRadians());
        return output;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::scale(const Vec3<T>& other) const
    {
        Mat4x4 output    = identity();
        output.mat[0][0] = other.x;
        output.mat[1][1] = other.y;
        output.mat[2][2] = other.z;
        return output;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::lookAt(const Vec3<T>& eye, const Vec3<T>& center, const Vec3<T>& up) const
    {
        Vec3<T> z        = (center - eye).normal();
        Vec3<T> x        = up.cross(z).normal();
        Vec3<T> y        = z.cross(x).normal();
        Mat4x4 output;
        output.mat[0][0] = x.x;
        output.mat[0][1] = x.y;
        output.mat[0][2] = x.z;
        output.mat[0][3] = 0;
        output.mat[1][0] = y.x;
        output.mat[1][1] = y.y;
        output.mat[1][2] = y.z;
        output.mat[1][3] = 0;
        output.mat[2][0] = z.x;
        output.mat[2][1] = z.y;
        output.mat[2][2] = z.z;
        output.mat[2][3] = 0;
        output.mat[3][0] = -eye.dot(x);
        output.mat[3][1] = -eye.dot(y);
        output.mat[3][2] = -eye.dot(z);
        output.mat[3][3] = 1;
        return output;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::perspective(T fov, T aspect, T near, T far) const
    {
        Mat4x4 output;
        T scale = 1 / std::tan(fov * 0.5f);
        output.mat[0][0] = scale / aspect;
        output.mat[1][1] = scale;
        output.mat[2][2] = far / (far - near);
        output.mat[2][3] = 1;
        output.mat[3][2] = (-far * near) / (far - near);
        output.mat[3][3] = 0;
        return output;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::orthographic(T left, T right, T bottom, T top, T near, T far) const
    {
        Mat4x4 output;
        output.mat[0][0] = 2 / (right - left);
        output.mat[1][1] = 2 / (top - bottom);
        output.mat[2][2] = -2 / (far - near);
        output.mat[3][0] = -(right + left) / (right - left);
        output.mat[3][1] = -(top + bottom) / (top - bottom);
        output.mat[3][2] = -(far + near) / (far - near);
        return output;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::frustum(T left, T right, T bottom, T top, T near, T far) const
    {
        Mat4x4 output;
        output.mat[0][0] = 2 * near / (right - left);
        output.mat[1][1] = 2 * near / (top - bottom);
        output.mat[2][0] = (right + left) / (right - left);
        output.mat[2][1] = (top + bottom) / (top - bottom);
        output.mat[2][2] = -(far + near) / (far - near);
        output.mat[2][3] = -1;
        output.mat[3][2] = -2 * far * near / (far - near);
        output.mat[3][3] = 0;
        return output;
    }

    template class Mat4x4<float>;
    template class Mat4x4<int>;
    template class Mat4x4<double>;
    template class Mat4x4<uint>;
    template class Mat4x4<long double>;
} // namespace nt


#endif // _NT_MATH_MAT4X4_cpp_
