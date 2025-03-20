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


#ifndef _NT_MATH_MAT4X4_inl_
    #define _NT_MATH_MAT4X4_inl_

#include "Mat4x4.h"

#include "Internal.h"

#include <cassert>

namespace nt
{
    template<typename T>
    Mat4x4<T> operator+(Mat4x4<T> lhs)
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                lhs.mat[i][j] = +lhs.mat[i][j];
        return lhs;
    }

    template<typename T>
    Mat4x4<T> operator-(Mat4x4<T> lhs)
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                lhs.mat[i][j] = -lhs.mat[i][j];
        return lhs;
    }

    template<typename T>
    Mat4x4<T> operator+(Mat4x4<T> lhs, Mat4x4<T> rhs)
    {
        Mat4x4<T> output = Mat4x4<T>();
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                output.mat[i][j] = lhs.mat[i][j] + rhs.mat[i][j];
        return output;
    }

    template<typename T>
    Mat4x4<T> operator-(Mat4x4<T> lhs, Mat4x4<T> rhs)
    {
        Mat4x4<T> output = Mat4x4<T>();
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                output.mat[i][j] = lhs.mat[i][j] - rhs.mat[i][j];
        return output;
    }

    template<typename T>
    Mat4x4<T> operator*(Mat4x4<T> lhs, Mat4x4<T> rhs)
    {
        Mat4x4<T> output = Mat4x4<T>();
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                output.mat[i][j] = lhs.mat[i][j] * rhs.mat[i][j];
        return output;
    }

    template<typename T>
    Mat4x4<T> operator/(Mat4x4<T> lhs, Mat4x4<T> rhs)
    {
        Mat4x4<T> output = Mat4x4<T>();
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                assert(rhs.mat[i][j] != 0.0f && "Mat4x4 operator / cannot divide by zero!");
                output.mat[i][j] = lhs.mat[i][j] / rhs.mat[i][j];
            }
        }
        return output;
    }

    template<typename T>
    Mat4x4<T> operator%(Mat4x4<T> lhs, Mat4x4<T> rhs)
    {
        Mat4x4<T> output = Mat4x4<T>();
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                assert(rhs.mat[i][j] != 0.0f && "Mat4x4 operator % cannot modulus by zero!");
                output.mat[i][j] = internal::positiveRemainder<T>(lhs.mat[i][j], rhs.mat[i][j]);
            }
        }
        return output;
    }

    template<typename T>
    Mat4x4<T> operator+=(Mat4x4<T>& lhs, Mat4x4<T> rhs)
    {
        return lhs = lhs + rhs;
    }

    template<typename T>
    Mat4x4<T> operator-=(Mat4x4<T>& lhs, Mat4x4<T> rhs)
    {
        return lhs = lhs - rhs;
    }

    template<typename T>
    Mat4x4<T> operator*=(Mat4x4<T>& lhs, Mat4x4<T> rhs)
    {
        return lhs = lhs * rhs;
    }

    template<typename T>
    Mat4x4<T> operator/=(Mat4x4<T>& lhs, Mat4x4<T> rhs)
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                assert(rhs.mat[i][j] != 0.0f && "Mat4x4 operator /= cannot divide by zero!");
        return lhs = lhs / rhs;
    }

    template<typename T>
    Mat4x4<T> operator%=(Mat4x4<T>& lhs, Mat4x4<T> rhs)
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                assert(rhs.mat[i][j] != 0.0f && "Mat4x4 operator %= cannot modulus by zero!");
        return lhs = lhs % rhs;
    }

    template <typename T>
    bool operator==(Mat4x4<T> lhs, Mat4x4<T> rhs)
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (lhs.mat[i][j] != rhs.mat[i][j])
                    return false;
        return true;
    }

    template <typename T>
    bool operator!=(Mat4x4<T> lhs, Mat4x4<T> rhs)
    {
        return !(lhs == rhs);
    }

    template <typename T>
    bool operator<(Mat4x4<T> lhs, Mat4x4<T> rhs)
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (lhs.mat[i][j] >= rhs.mat[i][j])
                    return false;
        return true;
    }

    template <typename T>
    bool operator>(Mat4x4<T> lhs, Mat4x4<T> rhs)
    {
        return !((lhs < rhs) || (lhs == rhs));
    }

    template <typename T>
    bool operator<=(Mat4x4<T> lhs, Mat4x4<T> rhs)
    {
        return (lhs < rhs) || (lhs == rhs);
    }

    template <typename T>
    bool operator>=(Mat4x4<T> lhs, Mat4x4<T> rhs)
    {
        return (lhs > rhs) || (lhs == rhs);
    }
} // namespace nt

#endif // _NT_MATH_MAT4X4_inl_
