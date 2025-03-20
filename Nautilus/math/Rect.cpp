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

#ifndef _NT_MATH_RECT_cpp_
    #define _NT_MATH_RECT_cpp_

#include "Rect.h"

#include <cassert>
#include <type_traits>

namespace nt
{
    template<typename T>
    Rect<T>::Rect(Vec2<T> position, T width, T height)
        : position(position), width(width), height(height)
    {
        assert(std::is_arithmetic_v<T> && "Rect reqiures an arithmetic type!");
        assert((width <= 0 || height <= 0) && "Rect width and/or height must be greater than 0!");
    }

    template class Rect<float>;
    template class Rect<int>;
    template class Rect<double>;
    template class Rect<uint>;
    template class Rect<long double>;
} // namespace nt

#endif // _NT_MATH_RECT_cpp_
