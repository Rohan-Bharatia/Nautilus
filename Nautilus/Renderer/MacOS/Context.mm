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

#ifndef _NT_RENDERER_MACOS_CONTEXT_CPP_
    #define _NT_RENDERER_MACOS_CONTEXT_CPP_

#import "../Context.h"

#import "../../Core/Logger.h"

namespace Nt
{
    bool GraphicsContext::Initialize(void)
    {
        m_handle.device = MTLCreateSystemDefaultDevice();

        if (!m_handle.device)
        {
            [Logger Error:@"Failed to create device!"];
            return false;
        }

        m_handle.layer             = [CAMetalLayer layer];
        m_handle.layer.device      = m_handle.device;
        m_handle.layer.pixelFormat = MTLPixelFormatBGRA8Unorm;

        NSView* contentView = [(__bridge NSWindow*)m_window->GetHandle().window contentView];

        [contentView setWantsLayer:YES];
        [contentView setLayer:m_handle.layer];

        m_handle.commandQueue = [m_handle.device newCommandQueue];

        if (!m_handle.commandQueue)
        {
            [Logger Error:@"Failed to create command queue!"];
            return false;
        }

        return true;
    }

    void GraphicsContext::OnUpdate(void)
    {
        @autoreleasepool
        {
            m_handle.drawable = [m_handle.layer nextDrawable];

            if (!m_handle.drawable)
            {
                [Logger Error:@"Failed to create a drawable object"];
                return;
            }

            m_handle.renderPassDescriptor = [MTLRenderPassDescriptor renderPassDescriptor];
            m_handle.renderPassDescriptor.colorAttachment[0].texture     = m_handle.drawable.texture;
            m_handle.renderPassDescriptor.colorAttachment[0].loadAction  = MTLLoadActionClear;
            m_handle.renderPassDescriptor.colorAttachment[0].storeAction = MTLStoreActionStore;
            m_handle.renderPassDescriptor.colorAttachment[0].clearColor  = MTLClearColorMake(m_clearColor.r / 255.0f,
                                                                                             m_clearColor.g / 255.0f,
                                                                                             m_clearColor.b / 255.0f,
                                                                                             m_clearColor.a);


            m_handle.commandBuffer = [m_handle.commandQueue commandBuffer];

            m_handle.renderEncoder = [m_handle.commandBuffer renderCommandEncoderWithDescriptor:m_handle.renderPassDescriptor];
            [m_handle.renderEncoder endEncoding];

            [m_handle.commandBuffer presentDrawable:m_handle.drawable];
            [m_handle.commandBuffer commit];
        }
    }

    void GraphicsContext::Shutdown(void)
    {
        m_handle.device               = nil;
        m_handle.commandQueue         = nil;
        m_handle.layer                = nil;
        m_handle.drawable             = nil;
        m_handle.renderEncoder        = nil;
        m_handle.commandBuffer        = nil;
        m_handle.renderPassDescriptor = nil;
    }
} // namespace Nt

#endif // _NT_RENDERER_MACOS_CONTEXT_CPP_
