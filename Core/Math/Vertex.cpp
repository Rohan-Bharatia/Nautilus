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

#ifndef _NT_CORE_MATH_VERTEX_CPP_
    #define _NT_CORE_MATH_VERTEX_CPP_

#include "Vertex.h"

#include <cassert>

namespace nt
{
    Vertex::Vertex(Vec3f pos, Vec2f uv, Color col) :
        pos(pos), uv(uv), col(col)
    {}

    Vertex operator+(Vertex lhs)
    {
        return Vertex(+lhs.pos, +lhs.uv, lhs.col);
    }

    Vertex operator-(Vertex lhs)
    {
        return Vertex(-lhs.pos, -lhs.uv, lhs.col);
    }

    Vertex operator+(Vertex lhs, Vertex rhs)
    {
        return Vertex(lhs.pos + rhs.pos, lhs.uv + rhs.uv, lhs.col + rhs.col);
    }

    Vertex operator-(Vertex lhs, Vertex rhs)
    {
        return Vertex(lhs.pos - rhs.pos, lhs.uv - rhs.uv, lhs.col - rhs.col);
    }

    Vertex operator*(Vertex lhs, Vertex rhs)
    {
        return Vertex(lhs.pos * rhs.pos, lhs.uv * rhs.uv, lhs.col * rhs.col);
    }

    Vertex operator/(Vertex lhs, Vertex rhs)
    {
        assert(rhs.pos.x != 0 && rhs.pos.y != 0 && rhs.pos.z != 0 && rhs.uv.x != 0 && rhs.uv.y != 0 && rhs.col.r != 0 && rhs.col.g != 0 && rhs.col.b != 0 && rhs.col.a != 0);
        return Vertex(lhs.pos / rhs.pos, lhs.uv / rhs.uv, lhs.col / rhs.col);
    }

    Vertex operator%(Vertex lhs, Vertex rhs)
    {
        assert(rhs.pos.x != 0 && rhs.pos.y != 0 && rhs.pos.z != 0 && rhs.uv.x != 0 && rhs.uv.y != 0 && rhs.col.r != 0 && rhs.col.g != 0 && rhs.col.b != 0 && rhs.col.a != 0);
        return Vertex(lhs.pos % rhs.pos, lhs.uv % rhs.uv, lhs.col % rhs.col);
    }

    Vertex operator++(Vertex& lhs)
    {
        ++lhs.pos;
        ++lhs.uv;
        ++lhs.col;
        return lhs;
    }

    Vertex operator--(Vertex& lhs)
    {
        --lhs.pos;
        --lhs.uv;
        --lhs.col;
        return lhs;
    }

    Vertex operator++(Vertex& lhs, int)
    {
        Vertex temp = lhs;
        ++lhs.pos;
        ++lhs.uv;
        ++lhs.col;
        return temp;
    }

    Vertex operator--(Vertex& lhs, int)
    {
        Vertex temp = lhs;
        ++lhs.pos;
        ++lhs.uv;
        ++lhs.col;
        return temp;
    }

    Vertex& operator+=(Vertex& lhs, Vertex rhs)
    {
        return lhs = lhs + rhs;
    }

    Vertex& operator-=(Vertex& lhs, Vertex rhs)
    {
        return lhs = lhs - rhs;
    }

    Vertex& operator*=(Vertex& lhs, Vertex rhs)
    {
        return lhs = lhs * rhs;
    }

    Vertex& operator/=(Vertex& lhs, Vertex rhs)
    {
        assert(rhs.pos.x != 0 && rhs.pos.y != 0 && rhs.pos.z != 0 && rhs.uv.x != 0 && rhs.uv.y != 0 && rhs.col.r != 0 && rhs.col.g != 0 && rhs.col.b != 0 && rhs.col.a != 0);
        return lhs = lhs / rhs;
    }

    Vertex& operator%=(Vertex& lhs, Vertex rhs)
    {
        assert(rhs.pos.x != 0 && rhs.pos.y != 0 && rhs.pos.z != 0 && rhs.uv.x != 0 && rhs.uv.y != 0 && rhs.col.r != 0 && rhs.col.g != 0 && rhs.col.b != 0 && rhs.col.a != 0);
        return lhs = lhs % rhs;
    }

    bool operator==(Vertex lhs, Vertex rhs)
    {
        return lhs.pos == rhs.pos && lhs.uv == rhs.uv && lhs.col == rhs.col;
    }

    bool operator!=(Vertex lhs, Vertex rhs)
    {
        return !(lhs == rhs);
    }

    bool operator<(Vertex lhs, Vertex rhs)
    {
        return lhs.pos < rhs.pos && lhs.uv < rhs.uv && lhs.col < rhs.col;
    }

    bool operator>(Vertex lhs, Vertex rhs)
    {
        return lhs.pos > rhs.pos && lhs.uv > rhs.uv && lhs.col > rhs.col;
    }

    bool operator<=(Vertex lhs, Vertex rhs)
    {
        return !(lhs > rhs);
    }

    bool operator>=(Vertex lhs, Vertex rhs)
    {
        return !(lhs < rhs);
    }
} // namespace nt

#endif // _NT_CORE_MATH_VERTEX_CPP_
