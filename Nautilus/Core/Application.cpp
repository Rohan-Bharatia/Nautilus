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

#ifndef _CORE_APPLICATION_CPP_
    #define _CORE_APPLICATION_CPP_

#include "Application.h"

#include "Logger.h"

namespace Nt
{
    Application::Application(int32 argc, char** argv) :
        m_running(true)
    {
        Logger::Debug(R"(
                   GNU GENERAL PUBLIC LICENSE
                      Version 3, 29 June 2007

Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
Everyone is permitted to copy and distribute verbatim copies
of this license document, but changing it is not allowed.
                                ...

                 Copyright (c) Rohan Bharatia 2025)");
    }

    void Application::PushLayer(Layer* layer)
    {
        m_layerStack.PushLayer(layer);
    }

    void Application::PushOverlay(Layer* layer)
    {
        m_layerStack.PushOverlay(layer);
    }

    void Application::Run(void)
    {
        while (m_running)
        {
            for (Layer* layer : m_layerStack)
            {
                layer->OnUpdate();
                layer->OnRender();
            }
        }
    }

    void Application::OnEvent(Event& event)
    {
        EventDispatcher dispatcher(event);

        if (m_layerStack.Size() == 0)
            Logger::Warn("Layer stack is empty!");

        for (auto it = m_layerStack.rbegin(); it != m_layerStack.rend(); ++it)
        {
            if (event.IsHandled())
                break;
            (*it)->OnEvent(event);
        }
    }
} // namespace Nt


#endif // _CORE_APPLICATION_CPP_
