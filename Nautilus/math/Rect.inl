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

#ifndef _NT_MATH_RECT_inl_
    #define _NT_MATH_RECT_inl_

#include "Rect.h"

#include "Internal.h"

#include <cassert>

namespace nt
{
    template<typename T>
    Rect<T> operator+(Rect<T> lhs)
    {
        return Rect(+lhs.position, +lhs.width, +lhs.height);
    }

    template<typename T>
    Rect<T> operator-(Rect<T> lhs)
    {
        return Rect(-lhs.position, -lhs.width, -lhs.height);
    }

    template<typename T>
    Rect<T> operator+(Rect<T> lhs, Rect<T> rhs)
    {
        return Rect(lhs.position + rhs.position, lhs.width + rhs.width, lhs.height + rhs.height);
    }

    template<typename T>
    Rect<T> operator-(Rect<T> lhs, Rect<T> rhs)
    {
        return Rect(lhs.position - rhs.position, lhs.width - rhs.width, lhs.height - rhs.height);
    }

    template<typename T>
    Rect<T> operator*(Rect<T> lhs, Rect<T> rhs)
    {
        return Rect(lhs.position * rhs.position, lhs.width * rhs.width, lhs.height * rhs.height);
    }

    template<typename T>
    Rect<T> operator/(Rect<T> lhs, Rect<T> rhs)
    {
        assert(rhs.position.x != 0 && "Rect operator / cannot divide by zero!");
        assert(rhs.position.y != 0 && "Rect operator / cannot divide by zero!");
        assert(rhs.width != 0 && "Rect operator / cannot divide by zero!");
        assert(rhs.height != 0 && "Rect operator / cannot divide by zero!");
        return Rect(lhs.position / rhs.position, lhs.width / rhs.width, lhs.height / rhs.height);
    }

    template<typename T>
    Rect<T> operator%(Rect<T> lhs, Rect<T> rhs)
    {
        assert(rhs.position.x != 0 && "Rect operator % cannot modulus by zero!");
        assert(rhs.position.y != 0 && "Rect operator % cannot modulus by zero!");
        assert(rhs.width != 0 && "Rect operator % cannot modulus by zero!");
        assert(rhs.height != 0 && "Rect operator % cannot modulus by zero!");
        return Rect(lhs.position % rhs.position, internal::positiveRemainder<T>(lhs.width, rhs.width), internal::positiveRemainder<T>(lhs.height, rhs.height));
    }

    template<typename T>
    Rect<T> operator+=(Rect<T>& lhs, Rect<T> rhs)
    {
        return lhs = lhs + rhs;
    }

    template<typename T>
    Rect<T> operator-=(Rect<T>& lhs, Rect<T> rhs)
    {
        return lhs = lhs - rhs;
    }

    template<typename T>
    Rect<T> operator*=(Rect<T>& lhs, Rect<T> rhs)
    {
        return lhs = lhs * rhs;
    }

    template<typename T>
    Rect<T> operator/=(Rect<T>& lhs, Rect<T> rhs)
    {
        assert(rhs.position.x != 0 && "Rect operator / cannot divide by zero!");
        assert(rhs.position.y != 0 && "Rect operator / cannot divide by zero!");
        assert(rhs.width != 0 && "Rect operator / cannot divide by zero!");
        assert(rhs.height != 0 && "Rect operator / cannot divide by zero!");
        return lhs = lhs / rhs;
    }

    template<typename T>
    Rect<T> operator%=(Rect<T>& lhs, Rect<T> rhs)
    {
        assert(rhs.position.x != 0 && "Rect operator % cannot modulus by zero!");
        assert(rhs.position.y != 0 && "Rect operator % cannot modulus by zero!");
        assert(rhs.width != 0 && "Rect operator % cannot modulus by zero!");
        assert(rhs.height != 0 && "Rect operator % cannot modulus by zero!");
        return lhs = lhs % rhs;
    }

    template <typename T>
    bool operator==(Rect<T> lhs, Rect<T> rhs)
    {
        return (lhs.position == rhs.position) && (lhs.width == rhs.width) && (lhs.height == rhs.height);
    }

    template <typename T>
    bool operator!=(Rect<T> lhs, Rect<T> rhs)
    {
        return (lhs.position != rhs.position) && (lhs.width != rhs.width) && (lhs.height != rhs.height);
    }

    template <typename T>
    bool operator<(Rect<T> lhs, Rect<T> rhs)
    {
        return (lhs.position < rhs.position) && (lhs.width < rhs.width) && (lhs.height < rhs.height);
    }

    template <typename T>
    bool operator>(Rect<T> lhs, Rect<T> rhs)
    {
        return (lhs.position > rhs.position) && (lhs.width > rhs.width) && (lhs.height > rhs.height);
    }

    template <typename T>
    bool operator<=(Rect<T> lhs, Rect<T> rhs)
    {
        return (lhs.position <= rhs.position) && (lhs.width <= rhs.width) && (lhs.height <= rhs.height);
    }

    template <typename T>
    bool operator>=(Rect<T> lhs, Rect<T> rhs)
    {
        return (lhs.position >= rhs.position) && (lhs.width >= rhs.width) && (lhs.height >= rhs.height);
    }
} // namespace nt

#endif // _NT_MATH_RECT_inl_
