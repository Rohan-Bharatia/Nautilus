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

#ifndef _NT_MATH_INTERNAL_cpp_
    #define _NT_MATH_INTERNAL_cpp_

#include "Internal.h"

#include <cassert>

namespace nt::internal
{
    template<typename T>
    T positiveRemainder(T a, T b)
    {
        assert((b > 0.0f) && "Cannot calculate remainder with non-positive divisor!");
        const T val = a - static_cast<T>(static_cast<int>(a / b)) * b;
        return val >= 0.f ? val : val + b;
    }

    template float positiveRemainder<float>(float a, float b);
} // namespace nt::internal

#endif // _NT_MATH_INTERNAL_cpp_
