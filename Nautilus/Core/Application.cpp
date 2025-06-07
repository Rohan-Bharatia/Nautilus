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
#include "Assertion.h"
#include "DeviceInfo.h"
#include "Timer.h"

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

        NT_ASSERT(DeviceInfo::GetBatteryLevel() > 20.0f, "Battery level too low! Please charge your device.");
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
        Timer timer;
        float32 prev = 0.0f;
        while (m_running)
        {
            float32 current   = timer.GetElapsedTime();
            float32 deltaTime = current - prev;
            prev              = current;

            for (Layer* layer : m_layerStack)
            {
                layer->OnUpdate(deltaTime);
                layer->OnRender();
            }
        }
    }

    void Application::OnEvent(Event& event)
    {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<WindowCloseEvent>(NT_BIND_EVENT_FN(Application::OnWindowClose));

        if (m_layerStack.Size() == 0)
            Logger::Warn("Layer stack is empty!");

        for (auto it = m_layerStack.rbegin(); it != m_layerStack.rend(); ++it)
        {
            if (event.IsHandled())
                break;
            (*it)->OnEvent(event);
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& event)
    {
        m_running = false;
        return true;
    }
} // namespace Nt

#endif // _CORE_APPLICATION_CPP_
