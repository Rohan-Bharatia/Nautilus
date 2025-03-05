//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#ifndef _NT_MATH_RAY2_cpp_
    #define _NT_MATH_RAY2_cpp_

#include "Ray2.h"

#include <cassert>
#include <type_traits>

namespace nt
{
    template<typename T>
    Ray2<T>::Ray2(Vec2<T> origin, Vec2<T> direction) : 
        origin(origin), direction(direction)
    {
        assert((std::is_arithmetic_v<T>) && "Ray2 reqiures an arithmetic type!");
    }

    template class Ray2<float>;
    template class Ray2<int>;
    template class Ray2<double>;
    template class Ray2<uint>;
    template class Ray2<long double>;
} // namespace nt

#endif // _NT_MATH_RAY2_cpp_