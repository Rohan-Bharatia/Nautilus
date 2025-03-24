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

#pragma once

#ifndef _NT_MATH_RECT_h_
    #define _NT_MATH_RECT_h_

#include "../core/Types.h"
#include "Vec2.h"

namespace nt
{
    template<typename T>
    class Rect
    {
    public:
        Rect()                             = default;
        Rect(Vec2<T> position, T width, T height);
        ~Rect()                            = default;
        Rect(const Rect& other)            = default;
        Rect& operator=(const Rect& other) = default;

        Vec2<T> position;
        T width;
        T height;
    };

    // Sign operations
    template<typename T>
    Rect<T> operator+(Rect<T> lhs);
    template<typename T>
    Rect<T> operator-(Rect<T> lhs);

    // Arithmetic operations
    template<typename T>
    Rect<T> operator+(Rect<T> lhs, Rect<T> rhs);
    template<typename T>
    Rect<T> operator-(Rect<T> lhs, Rect<T> rhs);
    template<typename T>
    Rect<T> operator*(Rect<T> lhs, Rect<T> rhs);
    template<typename T>
    Rect<T> operator/(Rect<T> lhs, Rect<T> rhs);
    template<typename T>
    Rect<T> operator%(Rect<T> lhs, Rect<T> rhs);

    // Assignment operations
    template<typename T>
    Rect<T> operator+=(Rect<T>& lhs, Rect<T> rhs);
    template<typename T>
    Rect<T> operator-=(Rect<T>& lhs, Rect<T> rhs);
    template<typename T>
    Rect<T> operator*=(Rect<T>& lhs, Rect<T> rhs);
    template<typename T>
    Rect<T> operator/=(Rect<T>& lhs, Rect<T> rhs);
    template<typename T>
    Rect<T> operator%=(Rect<T>& lhs, Rect<T> rhs);

    // Relation operations
    template<typename T>
    bool operator==(Rect<T> lhs, Rect<T> rhs);
    template<typename T>
    bool operator!=(Rect<T> lhs, Rect<T> rhs);
    template<typename T>
    bool operator<(Rect<T> lhs, Rect<T> rhs);
    template<typename T>
    bool operator>(Rect<T> lhs, Rect<T> rhs);
    template<typename T>
    bool operator<=(Rect<T> lhs, Rect<T> rhs);
    template<typename T>
    bool operator>=(Rect<T> lhs, Rect<T> rhs);

    using Rectf = Rect<float>;
    using Recti = Rect<int>;
    using Rectd = Rect<double>;
    using Rectu = Rect<uint>;
    using Rectl = Rect<long double>;
}

#include "Rect.inl"

#endif // _NT_MATH_RECT_h_
