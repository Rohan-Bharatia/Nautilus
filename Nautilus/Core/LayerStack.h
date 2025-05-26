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

#ifndef _NT_CORE_LAYER_LAYER_STACK_H_
    #define _NT_CORE_LAYER_LAYER_STACK_H_

#include "Layer.h"

namespace Nt
{
    class NT_API LayerStack
    {
    public:
        // NT_CLASS_DEFAULTS(LayerStack)
        ~LayerStack(void);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);
        void PopLayer(Layer* layer);
        void PopOverlay(Layer* layer);

        std::vector<Layer*>::iterator begin(void);
        std::vector<Layer*>::iterator end(void);
        std::vector<Layer*>::reverse_iterator rbegin(void);
        std::vector<Layer*>::reverse_iterator rend(void);
        std::vector<Layer*>::const_iterator begin(void) const;
        std::vector<Layer*>::const_iterator end(void) const;
        std::vector<Layer*>::const_reverse_iterator rbegin(void) const;
        std::vector<Layer*>::const_reverse_iterator rend(void) const;
        opsize Size(void) const;

    private:
        std::vector<Layer*> m_layers;
        uint32 m_layerInsertIndex = 0;
    };
} // namespace Nt

#endif // _NT_CORE_LAYER_LAYER_STACK_H_
