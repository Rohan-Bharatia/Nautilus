//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

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
        Color(uint8 value, float alpha=1.0f);
        Color(uint8 red, uint8 green, uint8 blue, float alpha=1.0f);
        Color(float hue, float saturation, float lv, float alpha=1.0f);
        Color(float cyan, float magenta, float yellow, float key, float alpha=1.0f);
        Color(uint32 hex, float alpha=1.0f);
        ~Color()                       = default;
        Color(const Color&)            = default;
        Color& operator=(const Color&) = default;

        Color toGrayscale();
        Color toRGB();
        Color toHSL();
        Color toHSV();
        Color toCMYK();
        Color toHex();
        
        enum class Colorspace
        {
            GRAYSCALE,
            RGB,
            HSL,
            HSV,
            CMYK,
            HEX,
        };

        Colorspace colorspace;

        union
        {
            struct
            {
                uint8 value;
            } Grayscale;
            struct
            {
                uint8 red;
                uint8 green;
                uint8 blue;
            } RGB;
            struct
            {
                float hue;
                float saturation;
                float lightness;
            } HSL;
            struct
            {
                float hue;
                float saturation;
                float value;
            } HSV;
            struct
            {
                float cyan;
                float magenta;
                float yellow;
                float key;
            } CMYK;
            uint32 hex;
            float alpha;
        } data;
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