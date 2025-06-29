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

#ifndef _NT_CORE_MAT4X4_INL_
    #define _NT_CORE_MAT4X4_INL_

#include "Mat4x4.h"

#include "Assertion.h"

namespace Nt
{
    template<typename T>
    Mat4x4<T>::Mat4x4(T val)
    {
        NT_ASSERT(std::is_arithmetic<T>::value, "T must be numeric!");

        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                mat[row][col] = val;
    }

    template<typename T>
    Mat4x4<T>::Mat4x4(T** data)
    {
        NT_ASSERT(sizeof(mat) == sizeof(data), "Mat4x4 size mismatch!");
        NT_ASSERT(std::is_arithmetic<T>::value, "T must be numeric!");

        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                mat[row][col] = data[row][col];
    }

    template<typename T>
    T& Mat4x4<T>::operator()(uint32 row, uint32 col)
    {
        return mat[row][col];
    }

    template<typename T>
    const T& Mat4x4<T>::operator()(uint32 row, uint32 col) const
    {
        return mat[row][col];
    }

    template<typename T>
    T* Mat4x4<T>::operator[](uint32 index)
    {
        return mat[index];
    }

    template<typename T>
    const T* Mat4x4<T>::operator[](uint32 index) const
    {
        return mat[index];
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::operator+(const Mat4x4<T>& other) const
    {
        Mat4x4<T> output = *this;
        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                output.mat[row][col] = mat[row][col] + other.mat[row][col];
        return *this;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::operator+(const T& other) const
    {
        Mat4x4<T> output = *this;
        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                output.mat[row][col] = mat[row][col] + other;
        return *this;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::operator-(const Mat4x4<T>& other) const
    {
        Mat4x4<T> output = *this;
        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                output.mat[row][col] = mat[row][col] - other.mat[row][col];
        return *this;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::operator-(const T& other) const
    {
        Mat4x4<T> output = *this;
        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                output.mat[row][col] = mat[row][col] - other;
        return *this;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::operator*(const Mat4x4<T>& other) const
    {
        Mat4x4<T> output = *this;
        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                output.mat[row][col] = mat[row][col] * other.mat[row][col];
        return *this;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::operator*(const T& other) const
    {
        Mat4x4<T> output = *this;
        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                output.mat[row][col] = mat[row][col] * other;
        return *this;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::operator/(const Mat4x4<T>& other) const
    {
        Mat4x4<T> output = *this;
        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                if (other.mat[row][col] != 0)
                    output.mat[row][col] = mat[row][col] / other.mat[row][col];
        return *this;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::operator/(const T& other) const
    {
        Mat4x4<T> output = *this;
        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                if (other != 0)
                    output.mat[row][col] = mat[row][col] / other;
                else
                    NT_ASSERT(false, "Cannot divide by 0!");
        return *this;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::operator%(const Mat4x4<T>& other) const
    {
        Mat4x4<T> output = *this;
        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                if (other.mat[row][col] != 0)
                    output.mat[row][col] = NT_MODULUS(T, mat[row][col], other.mat[row][col]);
        return *this;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::operator%(const T& other) const
    {
        Mat4x4<T> output = *this;
        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                if (other != 0)
                    output.mat[row][col] = mat[row][col] + other;
                else
                    NT_ASSERT(false, "Cannot modulus by 0!");
        return *this;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::operator++(void)
    {
        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                ++mat[row][col];
        return *this;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::operator++(int)
    {
        Mat4x4<T> temp = *this;
        ++*this;
        return temp;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::operator--(void)
    {
        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                --mat[row][col];
        return *this;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::operator--(int)
    {
        Mat4x4<T> temp = *this;
        --*this;
        return temp;
    }

    template<typename T>
    Mat4x4<T>& Mat4x4<T>::operator+=(const Mat4x4<T>& other)
    {
        return *this = *this + other;
    }

    template<typename T>
    Mat4x4<T>& Mat4x4<T>::operator+=(const T& other)
    {
        return *this = *this + other;
    }

    template<typename T>
    Mat4x4<T>& Mat4x4<T>::operator-=(const Mat4x4<T>& other)
    {
        return *this = *this - other;
    }

    template<typename T>
    Mat4x4<T>& Mat4x4<T>::operator-=(const T& other)
    {
        return *this = *this - other;
    }

    template<typename T>
    Mat4x4<T>& Mat4x4<T>::operator*=(const Mat4x4<T>& other)
    {
        return *this = *this * other;
    }

    template<typename T>
    Mat4x4<T>& Mat4x4<T>::operator*=(const T& other)
    {
        return *this = *this * other;
    }

    template<typename T>
    Mat4x4<T>& Mat4x4<T>::operator/=(const Mat4x4<T>& other)
    {
        return *this = *this / other;
    }

    template<typename T>
    Mat4x4<T>& Mat4x4<T>::operator/=(const T& other)
    {
        return *this = *this / other;
    }

    template<typename T>
    Mat4x4<T>& Mat4x4<T>::operator%=(const Mat4x4<T>& other)
    {
        return *this = *this % other;
    }

    template<typename T>
    Mat4x4<T>& Mat4x4<T>::operator%=(const T& other)
    {
        return *this = *this % other;
    }

    template<typename T>
    bool Mat4x4<T>::operator>(const Mat4x4<T>& other) const
    {
        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                if (mat[row][col] <= other.mat[row][col])
                    return false;
        return true;
    }

    template<typename T>
    bool Mat4x4<T>::operator>(const T& other) const
    {
        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                if (mat[row][col] <= other)
                    return false;
        return true;
    }

    template<typename T>
    bool Mat4x4<T>::operator>=(const Mat4x4<T>& other) const
    {
        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                if (mat[row][col] < other.mat[row][col])
                    return false;
        return true;
    }

    template<typename T>
    bool Mat4x4<T>::operator>=(const T& other) const
    {
        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                if (mat[row][col] < other)
                    return false;
        return true;
    }

    template<typename T>
    bool Mat4x4<T>::operator<(const Mat4x4<T>& other) const
    {
        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                if (mat[row][col] >= other.mat[row][col])
                    return false;
        return true;
    }

    template<typename T>
    bool Mat4x4<T>::operator<(const T& other) const
    {
        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                if (mat[row][col] >= other)
                    return false;
        return true;
    }

    template<typename T>
    bool Mat4x4<T>::operator<=(const Mat4x4<T>& other) const
    {
        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                if (mat[row][col] > other.mat[row][col])
                    return false;
        return true;
    }

    template<typename T>
    bool Mat4x4<T>::operator<=(const T& other) const
    {
        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                if (mat[row][col] > other)
                    return false;
        return true;
    }

    template<typename T>
    bool Mat4x4<T>::operator==(const Mat4x4<T>& other) const
    {
        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                if (mat[row][col] != other.mat[row][col])
                    return false;
        return true;
    }

    template<typename T>
    bool Mat4x4<T>::operator==(const T& other) const
    {
        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                if (mat[row][col] != other)
                    return false;
        return true;
    }

    template<typename T>
    bool Mat4x4<T>::operator!=(const Mat4x4<T>& other) const
    {
        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                if (mat[row][col] == other.mat[row][col])
                    return false;
        return true;
    }

    template<typename T>
    bool Mat4x4<T>::operator!=(const T& other) const
    {
        for (uint32 col = 0; col < 4; ++col)
            for (uint32 row = 0; row < 4; ++row)
                if (mat[row][col] == other)
                    return false;
        return true;
    }

    template<typename T>
    Mat4x4<T>::operator T**(void) const
    {
        return mat;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::Identity(void)
    {
        Mat4x4<T> output = Identity();
        output(0, 0)     = 1;
        output(1, 1)     = 1;
        output(2, 2)     = 1;
        output(3, 3)     = 1;
        return output;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::Perspective(T fovy, T aspect, T zNear, T zFar)
    {
        Mat4x4<T> output = Identity();
        output(0, 0)     = 1 / (aspect * (fovy / 2));
        output(1, 1)     = 1 / (fovy / 2);
        output(2, 2)     = -((zFar + zNear) / (zFar - zNear));
        output(2, 3)     = -1;
        output(3, 2)     = -((2 * zFar * zNear) / (zFar - zNear));
        output(3, 3)     = 0;
        return output;
    }

    template<typename T>
    T Mat4x4<T>::Determinant(void) const
    {
        T det = 0;

        for (uint32 col = 0; col < 4; ++col)
        {
            T minor[3][3];
            for (uint32 row = 1; row < 4; ++row)
            {
                uint32 minorRow = 0;
                for (uint32 minorCol = 0; minorCol < 4; ++minorCol)
                {
                    if (minorCol == col)
                        continue;

                    minor[minorRow][minorCol] = mat[row][minorCol];
                    ++minorRow;
                }

                det += mat[0][col] * MinorDeterminant(minor);
            }
        }

        return det;
    }

    template<typename T>
    T Mat4x4<T>::MinorDeterminant(T minor[3][3]) const
    {
        return minor[0][0] * (minor[1][1] * minor[2][2] - minor[1][2] * minor[2][1]) -
               minor[0][1] * (minor[1][0] * minor[2][2] - minor[1][2] * minor[2][0]) +
               minor[0][2] * (minor[1][0] * minor[2][1] - minor[1][1] * minor[2][0]);
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::Inverse(void)
    {
        Mat4x4<T> output = Identity();

        for (uint32 col = 0; col < 4; ++col)
        {
            uint32 maxRow = col;
            for (uint32 row = col + 1; row < 4; ++row)
                if (abs((int)mat[row][col]) > abs((int)mat[maxRow][col]))
                    maxRow = row;

            if (maxRow != col)
            {
                SwapRows(mat, col, maxRow);
                SwapRows(output.mat, col, maxRow);
            }

            T pivot = mat[col][col];

            for (uint32 row = col; row < 4; ++row)
                mat[row][col] /= pivot;
            for (uint32 row = 0; row < 4; ++row)
                output.mat[row][col] /= pivot;

            for (uint32 row = 0; row < 4; ++row)
            {
                if (row != col)
                {
                    T factor = mat[row][col];
                    for (uint32 col2 = col; col2 < 4; ++col2)
                        mat[row][col2] -= mat[col][col2] * factor;
                    for (uint32 col2 = 0; col2 < 4; ++col2)
                        output.mat[row][col2] -= output.mat[col][col2] * factor;
                }
            }
        }

        return output;
    }

    template<typename T>
    void Mat4x4<T>::SwapRows(T mat[4][4], uint32 row1, uint32 row2)
    {
        T temp[4];
        for (uint32 col = 0; col < 4; col++)
        {
            temp[col]      = mat[row1][col];
            mat[row1][col] = mat[row2][col];
            mat[row2][col] = temp[col];
        }
    }

    template<typename T>
    void Mat4x4<T>::SwapColumns(T mat[4][4], uint32 col1, uint32 col2)
    {
        T temp[4];
        for (uint32 col = 0; col < 4; col++)
        {
            temp[col]      = mat[col][col1];
            mat[col][col1] = mat[col][col2];
            mat[col][col2] = temp[col];
        }
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::Transpose(void) const
    {
        Mat4x4<T> output = Identity();
        for (uint32 col = 0; col < 4; col++)
            for (uint32 row = 0; row < 4; row++)
                output.mat[row][col] = mat[col][row];
        return output;
    }

    template<typename T>
    void Mat4x4<T>::Orthogonalize(void)
    {
        // Gram-Schmidt process
        for (uint32 col = 0; col < 4; ++col)
        {
            T norm = 0;

            for (uint32 row = 0; row < 4; ++row)
                norm += mat[row][col] * mat[row][col];

            norm = sqrt(norm);

            for (uint32 row = 0; row < 4; ++row)
                mat[row][col] /= norm;

            for (uint32 col2 = col + 1; col2 < 4; ++col2)
            {
                T dot = 0;

                for (uint32 row = 0; row < 4; ++row)
                    dot += mat[row][col] * mat[row][col2];
                for (uint32 row = 0; row < 4; ++row)
                    mat[row][col2] -= dot * mat[row][col];
            }
        }
    }

    template<typename T>
    Vec3<T> Mat4x4<T>::Translate(const Vec3<T>& other) const
    {
        Vec3<T> output(0, 0, 0);
        output.x = mat[3][0] + other.x;
        output.y = mat[3][1] + other.y;
        output.z = mat[3][2] + other.z;
        return output;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::Translation(const Vec3<T>& other)
    {
        Mat4x4<T> output = Identity();
        output.mat[3][0] = other.x;
        output.mat[3][1] = other.y;
        output.mat[3][2] = other.z;
        return output;
    }

    template<typename T>
    Vec3<T> Mat4x4<T>::Rotate(const Vec3<T>& other) const
    {
        Vec3<T> output(0, 0, 0);
        output.x = mat[0][0] * other.x + mat[0][1] * other.y + mat[0][2] * other.z;
        output.y = mat[1][0] * other.x + mat[1][1] * other.y + mat[1][2] * other.z;
        output.z = mat[2][0] * other.x + mat[2][1] * other.y + mat[2][2] * other.z;
        return output;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::Rotation(Angle angle)
    {
        Mat4x4<T> output = Identity();
        output(0, 0)     = cos(angle.InRadians());
        output(0, 1)     = -sin(angle.InRadians());
        output(1, 0)     = sin(angle.InRadians());
        output(1, 1)     = cos(angle.InRadians());
        return output;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::Rotation(const Quaternion<T>& quaternion)
    {
        T x = quaternion.Normalize().x;
        T y = quaternion.Normalize().y;
        T z = quaternion.Normalize().z;
        T w = sqrt(1.0f - x * x - y * y - z * z);

        Mat4x4<T> rotationMatrix = Identity();

        rotationMatrix(0, 0) = 1.0f - 2.0f * y * y - 2.0f * z * z;
        rotationMatrix(0, 1) = 2.0f * x * y + 2.0f * w * z;
        rotationMatrix(0, 2) = 2.0f * x * z - 2.0f * w * y;
        rotationMatrix(0, 3) = 0.0f;

        rotationMatrix(1, 0) = 2.0f * x * y - 2.0f * w * z;
        rotationMatrix(1, 1) = 1.0f - 2.0f * x * x - 2.0f * z * z;
        rotationMatrix(1, 2) = 2.0f * y * z + 2.0f * w * x;
        rotationMatrix(1, 3) = 0.0f;

        rotationMatrix(2, 0) = 2.0f * x * z + 2.0f * w * y;
        rotationMatrix(2, 1) = 2.0f * y * z - 2.0f * w * x;
        rotationMatrix(2, 2) = 1.0f - 2.0f * x * x - 2.0f * y * y;
        rotationMatrix(2, 3) = 0.0f;

        rotationMatrix(3, 0) = 0.0f;
        rotationMatrix(3, 1) = 0.0f;
        rotationMatrix(3, 2) = 0.0f;
        rotationMatrix(3, 3) = 1.0f;

        return rotationMatrix;
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::Rotation(Angle angle, const Vec3<T>& axis)
    {
        return Rotation(axis.Normalize()) * Rotation(angle.InRadians());
    }

    template<typename T>
    Mat4x4<T> Mat4x4<T>::Orthographic(T left, T right, T bottom, T top, T _near, T _far)
    {
        Mat4x4<T> output = Identity();
        output(0, 0)     = 2.0f / (right - left);
        output(1, 1)     = 2.0f / (top - bottom);
        output(2, 2)     = -2.0f / (_far - _near);
        output(3, 0)     = -(right + left) / (right - left);
        output(3, 1)     = -(top + bottom) / (top - bottom);
        output(3, 2)     = -(_far + _near) / (_far - _near);
        return output;
    }
} // namespace Nt

#endif // _NT_CORE_MAT4X4_INL_
