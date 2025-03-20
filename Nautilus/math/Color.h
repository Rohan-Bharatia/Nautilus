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

#ifndef _NT_MATH_COLOR_h_
    #define _NT_MATH_COLOR_h_

#include "../core/Types.h"

namespace nt
{
    class Color
    {
    public:
        Color()                        = default;
        Color(uint8 red, uint8 green, uint8 blue, float alpha=1.0f);
        ~Color()                       = default;
        Color(const Color&)            = default;
        Color& operator=(const Color&) = default;

        uint8 red;
        uint8 green;
        uint8 blue;
        float alpha;
    };

    // Arithmetic & assignment operations
    Color operator+(Color lhs, Color rhs);
    Color operator+=(Color& lhs, Color rhs);

    // Relation operations
    bool operator==(Color lhs, Color rhs);
    bool operator!=(Color lhs, Color rhs);
    bool operator<(Color lhs, Color rhs);
    bool operator>(Color lhs, Color rhs);
    bool operator<=(Color lhs, Color rhs);
    bool operator>=(Color lhs, Color rhs);
}

#endif // _NT_MATH_COLOR_h_
