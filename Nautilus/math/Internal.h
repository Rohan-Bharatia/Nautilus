//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#pragma once

#ifndef _NT_MATH_INTERNAL_h_
    #define _NT_MATH_INTERNAL_h_

namespace nt::internal
{
    template<typename T>
    T positiveRemainder(T a, T b);
} // namespace nt::internal

#endif // _NT_MATH_INTERNAL_h_