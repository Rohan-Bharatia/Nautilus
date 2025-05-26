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

#ifndef _NT_CORE_LAYER_LAYER_H_
    #define _NT_CORE_LAYER_LAYER_H_

#include "Event.h"

namespace Nt
{
    class NT_API Layer
    {
    public:
        NT_CLASS_DEFAULTS(Layer)
        Layer(const std::string& name="Layer");

        virtual void OnAttach(void)        = 0;
        virtual void OnDetach(void)        = 0;
        virtual void OnUpdate(void)        = 0;
        virtual void OnEvent(Event& event) = 0;
        virtual void OnRender(void)        = 0;

        const std::string& GetName(void) const;

    private:
        std::string m_name;
    };
} // namespace Nt

#endif // _NT_CORE_LAYER_LAYER_H_
