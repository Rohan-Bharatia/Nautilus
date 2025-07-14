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

#ifndef _NT_RENDERER_LINUX_CONTEXT_CPP_
    #define _NT_RENDERER_LINUX_CONTEXT_CPP_

#include "../Context.h"

#include "../../Core/Logger.h"

namespace Nt
{
    bool GraphicsContext::Initialize(void)
    {
        VkApplicationInfo appInfo{};
        appInfo.sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName   = m_window->GetDescription().title.c_str();
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName        = "Nautilus Engine";
        appInfo.engineVersion      = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion         = VK_API_VERSION_1_0;

        std::vector<const char*> extensions =
        {
            VK_KHR_SURFACE_EXTENSION_NAME,
            VK_KHR_XLIB_SURFACE_EXTENSION_NAME,
        };

        VkInstanceCreateInfo instanceInfo{};
        instanceInfo.sType                   = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        instanceInfo.pApplicationInfo        = &appInfo;
        instanceInfo.enabledExtensionCount   = extensions.size();
        instanceInfo.ppEnabledExtensionNames = extensions.data();
        instanceInfo.enabledLayerCount       = 0;

        if (vkCreateInstance(&instanceInfo, nullptr, &m_handle.instance) != VK_SUCCESS)
        {
            Logger::Error("Failed to create instance!");
            return false;
        }

        VkXlibSurfaceCreateInfoKHR surfaceInfo{};
        surfaceInfo.sType  = VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR;
        surfaceInfo.dpy    = m_window->GetHandle().display;
        surfaceInfo.window = m_window->GetHandle().window;

        if (vkCreateXlibSurfaceKHR(m_handle.instance, &surfaceInfo, nullptr, &m_handle.surface) != VK_SUCCESS)
        {
            Logger::Error("Failed to create window surface!");
            return false;
        }

        uint24 deviceCount = 0;
        vkEnumeratePhysicalDevices(m_handle.instance, &deviceCount, nullptr);

        if (deviceCount == 0)
        {
            Logger::Error("Failed to find a compatible GPU!");
            return false;
        }

        std::vector<VkPhysicalDevice> devices(deviceCount);
        vkEnumeratePhysicalDevices(m_handle.instance, &deviceCount, devices.data());

        int24 graphicsFamily = -1,
              presentFamily  = -1;

        for (VkPhysicalDevice device : devices)
        {
            uint24 queueFamilyCount = 0;
            vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

            std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
            vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

            for (int i = 0; i < queueFamilies.size(); ++i)
            {
                if (queueFamilies[i].queueFlags & VK_QUEUE_GRAPHICS_BIT)
                    graphicsFamily = i;

                VkBool32 presentSupport = VK_FALSE;
                vkGetPhysicalDeviceSurfaceSupportKHR(device, i, m_handle.surface, &presentSupport);

                if (presentSupport == VK_TRUE)
                    presentFamily = i;

                if (graphicsFamily >= 0 &&
                    presentFamily >= 0)
                    break;
            }

            if (graphicsFamily >= 0 &&
                presentFamily >= 0)
            {
                m_handle.physicalDevice = device;
                break;
            }
        }

        if (m_handle.physicalDevice == VK_NULL_HANDLE)
        {
            Logger::Error("Failed to find suitable physical device!");
            return false;
        }

        if (graphicsFamily < 0 ||
            presentFamily < 0)
        {
            Logger::Error("Failed to find suitable queue families!");
            return false;
        }

        std::vector<VkDeviceQueueCreateInfo> queueInfos;
        std::set<int24> uniqueFamilies =
        {
            graphicsFamily,
            presentFamily,
        };
        float32 queuePriority          = 1.0f;

        for (uint24 family : uniqueFamilies)
        {
            VkDeviceQueueCreateInfo queueInfo{};
            queueInfo.sType            = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
            queueInfo.queueFamilyIndex = family;
            queueInfo.queueCount       = 1;
            queueInfo.pQueuePriorities = &queuePriority;

            queueInfos.push_back(queueInfo);
        }

        VkPhysicalDeviceFeatures deviceFeatures{};

        std::vector<const char*> deviceExtensions =
        {
            VK_KHR_SWAPCHAIN_EXTENSION_NAME,
        };

        VkDeviceCreateInfo deviceInfo{};
        deviceInfo.sType                   = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
        deviceInfo.queueCreateInfoCount    = queueInfos.size();
        deviceInfo.pQueueCreateInfos       = queueInfos.data();
        deviceInfo.pEnabledFeatures        = &deviceFeatures;
        deviceInfo.enabledExtensionCount   = deviceExtensions.size();
        deviceInfo.ppEnabledExtensionNames = deviceExtensions.data();
        deviceInfo.enabledLayerCount       = 0;

        if (vkCreateDevice(m_handle.physicalDevice, &deviceInfo, nullptr, &m_handle.device) != VK_SUCCESS)
        {
            Logger::Error("Failed to create a logical device!");
            return false;
        }

        vkGetDeviceQueue(m_handle.device, graphicsFamily, 0, &m_handle.graphicsQueue);
        vkGetDeviceQueue(m_handle.device, presentFamily, 0, &m_handle.presentQueue);

        VkSurfaceCapabilitiesKHR capabilities;
        vkGetPhysicalDeviceSurfaceCapabilitiesKHR(m_handle.physicalDevice, m_handle.surface, &capabilities);

        uint24 formatCount = 0;
        vkGetPhysicalDeviceSurfaceFormatsKHR(m_handle.physicalDevice, m_handle.surface, &formatCount, nullptr);

        std::vector<VkSurfaceFormatKHR> formats(formatCount);
        vkGetPhysicalDeviceSurfaceFormatsKHR(m_handle.physicalDevice, m_handle.surface, &formatCount, formats.data());

        VkSurfaceFormatKHR surfaceFormat = formats[0];
        for (const VkSurfaceFormatKHR& format : formats)
        {
            if (format.format == VK_FORMAT_B8G8R8A8_SRGB &&
                format.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR)
            {
                surfaceFormat = format;
                break;
            }
        }

        Rect view         = m_window->GetSize();
        VkExtent2D extent =
        {
            NT_STATIC_CAST(uint24, view.size.x),
            NT_STATIC_CAST(uint24, view.size.y),
        };

        uint24 imageCount = capabilities.minImageCount + 1;

        if (capabilities.maxImageCount > 0 &&
            imageCount > capabilities.maxImageCount)
            imageCount = capabilities.maxImageCount;

        VkSwapchainCreateInfoKHR swapchainInfo{};
        swapchainInfo.sType            = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
        swapchainInfo.surface          = m_handle.surface;
        swapchainInfo.minImageCount    = imageCount;
        swapchainInfo.imageFormat      = surfaceFormat.format;
        swapchainInfo.imageColorSpace  = surfaceFormat.colorSpace;
        swapchainInfo.imageExtent      = extent;
        swapchainInfo.imageArrayLayers = 1;
        swapchainInfo.imageUsage       = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
        swapchainInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
        swapchainInfo.preTransform     = capabilities.currentTransform;
        swapchainInfo.compositeAlpha   = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
        swapchainInfo.presentMode      = VK_PRESENT_MODE_FIFO_KHR;
        swapchainInfo.clipped          = VK_TRUE;
        swapchainInfo.oldSwapchain     = VK_NULL_HANDLE;

        if (vkCreateSwapchainKHR(m_handle.device, &swapchainInfo, nullptr, &m_handle.swapchain) != VK_SUCCESS)
        {
            Logger::Error("Failed to create swapchain!");
            return false;
        }

        vkGetSwapchainImagesKHR(m_handle.device, m_handle.swapchain, &imageCount, nullptr);
        m_handle.swapchainImages.resize(imageCount);
        vkGetSwapchainImagesKHR(m_handle.device, m_handle.swapchain, &imageCount, m_handle.swapchainImages.data());

        m_handle.swapchainImageFormat = surfaceFormat.format;
        m_handle.swapchainExtent      = extent;

        m_handle.swapchainImageViews.resize(imageCount);

        for (int i = 0; i < m_handle.swapchainImageViews.size(); ++i)
        {
            VkImageViewCreateInfo viewInfo{};
            viewInfo.sType                           = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
            viewInfo.image                           = m_handle.swapchainImages[i];
            viewInfo.viewType                        = VK_IMAGE_VIEW_TYPE_2D;
            viewInfo.format                          = m_handle.swapchainImageFormat;
            viewInfo.components.r                    = VK_COMPONENT_SWIZZLE_IDENTITY;
            viewInfo.components.g                    = VK_COMPONENT_SWIZZLE_IDENTITY;
            viewInfo.components.b                    = VK_COMPONENT_SWIZZLE_IDENTITY;
            viewInfo.components.a                    = VK_COMPONENT_SWIZZLE_IDENTITY;
            viewInfo.subresourceRange.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
            viewInfo.subresourceRange.baseMipLevel   = 0;
            viewInfo.subresourceRange.levelCount     = 1;
            viewInfo.subresourceRange.baseArrayLayer = 0;
            viewInfo.subresourceRange.layerCount     = 1;

            if (vkCreateImageView(m_handle.device, &viewInfo, nullptr, &m_handle.swapchainImageViews[i]) != VK_SUCCESS)
            {
                Logger::Error("Failed to create image views!");
                return false;
            }
        }

        VkAttachmentDescription colorAttachment{};
        colorAttachment.format         = m_handle.swapchainImageFormat;
        colorAttachment.samples        = VK_SAMPLE_COUNT_1_BIT;
        colorAttachment.loadOp         = VK_ATTACHMENT_LOAD_OP_CLEAR;
        colorAttachment.storeOp        = VK_ATTACHMENT_STORE_OP_STORE;
        colorAttachment.stencilLoadOp  = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
        colorAttachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
        colorAttachment.initialLayout  = VK_IMAGE_LAYOUT_UNDEFINED;
        colorAttachment.finalLayout    = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

        VkAttachmentReference colorAttachmentRef{};
        colorAttachmentRef.attachment = 0;
        colorAttachmentRef.layout     = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

        VkSubpassDescription subpass{};
        subpass.pipelineBindPoint    = VK_PIPELINE_BIND_POINT_GRAPHICS;
        subpass.colorAttachmentCount = 1;
        subpass.pColorAttachments    = &colorAttachmentRef;

        VkRenderPassCreateInfo renderPassInfo{};
        renderPassInfo.sType           = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
        renderPassInfo.attachmentCount = 1;
        renderPassInfo.pAttachments    = &colorAttachment;
        renderPassInfo.subpassCount    = 1;
        renderPassInfo.pSubpasses      = &subpass;

        if (vkCreateRenderPass(m_handle.device, &renderPassInfo, nullptr, &m_handle.renderPass) != VK_SUCCESS)
        {
            Logger::Error("Failed to create render pass!");
            return false;
        }

        m_handle.swapchainFramebuffers.resize(imageCount);

        for (int i = 0; i < m_handle.swapchainFramebuffers.size(); ++i)
        {
            VkImageView attachments[] =
            {
                m_handle.swapchainImageViews[i],
            };

            VkFramebufferCreateInfo framebufferInfo{};
            framebufferInfo.sType           = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
            framebufferInfo.renderPass      = m_handle.renderPass;
            framebufferInfo.attachmentCount = 1;
            framebufferInfo.pAttachments    = attachments;
            framebufferInfo.width           = extent.width;
            framebufferInfo.height          = extent.height;
            framebufferInfo.layers          = 1;

            if (vkCreateFramebuffer(m_handle.device, &framebufferInfo, nullptr, &m_handle.swapchainFramebuffers[i]) != VK_SUCCESS)
            {
                Logger::Error("Failed to create framebuffers!");
                return false;
            }
        }

        VkCommandPoolCreateInfo poolInfo{};
        poolInfo.sType            = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
        poolInfo.flags            = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
        poolInfo.queueFamilyIndex = graphicsFamily;

        if (vkCreateCommandPool(m_handle.device, &poolInfo, nullptr, &m_handle.commandPool) != VK_SUCCESS)
        {
            Logger::Error("Failed to create command pool!");
            return false;
        }

        VkCommandBufferAllocateInfo allocInfo{};
        allocInfo.sType              = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        allocInfo.commandPool        = m_handle.commandPool;
        allocInfo.level              = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        allocInfo.commandBufferCount = 1;

        if (vkAllocateCommandBuffers(m_handle.device, &allocInfo, &m_handle.commandBuffer) != VK_SUCCESS)
        {
            Logger::Error("Failed to allocate command buffers!");
            return false;
        }

        VkSemaphoreCreateInfo semaphoreInfo{};
        semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

        VkFenceCreateInfo fenceInfo{};
        fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
        fenceInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

        if (vkCreateSemaphore(m_handle.device, &semaphoreInfo, nullptr, &m_handle.imageAvailableSemaphore) != VK_SUCCESS ||
            vkCreateSemaphore(m_handle.device, &semaphoreInfo, nullptr, &m_handle.renderFinishedSemaphore) != VK_SUCCESS ||
            vkCreateFence(m_handle.device, &fenceInfo, nullptr, &m_handle.inFlightFence) != VK_SUCCESS)
        {
            Logger::Error("Failed to create sync objects!");
            return false;
        }

        return true;
    }

    void GraphicsContext::OnUpdate(void)
    {
        vkWaitForFences(m_handle.device, 1, &m_handle.inFlightFence, VK_TRUE, UINT64_MAX);
        vkResetFences(m_handle.device, 1, &m_handle.inFlightFence);

        uint24 imageIndex = 0;
        vkAcquireNextImageKHR(m_handle.device, m_handle.swapchain, UINT64_MAX,
                              m_handle.imageAvailableSemaphore, VK_NULL_HANDLE,
                              &imageIndex);

        vkResetCommandBuffer(m_handle.commandBuffer, 0);

        VkCommandBufferBeginInfo beginInfo{};
        beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

        if (vkBeginCommandBuffer(m_handle.commandBuffer, &beginInfo) != VK_SUCCESS)
        {
            Logger::Error("Failed to begin recording command buffer!");
            return;
        }

        VkClearValue clearValue =
        {{
             m_clearColor.r / 255.0f,
             m_clearColor.g / 255.0f,
             m_clearColor.b / 255.0f,
             m_clearColor.a,
        }};

        VkRenderPassBeginInfo renderPassInfo{};
        renderPassInfo.sType             = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
        renderPassInfo.renderPass        = m_handle.renderPass;
        renderPassInfo.framebuffer       = m_handle.swapchainFramebuffers[imageIndex];
        renderPassInfo.renderArea.offset = VkOffset2D{ 0, 0 };
        renderPassInfo.renderArea.extent = m_handle.swapchainExtent;
        renderPassInfo.clearValueCount   = 1;
        renderPassInfo.pClearValues      = &clearValue;

        vkCmdBeginRenderPass(m_handle.commandBuffer, &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);
        vkCmdEndRenderPass(m_handle.commandBuffer);

        if (vkEndCommandBuffer(m_handle.commandBuffer) != VK_SUCCESS)
        {
            Logger::Error("Failed to record command buffer!");
            return;
        }

        VkSemaphore waitSemaphores[]      = { m_handle.imageAvailableSemaphore };
        VkSemaphore signalSemaphores[]    = { m_handle.renderFinishedSemaphore };
        VkPipelineStageFlags waitStages[] = { VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT };

        VkSubmitInfo submitInfo{};
        submitInfo.sType                = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        submitInfo.waitSemaphoreCount   = 1;
        submitInfo.pWaitSemaphores      = waitSemaphores;
        submitInfo.pWaitDstStageMask    = waitStages;
        submitInfo.commandBufferCount   = 1;
        submitInfo.pCommandBuffers      = &m_handle.commandBuffer;
        submitInfo.signalSemaphoreCount = 1;
        submitInfo.pSignalSemaphores    = signalSemaphores;

        if (vkQueueSubmit(m_handle.graphicsQueue, 1, &submitInfo, m_handle.inFlightFence) != VK_SUCCESS)
        {
            Logger::Error("Failed to submit draw command buffer!");
            return;
        }

        VkSwapchainKHR swapchains[] = { m_handle.swapchain };

        VkPresentInfoKHR presentInfo{};
        presentInfo.sType              = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
        presentInfo.waitSemaphoreCount = 1;
        presentInfo.pWaitSemaphores    = signalSemaphores;
        presentInfo.swapchainCount     = 1;
        presentInfo.pSwapchains        = swapchains;
        presentInfo.pImageIndices      = &imageIndex;

        vkQueuePresentKHR(m_handle.presentQueue, &presentInfo);
    }

    void GraphicsContext::Shutdown(void)
    {
        vkDeviceWaitIdle(m_handle.device);

        vkDestroySemaphore(m_handle.device, m_handle.renderFinishedSemaphore, nullptr);
        vkDestroySemaphore(m_handle.device, m_handle.imageAvailableSemaphore, nullptr);
        vkDestroyFence(m_handle.device, m_handle.inFlightFence, nullptr);
        vkDestroyCommandPool(m_handle.device, m_handle.commandPool, nullptr);
        for (VkFramebuffer buffer : m_handle.swapchainFramebuffers)
            vkDestroyFramebuffer(m_handle.device, buffer, nullptr);
        vkDestroyRenderPass(m_handle.device, m_handle.renderPass, nullptr);
        for (VkImageView view : m_handle.swapchainImageViews)
            vkDestroyImageView(m_handle.device, view, nullptr);
        vkDestroySwapchainKHR(m_handle.device, m_handle.swapchain, nullptr);
        vkDestroyDevice(m_handle.device, nullptr);
        vkDestroySurfaceKHR(m_handle.instance, m_handle.surface, nullptr);
        vkDestroyInstance(m_handle.instance, nullptr);
    }
} // namespace Nt

#endif // _NT_RENDERER_LINUX_CONTEXT_CPP_
