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

#ifndef _NT_CORE_MATH_MAT3X3_INL_
    #define _NT_CORE_MATH_MAT3X3_INL_

#include "Mat3x3.h"

#include "Assertion.h"

namespace Nt
{
    template<typename T>
    T& Mat3x3<T>::operator()(int row, int col)
    {
        return mat[row][col];
    }

    template<typename T>
    const T& Mat3x3<T>::operator()(int row, int col) const
    {
        return mat[row][col];
    }

    template<typename T>
    T* Mat3x3<T>::operator[](int index)
    {
        return mat[index];
    }

    template<typename T>
    const T* Mat3x3<T>::operator[](int index) const
    {
        return mat[index];
    }

    template<typename T>
    Mat3x3<T> Mat3x3<T>::operator+(const Mat3x3<T>& other) const
    {
        Mat3x3<T> output = *this;
        for (int col = 0; col < 3; ++col)
            for (int row = 0; row < 3; ++row)
                output.mat[row][col] = mat[row][col] + other.mat[row][col];
        return *this;
    }

    template<typename T>
    Mat3x3<T> Mat3x3<T>::operator+(const T& other) const
    {
        Mat3x3<T> output = *this;
        for (int col = 0; col < 3; ++col)
            for (int row = 0; row < 3; ++row)
                output.mat[row][col] = mat[row][col] + other;
        return *this;
    }

    template<typename T>
    Mat3x3<T> Mat3x3<T>::operator-(const Mat3x3<T>& other) const
    {
        Mat3x3<T> output = *this;
        for (int col = 0; col < 3; ++col)
            for (int row = 0; row < 3; ++row)
                output.mat[row][col] = mat[row][col] - other.mat[row][col];
        return *this;
    }

    template<typename T>
    Mat3x3<T> Mat3x3<T>::operator-(const T& other) const
    {
        Mat3x3<T> output = *this;
        for (int col = 0; col < 3; ++col)
            for (int row = 0; row < 3; ++row)
                output.mat[row][col] = mat[row][col] - other;
        return *this;
    }

    template<typename T>
    Mat3x3<T> Mat3x3<T>::operator*(const Mat3x3<T>& other) const
    {
        Mat3x3<T> output = *this;
        for (int col = 0; col < 3; ++col)
            for (int row = 0; row < 3; ++row)
                output.mat[row][col] = mat[row][col] * other.mat[row][col];
        return *this;
    }

    template<typename T>
    Mat3x3<T> Mat3x3<T>::operator*(const T& other) const
    {
        Mat3x3<T> output = *this;
        for (int col = 0; col < 3; ++col)
            for (int row = 0; row < 3; ++row)
                output.mat[row][col] = mat[row][col] * other;
        return *this;
    }

    template<typename T>
    Mat3x3<T> Mat3x3<T>::operator/(const Mat3x3<T>& other) const
    {
        Mat3x3<T> output = *this;
        for (int col = 0; col < 3; ++col)
            for (int row = 0; row < 3; ++row)
                if (other.mat[row][col] != 0)
                    output.mat[row][col] = mat[row][col] / other.mat[row][col];
        return *this;
    }

    template<typename T>
    Mat3x3<T> Mat3x3<T>::operator/(const T& other) const
    {
        Mat3x3<T> output = *this;
        for (int col = 0; col < 3; ++col)
            for (int row = 0; row < 3; ++row)
                if (other != 0)
                    output.mat[row][col] = mat[row][col] / other;
                else
                    NT_ASSERT(false, "Cannot divide by 0!");
        return *this;
    }

    template<typename T>
    Mat3x3<T> Mat3x3<T>::operator%(const Mat3x3<T>& other) const
    {
        Mat3x3<T> output = *this;
        for (int col = 0; col < 3; ++col)
            for (int row = 0; row < 3; ++row)
                if (other.mat[row][col] != 0)
                    output.mat[row][col] = NT_MODULUS(T, mat[row][col], other.mat[row][col]);
        return *this;
    }

    template<typename T>
    Mat3x3<T> Mat3x3<T>::operator%(const T& other) const
    {
        Mat3x3<T> output = *this;
        for (int col = 0; col < 3; ++col)
            for (int row = 0; row < 3; ++row)
                if (other != 0)
                    output.mat[row][col] = mat[row][col] + other;
                else
                    NT_ASSERT(false, "Cannot modulus by 0!");
        return *this;
    }

    template<typename T>
    Mat3x3<T> Mat3x3<T>::operator++(void)
    {
        for (int col = 0; col < 3; ++col)
            for (int row = 0; row < 3; ++row)
                ++mat[row][col];
        return *this;
    }

    template<typename T>
    Mat3x3<T> Mat3x3<T>::operator++(int)
    {
        Mat3x3<T> temp = *this;
        ++*this;
        return temp;
    }

    template<typename T>
    Mat3x3<T> Mat3x3<T>::operator--(void)
    {
        for (int col = 0; col < 3; ++col)
            for (int row = 0; row < 3; ++row)
                --mat[row][col];
        return *this;
    }

    template<typename T>
    Mat3x3<T> Mat3x3<T>::operator--(int)
    {
        Mat3x3<T> temp = *this;
        --*this;
        return temp;
    }

    template<typename T>
    Mat3x3<T>& Mat3x3<T>::operator+=(const Mat3x3<T>& other)
    {
        return *this = *this + other;
    }

    template<typename T>
    Mat3x3<T>& Mat3x3<T>::operator+=(const T& other)
    {
        return *this = *this + other;
    }

    template<typename T>
    Mat3x3<T>& Mat3x3<T>::operator-=(const Mat3x3<T>& other)
    {
        return *this = *this - other;
    }

    template<typename T>
    Mat3x3<T>& Mat3x3<T>::operator-=(const T& other)
    {
        return *this = *this - other;
    }

    template<typename T>
    Mat3x3<T>& Mat3x3<T>::operator*=(const Mat3x3<T>& other)
    {
        return *this = *this * other;
    }

    template<typename T>
    Mat3x3<T>& Mat3x3<T>::operator*=(const T& other)
    {
        return *this = *this * other;
    }

    template<typename T>
    Mat3x3<T>& Mat3x3<T>::operator/=(const Mat3x3<T>& other)
    {
        return *this = *this / other;
    }

    template<typename T>
    Mat3x3<T>& Mat3x3<T>::operator/=(const T& other)
    {
        return *this = *this / other;
    }

    template<typename T>
    Mat3x3<T>& Mat3x3<T>::operator%=(const Mat3x3<T>& other)
    {
        return *this = *this % other;
    }

    template<typename T>
    Mat3x3<T>& Mat3x3<T>::operator%=(const T& other)
    {
        return *this = *this % other;
    }

    template<typename T>
    bool Mat3x3<T>::operator>(const Mat3x3<T>& other) const
    {
        for (int col = 0; col < 3; ++col)
            for (int row = 0; row < 3; ++row)
                if (mat[row][col] <= other.mat[row][col])
                    return false;
        return true;
    }

    template<typename T>
    bool Mat3x3<T>::operator>(const T& other) const
    {
        for (int col = 0; col < 3; ++col)
            for (int row = 0; row < 3; ++row)
                if (mat[row][col] <= other)
                    return false;
        return true;
    }

    template<typename T>
    bool Mat3x3<T>::operator>=(const Mat3x3<T>& other) const
    {
        for (int col = 0; col < 3; ++col)
            for (int row = 0; row < 3; ++row)
                if (mat[row][col] < other.mat[row][col])
                    return false;
        return true;
    }

    template<typename T>
    bool Mat3x3<T>::operator>=(const T& other) const
    {
        for (int col = 0; col < 3; ++col)
            for (int row = 0; row < 3; ++row)
                if (mat[row][col] < other)
                    return false;
        return true;
    }

    template<typename T>
    bool Mat3x3<T>::operator<(const Mat3x3<T>& other) const
    {
        for (int col = 0; col < 3; ++col)
            for (int row = 0; row < 3; ++row)
                if (mat[row][col] >= other.mat[row][col])
                    return false;
        return true;
    }

    template<typename T>
    bool Mat3x3<T>::operator<(const T& other) const
    {
        for (int col = 0; col < 3; ++col)
            for (int row = 0; row < 3; ++row)
                if (mat[row][col] >= other)
                    return false;
        return true;
    }

    template<typename T>
    bool Mat3x3<T>::operator<=(const Mat3x3<T>& other) const
    {
        for (int col = 0; col < 3; ++col)
            for (int row = 0; row < 3; ++row)
                if (mat[row][col] > other.mat[row][col])
                    return false;
        return true;
    }

    template<typename T>
    bool Mat3x3<T>::operator<=(const T& other) const
    {
        for (int col = 0; col < 3; ++col)
            for (int row = 0; row < 3; ++row)
                if (mat[row][col] > other)
                    return false;
        return true;
    }

    template<typename T>
    bool Mat3x3<T>::operator==(const Mat3x3<T>& other) const
    {
        for (int col = 0; col < 3; ++col)
            for (int row = 0; row < 3; ++row)
                if (mat[row][col] != other.mat[row][col])
                    return false;
        return true;
    }

    template<typename T>
    bool Mat3x3<T>::operator==(const T& other) const
    {
        for (int col = 0; col < 3; ++col)
            for (int row = 0; row < 3; ++row)
                if (mat[row][col] != other)
                    return false;
        return true;
    }

    template<typename T>
    bool Mat3x3<T>::operator!=(const Mat3x3<T>& other) const
    {
        for (int col = 0; col < 3; ++col)
            for (int row = 0; row < 3; ++row)
                if (mat[row][col] == other.mat[row][col])
                    return false;
        return true;
    }

    template<typename T>
    bool Mat3x3<T>::operator!=(const T& other) const
    {
        for (int col = 0; col < 3; ++col)
            for (int row = 0; row < 3; ++row)
                if (mat[row][col] == other)
                    return false;
        return true;
    }
} // namespace Nt

#endif // _NT_CORE_MATH_MAT3X3_INL_
