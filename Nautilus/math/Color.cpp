//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia


#ifndef _NT_MATH_COLOR_cpp_
    #define _NT_MATH_COLOR_cpp_

#include "Color.h"

#include <cmath>

namespace nt
{
    Color::Color(uint8 value, float alpha) : 
        colorspace(Colorspace::GRAYSCALE)
    {
        data.Grayscale.value = value;
        data.alpha           = alpha;
    }
    
    Color::Color(uint8 red, uint8 green, uint8 blue, float alpha) : 
        colorspace(Colorspace::RGB)
    {
        data.RGB.red   = red;
        data.RGB.green = green;
        data.RGB.blue  = blue;
        data.alpha     = alpha;
    }
    
    Color::Color(float hue, float saturation, float lv, float alpha) : 
        colorspace(Colorspace::HSL)
    {
        data.HSL.hue        = hue;
        data.HSL.saturation = saturation;
        data.HSL.lightness  = lv;
        data.HSV.hue        = hue;
        data.HSV.saturation = saturation;
        data.HSV.value      = lv;
        data.alpha          = alpha;
    }
    
    Color::Color(uint32 hex, float alpha) : 
        colorspace(Colorspace::HEX)
    {
        data.hex   = hex;
        data.alpha = alpha;
    }
    
    Color Color::toGrayscale()
    {
        Color grayscale;
        grayscale.colorspace = Colorspace::GRAYSCALE;
        switch (colorspace)
        {
            case Colorspace::GRAYSCALE:
            {
                grayscale.data.Grayscale.value = data.Grayscale.value;
            }
                break;
            case Colorspace::RGB:
            {
                grayscale.data.Grayscale.value = (uint8)((data.RGB.red * 0.2126f) + (data.RGB.green * 0.7152f) + (data.RGB.blue * 0.0722f));
            }
                break;
            case Colorspace::HSL:
            {
                grayscale.data.Grayscale.value = (uint8)(data.HSL.lightness * 255.0f);
            }
                break;
            case Colorspace::HSV:
            {
                grayscale.data.Grayscale.value = (uint8)(data.HSV.value * 255.0f);
            }
                break;
            case Colorspace::CMYK:
            {
                grayscale.data.Grayscale.value = (uint8)((1.0f - data.CMYK.cyan) * 255.0f);
            }
                break;
            case Colorspace::HEX:
            {
                uint32 hex                     = data.hex;
                uint8 r                        = (uint8)((hex >> 16) & 0xFF);
                uint8 g                        = (uint8)((hex >> 8) & 0xFF);
                uint8 b                        = (uint8)(hex & 0xFF);
                grayscale.data.Grayscale.value = (uint8)((r * 0.2126f) + (g * 0.7152f) + (b * 0.0722f));
            }
                break;
        }
        return grayscale;
    }

    Color Color::toRGB()
    {
        Color rgb;
        rgb.colorspace = Colorspace::RGB;
        switch (colorspace)
        {
            case Colorspace::GRAYSCALE:
            {
                rgb.data.RGB.red   = data.Grayscale.value;
                rgb.data.RGB.green = data.Grayscale.value;
                rgb.data.RGB.blue  = data.Grayscale.value;
            }
                break;
            case Colorspace::RGB:
            {
                rgb.data.RGB.red   = data.RGB.red;
                rgb.data.RGB.green = data.RGB.green;
                rgb.data.RGB.blue  = data.RGB.blue;
            }
                break;
            case Colorspace::HSL:
            {
                float h = data.HSL.hue / 360.0f;
                float s = data.HSL.saturation;
                float l = data.HSL.lightness;
                float c = (1.0f - std::abs(2.0f * l - 1.0f)) * s;
                float x = c * (1.0f - std::abs(std::fmod(h * 6.0f, 2.0f) - 1.0f));
                float m = l - c / 2.0f;
                float r, g, b;
                if (h < 1.0f / 6.0f)
                {
                    r = c;
                    g = x;
                    b = 0.0f;
                } 
                else if (h < 2.0f / 6.0f)
                {
                    r = x;
                    g = c;
                    b = 0.0f;
                }
                else if (h < 3.0f / 6.0f)
                {
                    r = 0.0f;
                    g = c;
                    b = x;
                }
                else if (h < 4.0f / 6.0f)
                {
                    r = 0.0f;
                    g = x;
                    b = c;
                }
                else if (h < 5.0f / 6.0f)
                {
                    r = x;
                    g = 0.0f;
                    b = c;
                }
                else
                {
                    r = c;
                    g = 0.0f;
                    b = x;
                }
                rgb.data.RGB.red   = (uint8)((r + m) * 255.0f);
                rgb.data.RGB.green = (uint8)((g + m) * 255.0f);
                rgb.data.RGB.blue  = (uint8)((b + m) * 255.0f);
            }
                break;
            case Colorspace::HSV:
            {
                float h = data.HSV.hue / 360.0f;
                float s = data.HSV.saturation;
                float v = data.HSV.value;
                float c = v * s;
                float x = c * (1.0f - std::abs(std::fmod(h * 6.0f, 2.0f) - 1.0f));
                float m = v - c;
                float r, g, b;
                if (h < 1.0f / 6.0f)
                {
                    r = c;
                    g = x;
                    b = 0.0f;
                }
                else if (h < 2.0f / 6.0f)
                {
                    r = x;
                    g = c;
                    b = 0.0f;
                }
                else if (h < 3.0f / 6.0f)
                {
                    r = 0.0f;
                    g = c;
                    b = x;
                }
                else if (h < 4.0f / 6.0f)
                {
                    r = 0.0f;
                    g = x;
                    b = c;
                }
                else if (h < 5.0f / 6.0f)
                {
                    r = x;
                    g = 0.0f;
                    b = c;
                }
                else
                {
                    r = c;
                    g = 0.0f;
                    b = x;
                }
                rgb.data.RGB.red   = (uint8)((r + m) * 255.0f);
                rgb.data.RGB.green = (uint8)((g + m) * 255.0f);
                rgb.data.RGB.blue  = (uint8)((b + m) * 255.0f);
            }
                break;
            case Colorspace::CMYK:
            {
                float c            = data.CMYK.cyan / 255.0f;
                float m            = data.CMYK.magenta / 255.0f;
                float y            = data.CMYK.yellow / 255.0f;
                float k            = data.CMYK.key / 255.0f;
                float r            = 1.0f - c;
                float g            = 1.0f - m;
                float b            = 1.0f - y;
                r                 *= (1.0f - k);
                g                 *= (1.0f - k);
                b                 *= (1.0f - k);
                rgb.data.RGB.red   = (uint8)(r * 255.0f);
                rgb.data.RGB.green = (uint8)(g * 255.0f);
                rgb.data.RGB.blue  = (uint8)(b * 255.0f);
            }
                break;
            case Colorspace::HEX:
            {
                uint32 hex         = data.hex;
                rgb.data.RGB.red   = (uint8)((hex >> 16) & 0xFF);
                rgb.data.RGB.green = (uint8)((hex >> 8) & 0xFF);
                rgb.data.RGB.blue  = (uint8)(hex & 0xFF);
            }
                break;
        }
        return rgb;
    }

    Color Color::toHSL()
    {
        Color hsl;
        hsl.colorspace = Colorspace::HSL;
        switch (colorspace)
        {
            case Colorspace::GRAYSCALE:
            {
                hsl.data.HSL.hue        = 0.0f;
                hsl.data.HSL.saturation = 0.0f;
                hsl.data.HSL.lightness  = (float)data.Grayscale.value / 255.0f;
            }
                break;
            case Colorspace::RGB:
            {
                float r                = (float)data.RGB.red / 255.0f;
                float g                = (float)data.RGB.green / 255.0f;
                float b                = (float)data.RGB.blue / 255.0f;
                float max              = std::max(r, std::max(g, b));
                float min              = std::min(r, std::min(g, b));
                float delta            = max - min;
                hsl.data.HSL.lightness = (max + min) / 2.0f;
                if (delta == 0.0f)
                {
                    hsl.data.HSL.hue = 0.0f;
                    hsl.data.HSL.saturation = 0.0f;
                }
                else
                {
                    hsl.data.HSL.saturation = (hsl.data.HSL.lightness > 0.5f) ? delta / (2.0f - max - min) : delta / (max + min);
                    if (r == max)
                        hsl.data.HSL.hue = (g - b) / delta;
                    else if (g == max)
                        hsl.data.HSL.hue = 2.0f + (b - r) / delta;
                    else
                        hsl.data.HSL.hue = 4.0f + (r - g) / delta;
                    hsl.data.HSL.hue *= 60.0f;
                    if (hsl.data.HSL.hue < 0.0f)
                        hsl.data.HSL.hue += 360.0f;
                }
            }
                break;
            case Colorspace::HSL:
            {
                hsl.data.HSL.hue        = data.HSL.hue;
                hsl.data.HSL.saturation = data.HSL.saturation;
                hsl.data.HSL.lightness  = data.HSL.lightness;
            }
                break;
            case Colorspace::HSV:
            {
                hsl.data.HSL.hue        = data.HSV.hue;
                hsl.data.HSL.saturation = data.HSV.saturation;
                hsl.data.HSL.lightness  = data.HSV.value;
            }
                break;
            case Colorspace::CMYK:
            {
                Color rgb = toRGB();
                hsl       = rgb.toHSL();
            }
                break;
            case Colorspace::HEX:
            {
                uint32 hex = data.hex;
                uint8 r    = (uint8)((hex >> 16) & 0xFF);
                uint8 g    = (uint8)((hex >> 8) & 0xFF);
                uint8 b    = (uint8)(hex & 0xFF);
                Color rgb;
                rgb.data.RGB.red   = r;
                rgb.data.RGB.green = g;
                rgb.data.RGB.blue  = b;
                hsl                = rgb.toHSL();
            }
                break;
        }
    
        return hsl;
    }

    Color Color::toHSV()
    {
        Color hsv;
        hsv.colorspace = Colorspace::HSV;
        switch (colorspace)
        {
            case Colorspace::GRAYSCALE:
            {
                hsv.data.HSV.hue        = 0.0f;
                hsv.data.HSV.saturation = 0.0f;
                hsv.data.HSV.value      = (float)data.Grayscale.value / 255.0f;
            }
                break;
            case Colorspace::RGB:
            {
                float r            = (float)data.RGB.red / 255.0f;
                float g            = (float)data.RGB.green / 255.0f;
                float b            = (float)data.RGB.blue / 255.0f;
                float max          = std::max(r, std::max(g, b));
                float min          = std::min(r, std::min(g, b));
                float delta        = max - min;
                hsv.data.HSV.value = (max + min) / 2.0f;
                if (delta == 0.0f)
                {
                    hsv.data.HSV.hue        = 0.0f;
                    hsv.data.HSV.saturation = 0.0f;
                }
                else
                {
                    hsv.data.HSV.saturation = (hsv.data.HSV.value > 0.5f) ? delta / (2.0f - max - min) : delta / (max + min);
                    if (r == max)
                        hsv.data.HSL.hue = (g - b) / delta;
                    else if (g == max)
                        hsv.data.HSL.hue = 2.0f + (b - r) / delta;
                    else
                        hsv.data.HSL.hue = 4.0f + (r - g) / delta;
                    hsv.data.HSV.hue *= 60.0f;
                    if (hsv.data.HSV.hue < 0.0f)
                        hsv.data.HSV.hue += 360.0f;
                }
            }
                break;
            case Colorspace::HSL:
            {
                hsv.data.HSV.hue        = data.HSL.hue;
                hsv.data.HSV.saturation = data.HSL.saturation;
                hsv.data.HSV.value      = data.HSL.lightness;
            }
                break;
            case Colorspace::HSV:
            {
                hsv.data.HSV.hue        = data.HSV.hue;
                hsv.data.HSV.saturation = data.HSV.saturation;
                hsv.data.HSV.value      = data.HSV.value;
            }
                break;
            case Colorspace::CMYK:
            {
                Color rgb = toRGB();
                hsv       = rgb.toHSL();
            }
                break;
            case Colorspace::HEX:
            {
                uint32 hex = data.hex;
                uint8 r    = (uint8)((hex >> 16) & 0xFF);
                uint8 g    = (uint8)((hex >> 8) & 0xFF);
                uint8 b    = (uint8)(hex & 0xFF);
                Color rgb;
                rgb.data.RGB.red   = r;
                rgb.data.RGB.green = g;
                rgb.data.RGB.blue  = b;
                hsv                = rgb.toHSL();
            }
                break;
        }
        return hsv;
    }

    Color Color::toCMYK()
    {
        Color cmyk;
        cmyk.colorspace = Colorspace::CMYK;
        switch (colorspace)
        {
            case Colorspace::GRAYSCALE:
            {
                cmyk.data.CMYK.cyan    = 0;
                cmyk.data.CMYK.magenta = 0;
                cmyk.data.CMYK.yellow  = 0;
                cmyk.data.CMYK.key     = 255 - data.Grayscale.value;
            }
                break;
            case Colorspace::RGB:
            {
                float r                = data.RGB.red / 255.0f;
                float g                = data.RGB.green / 255.0f;
                float b                = data.RGB.blue / 255.0f;
                float k                = 1.0f - std::max(std::max(r, g), b);
                float c                = (1.0f - r - k) / (1.0f - k);
                float m                = (1.0f - g - k) / (1.0f - k);
                float y                = (1.0f - b - k) / (1.0f - k);
                cmyk.data.CMYK.cyan    = (uint8)(c * 255.0f);
                cmyk.data.CMYK.magenta = (uint8)(m * 255.0f);
                cmyk.data.CMYK.yellow  = (uint8)(y * 255.0f);
                cmyk.data.CMYK.key     = (uint8)(k * 255.0f);
            }
                break;
            case Colorspace::HSL:
            {
                float h = data.HSL.hue / 360.0f;
                float s = data.HSL.saturation;
                float l = data.HSL.lightness;
                float c, m, y, k;
                if (s == 0.0f)
                {
                    c = 0.0f;
                    m = 0.0f;
                    y = 0.0f;
                    k = 1.0f - l;
                }
                else
                {
                    float q = l < 0.5f ? l * (1.0f + s) : l + s - l * s;
                    float p = 2.0f * l - q;
                    c       = 0.0f;
                    m       = 0.0f;
                    y       = 0.0f;
                    k       = 0.0f;
                    if (h < 1.0f / 6.0f)
                    {
                        c = (q - p) / (q - p);
                        m = 0.0f;
                        y = 0.0f;
                        k = 1.0f - q;
                    }
                    else if (h < 2.0f / 6.0f)
                    {
                        c = 0.0f;
                        m = (q - p) / (q - p);
                        y = 0.0f;
                        k = 1.0f - q;
                    }
                    else if (h < 3.0f / 6.0f)
                    {
                        c = 0.0f;
                        m = 0.0f;
                        y = (q - p) / (q - p);
                        k = 1.0f - q;
                    }
                    else if (h < 4.0f / 6.0f)
                    {
                        c = (p - q) / (q - p);
                        m = 0.0f;
                        y = 0.0f;
                        k = 1.0f - q;
                    }
                    else if (h < 5.0f / 6.0f)
                    {
                        c = 0.0f;
                        m = (p - q) / (q - p);
                        y = 0.0f;
                        k = 1.0f - q;
                    }
                    else
                    {
                        c = 0.0f;
                        m = 0.0f;
                        y = (p - q) / (q - p);
                        k = 1.0f - q;
                    }
                }
                cmyk.data.CMYK.cyan    = (uint8)(c * 255.0f);
                cmyk.data.CMYK.magenta = (uint8)(m * 255.0f);
                cmyk.data.CMYK.yellow  = (uint8)(y * 255.0f);
                cmyk.data.CMYK.key     = (uint8)(k * 255.0f);
            }
                break;
            case Colorspace::HSV:
            {
                float h = data.HSV.hue / 360.0f;
                float s = data.HSV.saturation;
                float v = data.HSV.value;
                float c, m, y, k;
                if
                (s == 0.0f)
                {
                    c = 0.0f;
                    m = 0.0f;
                    y = 0.0f;
                    k = 1.0f - v;
                }
                else
                {
                    float q = v < 0.5f ? v * (1.0f + s) : v + s - v * s;
                    float p = 2.0f * v - q;
                    c       = 0.0f;
                    m       = 0.0f;
                    y       = 0.0f;
                    k       = 0.0f;
                    if (h < 1.0f / 6.0f)
                    {
                        c = (q - p) / (q - p);
                        m = 0.0f;
                        y = 0.0f;
                        k = 1.0f - q;
                    }
                    else if (h < 2.0f / 6.0f)
                    {
                        c = 0.0f;
                        m = (q - p) / (q - p);
                        y = 0.0f;
                        k = 1.0f - q;
                    }
                    else if (h < 3.0f / 6.0f)
                    {
                        c = 0.0f;
                        m = 0.0f;
                        y = (q - p) / (q - p);
                        k = 1.0f - q;
                    }
                    else if (h < 4.0f / 6.0f)
                    {
                        c = (p - q) / (q - p);
                        m = 0.0f;
                        y = 0.0f;
                        k = 1.0f - q;
                    }
                    else if (h < 5.0f / 6.0f)
                    {
                        c = 0.0f;
                        m = (p - q) / (q - p);
                        y = 0.0f;
                        k = 1.0f - q;
                    }
                    else
                    {
                        c = 0.0f;
                        m = 0.0f;
                        y = (p - q) / (q - p);
                        k = 1.0f - q;
                    }
                }
                cmyk.data.CMYK.cyan    = (uint8)(c * 255.0f);
                cmyk.data.CMYK.magenta = (uint8)(m * 255.0f);
                cmyk.data.CMYK.yellow  = (uint8)(y * 255.0f);
                cmyk.data.CMYK.key     = (uint8)(k * 255.0f);
            }
                break;
            case Colorspace::CMYK:
            {
                cmyk.data.CMYK.cyan    = data.CMYK.cyan;
                cmyk.data.CMYK.magenta = data.CMYK.magenta;
                cmyk.data.CMYK.yellow  = data.CMYK.yellow;
                cmyk.data.CMYK.key     = data.CMYK.key;
            }
                break;
            case Colorspace::HEX:
            {
                uint32 hex = data.hex;
                Color rgb;
                rgb.data.RGB.red   = (uint8)((hex >> 16) & 0xFF);
                rgb.data.RGB.green = (uint8)((hex >> 8) & 0xFF);
                rgb.data.RGB.blue  = (uint8)(hex & 0xFF);
                cmyk               = rgb.toCMYK();
            }
                break;
        }
        return cmyk;
    }

    Color Color::toHex()
    {
        Color hex;
        hex.colorspace = Colorspace::HEX;
        switch (colorspace)
        {
            case Colorspace::GRAYSCALE:
            {
                hex.data.hex = (uint32)data.Grayscale.value << 16 | (uint32)data.Grayscale.value << 8 | (uint32)data.Grayscale.value;
            }
                break;
            case Colorspace::RGB:
            {
                hex.data.hex = (uint32)data.RGB.red << 16 | (uint32)data.RGB.green << 8 | (uint32)data.RGB.blue;
            }
                break;
            case Colorspace::HSL:
            {
                Color rgb    = toRGB();
                hex.data.hex = (uint32)rgb.data.RGB.red << 16 | (uint32)rgb.data.RGB.green << 8 | (uint32)rgb.data.RGB.blue;
            }
                break;
            case Colorspace::HSV:
            {
                Color rgb    = toRGB();
                hex.data.hex = (uint32)rgb.data.RGB.red << 16 | (uint32)rgb.data.RGB.green << 8 | (uint32)rgb.data.RGB.blue;
            }
                break;
            case Colorspace::CMYK:
            {
                Color rgb    = toRGB();
                hex.data.hex = (uint32)rgb.data.RGB.red << 16 | (uint32)rgb.data.RGB.green << 8 | (uint32)rgb.data.RGB.blue;
            }
                break;
            case Colorspace::HEX:
            {
                hex.data.hex = data.hex;
            }
                break;
        }
        return hex;
    }

    Color operator+(Color lhs, Color rhs)
    {
        Color output;
        output.data.Grayscale.value = lhs.data.Grayscale.value + rhs.data.Grayscale.value;
        output.data.RGB.red         = lhs.data.RGB.red + rhs.data.RGB.red;
        output.data.RGB.green       = lhs.data.RGB.green+ rhs.data.RGB.green;
        output.data.RGB.blue        = lhs.data.RGB.blue + rhs.data.RGB.blue;
        output.data.HSL.hue         = lhs.data.HSL.hue + rhs.data.HSL.hue;
        output.data.HSL.saturation  = lhs.data.HSL.saturation + rhs.data.HSL.saturation;
        output.data.HSL.lightness   = lhs.data.HSL.lightness + rhs.data.HSL.lightness;
        output.data.HSV.hue         = lhs.data.HSV.hue + rhs.data.HSV.hue;
        output.data.HSV.saturation  = lhs.data.HSV.saturation + rhs.data.HSV.saturation;
        output.data.HSV.value       = lhs.data.HSV.value + rhs.data.HSV.value;
        output.data.CMYK.cyan       = lhs.data.CMYK.cyan + rhs.data.CMYK.cyan;
        output.data.CMYK.magenta    = lhs.data.CMYK.magenta + rhs.data.CMYK.magenta;
        output.data.CMYK.yellow     = lhs.data.CMYK.yellow + rhs.data.CMYK.yellow;
        output.data.CMYK.key        = lhs.data.CMYK.key + rhs.data.CMYK.key;
        output.data.hex             = lhs.data.hex + rhs.data.hex;
        output.data.alpha           = lhs.data.alpha + rhs.data.alpha;
        return output;
    }

    Color operator+=(Color& lhs, Color rhs)
    {
        return lhs = lhs + rhs;
    }

    bool operator==(Color lhs, Color rhs)
    {
        Color a = lhs.toRGB();
        Color b = rhs.toRGB();
        return (a.data.RGB.red == b.data.RGB.red) && 
               (a.data.RGB.green == b.data.RGB.green) && 
               (a.data.RGB.blue == b.data.RGB.blue) && 
               (a.data.alpha == b.data.alpha);
    }

    bool operator!=(Color lhs, Color rhs)
    {
        Color a = lhs.toRGB();
        Color b = rhs.toRGB();
        return (a.data.RGB.red != b.data.RGB.red) && 
               (a.data.RGB.green != b.data.RGB.green) && 
               (a.data.RGB.blue != b.data.RGB.blue) && 
               (a.data.alpha != b.data.alpha);
    }

    bool operator<(Color lhs, Color rhs)
    {
        Color a = lhs.toRGB();
        Color b = rhs.toRGB();
        return (a.data.RGB.red < b.data.RGB.red) && 
               (a.data.RGB.green < b.data.RGB.green) && 
               (a.data.RGB.blue < b.data.RGB.blue) && 
               (a.data.alpha < b.data.alpha);
    }

    bool operator>(Color lhs, Color rhs)
    {
        Color a = lhs.toRGB();
        Color b = rhs.toRGB();
        return (a.data.RGB.red > b.data.RGB.red) && 
               (a.data.RGB.green > b.data.RGB.green) && 
               (a.data.RGB.blue > b.data.RGB.blue) && 
               (a.data.alpha > b.data.alpha);
    }

    bool operator<=(Color lhs, Color rhs)
    {
        Color a = lhs.toRGB();
        Color b = rhs.toRGB();
        return (a.data.RGB.red <= b.data.RGB.red) && 
               (a.data.RGB.green <= b.data.RGB.green) && 
               (a.data.RGB.blue <= b.data.RGB.blue) && 
               (a.data.alpha <= b.data.alpha);
    }

    bool operator>=(Color lhs, Color rhs)
    {
        Color a = lhs.toRGB();
        Color b = rhs.toRGB();
        return (a.data.RGB.red >= b.data.RGB.red) && 
               (a.data.RGB.green >= b.data.RGB.green) && 
               (a.data.RGB.blue >= b.data.RGB.blue) && 
               (a.data.alpha >= b.data.alpha);
    }
} // namespace nt

#endif // _NT_MATH_COLOR_cpp_