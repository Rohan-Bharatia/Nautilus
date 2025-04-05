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

#ifndef _NT_CORE_MATH_MAT4X4_INL_
    #define _NT_CORE_MATH_MAT4X4_INL_

#include "Mat4x4.h"

#include "../Platform/Platform.h"
namespace nt
{
    template<typename T> T* Mat4x4<T>::operator[](int index)
    {
        return data[index];
    }

    template<typename T> const T* Mat4x4<T>::operator[](int index) const
    {
        return data[index];
    }

    template<typename T> Mat4x4<T> operator+(Mat4x4<T> lhs)
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                lhs.data[i][j] = +lhs.data[i][j];
        return lhs;
    }

    template<typename T> Mat4x4<T> operator-(Mat4x4<T> lhs)
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                lhs.data[i][j] = -lhs.data[i][j];
        return lhs;
    }

    template<typename T> Mat4x4<T> operator+(Mat4x4<T> lhs, Mat4x4<T> rhs)
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                lhs.data[i][j] += rhs.data[i][j];
        return lhs;
    }

    template<typename T> Mat4x4<T> operator-(Mat4x4<T> lhs, Mat4x4<T> rhs)
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                lhs.data[i][j] -= rhs.data[i][j];
        return lhs;
    }

    template<typename T> Mat4x4<T> operator*(Mat4x4<T> lhs, Mat4x4<T> rhs)
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                lhs.data[i][j] *= rhs.data[i][j];
        return lhs;
    }

    template<typename T> Mat4x4<T> operator/(Mat4x4<T> lhs, Mat4x4<T> rhs)
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                assert(rhs.data[i][j] != 0);
                lhs.data[i][j] /= rhs.data[i][j];
            }
        }
        return lhs;
    }

    template<typename T> Mat4x4<T> operator%(Mat4x4<T> lhs, Mat4x4<T> rhs)
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                assert(rhs.data[i][j] != 0);
                lhs.data[i][j] = NT_MODULUS(lhs.data[i][j], rhs.data[i][j]);
            }
        }
        return lhs;
    }

    template<typename T> Mat4x4<T> operator++(Mat4x4<T>& lhs)
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                ++lhs.data[i][j];
        return lhs;
    }

    template<typename T> Mat4x4<T> operator--(Mat4x4<T>& lhs)
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                --lhs.data[i][j];
        return lhs;
    }

    template<typename T> Mat4x4<T> operator++(Mat4x4<T>& lhs, int)
    {
        Mat4x4<T> temp = lhs;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                ++lhs.data[i][j];
        return temp;
    }

    template<typename T> Mat4x4<T> operator--(Mat4x4<T>& lhs, int)
    {
        Mat4x4<T> temp = lhs;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                --lhs.data[i][j];
        return temp;
    }

    template<typename T> Mat4x4<T>& operator+=(Mat4x4<T>& lhs, Mat4x4<T> rhs)
    {
        return lhs = lhs + rhs;
    }

    template<typename T> Mat4x4<T>& operator-=(Mat4x4<T>& lhs, Mat4x4<T> rhs)
    {
        return lhs = lhs - rhs;
    }

    template<typename T> Mat4x4<T>& operator*=(Mat4x4<T>& lhs, Mat4x4<T> rhs)
    {
        return lhs = lhs * rhs;
    }

    template<typename T> Mat4x4<T>& operator/=(Mat4x4<T>& lhs, Mat4x4<T> rhs)
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                assert(rhs.data[i][j] != 0);
        return lhs = lhs / rhs;
    }

    template<typename T> Mat4x4<T>& operator%=(Mat4x4<T>& lhs, Mat4x4<T> rhs)
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                assert(rhs.data[i][j] != 0);
        return lhs = lhs % rhs;
    }

    template<typename T> bool operator==(Mat4x4<T> lhs, Mat4x4<T> rhs)
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (lhs.data[i][j] != rhs.data[i][j])
                    return false;
        return true;
    }

    template<typename T> bool operator!=(Mat4x4<T> lhs, Mat4x4<T> rhs)
    {
        return !(lhs == rhs);
    }

    template<typename T> bool operator<(Mat4x4<T> lhs, Mat4x4<T> rhs)
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (lhs.data[i][j] >= rhs.data[i][j])
                    return false;
        return true;
    }

    template<typename T> bool operator>(Mat4x4<T> lhs, Mat4x4<T> rhs)
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (lhs.data[i][j] <= rhs.data[i][j])
                    return false;
        return true;
    }

    template<typename T> bool operator<=(Mat4x4<T> lhs, Mat4x4<T> rhs)
    {
        return !(lhs > rhs);
    }

    template<typename T> bool operator>=(Mat4x4<T> lhs, Mat4x4<T> rhs)
    {
        return !(lhs < rhs);
    }
} // namespace nt

#endif // _NT_CORE_MATH_MAT4X4_INL_
