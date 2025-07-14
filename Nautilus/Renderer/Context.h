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

#ifndef _NT_RENDERER_CONTEXT_H_
    #define _NT_RENDERER_CONTEXT_H_

#include "../Core/Window.h"

namespace Nt
{
    struct NT_API GraphicsHandle
    {
    #if defined(NT_PLATFORM_WINDOWS)
        ID3D12Device* device;
        ID3D12CommandQueue* commandQueue;
        IDXGISwapChain3* swapChain;
        ID3D12DescriptorHeap* rtvHeap;
        ID3D12Resource* renderTargets[2];
        ID3D12CommandAllocator* commandAllocator;
        ID3D12CommandList* commandList;
        ID3D12Fence* fence;
        HANDLE fenceEvent;
        UINT64 fenceValue;
        UINT32 frameIndex;
        UINT32 rtvDescriptorSize;
    #elif defined(NT_PLATFORM_LINUX) || defined(NT_PLATFORM_ANDROID)
        VkInstance instance;
        VkPhysicalDevice physicalDevice;
        VkDevice device;
        VkQueue graphicsQueue;
        VkQueue presentQueue;
        VkSurfaceKHR surface;
        VkSwapchainKHR swapchain;
        std::vector<VkImage> swapchainImages;
        std::vector<VkImageView> swapchainImageViews;
        VkFormat swapchainImageFormat;
        VkExtent2D swapchainExtent;
        VkRenderPass renderPass;
        std::vector<VkFramebuffer> swapchainFramebuffers;
        VkCommandPool commandPool;
        VkCommandBuffer commandBuffer;
        VkSemaphore imageAvailableSemaphore;
        VkSemaphore renderFinishedSemaphore;
        VkFence inFlightFence;
        uint24 currentFrame;
    #elif defined(NT_PLATFORM_MACOS) || defined(NT_PLATFORM_IOS)
        #ifdef __OBJC__
            id<MTLDevice> device;
            id<MTLCommandQueue> commandQueue;
            CAMetalLayer* layer;
            id<CAMetalDrawable> drawable;
            id<MTLRenderCommandEncoder> renderEncoder;
            id<MTLCommandBuffer> commandBuffer;
            MTLRenderPassDescriptor* renderPassDescriptor;
        #else // (NOT) __OBJC__
            void* device;
            void* commandQueue;
            void* layer;
            void* drawable;
            void* renderEncoder;
            void* commandBuffer;
            void* renderPassDescriptor;
        #endif // __OBJC__
    #elif defined(NT_PLATFORM_WASM)
        emscripten::val device;
        emscripten::val context;
        emscripten::val renderPassEncoder;
        emscripten::val commandEncoder;
    #endif // defined(NT_PLATFORM_WINDOWS), defined(NT_PLATFORM_LINUX) || defined(NT_PLATFORM_ANDROID), defined(NT_PLATFORM_MACOS) || defined(NT_PLATFORM_IOS), defined(NT_PLATFORM_WASM)
    };

    class NT_API GraphicsContext
    {
    public:
        NT_CLASS_DEFAULTS(GraphicsContext)
        GraphicsContext(Window* window);

        bool Initialize(void);
        void OnUpdate(void);
        void Shutdown(void);

        void SetClearColor(const Color& color);

        GraphicsHandle GetHandle(void);

    private:
        Window* m_window;
        GraphicsHandle m_handle;
        Color m_clearColor;
    };
} // namespace Nt

#endif // _NT_RENDERER_CONTEXT_H_
