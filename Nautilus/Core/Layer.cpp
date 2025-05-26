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

#ifndef _NT_CORE_LAYER_LAYER_CPP_
    #define _NT_CORE_LAYER_LAYER_CPP_

#include "Layer.h"

#include "Assertion.h"

namespace Nt
{
    Layer::Layer(const std::string& name) :
        m_name(name)
    {
        NT_ASSERT(!m_name.empty(), "Layer name cannot be empty!");
    }

    const std::string& Layer::GetName(void) const
    {
        return m_name;
    }
} // namespace Nt

#endif // _NT_CORE_LAYER_LAYER_CPP_
