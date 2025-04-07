//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                                 ...
//
//                  Copyright (c) Rohan Bharatia 2025

#import "../Renderer.h"

#import "../../Logger.h"

namespace nt
{
#if defined(NT_PLATFORM_MACOS)
    bool Renderer::initialize(NSWindow* wnd, Rect size)
#elif defined(NT_PLATFORM_IOS)
    bool Renderer::initialize(UIWindow* wnd, Rect size)
#endif // defined(NT_PLATFORM_MACOS), defined(NT_PLATFORM_IOS)
    {
        // Create a Metal device
        m_device = MTLCreateSystemDefaultDevice();
        if (!m_device)
        {
            Logger::error("Failed to create the Metal device!");
            return false;
        }

        // Create a Metal command queue
        m_commandQueue = [m_device newCommandQueue];
        if (!m_commandQueue)
        {
            Logger::error("Failed to create the Metal command queue!");
            return false;
        }

        // Create a Metal render pipeline state
        MTLRenderPipelineDescriptor* pipelineDescriptor    = [[MTLRenderPipelineDescriptor alloc] init];
        pipelineDescriptor.vertexFunction                  = [m_device newFunctionWithName:@"vertex_shader"];
        pipelineDescriptor.fragmentFunction                = [m_device newFunctionWithName:@"fragment_shader"];
        pipelineDescriptor.colorAttachments[0].pixelFormat = MTLPixelFormatBGRA8Unorm;
        m_renderPipelineState = [m_device newRenderPipelineStateWithDescriptor:pipelineDescriptor options:0 reflection:nil error:nil];
        if (!m_renderPipelineState)
        {
            Logger::error("Failed to create the Metal render pipeline state!");
            return false;
        }

        // Create a Metal vertex buffer
        float vertices[9] =
        {
            -0.5, -0.5, 0.0,
             0.5, -0.5, 0.0,
             0.0,  0.5, 0.0,
        };
        m_vertexBuffer   = [m_device newBufferWithBytes:vertices length:sizeof(vertices) options:MTLResourceOptionCPUCacheModeDefault];
        if (!m_vertexBuffer)
        {
            Logger::error("Failed to create the Metal vertex buffer!");
            return false;
        }

        return true;
    }

    void Renderer::clear(Color col)
    {
        // Clear the screen
        MTLRenderPassDescriptor* renderPassDescriptor       = [[MTLRenderPassDescriptor alloc] init];
        renderPassDescriptor.colorAttachments[0].loadAction = MTLLoadActionClear;
        renderPassDescriptor.colorAttachments[0].clearColor = MTLClearColorMake(col.r / 255.0f, col.g / 255.0f, col.b / 255.0f, col.a);
        id<MTLCommandBuffer> commandBuffer                  = [m_commandQueue commandBuffer];
        id<MTLRenderCommandEncoder> renderCommandEncoder    = [commandBuffer renderCommandEncoderWithDescriptor:renderPassDescriptor];
        [renderCommandEncoder endEncoding];
        [commandBuffer commit];
    }

    void Renderer::beginFrame()
    {}

    void Renderer::drawTriangle(Vertex a, Vertex b, Vertex c)
    {
        id<MTLCommandBuffer> commandBuffer               = [m_commandQueue commandBuffer];
        id<MTLRenderCommandEncoder> renderCommandEncoder = [commandBuffer renderCommandEncoderWithDescriptor:nil];
        [renderCommandEncoder setRenderPipelineState:m_renderPipelineState];
        [renderCommandEncoder setVertexBuffer:m_vertexBuffer offset:0 atIndex:0];
        [renderCommandEncoder drawPrimitives:MTLPrimitiveTypeTriangle vertexStart:0 vertexCount:3];
        [renderCommandEncoder endEncoding];
        [commandBuffer commit];
    }

    void Renderer::endFrame()
    {}

    void Renderer::shutdown()
    {
        m_device = nil;
        m_commandQueue = nil;
    }
}
