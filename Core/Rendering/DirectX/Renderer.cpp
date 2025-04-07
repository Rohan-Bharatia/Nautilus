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

#ifndef _NT_CORE_RENDERING_DIRECTX_RENDERER_CPP_
    #define _NT_CORE_RENDERING_DIRECTX_RENDERER_CPP_

#include "../Renderer.h"
#include "../../Logger.h"

namespace nt
{
    bool Renderer::initialize(HWND hwnd, Rect size)
    {
        HRESULT hr = S_OK;

        // Create the DirectX12 device
        hr = D3D12CreateDevice(nullptr, D3D_FEATURE_LEVEL_12_0, IID_PPV_ARGS(&m_device));
        if (FAILED(hr))
        {
            Logger::error("Failed to create the DirectX 12 device!");
            return false;
        }

        // Create the command queue
        D3D12_COMMAND_QUEUE_DESC queueDesc{};
        queueDesc.Type                     = D3D12_COMMAND_LIST_TYPE_DIRECT;
        queueDesc.Priority                 = D3D12_COMMAND_QUEUE_PRIORITY_NORMAL;
        queueDesc.Flags                    = D3D12_COMMAND_QUEUE_FLAG_NONE;
        queueDesc.NodeMask                 = 0;

        hr = m_device->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&m_commandQueue));
        if (FAILED(hr))
        {
            Logger::error("Failed to create the command queue!");
            return false;
        }

        // Create the swapchain
        DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};
        swapChainDesc.BufferCount           = 2;
        swapChainDesc.Width                 = size.width;
        swapChainDesc.Height                = size.height;
        swapChainDesc.Format                = DXGI_FORMAT_R8G8B8A8_UNORM;
        swapChainDesc.BufferUsage           = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        swapChainDesc.SwapEffect            = DXGI_SWAP_EFFECT_FLIP_DISCARD;
        swapChainDesc.SampleDesc.Count      = 1;

        ComPtr<IDXGIFactory7> dxgiFactory;
        hr = CreateDXGIFactory1(IID_PPV_ARGS(&dxgiFactory));
        if (FAILED(hr))
        {
            Logger::error("Failed to create the DXGI factory!");
            return false;
        }

        hr = dxgiFactory->CreateSwapChainForHwnd(m_commandQueue.Get(), hwnd, &swapChainDesc, nullptr, nullptr, &m_swapChain);
        if (FAILED(hr))
        {
            Logger::error("Failed to create the swapchain!");
            return false;
        }

        for (UINT i = 0; i < 2; ++i)
        {
            hr = m_swapChain->GetBuffer(i, IID_PPV_ARGS(&m_renderTargets[i]));
            if (FAILED(hr))
            {
                Logger::error("Failed to create the render target!");
                return false;
            }

            // Create the render target view
            m_device->CreateRenderTargetView(m_renderTargets[i].Get(), nullptr, m_renderTargetViews[i]->GetCPUDescriptorHandleForHeapStart());
        }


        // Create the command allocator
        hr = m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_commandAllocator));
        if (FAILED(hr))
        {
            Logger::error("Failed to create the command allocator!");
            return false;
        }

        hr = m_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, m_commandAllocator.Get(), nullptr, IID_PPV_ARGS(&m_commandList));
        if (FAILED(hr))
        {
            Logger::error("Failed to create the command list!");
            return false;
        }

        return true;
    }

    void Renderer::clear(Color col)
    {
        float clearColor[4] = { col.r / 255.0f, col.g / 255.0f, col.b / 255.0f, col.a };

        m_commandList->ClearRenderTargetView(m_renderTargetViews[0]->GetCPUDescriptorHandleForHeapStart(), clearColor, 0, nullptr);
        m_commandList->ClearDepthStencilView(m_renderTargetViews[0]->GetCPUDescriptorHandleForHeapStart(), D3D12_CLEAR_FLAG_DEPTH, 1.0f, 0, 0, nullptr);
    }

    void Renderer::beginFrame()
    {
        HRESULT hr = m_commandAllocator->Reset();
        if (FAILED(hr))
        {
            Logger::error("Failed to reset command allocator!");
            return;
        }

        hr = m_commandList->Reset(m_commandAllocator.Get(), nullptr);
        if (FAILED(hr))
        {
            Logger::error("Failed to reset command list!");
            return;
        }
    }

    void Renderer::drawTriangle(Vertex a, Vertex b, Vertex c)
    {
        // Draw a triangle (xyz, uv, rgba)
    }

    void Renderer::endFrame()
    {
        HRESULT hr = m_commandList->Close();
        if (FAILED(hr))
        {
            Logger::error("Failed to close command list!");
            return;
        }

        ID3D12CommandList* commandLists[] = { m_commandList.Get() };
        m_commandQueue->ExecuteCommandLists(1, commandLists);

        hr = m_swapChain->Present(1, 0);
        if (FAILED(hr))
        {
            Logger::error("Failed to present the swap chain!");
        }
    }

    void Renderer::shutdown()
    {
        if (m_device)
            m_device->Release();
        if (m_commandQueue)
            m_commandQueue->Release();
        if (m_swapChain)
            m_swapChain->Release();
        if (m_commandAllocator)
            m_commandAllocator->Release();
        if (m_commandList)
            m_commandList->Release();

        for (UINT i = 0; i < 2; ++i)
        {
            if (m_renderTargets[i])
                m_renderTargets[i]->Release();
            if (m_renderTargetViews[i])
                m_renderTargetViews[i]->Release();
        }
    }
}

#endif // _NT_CORE_RENDERING_DIRECTX_RENDERER_CPP_
