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

#ifndef _NT_RENDERER_WINDOWS_CONTEXT_CPP_
    #define _NT_RENDERER_WINDOWS_CONTEXT_CPP_

#include "../Context.h"

#include "../../Core/Logger.h"

namespace Nt
{
    bool GraphicsContext::Initialize(void)
    {
        uint24 dxgiFactoryFlags = 0;

        ComPtr<IDXGIFactory4> factory;

        if (FAILED(CreateDXGIFactory2(dxgiFactoryFlags, IID_PPV_ARGS(&factory))))
        {
            Logger::Error("Failed to create factory!");
            return false;
        }

        if (FAILED(D3D12CreateDevice(nullptr, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&m_handle.device))))
        {
            Logger::Error("Failed to create device!");
            return false;
        }

        D3D12_COMMAND_QUEUE_DESC queueDesc{};
        queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
        queueDesc.Type  = D3D12_COMMAND_LIST_TYPE_DIRECT;

        if (FAILED(m_handle.device->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&m_handle.commandQueue))))
        {
            Logger::Error("Failed to create command queue");
            return false;
        }

        Rect bounds = m_window->GetSize();

        DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};
        swapChainDesc.BufferCount      = 2;
        swapChainDesc.Width            = bounds.size.x;
        swapChainDesc.Height           = bounds.size.y;
        swapChainDesc.Format           = DXGI_FORMAT_R8G8B8A8_UNORM;
        swapchainDesc.BufferUsage      = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        swapChainDesc.SampleDesc.Count = 1;

        ComPtr<IDXGISwapChain1> swapChain;

        if (FAILED(factory->CreateSwapChainForHwnd(m_handle.commandQueue, m_window->GetHandle().hwnd, &swapChainDesc,
                                                   nullptr, nullptr, &swapChain)))
        {
            Logger::Error("Failed to create swap chain!");
            return false;
        }

        if (FAILED(swapChain.As(&m_handle.swapChain)))
        {
            Logger::Error("Failed to cast swap chain!");
            return false;
        }

        m_handle.frameIndex = m_handle.swapChain->GetCurrentBackBufferIndex();

        D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc{};
        rtvHeapDesc.NumDescriptors = 2;
        rtvHeapDesc.Type           = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
        rtvHeapDesc.Flags          = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

        if (FAILED(m_handle.device->CreateDescriptorHeap(&rtvHeapDesc, IID_PPV_ARGS(&m_handle.rtvHeap))))
        {
            Logger::Error("Failed to create RTV descriptor heap!");
            return false;
        }

        m_handle.rtvDescriptorSize = m_handle.device->GetDescriptorHandleIncrementSize(rtvHeapDesc.Type);

        D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_handle.rtvHeap->GetCPUDescriptorHandleForHeapStart());

        for (UINT i = 0; i < 2; ++i)
        {
            m_handle.swapChain->GetBuffer(i, IID_PPV_ARGS(&m_handle.renderTargets[i]));
            m_handle.device->CreateRenderTargetView(m_handle.renderTargets[i], nullptr, rtvHandle);

            rtvHandle.ptr += m_handle.rtvDescriptorSize;
        }

        if (FAILED(m_handle.device->CreateCommandAllocator(queueDesc.Type, IID_PPV_ARGS(&m_handle.commandAllocator))))
        {
            Logger::Error("Failed to create command allocator!");
            return false;
        }

        if (FAILED(m_handle.device->CreateCommandList(0, queueDesc.Type, m_handle.commandAllocator, nullptr,
                                                      IID_PPV_ARGS(&m_handle.commandList))))
        {
            Logger::Error("Failed to create command list!");
            return false;
        }

        m_handle.commandList->Close();

        if (FAILED(m_handle.device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m_handle.fence))))
        {
            Logger::Error("Failed to create fence!");
            return false;
        }

        m_handle.fenceValue = 1;
        m_handle.fenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);

        if (!m_handle.fenceEvent)
        {
            Logger::Error("Failed to create fence event!");
            return false;
        }

        return true;
    }

    void GraphicsContext::OnUpdate(void)
    {
        m_handle.commandAllocator->Reset();
        m_handle.commandList->Reset(m_handle.commandAllocator, nullptr);

        D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_handle.rtvHeap->GetCPUDescriptorHandleForHeapStart());
        rtvHandle.ptr += m_handle.frameIndex * m_handle.rtvDescriptorSize;

        D3D12_RESOURCE_BARRIER barrier{};
        barrier.Type                   = D3D12_RESOURCE_BARRIER_TYPE_TRANSISION;
        barrier.Flags                  = D3D12_RESOURCE_BARRIER_FLAG_NONE;
        barrier.Transision.pResource   = m_handle.renderTargets[m_handle.frameIndex];
        barrier.Transision.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
        barrier.Transision.StateAfter  = D3D12_RESOURCE_STATE_RENDER_TARGET;
        barrier.Transision.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;

        m_handle.commandList->ResourceBarrier(1, &barrier);
        m_handle.commandList->OMSetRenderTargets(1, &rtvHandle, FALSE, nullptr);

        const float32 clearColor[4] =
        {
            m_clearColor.r / 255.0f,
            m_clearColor.g / 255.0f,
            m_clearColor.b / 255.0f,
            m_clearColor.a,
        };

        m_handle.commandList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);

        barrier.Transision.StageBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
        barrier.Transision.StageAfter  = D3D12_RESOURCE_STATE_PRESENT;

        m_handle.commandList->ResourceBarrier(1, &barrier);
        m_handle.commandList->Close();

        ID3D12CommandList* commandLists[] = { m_handle.commandList };
        m_handle.commandQueue->ExecuteCommandLists(_countof(commandLists), commandLists);

        m_handle.swapChain->Present(1, 0);

        const UINT64 fence = m_handle.fenceValue;
        m_handle.commandQueue->Signal(m_handle.fence, fence);
        ++m_handle.fenceValue;

        if (m_handle.fence->GetCompletedValue() < fence)
        {
            m_handle.fence->SetEventOnCompletion(fence, m_handle.fenceEvent);
            WaitForSingleObject(m_handle.fenceEvent, INFINITE);
        }

        m_handle.frameIndex = m_handle.swapChain->GetCurrentBackBufferIndex();
    }

    void GraphicsContext::Shutdown(void)
    {
        const UINT64 fence = m_handle.fenceValue;
        m_handle.commandQueue->Signal(m_handle.fence, fence);
        ++m_handle.fenceValue;

        if (m_handle.fence->GetCompletedValue() < fence)
        {
            m_handle.fence->SetEventOnCompletion(fence, m_handle.fenceEvent);
            WaitForSingleObject(m_handle.fenceEvent, INFINITE);
        }

        m_handle.frameIndex = m_handle.swapChain->GetCurrentBackBufferIndex();

        CloseHandle(m_handle.fenceEvent);
        m_handle.fence->Release();
        m_handle.commandList->Release();
        m_handle.commandAllocator->Release();
        for (int i = 0; i < 2; ++i)
            m_handle.renderTargets[i]->Release();
        m_handle.rtvHeap->Release();
        m_handle.swapChain->Release();
        m_handle.commandQueue->Release();
        m_handle.device->Release();
    }
} // namespace Nt

#endif // _NT_RENDERER_WINDOWS_CONTEXT_CPP_
