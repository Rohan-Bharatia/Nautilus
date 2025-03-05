//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#ifndef _NT_MATH_RAY3_cpp_
    #define _NT_MATH_RAY3_cpp_

#include "Ray3.h"

#include <cassert>
#include <type_traits>

namespace nt
{
    template<typename T>
    Ray3<T>::Ray3(Vec3<T> origin, Vec3<T> direction) : 
        origin(origin), direction(direction)
    {
        assert((std::is_arithmetic_v<T>) && "Ray3 reqiures an arithmetic type!");
    }

    template class Ray3<float>;
    template class Ray3<int>;
    template class Ray3<double>;
    template class Ray3<uint>;
    template class Ray3<long double>;
} // namespace nt

#endif // _NT_MATH_RAY3_cpp_