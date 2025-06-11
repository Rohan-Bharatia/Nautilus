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

#pragma once

#ifndef _NT_CORE_MATH_COLOR_INL_
    #define _NT_CORE_MATH_COLOR_INL_

#include "Color.h"

namespace Nt
{
    template<float32 Default=1.0f, typename... Args>
    std::tuple<float32, float32, float32, float32> assignWithDefault(Args&&... args)
    {
        NT_ASSERT(sizeof...(Args) <= 5, "Too many arguments for color components");
        
        float32 comps[4] = { 0.0f, 0.0f, 0.0f, Default };
        float32 tmp[]    = { NT_STATIC_CAST(float32, args)... };
        for (opsize i = 0; i < sizeof...(Args); ++i)
            comps[i] = tmp[i];
        return { comps[0], comps[1], comps[2], comps[3] };
    }

    template<typename... Args>
    Color::Color(ColorSpace c, Args&&... args)
    {
        NT_ASSERT(sizeof...(Args) >= 3 && sizeof...(Args) <= 5, "Any color space requires 3 or 4 real arguments and an alpha channel!");

        switch (c)
        {
            case ColorSpace::RGB:
            {
                std::tie(r, g, b, a) = assignWithDefault<1.0f>(std::forward<Args>(args)...);
                break;
            }
            case ColorSpace::HSV:
            {
                float32 h, s, v, alpha = 1.0f;
                std::tie(h, s, v, alpha) = assignWithDefault<1.0f>(std::forward<Args>(args)...);
                *this = hsv2rgb(h, s, v, alpha);
                break;
            }
            case ColorSpace::HSL:
            {
                float32 h, s, l, alpha = 1.0f;
                std::tie(h, s, l, alpha) = assignWithDefault<1.0f>(std::forward<Args>(args)...);
                *this = hsl2rgb(h, s, l, alpha);
                break;
            }
            case ColorSpace::CMYK:
            {
                float32 c, m, y, k, alpha = 1.0f;
                std::tie(c, m, y, k, alpha) = assignWithDefault<1.0f>(std::forward<Args>(args)...);
                *this = cmyk2rgb(c, m, y, k, alpha);
                break;
            }
            case ColorSpace::LCH:
            {
                float32 l, c, h, alpha = 1.0f;
                std::tie(l, c, h, alpha) = assignWithDefault<1.0f>(std::forward<Args>(args)...);
                *this = lch2rgb(l, c, h, alpha);
                break;
            }
            case ColorSpace::PQ:
            {
                float32 pqR, pqG, pqB, alpha = 1.0f;
                std::tie(pqR, pqG, pqB, alpha) = assignWithDefault<1.0f>(std::forward<Args>(args)...);
                *this = pq2rgb(pqR, pqG, pqB, alpha);
                break;
            }
            case ColorSpace::HLG:
            {
                float32 hlgR, hlgG, hlgB, alpha = 1.0f;
                std::tie(hlgR, hlgG, hlgB, alpha) = assignWithDefault<1.0f>(std::forward<Args>(args)...);
                *this = hlg2rgb(hlgR, hlgG, hlgB, alpha);
                break;
            }
            default:
            {
                r = g = b = 0.0f;
                a = 1.0f;
                break;
            }
        }
    }
} // namespace Nt

#endif // _NT_CORE_MATH_COLOR_INL_
