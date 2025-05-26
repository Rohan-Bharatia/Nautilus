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

#ifndef _CORE_APPLICATION_H_
    #define _CORE_APPLICATION_H_

#include "PCH.h"
#include "LayerStack.h"

namespace Nt
{
    class NT_API Application
    {
    public:
        NT_CLASS_DEFAULTS(Application)
        Application(int32 argc, char** argv);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        void Run(void);

        void OnEvent(Event& event);

    private:
        LayerStack m_layerStack;
        bool m_running;
    };
} // namespace Nt

#endif // _CORE_APPLICATION_H_
