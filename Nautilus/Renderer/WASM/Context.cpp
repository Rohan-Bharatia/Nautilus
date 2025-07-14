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

#ifndef _NT_RENDERER_WASM_CONTEXT_CPP_
    #define _NT_RENDERER_WASM_CONTEXT_CPP_

#include "../Context.h"

#include "../../Core/Logger.h"

namespace Nt
{
    bool GraphicsContext::Initialize(void)
    {
        m_handle.device = emscripten::val::global("navigator")["gpu"].call<emscripten::val>("requestAdapter").call<emscripten::val>("then", emscripten::val::module_property("requestDevice"));

        if (!m_handle.device.as<bool>())
        {
            Logger::Error("Failed to create device!");
            return false;
        }

        m_handle.context = m_window.GetHandle().canvas.call<emscripten::val>("getContext", std::string("webgpu"));

        if (!m_handle.context.as<bool>())
        {
            Logger::Error("Failed to create context!");
            return false;
        }

        emscripten::val swapChainDesc = emscripten::val::object();
        swapChainDesc.set("device", m_handle.device);
        swapchainDesc.set("format", std::string("bgra8unorm"));

        m_handle.context.call<void>("configure", swapChainDesc);

        return true;
    }

    void GraphicsContext::OnUpdate(void)
    {
        m_handle.commandEncoder          = m_handle.device.call<emscripten::val>("createCommandEncoder");
        emscripten::val textureView      = m_handle.context.call<emscripten::val>("getCurrentTexture").call<emscripten::val>("createView");
        emscripten::val renderPassDesc   = emscripten::val::object();
        emscripten::val colorAttachments = emscripten::val::array();

        emscripten::val clearValue = emscripten::val::object();
        clearValue.set("r", m_clearColor.r / 255.0f);
        clearValue.set("g", m_clearColor.g / 255.0f);
        clearValue.set("b", m_clearColor.b / 255.0f);
        clearValue.set("a", m_clearColor.a);

        emscripten::val colorAttachment = emscripten::val::object();
        colorAttachment.set("view", textureView);
        colorAttachment.set("loadOp", std::string("clear"));
        colorAttachment.set("storeOp", std::string("store"));
        colorAttachment.set("clearValue", clearValue);

        colorAttachments.call<void>("push", colorAttachment);
        renderPassDesc.set("colorAttachments", colorAttachments);

        m_handle.renderPassEncoder = m_handle.commandEncoder.call<emscripten::val>("beginRenderPass", renderPassDesc);
        m_handle.renderPassEncoder.call<void>("end");

        emscripten::val commandBuffer = m_handle.commandEncoder.call<emscripten::val>("finish");

        emscripten::val queue = m_handle.device["queue"];
        queue.call<void>("submit", emscripten::val::array(std::vector<emscripten::val>{ commandBuffer }));
    }

    void GraphicsContext::Shutdown(void)
    {
        // The browser automatically cleans up resources
    }
} // namespace Nt

#endif // _NT_RENDERER_WASM_CONTEXT_CPP_
