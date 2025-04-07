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

#ifndef _NT_CORE_RENDERING_RENDERER_H_
    #define _NT_CORE_RENDERING_RENDERER_H_

#include "../Platform/Platform.h"
#include "../Platform/API.h"
#include "../Math/Vertex.h"
#include "../Platform/Window.h"
#include "../Math/Rect.h"

namespace nt
{
    class NT_API Renderer
    {
    public:
        Renderer()                                 = default;
        ~Renderer()                                = default;
        Renderer(const Renderer& other)            = default;
        Renderer& operator=(const Renderer& other) = default;

    #if defined(NT_API_DIRECTX)
        bool initialize(HWND hwnd, Rect size);
    #elif defined(NT_API_OPENGL)
        bool initialize(Window* window, Rect size);
    #elif defined(NT_API_METAL)
        #if defined(NT_PLATFORM_MACOS)
        bool initialize(NSWindow* window, Rect size);
        #elif defined(NT_PLATFORM_IOS)
        bool initialize(UIWindow* window, Rect size);
        #endif // defined(NT_PLATFORM_MACOS), defined(NT_PLATFORM_IOS)
    #elif defined(NT_API_OPENGLES)
        bool initialize(ANativeActivity native, Rect size);
    #endif // defined(NT_API_DIRECTX), defined(NT_API_OPENGL), defined(NT_API_METAL), defined(NT_API_OPENGLES)
        void clear(Color col);
        void beginFrame();
        void drawTriangle(Vertex a, Vertex b, Vertex c);
        void endFrame();
        void shutdown();

    private:
    #if defined(NT_API_DIRECTX)
        ComPtr<ID3D12Device> m_device;
        ComPtr<ID3D12CommandQueue> m_commandQueue;
        ComPtr<IDXGISwapChain1> m_swapChain;
        ComPtr<ID3D12Resource> m_renderTargets[2];
        ComPtr<ID3D12DescriptorHeap> m_renderTargetViews[2];
        ComPtr<ID3D12CommandAllocator> m_commandAllocator;
        ComPtr<ID3D12GraphicsCommandList> m_commandList;
        D3D12_RECT m_viewport;
    #elif defined(NT_API_OPENGL)
        Display* m_display;
        int m_screen;
        Window m_window;
        Colormap m_colormap;
        GLXContext m_context;
    #elif defined(NT_API_METAL)
        id<MTLDevice> m_device;
        id<MTLCommandQueue> m_commandQueue;
        id<MTLRenderPipelineState> m_renderPipelineState;
        id<MTLBuffer> m_vertexBuffer;
    #elif defined(NT_API_OPENGLES)
        EGLDisplay m_display;
        EGLSurface m_surface;
        EGLContext m_context;
    #endif // defined(NT_API_DIRECTX), defined(NT_API_OPENGL), defined(NT_API_METAL), defined(NT_API_OPENGLES)
    };
}

#endif // _NT_CORE_RENDERING_RENDERER_H_
