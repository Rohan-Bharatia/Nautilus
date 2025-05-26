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

#ifndef _NT_CORE_LAYER_LAYER_STACK_CPP_
    #define _NT_CORE_LAYER_LAYER_STACK_CPP_

#include "LayerStack.h"

namespace Nt
{
    LayerStack::~LayerStack(void)
    {
        for (Layer* layer : m_layers)
        {
            layer->OnDetach();
            delete layer;
        }
    }

    void LayerStack::PushLayer(Layer* layer)
    {
        m_layers.emplace(m_layers.begin() + m_layerInsertIndex++, layer);
    }

    void LayerStack::PushOverlay(Layer* layer)
    {
        m_layers.emplace_back(layer);
    }

    void LayerStack::PopLayer(Layer* layer)
    {
        std::vector<Layer*>::iterator it = std::find(m_layers.begin(), m_layers.end(), layer);
        if (it != m_layers.end())
        {
            layer->OnDetach();
            m_layers.erase(it);
            --m_layerInsertIndex;
        }
    }

    void LayerStack::PopOverlay(Layer* layer)
    {
        std::vector<Layer*>::iterator it = std::find(m_layers.begin(), m_layers.end(), layer);
        if (it != m_layers.end())
        {
            layer->OnDetach();
            m_layers.erase(it);
        }
    }

    std::vector<Layer*>::iterator LayerStack::begin(void)
    {
        return m_layers.begin();
    }

    std::vector<Layer*>::iterator LayerStack::end(void)
    {
        return m_layers.end();
    }

    std::vector<Layer*>::reverse_iterator LayerStack::rbegin(void)
    {
        return m_layers.rbegin();
    }

    std::vector<Layer*>::reverse_iterator LayerStack::rend(void)
    {
        return m_layers.rend();
    }

    std::vector<Layer*>::const_iterator LayerStack::begin(void) const
    {
        return m_layers.begin();
    }

    std::vector<Layer*>::const_iterator LayerStack::end(void) const
    {
        return m_layers.end();
    }

    std::vector<Layer*>::const_reverse_iterator LayerStack::rbegin(void) const
    {
        return m_layers.rbegin();
    }

    std::vector<Layer*>::const_reverse_iterator LayerStack::rend(void) const
    {
        return m_layers.rend();
    }

    opsize LayerStack::Size(void) const
    {
        return m_layers.size();
    }
} // namespace Nt

#endif // _NT_CORE_LAYER_LAYER_STACK_CPP_