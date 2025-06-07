#pragma region LICENSE

//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                                 ...
//
//                  Copyright (c) Rohan Bharatia 2025

#pragma endregion LICENSE

#ifndef _NT_CORE_MATH_COLOR_CPP_
    #define _NT_CORE_MATH_COLOR_CPP_

#include "Color.h"

#include "Assertion.h"

namespace Nt
{
    Color::Color(float32 r, float32 g, float32 b, float32 a) :
        r(r), g(g), b(b), a(a)
    {}

    Color::Color(const Vec3f& other, float32 a) :
        r(other.x), g(other.y), b(other.z), a(a)
    {}

    Color::Color(const Vec4f& other) :
        r(other.x), g(other.y), b(other.z), a(other.w)
    {}

    Color Color::operator+(const Color& other) const
    {
        return Color(r + other.r, g + other.g, b + other.b, a + other.a);
    }

    Color Color::operator+(float32 other) const
    {
        return Color(r + other, g + other, b + other, a + other);
    }

    Color Color::operator-(const Color& other) const
    {
        return Color(r - other.r, g - other.g, b - other.b, a - other.a);
    }

    Color Color::operator-(float32 other) const
    {
        return Color(r - other, g - other, b - other, a - other);
    }

    Color Color::operator*(const Color& other) const
    {
        return Color(r * other.r, g * other.g, b * other.b, a * other.a);
    }

    Color Color::operator*(float32 other) const
    {
        return Color(r * other, g * other, b * other, a * other);
    }

    Color Color::operator/(const Color& other) const
    {
        NT_ASSERT(other == 0.0f, "Cannot divide by zero!");
        return Color(r / other.r, g / other.g, b / other.b, a / other.a);
    }

    Color Color::operator/(float32 other) const
    {
        NT_ASSERT(other == 0.0f, "Cannot divide by zero!");
        return Color(r / other, g / other, b / other, a / other);
    }

    Color Color::operator%(const Color& other) const
    {
        NT_ASSERT(other == 0.0f, "Cannot modulus by zero!");
        return Color(NT_MODULUS(float32, r, other.r), NT_MODULUS(float32, g, other.g), NT_MODULUS(float32, b, other.b), NT_MODULUS(float32, a, other.a));
    }

    Color Color::operator%(float32 other) const
    {
        NT_ASSERT(other == 0.0f, "Cannot modulus by zero!");
        return Color(NT_MODULUS(float32, r, other), NT_MODULUS(float32, g, other), NT_MODULUS(float32, b, other), NT_MODULUS(float32, a, other));
    }

    Color Color::operator++(void)
    {
        ++r;
        ++g;
        ++b;
        ++a;
        return *this;
    }

    Color Color::operator++(int)
    {
        Color temp = *this;
        ++*this;
        return temp;
    }

    Color Color::operator--(void)
    {
        --r;
        --g;
        --b;
        --a;
        return *this;
    }

    Color Color::operator--(int)
    {
        Color temp = *this;
        --*this;
        return temp;
    }

    Color& Color::operator+=(const Color& other)
    {
        return *this = *this + other;
    }

    Color& Color::operator+=(float32 other)
    {
        return *this = *this + other;
    }

    Color& Color::operator-=(const Color& other)
    {
        return *this = *this - other;
    }

    Color& Color::operator-=(float32 other)
    {
        return *this = *this - other;
    }

    Color& Color::operator*=(const Color& other)
    {
        return *this = *this * other;
    }

    Color& Color::operator*=(float32 other)
    {
        return *this = *this * other;
    }

    Color& Color::operator/=(const Color& other)
    {
        NT_ASSERT(other == 0.0f, "Cannot divide by zero!");
        return *this = *this / other;
    }

    Color& Color::operator/=(float32 other)
    {
        NT_ASSERT(other == 0.0f, "Cannot divide by zero!");
        return *this = *this / other;
    }

    Color& Color::operator%=(const Color& other)
    {
        NT_ASSERT(other == 0.0f, "Cannot modulus by zero!");
        return *this = *this % other;
    }

    Color& Color::operator%=(float32 other)
    {
        NT_ASSERT(other == 0.0f, "Cannot modulus by zero!");
        return *this = *this % other;
    }

    bool Color::operator>(const Color& other) const
    {
        return (r > other.r && g > other.g && b > other.b && a > other.a);
    }

    bool Color::operator>(float32 other) const
    {
        return (r > other && g > other && b > other && a > other);
    }

    bool Color::operator>=(const Color& other) const
    {
        return (r >= other.r && g >= other.g && b >= other.b && a >= other.a);
    }

    bool Color::operator>=(float32 other) const
    {
        return (r >= other && g >= other && b >= other && a >= other);
    }

    bool Color::operator<(const Color& other) const
    {
        return (r < other.r && g < other.g && b < other.b && a < other.a);
    }

    bool Color::operator<(float32 other) const
    {
        return (r < other && g < other && b < other && a < other);
    }

    bool Color::operator<=(const Color& other) const
    {
        return (r <= other.r && g <= other.g && b <= other.b && a <= other.a);
    }

    bool Color::operator<=(float32 other) const
    {
        return (r <= other && g <= other && b <= other && a <= other);
    }

    bool Color::operator==(const Color& other) const
    {
        return (r == other.r && g == other.g && b == other.b && a == other.a);
    }

    bool Color::operator==(float32 other) const
    {
        return (r == other && g == other && b == other && a == other);
    }

    bool Color::operator!=(const Color& other) const
    {
        return (r != other.r || g != other.g || b != other.b || a != other.a);
    }

    bool Color::operator!=(float32 other) const
    {
        return (r != other || g != other || b != other || a != other);
    }

    Color::operator float32*(void) const
    {
        return new float[4]{ r, g, b, a };
    }

    Color Color::hsv2rgb(float32 h, float32 s, float32 v, float32 a)
    {
        float32 c = v * s;
        float32 x = c * (1 - fabs(fmod(h / 60.0f, 2) - 1));
        float32 m = v - c;

        float32 r1, g1, b1;

        if (h < 60)
        {
            r1 = c;
            g1 = x;
            b1 = 0;
        }
        else if (h < 120)
        {
            r1 = x;
            g1 = c;
            b1 = 0;
        }
        else if (h < 180)
        {
            r1 = 0;
            g1 = c;
            b1 = x;
        }
        else if (h < 240)
        {
            r1 = 0;
            g1 = x;
            b1 = c;
        }
        else if (h < 300)
        {
            r1 = x;
            g1 = 0;
            b1 = c;
        }
        else
        {
            r1 = c;
            g1 = 0;
            b1 = x;
        }

        return Color(r1 + m, g1 + m, b1 + m, a);
    }

    Color Color::hslrgb(float32 h, float32 s, float32 l, float32 a)
    {
        float32 c = (1 - fabs(2 * l - 1)) * s;
        float32 x = c * (1 - fabs(fmod(h / 60.0f, 2) - 1));
        float32 m = l - c / 2;

        float32 r1, g1, b1;

        if (h < 60)
        {
            r1 = c;
            g1 = x;
            b1 = 0;
        }
        else if (h < 120)
        {
            r1 = x;
            g1 = c;
            b1 = 0;
        }
        else if (h < 180)
        {
            r1 = 0;
            g1 = c;
            b1 = x;
        }
        else if (h < 240)
        {
            r1 = 0;
            g1 = x;
            b1 = c;
        }
        else if (h < 300)
        {
            r1 = x;
            g1 = 0;
            b1 = c;
        }
        else
        {
            r1 = c;
            g1 = 0;
            b1 = x;
        }

        return Color(r1 + m, g1 + m, b1 + m, a);
    }

    // CMYK to RGB
    Color Color::cmyk2rgb(float32 c, float32 m, float32 y, float32 k, float32 a)
    {
        return Color((1 - c) * (1 - k), (1 - m) * (1 - k), (1 - y) * (1 - k), a);
    }

    Color Color::lch2rgb(float32 l, float32 c, float32 h, float32 a)
    {
        float32 hr = h * NT_PI / 180.0f;
        float32 a  = cos(hr) * c;
        float32 b  = sin(hr) * c;

        // Convert Lab to XYZ
        float32 Y = (l + 16.0f) / 116.0f;
        float32 X = a / 500.0f + Y;
        float32 Z = Y - b / 200.0f;

        X = 0.95047f * powf(X, 3);
        Y = 1.00000f * powf(Y, 3);
        Z = 1.08883f * powf(Z, 3);

        // Convert XYZ to linear RGB
        float32 r =  3.2406f * X - 1.5372f * Y - 0.4986f * Z;
        float32 g = -0.9689f * X + 1.8758f * Y + 0.0415f * Z;
        float32 b =  0.0557f * X - 0.2040f * Y + 1.0570f * Z;

        // Apply gamma correction
        r = r <= 0.0031308f ? 12.92f * r : 1.055f * powf(r, 1/2.4f) - 0.055f;
        g = g <= 0.0031308f ? 12.92f * g : 1.055f * powf(g, 1/2.4f) - 0.055f;
        b = b <= 0.0031308f ? 12.92f * b : 1.055f * powf(b, 1/2.4f) - 0.055f;

        return Color(r, g, b, a);
    }

    Color Color::pq2rgb(float32 r, float32 g, float32 b, float32 n, float32 a)
    {
        auto invPQ = [](float32 v) -> float32
        {
            const float32 m1 = 2610.0f / 16384.0f;
            const float32 m2 = 2523.0f / 32.0f;
            const float32 c1 = 3424.0f / 4096.0f;
            const float32 c2 = 2413.0f / 128.0f;
            const float32 c3 = 2392.0f / 128.0f;

            float32 vp = powf(std::max(v, 0.0f), 1.0f / m2);
            return powf(std::max((vp - c1) / (c2 - c3 * vp), 0.0f), 1.0f / m1);
        };

        return Color(invPQ(r) * n, invPQ(g) * n, invPQ(b) * n, a);
    }

    Color Color::hlg2rgb(float32 r, float32 g, float32 b, float32 n, float32 a)
    {
        auto invHLG = [](float32 v) -> float32
        {
            const float32 x = 0.17883277f;
            const float32 y = 1.0f - 4.0f * x;
            const float32 z = 0.5f - x * logf(4.0f * x);

            if (v <= 0.5f)
                return v * v / 3.0f;
            else
                return expf((v - z) / x) + y;
        };

        return Color(invHLG(r) * n, invHLG(g) * n, invHLG(b) * n, a);
    }
} // namespace Nt

#endif // _NT_CORE_MATH_COLOR_CPP_
