/**
 * SPDX-License-Identifier: (WTFPL OR CC0-1.0) AND Apache-2.0
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <../include/glad/vulkansc.h>

#ifndef GLAD_IMPL_UTIL_C_
#define GLAD_IMPL_UTIL_C_

#ifdef _MSC_VER
#define GLAD_IMPL_UTIL_SSCANF sscanf_s
#else
#define GLAD_IMPL_UTIL_SSCANF sscanf
#endif

#endif /* GLAD_IMPL_UTIL_C_ */

#ifdef __cplusplus
extern "C" {
#endif



int GLAD_VKSC_VERSION_1_0 = 0;
int GLAD_VK_VERSION_1_1 = 0;
int GLAD_VK_VERSION_1_2 = 0;
int GLAD_VK_VERSION_1_3 = 0;
int GLAD_VK_VERSION_1_4 = 0;
int GLAD_VK_EXT_4444_formats = 0;
int GLAD_VK_EXT_application_parameters = 0;
int GLAD_VK_EXT_astc_decode_mode = 0;
int GLAD_VK_EXT_blend_operation_advanced = 0;
int GLAD_VK_EXT_color_write_enable = 0;
int GLAD_VK_EXT_conservative_rasterization = 0;
int GLAD_VK_EXT_custom_border_color = 0;
int GLAD_VK_EXT_debug_utils = 0;
int GLAD_VK_EXT_depth_clip_enable = 0;
int GLAD_VK_EXT_depth_range_unrestricted = 0;
int GLAD_VK_EXT_direct_mode_display = 0;
int GLAD_VK_EXT_discard_rectangles = 0;
int GLAD_VK_EXT_display_control = 0;
int GLAD_VK_EXT_display_surface_counter = 0;
int GLAD_VK_EXT_extended_dynamic_state = 0;
int GLAD_VK_EXT_extended_dynamic_state2 = 0;
int GLAD_VK_EXT_external_memory_dma_buf = 0;
int GLAD_VK_EXT_external_memory_host = 0;
int GLAD_VK_EXT_filter_cubic = 0;
int GLAD_VK_EXT_fragment_shader_interlock = 0;
int GLAD_VK_EXT_hdr_metadata = 0;
int GLAD_VK_EXT_headless_surface = 0;
int GLAD_VK_EXT_image_drm_format_modifier = 0;
int GLAD_VK_EXT_image_robustness = 0;
int GLAD_VK_EXT_index_type_uint8 = 0;
int GLAD_VK_EXT_layer_settings = 0;
int GLAD_VK_EXT_line_rasterization = 0;
int GLAD_VK_EXT_memory_budget = 0;
int GLAD_VK_EXT_pci_bus_info = 0;
int GLAD_VK_EXT_post_depth_coverage = 0;
int GLAD_VK_EXT_queue_family_foreign = 0;
int GLAD_VK_EXT_robustness2 = 0;
int GLAD_VK_EXT_sample_locations = 0;
int GLAD_VK_EXT_shader_atomic_float = 0;
int GLAD_VK_EXT_shader_demote_to_helper_invocation = 0;
int GLAD_VK_EXT_shader_image_atomic_int64 = 0;
int GLAD_VK_EXT_shader_stencil_export = 0;
int GLAD_VK_EXT_subgroup_size_control = 0;
int GLAD_VK_EXT_swapchain_colorspace = 0;
int GLAD_VK_EXT_texel_buffer_alignment = 0;
int GLAD_VK_EXT_texture_compression_astc_hdr = 0;
int GLAD_VK_EXT_validation_features = 0;
int GLAD_VK_EXT_vertex_input_dynamic_state = 0;
int GLAD_VK_EXT_ycbcr_2plane_444_formats = 0;
int GLAD_VK_EXT_ycbcr_image_arrays = 0;
int GLAD_VK_KHR_calibrated_timestamps = 0;
int GLAD_VK_KHR_copy_commands2 = 0;
int GLAD_VK_KHR_display = 0;
int GLAD_VK_KHR_display_swapchain = 0;
int GLAD_VK_KHR_external_fence_fd = 0;
int GLAD_VK_KHR_external_memory_fd = 0;
int GLAD_VK_KHR_external_semaphore_fd = 0;
int GLAD_VK_KHR_fragment_shading_rate = 0;
int GLAD_VK_KHR_get_display_properties2 = 0;
int GLAD_VK_KHR_get_surface_capabilities2 = 0;
int GLAD_VK_KHR_global_priority = 0;
int GLAD_VK_KHR_incremental_present = 0;
int GLAD_VK_KHR_index_type_uint8 = 0;
int GLAD_VK_KHR_line_rasterization = 0;
int GLAD_VK_KHR_object_refresh = 0;
int GLAD_VK_KHR_performance_query = 0;
int GLAD_VK_KHR_shader_clock = 0;
int GLAD_VK_KHR_shader_terminate_invocation = 0;
int GLAD_VK_KHR_shared_presentable_image = 0;
int GLAD_VK_KHR_surface = 0;
int GLAD_VK_KHR_swapchain = 0;
int GLAD_VK_KHR_swapchain_mutable_format = 0;
int GLAD_VK_KHR_synchronization2 = 0;
int GLAD_VK_KHR_vertex_attribute_divisor = 0;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
int GLAD_VK_NV_acquire_winrt_display = 0;

#endif
#if defined(VK_USE_PLATFORM_SCI)
int GLAD_VK_NV_external_memory_sci_buf = 0;

#endif
#if defined(VK_USE_PLATFORM_SCI)
int GLAD_VK_NV_external_sci_sync = 0;

#endif
#if defined(VK_USE_PLATFORM_SCI)
int GLAD_VK_NV_external_sci_sync2 = 0;

#endif
int GLAD_VK_NV_private_vendor_info = 0;
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
int GLAD_VK_QNX_external_memory_screen_buffer = 0;

#endif



PFN_vkAcquireNextImage2KHR glad_vkAcquireNextImage2KHR = NULL;
PFN_vkAcquireNextImageKHR glad_vkAcquireNextImageKHR = NULL;
PFN_vkAcquireProfilingLockKHR glad_vkAcquireProfilingLockKHR = NULL;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
PFN_vkAcquireWinrtDisplayNV glad_vkAcquireWinrtDisplayNV = NULL;

#endif
PFN_vkBindBufferMemory2 glad_vkBindBufferMemory2 = NULL;
PFN_vkBindImageMemory2 glad_vkBindImageMemory2 = NULL;
PFN_vkCmdBeginDebugUtilsLabelEXT glad_vkCmdBeginDebugUtilsLabelEXT = NULL;
PFN_vkCmdBeginRenderPass2 glad_vkCmdBeginRenderPass2 = NULL;
PFN_vkCmdBeginRendering glad_vkCmdBeginRendering = NULL;
PFN_vkCmdBindDescriptorSets2 glad_vkCmdBindDescriptorSets2 = NULL;
PFN_vkCmdBindIndexBuffer2 glad_vkCmdBindIndexBuffer2 = NULL;
PFN_vkCmdBindVertexBuffers2 glad_vkCmdBindVertexBuffers2 = NULL;
PFN_vkCmdBindVertexBuffers2EXT glad_vkCmdBindVertexBuffers2EXT = NULL;
PFN_vkCmdBlitImage2 glad_vkCmdBlitImage2 = NULL;
PFN_vkCmdBlitImage2KHR glad_vkCmdBlitImage2KHR = NULL;
PFN_vkCmdCopyBuffer2 glad_vkCmdCopyBuffer2 = NULL;
PFN_vkCmdCopyBuffer2KHR glad_vkCmdCopyBuffer2KHR = NULL;
PFN_vkCmdCopyBufferToImage2 glad_vkCmdCopyBufferToImage2 = NULL;
PFN_vkCmdCopyBufferToImage2KHR glad_vkCmdCopyBufferToImage2KHR = NULL;
PFN_vkCmdCopyImage2 glad_vkCmdCopyImage2 = NULL;
PFN_vkCmdCopyImage2KHR glad_vkCmdCopyImage2KHR = NULL;
PFN_vkCmdCopyImageToBuffer2 glad_vkCmdCopyImageToBuffer2 = NULL;
PFN_vkCmdCopyImageToBuffer2KHR glad_vkCmdCopyImageToBuffer2KHR = NULL;
PFN_vkCmdDispatchBase glad_vkCmdDispatchBase = NULL;
PFN_vkCmdDrawIndexedIndirectCount glad_vkCmdDrawIndexedIndirectCount = NULL;
PFN_vkCmdDrawIndirectCount glad_vkCmdDrawIndirectCount = NULL;
PFN_vkCmdEndDebugUtilsLabelEXT glad_vkCmdEndDebugUtilsLabelEXT = NULL;
PFN_vkCmdEndRenderPass2 glad_vkCmdEndRenderPass2 = NULL;
PFN_vkCmdEndRendering glad_vkCmdEndRendering = NULL;
PFN_vkCmdInsertDebugUtilsLabelEXT glad_vkCmdInsertDebugUtilsLabelEXT = NULL;
PFN_vkCmdNextSubpass2 glad_vkCmdNextSubpass2 = NULL;
PFN_vkCmdPipelineBarrier2 glad_vkCmdPipelineBarrier2 = NULL;
PFN_vkCmdPipelineBarrier2KHR glad_vkCmdPipelineBarrier2KHR = NULL;
PFN_vkCmdPushConstants2 glad_vkCmdPushConstants2 = NULL;
PFN_vkCmdPushDescriptorSet glad_vkCmdPushDescriptorSet = NULL;
PFN_vkCmdPushDescriptorSet2 glad_vkCmdPushDescriptorSet2 = NULL;
PFN_vkCmdPushDescriptorSetWithTemplate glad_vkCmdPushDescriptorSetWithTemplate = NULL;
PFN_vkCmdPushDescriptorSetWithTemplate2 glad_vkCmdPushDescriptorSetWithTemplate2 = NULL;
PFN_vkCmdRefreshObjectsKHR glad_vkCmdRefreshObjectsKHR = NULL;
PFN_vkCmdResetEvent2 glad_vkCmdResetEvent2 = NULL;
PFN_vkCmdResetEvent2KHR glad_vkCmdResetEvent2KHR = NULL;
PFN_vkCmdResolveImage2 glad_vkCmdResolveImage2 = NULL;
PFN_vkCmdResolveImage2KHR glad_vkCmdResolveImage2KHR = NULL;
PFN_vkCmdSetColorWriteEnableEXT glad_vkCmdSetColorWriteEnableEXT = NULL;
PFN_vkCmdSetCullMode glad_vkCmdSetCullMode = NULL;
PFN_vkCmdSetCullModeEXT glad_vkCmdSetCullModeEXT = NULL;
PFN_vkCmdSetDepthBiasEnable glad_vkCmdSetDepthBiasEnable = NULL;
PFN_vkCmdSetDepthBiasEnableEXT glad_vkCmdSetDepthBiasEnableEXT = NULL;
PFN_vkCmdSetDepthBoundsTestEnable glad_vkCmdSetDepthBoundsTestEnable = NULL;
PFN_vkCmdSetDepthBoundsTestEnableEXT glad_vkCmdSetDepthBoundsTestEnableEXT = NULL;
PFN_vkCmdSetDepthCompareOp glad_vkCmdSetDepthCompareOp = NULL;
PFN_vkCmdSetDepthCompareOpEXT glad_vkCmdSetDepthCompareOpEXT = NULL;
PFN_vkCmdSetDepthTestEnable glad_vkCmdSetDepthTestEnable = NULL;
PFN_vkCmdSetDepthTestEnableEXT glad_vkCmdSetDepthTestEnableEXT = NULL;
PFN_vkCmdSetDepthWriteEnable glad_vkCmdSetDepthWriteEnable = NULL;
PFN_vkCmdSetDepthWriteEnableEXT glad_vkCmdSetDepthWriteEnableEXT = NULL;
PFN_vkCmdSetDeviceMask glad_vkCmdSetDeviceMask = NULL;
PFN_vkCmdSetDiscardRectangleEXT glad_vkCmdSetDiscardRectangleEXT = NULL;
PFN_vkCmdSetDiscardRectangleEnableEXT glad_vkCmdSetDiscardRectangleEnableEXT = NULL;
PFN_vkCmdSetDiscardRectangleModeEXT glad_vkCmdSetDiscardRectangleModeEXT = NULL;
PFN_vkCmdSetEvent2 glad_vkCmdSetEvent2 = NULL;
PFN_vkCmdSetEvent2KHR glad_vkCmdSetEvent2KHR = NULL;
PFN_vkCmdSetFragmentShadingRateKHR glad_vkCmdSetFragmentShadingRateKHR = NULL;
PFN_vkCmdSetFrontFace glad_vkCmdSetFrontFace = NULL;
PFN_vkCmdSetFrontFaceEXT glad_vkCmdSetFrontFaceEXT = NULL;
PFN_vkCmdSetLineStipple glad_vkCmdSetLineStipple = NULL;
PFN_vkCmdSetLineStippleEXT glad_vkCmdSetLineStippleEXT = NULL;
PFN_vkCmdSetLineStippleKHR glad_vkCmdSetLineStippleKHR = NULL;
PFN_vkCmdSetLogicOpEXT glad_vkCmdSetLogicOpEXT = NULL;
PFN_vkCmdSetPatchControlPointsEXT glad_vkCmdSetPatchControlPointsEXT = NULL;
PFN_vkCmdSetPrimitiveRestartEnable glad_vkCmdSetPrimitiveRestartEnable = NULL;
PFN_vkCmdSetPrimitiveRestartEnableEXT glad_vkCmdSetPrimitiveRestartEnableEXT = NULL;
PFN_vkCmdSetPrimitiveTopology glad_vkCmdSetPrimitiveTopology = NULL;
PFN_vkCmdSetPrimitiveTopologyEXT glad_vkCmdSetPrimitiveTopologyEXT = NULL;
PFN_vkCmdSetRasterizerDiscardEnable glad_vkCmdSetRasterizerDiscardEnable = NULL;
PFN_vkCmdSetRasterizerDiscardEnableEXT glad_vkCmdSetRasterizerDiscardEnableEXT = NULL;
PFN_vkCmdSetRenderingAttachmentLocations glad_vkCmdSetRenderingAttachmentLocations = NULL;
PFN_vkCmdSetRenderingInputAttachmentIndices glad_vkCmdSetRenderingInputAttachmentIndices = NULL;
PFN_vkCmdSetSampleLocationsEXT glad_vkCmdSetSampleLocationsEXT = NULL;
PFN_vkCmdSetScissorWithCount glad_vkCmdSetScissorWithCount = NULL;
PFN_vkCmdSetScissorWithCountEXT glad_vkCmdSetScissorWithCountEXT = NULL;
PFN_vkCmdSetStencilOp glad_vkCmdSetStencilOp = NULL;
PFN_vkCmdSetStencilOpEXT glad_vkCmdSetStencilOpEXT = NULL;
PFN_vkCmdSetStencilTestEnable glad_vkCmdSetStencilTestEnable = NULL;
PFN_vkCmdSetStencilTestEnableEXT glad_vkCmdSetStencilTestEnableEXT = NULL;
PFN_vkCmdSetVertexInputEXT glad_vkCmdSetVertexInputEXT = NULL;
PFN_vkCmdSetViewportWithCount glad_vkCmdSetViewportWithCount = NULL;
PFN_vkCmdSetViewportWithCountEXT glad_vkCmdSetViewportWithCountEXT = NULL;
PFN_vkCmdWaitEvents2 glad_vkCmdWaitEvents2 = NULL;
PFN_vkCmdWaitEvents2KHR glad_vkCmdWaitEvents2KHR = NULL;
PFN_vkCmdWriteTimestamp2 glad_vkCmdWriteTimestamp2 = NULL;
PFN_vkCmdWriteTimestamp2KHR glad_vkCmdWriteTimestamp2KHR = NULL;
PFN_vkCopyImageToImage glad_vkCopyImageToImage = NULL;
PFN_vkCopyImageToMemory glad_vkCopyImageToMemory = NULL;
PFN_vkCopyMemoryToImage glad_vkCopyMemoryToImage = NULL;
PFN_vkCreateDebugUtilsMessengerEXT glad_vkCreateDebugUtilsMessengerEXT = NULL;
PFN_vkCreateDescriptorUpdateTemplate glad_vkCreateDescriptorUpdateTemplate = NULL;
PFN_vkCreateDisplayModeKHR glad_vkCreateDisplayModeKHR = NULL;
PFN_vkCreateDisplayPlaneSurfaceKHR glad_vkCreateDisplayPlaneSurfaceKHR = NULL;
PFN_vkCreateHeadlessSurfaceEXT glad_vkCreateHeadlessSurfaceEXT = NULL;
PFN_vkCreatePrivateDataSlot glad_vkCreatePrivateDataSlot = NULL;
PFN_vkCreateRenderPass2 glad_vkCreateRenderPass2 = NULL;
PFN_vkCreateSamplerYcbcrConversion glad_vkCreateSamplerYcbcrConversion = NULL;
#if defined(VK_USE_PLATFORM_SCI)
PFN_vkCreateSemaphoreSciSyncPoolNV glad_vkCreateSemaphoreSciSyncPoolNV = NULL;

#endif
PFN_vkCreateSharedSwapchainsKHR glad_vkCreateSharedSwapchainsKHR = NULL;
PFN_vkCreateSwapchainKHR glad_vkCreateSwapchainKHR = NULL;
PFN_vkDestroyDebugUtilsMessengerEXT glad_vkDestroyDebugUtilsMessengerEXT = NULL;
PFN_vkDestroyDescriptorUpdateTemplate glad_vkDestroyDescriptorUpdateTemplate = NULL;
PFN_vkDestroyPrivateDataSlot glad_vkDestroyPrivateDataSlot = NULL;
PFN_vkDestroySamplerYcbcrConversion glad_vkDestroySamplerYcbcrConversion = NULL;
#if defined(VK_USE_PLATFORM_SCI)
PFN_vkDestroySemaphoreSciSyncPoolNV glad_vkDestroySemaphoreSciSyncPoolNV = NULL;

#endif
PFN_vkDestroySurfaceKHR glad_vkDestroySurfaceKHR = NULL;
PFN_vkDestroySwapchainKHR glad_vkDestroySwapchainKHR = NULL;
PFN_vkDisplayPowerControlEXT glad_vkDisplayPowerControlEXT = NULL;
PFN_vkEnumerateInstanceVersion glad_vkEnumerateInstanceVersion = NULL;
PFN_vkEnumeratePhysicalDeviceGroups glad_vkEnumeratePhysicalDeviceGroups = NULL;
PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR glad_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR = NULL;
PFN_vkGetBufferDeviceAddress glad_vkGetBufferDeviceAddress = NULL;
PFN_vkGetBufferMemoryRequirements2 glad_vkGetBufferMemoryRequirements2 = NULL;
PFN_vkGetBufferOpaqueCaptureAddress glad_vkGetBufferOpaqueCaptureAddress = NULL;
PFN_vkGetCalibratedTimestampsKHR glad_vkGetCalibratedTimestampsKHR = NULL;
PFN_vkGetCommandPoolMemoryConsumption glad_vkGetCommandPoolMemoryConsumption = NULL;
PFN_vkGetDescriptorSetLayoutSupport glad_vkGetDescriptorSetLayoutSupport = NULL;
PFN_vkGetDeviceBufferMemoryRequirements glad_vkGetDeviceBufferMemoryRequirements = NULL;
PFN_vkGetDeviceGroupPeerMemoryFeatures glad_vkGetDeviceGroupPeerMemoryFeatures = NULL;
PFN_vkGetDeviceGroupPresentCapabilitiesKHR glad_vkGetDeviceGroupPresentCapabilitiesKHR = NULL;
PFN_vkGetDeviceGroupSurfacePresentModesKHR glad_vkGetDeviceGroupSurfacePresentModesKHR = NULL;
PFN_vkGetDeviceImageMemoryRequirements glad_vkGetDeviceImageMemoryRequirements = NULL;
PFN_vkGetDeviceImageSparseMemoryRequirements glad_vkGetDeviceImageSparseMemoryRequirements = NULL;
PFN_vkGetDeviceImageSubresourceLayout glad_vkGetDeviceImageSubresourceLayout = NULL;
PFN_vkGetDeviceMemoryOpaqueCaptureAddress glad_vkGetDeviceMemoryOpaqueCaptureAddress = NULL;
PFN_vkGetDeviceQueue2 glad_vkGetDeviceQueue2 = NULL;
PFN_vkGetDisplayModeProperties2KHR glad_vkGetDisplayModeProperties2KHR = NULL;
PFN_vkGetDisplayModePropertiesKHR glad_vkGetDisplayModePropertiesKHR = NULL;
PFN_vkGetDisplayPlaneCapabilities2KHR glad_vkGetDisplayPlaneCapabilities2KHR = NULL;
PFN_vkGetDisplayPlaneCapabilitiesKHR glad_vkGetDisplayPlaneCapabilitiesKHR = NULL;
PFN_vkGetDisplayPlaneSupportedDisplaysKHR glad_vkGetDisplayPlaneSupportedDisplaysKHR = NULL;
PFN_vkGetFaultData glad_vkGetFaultData = NULL;
PFN_vkGetFenceFdKHR glad_vkGetFenceFdKHR = NULL;
#if defined(VK_USE_PLATFORM_SCI) || defined(VK_USE_PLATFORM_SCI)
PFN_vkGetFenceSciSyncFenceNV glad_vkGetFenceSciSyncFenceNV = NULL;

#endif
#if defined(VK_USE_PLATFORM_SCI) || defined(VK_USE_PLATFORM_SCI)
PFN_vkGetFenceSciSyncObjNV glad_vkGetFenceSciSyncObjNV = NULL;

#endif
PFN_vkGetImageDrmFormatModifierPropertiesEXT glad_vkGetImageDrmFormatModifierPropertiesEXT = NULL;
PFN_vkGetImageMemoryRequirements2 glad_vkGetImageMemoryRequirements2 = NULL;
PFN_vkGetImageSparseMemoryRequirements2 glad_vkGetImageSparseMemoryRequirements2 = NULL;
PFN_vkGetImageSubresourceLayout2 glad_vkGetImageSubresourceLayout2 = NULL;
PFN_vkGetMemoryFdKHR glad_vkGetMemoryFdKHR = NULL;
PFN_vkGetMemoryFdPropertiesKHR glad_vkGetMemoryFdPropertiesKHR = NULL;
PFN_vkGetMemoryHostPointerPropertiesEXT glad_vkGetMemoryHostPointerPropertiesEXT = NULL;
#if defined(VK_USE_PLATFORM_SCI)
PFN_vkGetMemorySciBufNV glad_vkGetMemorySciBufNV = NULL;

#endif
PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR glad_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR = NULL;
PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR glad_vkGetPhysicalDeviceDisplayPlaneProperties2KHR = NULL;
PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR glad_vkGetPhysicalDeviceDisplayPlanePropertiesKHR = NULL;
PFN_vkGetPhysicalDeviceDisplayProperties2KHR glad_vkGetPhysicalDeviceDisplayProperties2KHR = NULL;
PFN_vkGetPhysicalDeviceDisplayPropertiesKHR glad_vkGetPhysicalDeviceDisplayPropertiesKHR = NULL;
PFN_vkGetPhysicalDeviceExternalBufferProperties glad_vkGetPhysicalDeviceExternalBufferProperties = NULL;
PFN_vkGetPhysicalDeviceExternalFenceProperties glad_vkGetPhysicalDeviceExternalFenceProperties = NULL;
#if defined(VK_USE_PLATFORM_SCI)
PFN_vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV glad_vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV = NULL;

#endif
PFN_vkGetPhysicalDeviceExternalSemaphoreProperties glad_vkGetPhysicalDeviceExternalSemaphoreProperties = NULL;
PFN_vkGetPhysicalDeviceFeatures2 glad_vkGetPhysicalDeviceFeatures2 = NULL;
PFN_vkGetPhysicalDeviceFormatProperties2 glad_vkGetPhysicalDeviceFormatProperties2 = NULL;
PFN_vkGetPhysicalDeviceFragmentShadingRatesKHR glad_vkGetPhysicalDeviceFragmentShadingRatesKHR = NULL;
PFN_vkGetPhysicalDeviceImageFormatProperties2 glad_vkGetPhysicalDeviceImageFormatProperties2 = NULL;
PFN_vkGetPhysicalDeviceMemoryProperties2 glad_vkGetPhysicalDeviceMemoryProperties2 = NULL;
PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT glad_vkGetPhysicalDeviceMultisamplePropertiesEXT = NULL;
PFN_vkGetPhysicalDevicePresentRectanglesKHR glad_vkGetPhysicalDevicePresentRectanglesKHR = NULL;
PFN_vkGetPhysicalDeviceProperties2 glad_vkGetPhysicalDeviceProperties2 = NULL;
PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR glad_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR = NULL;
PFN_vkGetPhysicalDeviceQueueFamilyProperties2 glad_vkGetPhysicalDeviceQueueFamilyProperties2 = NULL;
PFN_vkGetPhysicalDeviceRefreshableObjectTypesKHR glad_vkGetPhysicalDeviceRefreshableObjectTypesKHR = NULL;
#if defined(VK_USE_PLATFORM_SCI)
PFN_vkGetPhysicalDeviceSciBufAttributesNV glad_vkGetPhysicalDeviceSciBufAttributesNV = NULL;

#endif
#if defined(VK_USE_PLATFORM_SCI) || defined(VK_USE_PLATFORM_SCI)
PFN_vkGetPhysicalDeviceSciSyncAttributesNV glad_vkGetPhysicalDeviceSciSyncAttributesNV = NULL;

#endif
PFN_vkGetPhysicalDeviceSparseImageFormatProperties2 glad_vkGetPhysicalDeviceSparseImageFormatProperties2 = NULL;
PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT glad_vkGetPhysicalDeviceSurfaceCapabilities2EXT = NULL;
PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR glad_vkGetPhysicalDeviceSurfaceCapabilities2KHR = NULL;
PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR glad_vkGetPhysicalDeviceSurfaceCapabilitiesKHR = NULL;
PFN_vkGetPhysicalDeviceSurfaceFormats2KHR glad_vkGetPhysicalDeviceSurfaceFormats2KHR = NULL;
PFN_vkGetPhysicalDeviceSurfaceFormatsKHR glad_vkGetPhysicalDeviceSurfaceFormatsKHR = NULL;
PFN_vkGetPhysicalDeviceSurfacePresentModesKHR glad_vkGetPhysicalDeviceSurfacePresentModesKHR = NULL;
PFN_vkGetPhysicalDeviceSurfaceSupportKHR glad_vkGetPhysicalDeviceSurfaceSupportKHR = NULL;
PFN_vkGetPhysicalDeviceToolProperties glad_vkGetPhysicalDeviceToolProperties = NULL;
PFN_vkGetPrivateData glad_vkGetPrivateData = NULL;
PFN_vkGetRenderingAreaGranularity glad_vkGetRenderingAreaGranularity = NULL;
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
PFN_vkGetScreenBufferPropertiesQNX glad_vkGetScreenBufferPropertiesQNX = NULL;

#endif
PFN_vkGetSemaphoreCounterValue glad_vkGetSemaphoreCounterValue = NULL;
PFN_vkGetSemaphoreFdKHR glad_vkGetSemaphoreFdKHR = NULL;
#if defined(VK_USE_PLATFORM_SCI)
PFN_vkGetSemaphoreSciSyncObjNV glad_vkGetSemaphoreSciSyncObjNV = NULL;

#endif
PFN_vkGetSwapchainCounterEXT glad_vkGetSwapchainCounterEXT = NULL;
PFN_vkGetSwapchainImagesKHR glad_vkGetSwapchainImagesKHR = NULL;
PFN_vkGetSwapchainStatusKHR glad_vkGetSwapchainStatusKHR = NULL;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
PFN_vkGetWinrtDisplayNV glad_vkGetWinrtDisplayNV = NULL;

#endif
PFN_vkImportFenceFdKHR glad_vkImportFenceFdKHR = NULL;
#if defined(VK_USE_PLATFORM_SCI) || defined(VK_USE_PLATFORM_SCI)
PFN_vkImportFenceSciSyncFenceNV glad_vkImportFenceSciSyncFenceNV = NULL;

#endif
#if defined(VK_USE_PLATFORM_SCI) || defined(VK_USE_PLATFORM_SCI)
PFN_vkImportFenceSciSyncObjNV glad_vkImportFenceSciSyncObjNV = NULL;

#endif
PFN_vkImportSemaphoreFdKHR glad_vkImportSemaphoreFdKHR = NULL;
#if defined(VK_USE_PLATFORM_SCI)
PFN_vkImportSemaphoreSciSyncObjNV glad_vkImportSemaphoreSciSyncObjNV = NULL;

#endif
PFN_vkMapMemory2 glad_vkMapMemory2 = NULL;
PFN_vkQueueBeginDebugUtilsLabelEXT glad_vkQueueBeginDebugUtilsLabelEXT = NULL;
PFN_vkQueueEndDebugUtilsLabelEXT glad_vkQueueEndDebugUtilsLabelEXT = NULL;
PFN_vkQueueInsertDebugUtilsLabelEXT glad_vkQueueInsertDebugUtilsLabelEXT = NULL;
PFN_vkQueuePresentKHR glad_vkQueuePresentKHR = NULL;
PFN_vkQueueSubmit2 glad_vkQueueSubmit2 = NULL;
PFN_vkQueueSubmit2KHR glad_vkQueueSubmit2KHR = NULL;
PFN_vkRegisterDeviceEventEXT glad_vkRegisterDeviceEventEXT = NULL;
PFN_vkRegisterDisplayEventEXT glad_vkRegisterDisplayEventEXT = NULL;
PFN_vkReleaseDisplayEXT glad_vkReleaseDisplayEXT = NULL;
PFN_vkReleaseProfilingLockKHR glad_vkReleaseProfilingLockKHR = NULL;
PFN_vkResetQueryPool glad_vkResetQueryPool = NULL;
PFN_vkSetDebugUtilsObjectNameEXT glad_vkSetDebugUtilsObjectNameEXT = NULL;
PFN_vkSetDebugUtilsObjectTagEXT glad_vkSetDebugUtilsObjectTagEXT = NULL;
PFN_vkSetHdrMetadataEXT glad_vkSetHdrMetadataEXT = NULL;
PFN_vkSetPrivateData glad_vkSetPrivateData = NULL;
PFN_vkSignalSemaphore glad_vkSignalSemaphore = NULL;
PFN_vkSubmitDebugUtilsMessageEXT glad_vkSubmitDebugUtilsMessageEXT = NULL;
PFN_vkTransitionImageLayout glad_vkTransitionImageLayout = NULL;
PFN_vkTrimCommandPool glad_vkTrimCommandPool = NULL;
PFN_vkUnmapMemory2 glad_vkUnmapMemory2 = NULL;
PFN_vkUpdateDescriptorSetWithTemplate glad_vkUpdateDescriptorSetWithTemplate = NULL;
PFN_vkWaitSemaphores glad_vkWaitSemaphores = NULL;


static void glad_vk_load_VKSC_VERSION_1_0( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VKSC_VERSION_1_0) return;
    glad_vkGetCommandPoolMemoryConsumption = (PFN_vkGetCommandPoolMemoryConsumption) load(userptr, "vkGetCommandPoolMemoryConsumption");
    glad_vkGetFaultData = (PFN_vkGetFaultData) load(userptr, "vkGetFaultData");
}
static void glad_vk_load_VK_VERSION_1_1( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_VERSION_1_1) return;
    glad_vkBindBufferMemory2 = (PFN_vkBindBufferMemory2) load(userptr, "vkBindBufferMemory2");
    glad_vkBindImageMemory2 = (PFN_vkBindImageMemory2) load(userptr, "vkBindImageMemory2");
    glad_vkCmdDispatchBase = (PFN_vkCmdDispatchBase) load(userptr, "vkCmdDispatchBase");
    glad_vkCmdSetDeviceMask = (PFN_vkCmdSetDeviceMask) load(userptr, "vkCmdSetDeviceMask");
    glad_vkCreateDescriptorUpdateTemplate = (PFN_vkCreateDescriptorUpdateTemplate) load(userptr, "vkCreateDescriptorUpdateTemplate");
    glad_vkCreateSamplerYcbcrConversion = (PFN_vkCreateSamplerYcbcrConversion) load(userptr, "vkCreateSamplerYcbcrConversion");
    glad_vkDestroyDescriptorUpdateTemplate = (PFN_vkDestroyDescriptorUpdateTemplate) load(userptr, "vkDestroyDescriptorUpdateTemplate");
    glad_vkDestroySamplerYcbcrConversion = (PFN_vkDestroySamplerYcbcrConversion) load(userptr, "vkDestroySamplerYcbcrConversion");
    glad_vkEnumerateInstanceVersion = (PFN_vkEnumerateInstanceVersion) load(userptr, "vkEnumerateInstanceVersion");
    glad_vkEnumeratePhysicalDeviceGroups = (PFN_vkEnumeratePhysicalDeviceGroups) load(userptr, "vkEnumeratePhysicalDeviceGroups");
    glad_vkGetBufferMemoryRequirements2 = (PFN_vkGetBufferMemoryRequirements2) load(userptr, "vkGetBufferMemoryRequirements2");
    glad_vkGetDescriptorSetLayoutSupport = (PFN_vkGetDescriptorSetLayoutSupport) load(userptr, "vkGetDescriptorSetLayoutSupport");
    glad_vkGetDeviceGroupPeerMemoryFeatures = (PFN_vkGetDeviceGroupPeerMemoryFeatures) load(userptr, "vkGetDeviceGroupPeerMemoryFeatures");
    glad_vkGetDeviceQueue2 = (PFN_vkGetDeviceQueue2) load(userptr, "vkGetDeviceQueue2");
    glad_vkGetImageMemoryRequirements2 = (PFN_vkGetImageMemoryRequirements2) load(userptr, "vkGetImageMemoryRequirements2");
    glad_vkGetImageSparseMemoryRequirements2 = (PFN_vkGetImageSparseMemoryRequirements2) load(userptr, "vkGetImageSparseMemoryRequirements2");
    glad_vkGetPhysicalDeviceExternalBufferProperties = (PFN_vkGetPhysicalDeviceExternalBufferProperties) load(userptr, "vkGetPhysicalDeviceExternalBufferProperties");
    glad_vkGetPhysicalDeviceExternalFenceProperties = (PFN_vkGetPhysicalDeviceExternalFenceProperties) load(userptr, "vkGetPhysicalDeviceExternalFenceProperties");
    glad_vkGetPhysicalDeviceExternalSemaphoreProperties = (PFN_vkGetPhysicalDeviceExternalSemaphoreProperties) load(userptr, "vkGetPhysicalDeviceExternalSemaphoreProperties");
    glad_vkGetPhysicalDeviceFeatures2 = (PFN_vkGetPhysicalDeviceFeatures2) load(userptr, "vkGetPhysicalDeviceFeatures2");
    glad_vkGetPhysicalDeviceFormatProperties2 = (PFN_vkGetPhysicalDeviceFormatProperties2) load(userptr, "vkGetPhysicalDeviceFormatProperties2");
    glad_vkGetPhysicalDeviceImageFormatProperties2 = (PFN_vkGetPhysicalDeviceImageFormatProperties2) load(userptr, "vkGetPhysicalDeviceImageFormatProperties2");
    glad_vkGetPhysicalDeviceMemoryProperties2 = (PFN_vkGetPhysicalDeviceMemoryProperties2) load(userptr, "vkGetPhysicalDeviceMemoryProperties2");
    glad_vkGetPhysicalDeviceProperties2 = (PFN_vkGetPhysicalDeviceProperties2) load(userptr, "vkGetPhysicalDeviceProperties2");
    glad_vkGetPhysicalDeviceQueueFamilyProperties2 = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2) load(userptr, "vkGetPhysicalDeviceQueueFamilyProperties2");
    glad_vkGetPhysicalDeviceSparseImageFormatProperties2 = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2) load(userptr, "vkGetPhysicalDeviceSparseImageFormatProperties2");
    glad_vkTrimCommandPool = (PFN_vkTrimCommandPool) load(userptr, "vkTrimCommandPool");
    glad_vkUpdateDescriptorSetWithTemplate = (PFN_vkUpdateDescriptorSetWithTemplate) load(userptr, "vkUpdateDescriptorSetWithTemplate");
}
static void glad_vk_load_VK_VERSION_1_2( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_VERSION_1_2) return;
    glad_vkCmdBeginRenderPass2 = (PFN_vkCmdBeginRenderPass2) load(userptr, "vkCmdBeginRenderPass2");
    glad_vkCmdDrawIndexedIndirectCount = (PFN_vkCmdDrawIndexedIndirectCount) load(userptr, "vkCmdDrawIndexedIndirectCount");
    glad_vkCmdDrawIndirectCount = (PFN_vkCmdDrawIndirectCount) load(userptr, "vkCmdDrawIndirectCount");
    glad_vkCmdEndRenderPass2 = (PFN_vkCmdEndRenderPass2) load(userptr, "vkCmdEndRenderPass2");
    glad_vkCmdNextSubpass2 = (PFN_vkCmdNextSubpass2) load(userptr, "vkCmdNextSubpass2");
    glad_vkCreateRenderPass2 = (PFN_vkCreateRenderPass2) load(userptr, "vkCreateRenderPass2");
    glad_vkGetBufferDeviceAddress = (PFN_vkGetBufferDeviceAddress) load(userptr, "vkGetBufferDeviceAddress");
    glad_vkGetBufferOpaqueCaptureAddress = (PFN_vkGetBufferOpaqueCaptureAddress) load(userptr, "vkGetBufferOpaqueCaptureAddress");
    glad_vkGetDeviceMemoryOpaqueCaptureAddress = (PFN_vkGetDeviceMemoryOpaqueCaptureAddress) load(userptr, "vkGetDeviceMemoryOpaqueCaptureAddress");
    glad_vkGetSemaphoreCounterValue = (PFN_vkGetSemaphoreCounterValue) load(userptr, "vkGetSemaphoreCounterValue");
    glad_vkResetQueryPool = (PFN_vkResetQueryPool) load(userptr, "vkResetQueryPool");
    glad_vkSignalSemaphore = (PFN_vkSignalSemaphore) load(userptr, "vkSignalSemaphore");
    glad_vkWaitSemaphores = (PFN_vkWaitSemaphores) load(userptr, "vkWaitSemaphores");
}
static void glad_vk_load_VK_VERSION_1_3( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_VERSION_1_3) return;
    glad_vkCmdBeginRendering = (PFN_vkCmdBeginRendering) load(userptr, "vkCmdBeginRendering");
    glad_vkCmdBindVertexBuffers2 = (PFN_vkCmdBindVertexBuffers2) load(userptr, "vkCmdBindVertexBuffers2");
    glad_vkCmdBlitImage2 = (PFN_vkCmdBlitImage2) load(userptr, "vkCmdBlitImage2");
    glad_vkCmdCopyBuffer2 = (PFN_vkCmdCopyBuffer2) load(userptr, "vkCmdCopyBuffer2");
    glad_vkCmdCopyBufferToImage2 = (PFN_vkCmdCopyBufferToImage2) load(userptr, "vkCmdCopyBufferToImage2");
    glad_vkCmdCopyImage2 = (PFN_vkCmdCopyImage2) load(userptr, "vkCmdCopyImage2");
    glad_vkCmdCopyImageToBuffer2 = (PFN_vkCmdCopyImageToBuffer2) load(userptr, "vkCmdCopyImageToBuffer2");
    glad_vkCmdEndRendering = (PFN_vkCmdEndRendering) load(userptr, "vkCmdEndRendering");
    glad_vkCmdPipelineBarrier2 = (PFN_vkCmdPipelineBarrier2) load(userptr, "vkCmdPipelineBarrier2");
    glad_vkCmdResetEvent2 = (PFN_vkCmdResetEvent2) load(userptr, "vkCmdResetEvent2");
    glad_vkCmdResolveImage2 = (PFN_vkCmdResolveImage2) load(userptr, "vkCmdResolveImage2");
    glad_vkCmdSetCullMode = (PFN_vkCmdSetCullMode) load(userptr, "vkCmdSetCullMode");
    glad_vkCmdSetDepthBiasEnable = (PFN_vkCmdSetDepthBiasEnable) load(userptr, "vkCmdSetDepthBiasEnable");
    glad_vkCmdSetDepthBoundsTestEnable = (PFN_vkCmdSetDepthBoundsTestEnable) load(userptr, "vkCmdSetDepthBoundsTestEnable");
    glad_vkCmdSetDepthCompareOp = (PFN_vkCmdSetDepthCompareOp) load(userptr, "vkCmdSetDepthCompareOp");
    glad_vkCmdSetDepthTestEnable = (PFN_vkCmdSetDepthTestEnable) load(userptr, "vkCmdSetDepthTestEnable");
    glad_vkCmdSetDepthWriteEnable = (PFN_vkCmdSetDepthWriteEnable) load(userptr, "vkCmdSetDepthWriteEnable");
    glad_vkCmdSetEvent2 = (PFN_vkCmdSetEvent2) load(userptr, "vkCmdSetEvent2");
    glad_vkCmdSetFrontFace = (PFN_vkCmdSetFrontFace) load(userptr, "vkCmdSetFrontFace");
    glad_vkCmdSetPrimitiveRestartEnable = (PFN_vkCmdSetPrimitiveRestartEnable) load(userptr, "vkCmdSetPrimitiveRestartEnable");
    glad_vkCmdSetPrimitiveTopology = (PFN_vkCmdSetPrimitiveTopology) load(userptr, "vkCmdSetPrimitiveTopology");
    glad_vkCmdSetRasterizerDiscardEnable = (PFN_vkCmdSetRasterizerDiscardEnable) load(userptr, "vkCmdSetRasterizerDiscardEnable");
    glad_vkCmdSetScissorWithCount = (PFN_vkCmdSetScissorWithCount) load(userptr, "vkCmdSetScissorWithCount");
    glad_vkCmdSetStencilOp = (PFN_vkCmdSetStencilOp) load(userptr, "vkCmdSetStencilOp");
    glad_vkCmdSetStencilTestEnable = (PFN_vkCmdSetStencilTestEnable) load(userptr, "vkCmdSetStencilTestEnable");
    glad_vkCmdSetViewportWithCount = (PFN_vkCmdSetViewportWithCount) load(userptr, "vkCmdSetViewportWithCount");
    glad_vkCmdWaitEvents2 = (PFN_vkCmdWaitEvents2) load(userptr, "vkCmdWaitEvents2");
    glad_vkCmdWriteTimestamp2 = (PFN_vkCmdWriteTimestamp2) load(userptr, "vkCmdWriteTimestamp2");
    glad_vkCreatePrivateDataSlot = (PFN_vkCreatePrivateDataSlot) load(userptr, "vkCreatePrivateDataSlot");
    glad_vkDestroyPrivateDataSlot = (PFN_vkDestroyPrivateDataSlot) load(userptr, "vkDestroyPrivateDataSlot");
    glad_vkGetDeviceBufferMemoryRequirements = (PFN_vkGetDeviceBufferMemoryRequirements) load(userptr, "vkGetDeviceBufferMemoryRequirements");
    glad_vkGetDeviceImageMemoryRequirements = (PFN_vkGetDeviceImageMemoryRequirements) load(userptr, "vkGetDeviceImageMemoryRequirements");
    glad_vkGetDeviceImageSparseMemoryRequirements = (PFN_vkGetDeviceImageSparseMemoryRequirements) load(userptr, "vkGetDeviceImageSparseMemoryRequirements");
    glad_vkGetPhysicalDeviceToolProperties = (PFN_vkGetPhysicalDeviceToolProperties) load(userptr, "vkGetPhysicalDeviceToolProperties");
    glad_vkGetPrivateData = (PFN_vkGetPrivateData) load(userptr, "vkGetPrivateData");
    glad_vkQueueSubmit2 = (PFN_vkQueueSubmit2) load(userptr, "vkQueueSubmit2");
    glad_vkSetPrivateData = (PFN_vkSetPrivateData) load(userptr, "vkSetPrivateData");
}
static void glad_vk_load_VK_VERSION_1_4( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_VERSION_1_4) return;
    glad_vkCmdBindDescriptorSets2 = (PFN_vkCmdBindDescriptorSets2) load(userptr, "vkCmdBindDescriptorSets2");
    glad_vkCmdBindIndexBuffer2 = (PFN_vkCmdBindIndexBuffer2) load(userptr, "vkCmdBindIndexBuffer2");
    glad_vkCmdPushConstants2 = (PFN_vkCmdPushConstants2) load(userptr, "vkCmdPushConstants2");
    glad_vkCmdPushDescriptorSet = (PFN_vkCmdPushDescriptorSet) load(userptr, "vkCmdPushDescriptorSet");
    glad_vkCmdPushDescriptorSet2 = (PFN_vkCmdPushDescriptorSet2) load(userptr, "vkCmdPushDescriptorSet2");
    glad_vkCmdPushDescriptorSetWithTemplate = (PFN_vkCmdPushDescriptorSetWithTemplate) load(userptr, "vkCmdPushDescriptorSetWithTemplate");
    glad_vkCmdPushDescriptorSetWithTemplate2 = (PFN_vkCmdPushDescriptorSetWithTemplate2) load(userptr, "vkCmdPushDescriptorSetWithTemplate2");
    glad_vkCmdSetLineStipple = (PFN_vkCmdSetLineStipple) load(userptr, "vkCmdSetLineStipple");
    glad_vkCmdSetRenderingAttachmentLocations = (PFN_vkCmdSetRenderingAttachmentLocations) load(userptr, "vkCmdSetRenderingAttachmentLocations");
    glad_vkCmdSetRenderingInputAttachmentIndices = (PFN_vkCmdSetRenderingInputAttachmentIndices) load(userptr, "vkCmdSetRenderingInputAttachmentIndices");
    glad_vkCopyImageToImage = (PFN_vkCopyImageToImage) load(userptr, "vkCopyImageToImage");
    glad_vkCopyImageToMemory = (PFN_vkCopyImageToMemory) load(userptr, "vkCopyImageToMemory");
    glad_vkCopyMemoryToImage = (PFN_vkCopyMemoryToImage) load(userptr, "vkCopyMemoryToImage");
    glad_vkGetDeviceImageSubresourceLayout = (PFN_vkGetDeviceImageSubresourceLayout) load(userptr, "vkGetDeviceImageSubresourceLayout");
    glad_vkGetImageSubresourceLayout2 = (PFN_vkGetImageSubresourceLayout2) load(userptr, "vkGetImageSubresourceLayout2");
    glad_vkGetRenderingAreaGranularity = (PFN_vkGetRenderingAreaGranularity) load(userptr, "vkGetRenderingAreaGranularity");
    glad_vkMapMemory2 = (PFN_vkMapMemory2) load(userptr, "vkMapMemory2");
    glad_vkTransitionImageLayout = (PFN_vkTransitionImageLayout) load(userptr, "vkTransitionImageLayout");
    glad_vkUnmapMemory2 = (PFN_vkUnmapMemory2) load(userptr, "vkUnmapMemory2");
}
static void glad_vk_load_VK_EXT_color_write_enable( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_color_write_enable) return;
    glad_vkCmdSetColorWriteEnableEXT = (PFN_vkCmdSetColorWriteEnableEXT) load(userptr, "vkCmdSetColorWriteEnableEXT");
}
static void glad_vk_load_VK_EXT_debug_utils( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_debug_utils) return;
    glad_vkCmdBeginDebugUtilsLabelEXT = (PFN_vkCmdBeginDebugUtilsLabelEXT) load(userptr, "vkCmdBeginDebugUtilsLabelEXT");
    glad_vkCmdEndDebugUtilsLabelEXT = (PFN_vkCmdEndDebugUtilsLabelEXT) load(userptr, "vkCmdEndDebugUtilsLabelEXT");
    glad_vkCmdInsertDebugUtilsLabelEXT = (PFN_vkCmdInsertDebugUtilsLabelEXT) load(userptr, "vkCmdInsertDebugUtilsLabelEXT");
    glad_vkCreateDebugUtilsMessengerEXT = (PFN_vkCreateDebugUtilsMessengerEXT) load(userptr, "vkCreateDebugUtilsMessengerEXT");
    glad_vkDestroyDebugUtilsMessengerEXT = (PFN_vkDestroyDebugUtilsMessengerEXT) load(userptr, "vkDestroyDebugUtilsMessengerEXT");
    glad_vkQueueBeginDebugUtilsLabelEXT = (PFN_vkQueueBeginDebugUtilsLabelEXT) load(userptr, "vkQueueBeginDebugUtilsLabelEXT");
    glad_vkQueueEndDebugUtilsLabelEXT = (PFN_vkQueueEndDebugUtilsLabelEXT) load(userptr, "vkQueueEndDebugUtilsLabelEXT");
    glad_vkQueueInsertDebugUtilsLabelEXT = (PFN_vkQueueInsertDebugUtilsLabelEXT) load(userptr, "vkQueueInsertDebugUtilsLabelEXT");
    glad_vkSetDebugUtilsObjectNameEXT = (PFN_vkSetDebugUtilsObjectNameEXT) load(userptr, "vkSetDebugUtilsObjectNameEXT");
    glad_vkSetDebugUtilsObjectTagEXT = (PFN_vkSetDebugUtilsObjectTagEXT) load(userptr, "vkSetDebugUtilsObjectTagEXT");
    glad_vkSubmitDebugUtilsMessageEXT = (PFN_vkSubmitDebugUtilsMessageEXT) load(userptr, "vkSubmitDebugUtilsMessageEXT");
}
static void glad_vk_load_VK_EXT_direct_mode_display( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_direct_mode_display) return;
    glad_vkReleaseDisplayEXT = (PFN_vkReleaseDisplayEXT) load(userptr, "vkReleaseDisplayEXT");
}
static void glad_vk_load_VK_EXT_discard_rectangles( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_discard_rectangles) return;
    glad_vkCmdSetDiscardRectangleEXT = (PFN_vkCmdSetDiscardRectangleEXT) load(userptr, "vkCmdSetDiscardRectangleEXT");
    glad_vkCmdSetDiscardRectangleEnableEXT = (PFN_vkCmdSetDiscardRectangleEnableEXT) load(userptr, "vkCmdSetDiscardRectangleEnableEXT");
    glad_vkCmdSetDiscardRectangleModeEXT = (PFN_vkCmdSetDiscardRectangleModeEXT) load(userptr, "vkCmdSetDiscardRectangleModeEXT");
}
static void glad_vk_load_VK_EXT_display_control( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_display_control) return;
    glad_vkDisplayPowerControlEXT = (PFN_vkDisplayPowerControlEXT) load(userptr, "vkDisplayPowerControlEXT");
    glad_vkGetSwapchainCounterEXT = (PFN_vkGetSwapchainCounterEXT) load(userptr, "vkGetSwapchainCounterEXT");
    glad_vkRegisterDeviceEventEXT = (PFN_vkRegisterDeviceEventEXT) load(userptr, "vkRegisterDeviceEventEXT");
    glad_vkRegisterDisplayEventEXT = (PFN_vkRegisterDisplayEventEXT) load(userptr, "vkRegisterDisplayEventEXT");
}
static void glad_vk_load_VK_EXT_display_surface_counter( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_display_surface_counter) return;
    glad_vkGetPhysicalDeviceSurfaceCapabilities2EXT = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT) load(userptr, "vkGetPhysicalDeviceSurfaceCapabilities2EXT");
}
static void glad_vk_load_VK_EXT_extended_dynamic_state( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_extended_dynamic_state) return;
    glad_vkCmdBindVertexBuffers2EXT = (PFN_vkCmdBindVertexBuffers2EXT) load(userptr, "vkCmdBindVertexBuffers2EXT");
    glad_vkCmdSetCullModeEXT = (PFN_vkCmdSetCullModeEXT) load(userptr, "vkCmdSetCullModeEXT");
    glad_vkCmdSetDepthBoundsTestEnableEXT = (PFN_vkCmdSetDepthBoundsTestEnableEXT) load(userptr, "vkCmdSetDepthBoundsTestEnableEXT");
    glad_vkCmdSetDepthCompareOpEXT = (PFN_vkCmdSetDepthCompareOpEXT) load(userptr, "vkCmdSetDepthCompareOpEXT");
    glad_vkCmdSetDepthTestEnableEXT = (PFN_vkCmdSetDepthTestEnableEXT) load(userptr, "vkCmdSetDepthTestEnableEXT");
    glad_vkCmdSetDepthWriteEnableEXT = (PFN_vkCmdSetDepthWriteEnableEXT) load(userptr, "vkCmdSetDepthWriteEnableEXT");
    glad_vkCmdSetFrontFaceEXT = (PFN_vkCmdSetFrontFaceEXT) load(userptr, "vkCmdSetFrontFaceEXT");
    glad_vkCmdSetPrimitiveTopologyEXT = (PFN_vkCmdSetPrimitiveTopologyEXT) load(userptr, "vkCmdSetPrimitiveTopologyEXT");
    glad_vkCmdSetScissorWithCountEXT = (PFN_vkCmdSetScissorWithCountEXT) load(userptr, "vkCmdSetScissorWithCountEXT");
    glad_vkCmdSetStencilOpEXT = (PFN_vkCmdSetStencilOpEXT) load(userptr, "vkCmdSetStencilOpEXT");
    glad_vkCmdSetStencilTestEnableEXT = (PFN_vkCmdSetStencilTestEnableEXT) load(userptr, "vkCmdSetStencilTestEnableEXT");
    glad_vkCmdSetViewportWithCountEXT = (PFN_vkCmdSetViewportWithCountEXT) load(userptr, "vkCmdSetViewportWithCountEXT");
}
static void glad_vk_load_VK_EXT_extended_dynamic_state2( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_extended_dynamic_state2) return;
    glad_vkCmdSetDepthBiasEnableEXT = (PFN_vkCmdSetDepthBiasEnableEXT) load(userptr, "vkCmdSetDepthBiasEnableEXT");
    glad_vkCmdSetLogicOpEXT = (PFN_vkCmdSetLogicOpEXT) load(userptr, "vkCmdSetLogicOpEXT");
    glad_vkCmdSetPatchControlPointsEXT = (PFN_vkCmdSetPatchControlPointsEXT) load(userptr, "vkCmdSetPatchControlPointsEXT");
    glad_vkCmdSetPrimitiveRestartEnableEXT = (PFN_vkCmdSetPrimitiveRestartEnableEXT) load(userptr, "vkCmdSetPrimitiveRestartEnableEXT");
    glad_vkCmdSetRasterizerDiscardEnableEXT = (PFN_vkCmdSetRasterizerDiscardEnableEXT) load(userptr, "vkCmdSetRasterizerDiscardEnableEXT");
}
static void glad_vk_load_VK_EXT_external_memory_host( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_external_memory_host) return;
    glad_vkGetMemoryHostPointerPropertiesEXT = (PFN_vkGetMemoryHostPointerPropertiesEXT) load(userptr, "vkGetMemoryHostPointerPropertiesEXT");
}
static void glad_vk_load_VK_EXT_hdr_metadata( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_hdr_metadata) return;
    glad_vkSetHdrMetadataEXT = (PFN_vkSetHdrMetadataEXT) load(userptr, "vkSetHdrMetadataEXT");
}
static void glad_vk_load_VK_EXT_headless_surface( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_headless_surface) return;
    glad_vkCreateHeadlessSurfaceEXT = (PFN_vkCreateHeadlessSurfaceEXT) load(userptr, "vkCreateHeadlessSurfaceEXT");
}
static void glad_vk_load_VK_EXT_image_drm_format_modifier( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_image_drm_format_modifier) return;
    glad_vkGetImageDrmFormatModifierPropertiesEXT = (PFN_vkGetImageDrmFormatModifierPropertiesEXT) load(userptr, "vkGetImageDrmFormatModifierPropertiesEXT");
}
static void glad_vk_load_VK_EXT_line_rasterization( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_line_rasterization) return;
    glad_vkCmdSetLineStippleEXT = (PFN_vkCmdSetLineStippleEXT) load(userptr, "vkCmdSetLineStippleEXT");
}
static void glad_vk_load_VK_EXT_sample_locations( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_sample_locations) return;
    glad_vkCmdSetSampleLocationsEXT = (PFN_vkCmdSetSampleLocationsEXT) load(userptr, "vkCmdSetSampleLocationsEXT");
    glad_vkGetPhysicalDeviceMultisamplePropertiesEXT = (PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT) load(userptr, "vkGetPhysicalDeviceMultisamplePropertiesEXT");
}
static void glad_vk_load_VK_EXT_vertex_input_dynamic_state( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_vertex_input_dynamic_state) return;
    glad_vkCmdSetVertexInputEXT = (PFN_vkCmdSetVertexInputEXT) load(userptr, "vkCmdSetVertexInputEXT");
}
static void glad_vk_load_VK_KHR_calibrated_timestamps( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_calibrated_timestamps) return;
    glad_vkGetCalibratedTimestampsKHR = (PFN_vkGetCalibratedTimestampsKHR) load(userptr, "vkGetCalibratedTimestampsKHR");
    glad_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR = (PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR) load(userptr, "vkGetPhysicalDeviceCalibrateableTimeDomainsKHR");
}
static void glad_vk_load_VK_KHR_copy_commands2( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_copy_commands2) return;
    glad_vkCmdBlitImage2KHR = (PFN_vkCmdBlitImage2KHR) load(userptr, "vkCmdBlitImage2KHR");
    glad_vkCmdCopyBuffer2KHR = (PFN_vkCmdCopyBuffer2KHR) load(userptr, "vkCmdCopyBuffer2KHR");
    glad_vkCmdCopyBufferToImage2KHR = (PFN_vkCmdCopyBufferToImage2KHR) load(userptr, "vkCmdCopyBufferToImage2KHR");
    glad_vkCmdCopyImage2KHR = (PFN_vkCmdCopyImage2KHR) load(userptr, "vkCmdCopyImage2KHR");
    glad_vkCmdCopyImageToBuffer2KHR = (PFN_vkCmdCopyImageToBuffer2KHR) load(userptr, "vkCmdCopyImageToBuffer2KHR");
    glad_vkCmdResolveImage2KHR = (PFN_vkCmdResolveImage2KHR) load(userptr, "vkCmdResolveImage2KHR");
}
static void glad_vk_load_VK_KHR_display( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_display) return;
    glad_vkCreateDisplayModeKHR = (PFN_vkCreateDisplayModeKHR) load(userptr, "vkCreateDisplayModeKHR");
    glad_vkCreateDisplayPlaneSurfaceKHR = (PFN_vkCreateDisplayPlaneSurfaceKHR) load(userptr, "vkCreateDisplayPlaneSurfaceKHR");
    glad_vkGetDisplayModePropertiesKHR = (PFN_vkGetDisplayModePropertiesKHR) load(userptr, "vkGetDisplayModePropertiesKHR");
    glad_vkGetDisplayPlaneCapabilitiesKHR = (PFN_vkGetDisplayPlaneCapabilitiesKHR) load(userptr, "vkGetDisplayPlaneCapabilitiesKHR");
    glad_vkGetDisplayPlaneSupportedDisplaysKHR = (PFN_vkGetDisplayPlaneSupportedDisplaysKHR) load(userptr, "vkGetDisplayPlaneSupportedDisplaysKHR");
    glad_vkGetPhysicalDeviceDisplayPlanePropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR) load(userptr, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
    glad_vkGetPhysicalDeviceDisplayPropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPropertiesKHR) load(userptr, "vkGetPhysicalDeviceDisplayPropertiesKHR");
}
static void glad_vk_load_VK_KHR_display_swapchain( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_display_swapchain) return;
    glad_vkCreateSharedSwapchainsKHR = (PFN_vkCreateSharedSwapchainsKHR) load(userptr, "vkCreateSharedSwapchainsKHR");
}
static void glad_vk_load_VK_KHR_external_fence_fd( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_external_fence_fd) return;
    glad_vkGetFenceFdKHR = (PFN_vkGetFenceFdKHR) load(userptr, "vkGetFenceFdKHR");
    glad_vkImportFenceFdKHR = (PFN_vkImportFenceFdKHR) load(userptr, "vkImportFenceFdKHR");
}
static void glad_vk_load_VK_KHR_external_memory_fd( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_external_memory_fd) return;
    glad_vkGetMemoryFdKHR = (PFN_vkGetMemoryFdKHR) load(userptr, "vkGetMemoryFdKHR");
    glad_vkGetMemoryFdPropertiesKHR = (PFN_vkGetMemoryFdPropertiesKHR) load(userptr, "vkGetMemoryFdPropertiesKHR");
}
static void glad_vk_load_VK_KHR_external_semaphore_fd( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_external_semaphore_fd) return;
    glad_vkGetSemaphoreFdKHR = (PFN_vkGetSemaphoreFdKHR) load(userptr, "vkGetSemaphoreFdKHR");
    glad_vkImportSemaphoreFdKHR = (PFN_vkImportSemaphoreFdKHR) load(userptr, "vkImportSemaphoreFdKHR");
}
static void glad_vk_load_VK_KHR_fragment_shading_rate( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_fragment_shading_rate) return;
    glad_vkCmdSetFragmentShadingRateKHR = (PFN_vkCmdSetFragmentShadingRateKHR) load(userptr, "vkCmdSetFragmentShadingRateKHR");
    glad_vkGetPhysicalDeviceFragmentShadingRatesKHR = (PFN_vkGetPhysicalDeviceFragmentShadingRatesKHR) load(userptr, "vkGetPhysicalDeviceFragmentShadingRatesKHR");
}
static void glad_vk_load_VK_KHR_get_display_properties2( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_get_display_properties2) return;
    glad_vkGetDisplayModeProperties2KHR = (PFN_vkGetDisplayModeProperties2KHR) load(userptr, "vkGetDisplayModeProperties2KHR");
    glad_vkGetDisplayPlaneCapabilities2KHR = (PFN_vkGetDisplayPlaneCapabilities2KHR) load(userptr, "vkGetDisplayPlaneCapabilities2KHR");
    glad_vkGetPhysicalDeviceDisplayPlaneProperties2KHR = (PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR) load(userptr, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
    glad_vkGetPhysicalDeviceDisplayProperties2KHR = (PFN_vkGetPhysicalDeviceDisplayProperties2KHR) load(userptr, "vkGetPhysicalDeviceDisplayProperties2KHR");
}
static void glad_vk_load_VK_KHR_get_surface_capabilities2( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_get_surface_capabilities2) return;
    glad_vkGetPhysicalDeviceSurfaceCapabilities2KHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR) load(userptr, "vkGetPhysicalDeviceSurfaceCapabilities2KHR");
    glad_vkGetPhysicalDeviceSurfaceFormats2KHR = (PFN_vkGetPhysicalDeviceSurfaceFormats2KHR) load(userptr, "vkGetPhysicalDeviceSurfaceFormats2KHR");
}
static void glad_vk_load_VK_KHR_line_rasterization( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_line_rasterization) return;
    glad_vkCmdSetLineStippleKHR = (PFN_vkCmdSetLineStippleKHR) load(userptr, "vkCmdSetLineStippleKHR");
}
static void glad_vk_load_VK_KHR_object_refresh( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_object_refresh) return;
    glad_vkCmdRefreshObjectsKHR = (PFN_vkCmdRefreshObjectsKHR) load(userptr, "vkCmdRefreshObjectsKHR");
    glad_vkGetPhysicalDeviceRefreshableObjectTypesKHR = (PFN_vkGetPhysicalDeviceRefreshableObjectTypesKHR) load(userptr, "vkGetPhysicalDeviceRefreshableObjectTypesKHR");
}
static void glad_vk_load_VK_KHR_performance_query( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_performance_query) return;
    glad_vkAcquireProfilingLockKHR = (PFN_vkAcquireProfilingLockKHR) load(userptr, "vkAcquireProfilingLockKHR");
    glad_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR = (PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR) load(userptr, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR");
    glad_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR = (PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR) load(userptr, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR");
    glad_vkReleaseProfilingLockKHR = (PFN_vkReleaseProfilingLockKHR) load(userptr, "vkReleaseProfilingLockKHR");
}
static void glad_vk_load_VK_KHR_shared_presentable_image( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_shared_presentable_image) return;
    glad_vkGetSwapchainStatusKHR = (PFN_vkGetSwapchainStatusKHR) load(userptr, "vkGetSwapchainStatusKHR");
}
static void glad_vk_load_VK_KHR_surface( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_surface) return;
    glad_vkDestroySurfaceKHR = (PFN_vkDestroySurfaceKHR) load(userptr, "vkDestroySurfaceKHR");
    glad_vkGetPhysicalDeviceSurfaceCapabilitiesKHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR) load(userptr, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
    glad_vkGetPhysicalDeviceSurfaceFormatsKHR = (PFN_vkGetPhysicalDeviceSurfaceFormatsKHR) load(userptr, "vkGetPhysicalDeviceSurfaceFormatsKHR");
    glad_vkGetPhysicalDeviceSurfacePresentModesKHR = (PFN_vkGetPhysicalDeviceSurfacePresentModesKHR) load(userptr, "vkGetPhysicalDeviceSurfacePresentModesKHR");
    glad_vkGetPhysicalDeviceSurfaceSupportKHR = (PFN_vkGetPhysicalDeviceSurfaceSupportKHR) load(userptr, "vkGetPhysicalDeviceSurfaceSupportKHR");
}
static void glad_vk_load_VK_KHR_swapchain( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_swapchain) return;
    glad_vkAcquireNextImage2KHR = (PFN_vkAcquireNextImage2KHR) load(userptr, "vkAcquireNextImage2KHR");
    glad_vkAcquireNextImageKHR = (PFN_vkAcquireNextImageKHR) load(userptr, "vkAcquireNextImageKHR");
    glad_vkCreateSwapchainKHR = (PFN_vkCreateSwapchainKHR) load(userptr, "vkCreateSwapchainKHR");
    glad_vkDestroySwapchainKHR = (PFN_vkDestroySwapchainKHR) load(userptr, "vkDestroySwapchainKHR");
    glad_vkGetDeviceGroupPresentCapabilitiesKHR = (PFN_vkGetDeviceGroupPresentCapabilitiesKHR) load(userptr, "vkGetDeviceGroupPresentCapabilitiesKHR");
    glad_vkGetDeviceGroupSurfacePresentModesKHR = (PFN_vkGetDeviceGroupSurfacePresentModesKHR) load(userptr, "vkGetDeviceGroupSurfacePresentModesKHR");
    glad_vkGetPhysicalDevicePresentRectanglesKHR = (PFN_vkGetPhysicalDevicePresentRectanglesKHR) load(userptr, "vkGetPhysicalDevicePresentRectanglesKHR");
    glad_vkGetSwapchainImagesKHR = (PFN_vkGetSwapchainImagesKHR) load(userptr, "vkGetSwapchainImagesKHR");
    glad_vkQueuePresentKHR = (PFN_vkQueuePresentKHR) load(userptr, "vkQueuePresentKHR");
}
static void glad_vk_load_VK_KHR_synchronization2( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_synchronization2) return;
    glad_vkCmdPipelineBarrier2KHR = (PFN_vkCmdPipelineBarrier2KHR) load(userptr, "vkCmdPipelineBarrier2KHR");
    glad_vkCmdResetEvent2KHR = (PFN_vkCmdResetEvent2KHR) load(userptr, "vkCmdResetEvent2KHR");
    glad_vkCmdSetEvent2KHR = (PFN_vkCmdSetEvent2KHR) load(userptr, "vkCmdSetEvent2KHR");
    glad_vkCmdWaitEvents2KHR = (PFN_vkCmdWaitEvents2KHR) load(userptr, "vkCmdWaitEvents2KHR");
    glad_vkCmdWriteTimestamp2KHR = (PFN_vkCmdWriteTimestamp2KHR) load(userptr, "vkCmdWriteTimestamp2KHR");
    glad_vkQueueSubmit2KHR = (PFN_vkQueueSubmit2KHR) load(userptr, "vkQueueSubmit2KHR");
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
static void glad_vk_load_VK_NV_acquire_winrt_display( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_NV_acquire_winrt_display) return;
    glad_vkAcquireWinrtDisplayNV = (PFN_vkAcquireWinrtDisplayNV) load(userptr, "vkAcquireWinrtDisplayNV");
    glad_vkGetWinrtDisplayNV = (PFN_vkGetWinrtDisplayNV) load(userptr, "vkGetWinrtDisplayNV");
}

#endif
#if defined(VK_USE_PLATFORM_SCI)
static void glad_vk_load_VK_NV_external_memory_sci_buf( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_NV_external_memory_sci_buf) return;
    glad_vkGetMemorySciBufNV = (PFN_vkGetMemorySciBufNV) load(userptr, "vkGetMemorySciBufNV");
    glad_vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV = (PFN_vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV) load(userptr, "vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV");
    glad_vkGetPhysicalDeviceSciBufAttributesNV = (PFN_vkGetPhysicalDeviceSciBufAttributesNV) load(userptr, "vkGetPhysicalDeviceSciBufAttributesNV");
}

#endif
#if defined(VK_USE_PLATFORM_SCI)
static void glad_vk_load_VK_NV_external_sci_sync( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_NV_external_sci_sync) return;
    glad_vkGetFenceSciSyncFenceNV = (PFN_vkGetFenceSciSyncFenceNV) load(userptr, "vkGetFenceSciSyncFenceNV");
    glad_vkGetFenceSciSyncObjNV = (PFN_vkGetFenceSciSyncObjNV) load(userptr, "vkGetFenceSciSyncObjNV");
    glad_vkGetPhysicalDeviceSciSyncAttributesNV = (PFN_vkGetPhysicalDeviceSciSyncAttributesNV) load(userptr, "vkGetPhysicalDeviceSciSyncAttributesNV");
    glad_vkGetSemaphoreSciSyncObjNV = (PFN_vkGetSemaphoreSciSyncObjNV) load(userptr, "vkGetSemaphoreSciSyncObjNV");
    glad_vkImportFenceSciSyncFenceNV = (PFN_vkImportFenceSciSyncFenceNV) load(userptr, "vkImportFenceSciSyncFenceNV");
    glad_vkImportFenceSciSyncObjNV = (PFN_vkImportFenceSciSyncObjNV) load(userptr, "vkImportFenceSciSyncObjNV");
    glad_vkImportSemaphoreSciSyncObjNV = (PFN_vkImportSemaphoreSciSyncObjNV) load(userptr, "vkImportSemaphoreSciSyncObjNV");
}

#endif
#if defined(VK_USE_PLATFORM_SCI)
static void glad_vk_load_VK_NV_external_sci_sync2( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_NV_external_sci_sync2) return;
    glad_vkCreateSemaphoreSciSyncPoolNV = (PFN_vkCreateSemaphoreSciSyncPoolNV) load(userptr, "vkCreateSemaphoreSciSyncPoolNV");
    glad_vkDestroySemaphoreSciSyncPoolNV = (PFN_vkDestroySemaphoreSciSyncPoolNV) load(userptr, "vkDestroySemaphoreSciSyncPoolNV");
    glad_vkGetFenceSciSyncFenceNV = (PFN_vkGetFenceSciSyncFenceNV) load(userptr, "vkGetFenceSciSyncFenceNV");
    glad_vkGetFenceSciSyncObjNV = (PFN_vkGetFenceSciSyncObjNV) load(userptr, "vkGetFenceSciSyncObjNV");
    glad_vkGetPhysicalDeviceSciSyncAttributesNV = (PFN_vkGetPhysicalDeviceSciSyncAttributesNV) load(userptr, "vkGetPhysicalDeviceSciSyncAttributesNV");
    glad_vkImportFenceSciSyncFenceNV = (PFN_vkImportFenceSciSyncFenceNV) load(userptr, "vkImportFenceSciSyncFenceNV");
    glad_vkImportFenceSciSyncObjNV = (PFN_vkImportFenceSciSyncObjNV) load(userptr, "vkImportFenceSciSyncObjNV");
}

#endif
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
static void glad_vk_load_VK_QNX_external_memory_screen_buffer( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_QNX_external_memory_screen_buffer) return;
    glad_vkGetScreenBufferPropertiesQNX = (PFN_vkGetScreenBufferPropertiesQNX) load(userptr, "vkGetScreenBufferPropertiesQNX");
}

#endif



static int glad_vk_get_extensions( VkPhysicalDevice physical_device, uint32_t *out_extension_count, char ***out_extensions) {
    uint32_t i;
    uint32_t instance_extension_count = 0;
    uint32_t device_extension_count = 0;
    uint32_t max_extension_count = 0;
    uint32_t total_extension_count = 0;
    char **extensions = NULL;
    VkExtensionProperties *ext_properties = NULL;
    VkResult result;

    if (glad_vkEnumerateInstanceExtensionProperties == NULL || (physical_device != NULL && glad_vkEnumerateDeviceExtensionProperties == NULL)) {
        return 0;
    }

    result = glad_vkEnumerateInstanceExtensionProperties(NULL, &instance_extension_count, NULL);
    if (result != VK_SUCCESS) {
        return 0;
    }

    if (physical_device != NULL) {
        result = glad_vkEnumerateDeviceExtensionProperties(physical_device, NULL, &device_extension_count, NULL);
        if (result != VK_SUCCESS) {
            return 0;
        }
    }

    total_extension_count = instance_extension_count + device_extension_count;
    if (total_extension_count <= 0) {
        return 0;
    }

    max_extension_count = instance_extension_count > device_extension_count
        ? instance_extension_count : device_extension_count;

    ext_properties = (VkExtensionProperties*) malloc(max_extension_count * sizeof(VkExtensionProperties));
    if (ext_properties == NULL) {
        goto glad_vk_get_extensions_error;
    }

    result = glad_vkEnumerateInstanceExtensionProperties(NULL, &instance_extension_count, ext_properties);
    if (result != VK_SUCCESS) {
        goto glad_vk_get_extensions_error;
    }

    extensions = (char**) calloc(total_extension_count, sizeof(char*));
    if (extensions == NULL) {
        goto glad_vk_get_extensions_error;
    }

    for (i = 0; i < instance_extension_count; ++i) {
        VkExtensionProperties ext = ext_properties[i];

        size_t extension_name_length = strlen(ext.extensionName) + 1;
        extensions[i] = (char*) malloc(extension_name_length * sizeof(char));
        if (extensions[i] == NULL) {
            goto glad_vk_get_extensions_error;
        }
        memcpy(extensions[i], ext.extensionName, extension_name_length * sizeof(char));
    }

    if (physical_device != NULL) {
        result = glad_vkEnumerateDeviceExtensionProperties(physical_device, NULL, &device_extension_count, ext_properties);
        if (result != VK_SUCCESS) {
            goto glad_vk_get_extensions_error;
        }

        for (i = 0; i < device_extension_count; ++i) {
            VkExtensionProperties ext = ext_properties[i];

            size_t extension_name_length = strlen(ext.extensionName) + 1;
            extensions[instance_extension_count + i] = (char*) malloc(extension_name_length * sizeof(char));
            if (extensions[instance_extension_count + i] == NULL) {
                goto glad_vk_get_extensions_error;
            }
            memcpy(extensions[instance_extension_count + i], ext.extensionName, extension_name_length * sizeof(char));
        }
    }

    free((void*) ext_properties);

    *out_extension_count = total_extension_count;
    *out_extensions = extensions;

    return 1;

glad_vk_get_extensions_error:
    free((void*) ext_properties);
    if (extensions != NULL) {
        for (i = 0; i < total_extension_count; ++i) {
            free((void*) extensions[i]);
        }
        free(extensions);
    }
    return 0;
}

static void glad_vk_free_extensions(uint32_t extension_count, char **extensions) {
    uint32_t i;

    for(i = 0; i < extension_count ; ++i) {
        free((void*) (extensions[i]));
    }

    free((void*) extensions);
}

static int glad_vk_has_extension(const char *name, uint32_t extension_count, char **extensions) {
    uint32_t i;

    for (i = 0; i < extension_count; ++i) {
        if(extensions[i] != NULL && strcmp(name, extensions[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

static GLADapiproc glad_vk_get_proc_from_userptr(void *userptr, const char* name) {
    return (GLAD_GNUC_EXTENSION (GLADapiproc (*)(const char *name)) userptr)(name);
}

static int glad_vk_find_extensions_vulkansc( VkPhysicalDevice physical_device) {
    uint32_t extension_count = 0;
    char **extensions = NULL;
    if (!glad_vk_get_extensions(physical_device, &extension_count, &extensions)) return 0;

    GLAD_VK_EXT_4444_formats = glad_vk_has_extension("VK_EXT_4444_formats", extension_count, extensions);
    GLAD_VK_EXT_application_parameters = glad_vk_has_extension("VK_EXT_application_parameters", extension_count, extensions);
    GLAD_VK_EXT_astc_decode_mode = glad_vk_has_extension("VK_EXT_astc_decode_mode", extension_count, extensions);
    GLAD_VK_EXT_blend_operation_advanced = glad_vk_has_extension("VK_EXT_blend_operation_advanced", extension_count, extensions);
    GLAD_VK_EXT_color_write_enable = glad_vk_has_extension("VK_EXT_color_write_enable", extension_count, extensions);
    GLAD_VK_EXT_conservative_rasterization = glad_vk_has_extension("VK_EXT_conservative_rasterization", extension_count, extensions);
    GLAD_VK_EXT_custom_border_color = glad_vk_has_extension("VK_EXT_custom_border_color", extension_count, extensions);
    GLAD_VK_EXT_debug_utils = glad_vk_has_extension("VK_EXT_debug_utils", extension_count, extensions);
    GLAD_VK_EXT_depth_clip_enable = glad_vk_has_extension("VK_EXT_depth_clip_enable", extension_count, extensions);
    GLAD_VK_EXT_depth_range_unrestricted = glad_vk_has_extension("VK_EXT_depth_range_unrestricted", extension_count, extensions);
    GLAD_VK_EXT_direct_mode_display = glad_vk_has_extension("VK_EXT_direct_mode_display", extension_count, extensions);
    GLAD_VK_EXT_discard_rectangles = glad_vk_has_extension("VK_EXT_discard_rectangles", extension_count, extensions);
    GLAD_VK_EXT_display_control = glad_vk_has_extension("VK_EXT_display_control", extension_count, extensions);
    GLAD_VK_EXT_display_surface_counter = glad_vk_has_extension("VK_EXT_display_surface_counter", extension_count, extensions);
    GLAD_VK_EXT_extended_dynamic_state = glad_vk_has_extension("VK_EXT_extended_dynamic_state", extension_count, extensions);
    GLAD_VK_EXT_extended_dynamic_state2 = glad_vk_has_extension("VK_EXT_extended_dynamic_state2", extension_count, extensions);
    GLAD_VK_EXT_external_memory_dma_buf = glad_vk_has_extension("VK_EXT_external_memory_dma_buf", extension_count, extensions);
    GLAD_VK_EXT_external_memory_host = glad_vk_has_extension("VK_EXT_external_memory_host", extension_count, extensions);
    GLAD_VK_EXT_filter_cubic = glad_vk_has_extension("VK_EXT_filter_cubic", extension_count, extensions);
    GLAD_VK_EXT_fragment_shader_interlock = glad_vk_has_extension("VK_EXT_fragment_shader_interlock", extension_count, extensions);
    GLAD_VK_EXT_hdr_metadata = glad_vk_has_extension("VK_EXT_hdr_metadata", extension_count, extensions);
    GLAD_VK_EXT_headless_surface = glad_vk_has_extension("VK_EXT_headless_surface", extension_count, extensions);
    GLAD_VK_EXT_image_drm_format_modifier = glad_vk_has_extension("VK_EXT_image_drm_format_modifier", extension_count, extensions);
    GLAD_VK_EXT_image_robustness = glad_vk_has_extension("VK_EXT_image_robustness", extension_count, extensions);
    GLAD_VK_EXT_index_type_uint8 = glad_vk_has_extension("VK_EXT_index_type_uint8", extension_count, extensions);
    GLAD_VK_EXT_layer_settings = glad_vk_has_extension("VK_EXT_layer_settings", extension_count, extensions);
    GLAD_VK_EXT_line_rasterization = glad_vk_has_extension("VK_EXT_line_rasterization", extension_count, extensions);
    GLAD_VK_EXT_memory_budget = glad_vk_has_extension("VK_EXT_memory_budget", extension_count, extensions);
    GLAD_VK_EXT_pci_bus_info = glad_vk_has_extension("VK_EXT_pci_bus_info", extension_count, extensions);
    GLAD_VK_EXT_post_depth_coverage = glad_vk_has_extension("VK_EXT_post_depth_coverage", extension_count, extensions);
    GLAD_VK_EXT_queue_family_foreign = glad_vk_has_extension("VK_EXT_queue_family_foreign", extension_count, extensions);
    GLAD_VK_EXT_robustness2 = glad_vk_has_extension("VK_EXT_robustness2", extension_count, extensions);
    GLAD_VK_EXT_sample_locations = glad_vk_has_extension("VK_EXT_sample_locations", extension_count, extensions);
    GLAD_VK_EXT_shader_atomic_float = glad_vk_has_extension("VK_EXT_shader_atomic_float", extension_count, extensions);
    GLAD_VK_EXT_shader_demote_to_helper_invocation = glad_vk_has_extension("VK_EXT_shader_demote_to_helper_invocation", extension_count, extensions);
    GLAD_VK_EXT_shader_image_atomic_int64 = glad_vk_has_extension("VK_EXT_shader_image_atomic_int64", extension_count, extensions);
    GLAD_VK_EXT_shader_stencil_export = glad_vk_has_extension("VK_EXT_shader_stencil_export", extension_count, extensions);
    GLAD_VK_EXT_subgroup_size_control = glad_vk_has_extension("VK_EXT_subgroup_size_control", extension_count, extensions);
    GLAD_VK_EXT_swapchain_colorspace = glad_vk_has_extension("VK_EXT_swapchain_colorspace", extension_count, extensions);
    GLAD_VK_EXT_texel_buffer_alignment = glad_vk_has_extension("VK_EXT_texel_buffer_alignment", extension_count, extensions);
    GLAD_VK_EXT_texture_compression_astc_hdr = glad_vk_has_extension("VK_EXT_texture_compression_astc_hdr", extension_count, extensions);
    GLAD_VK_EXT_validation_features = glad_vk_has_extension("VK_EXT_validation_features", extension_count, extensions);
    GLAD_VK_EXT_vertex_input_dynamic_state = glad_vk_has_extension("VK_EXT_vertex_input_dynamic_state", extension_count, extensions);
    GLAD_VK_EXT_ycbcr_2plane_444_formats = glad_vk_has_extension("VK_EXT_ycbcr_2plane_444_formats", extension_count, extensions);
    GLAD_VK_EXT_ycbcr_image_arrays = glad_vk_has_extension("VK_EXT_ycbcr_image_arrays", extension_count, extensions);
    GLAD_VK_KHR_calibrated_timestamps = glad_vk_has_extension("VK_KHR_calibrated_timestamps", extension_count, extensions);
    GLAD_VK_KHR_copy_commands2 = glad_vk_has_extension("VK_KHR_copy_commands2", extension_count, extensions);
    GLAD_VK_KHR_display = glad_vk_has_extension("VK_KHR_display", extension_count, extensions);
    GLAD_VK_KHR_display_swapchain = glad_vk_has_extension("VK_KHR_display_swapchain", extension_count, extensions);
    GLAD_VK_KHR_external_fence_fd = glad_vk_has_extension("VK_KHR_external_fence_fd", extension_count, extensions);
    GLAD_VK_KHR_external_memory_fd = glad_vk_has_extension("VK_KHR_external_memory_fd", extension_count, extensions);
    GLAD_VK_KHR_external_semaphore_fd = glad_vk_has_extension("VK_KHR_external_semaphore_fd", extension_count, extensions);
    GLAD_VK_KHR_fragment_shading_rate = glad_vk_has_extension("VK_KHR_fragment_shading_rate", extension_count, extensions);
    GLAD_VK_KHR_get_display_properties2 = glad_vk_has_extension("VK_KHR_get_display_properties2", extension_count, extensions);
    GLAD_VK_KHR_get_surface_capabilities2 = glad_vk_has_extension("VK_KHR_get_surface_capabilities2", extension_count, extensions);
    GLAD_VK_KHR_global_priority = glad_vk_has_extension("VK_KHR_global_priority", extension_count, extensions);
    GLAD_VK_KHR_incremental_present = glad_vk_has_extension("VK_KHR_incremental_present", extension_count, extensions);
    GLAD_VK_KHR_index_type_uint8 = glad_vk_has_extension("VK_KHR_index_type_uint8", extension_count, extensions);
    GLAD_VK_KHR_line_rasterization = glad_vk_has_extension("VK_KHR_line_rasterization", extension_count, extensions);
    GLAD_VK_KHR_object_refresh = glad_vk_has_extension("VK_KHR_object_refresh", extension_count, extensions);
    GLAD_VK_KHR_performance_query = glad_vk_has_extension("VK_KHR_performance_query", extension_count, extensions);
    GLAD_VK_KHR_shader_clock = glad_vk_has_extension("VK_KHR_shader_clock", extension_count, extensions);
    GLAD_VK_KHR_shader_terminate_invocation = glad_vk_has_extension("VK_KHR_shader_terminate_invocation", extension_count, extensions);
    GLAD_VK_KHR_shared_presentable_image = glad_vk_has_extension("VK_KHR_shared_presentable_image", extension_count, extensions);
    GLAD_VK_KHR_surface = glad_vk_has_extension("VK_KHR_surface", extension_count, extensions);
    GLAD_VK_KHR_swapchain = glad_vk_has_extension("VK_KHR_swapchain", extension_count, extensions);
    GLAD_VK_KHR_swapchain_mutable_format = glad_vk_has_extension("VK_KHR_swapchain_mutable_format", extension_count, extensions);
    GLAD_VK_KHR_synchronization2 = glad_vk_has_extension("VK_KHR_synchronization2", extension_count, extensions);
    GLAD_VK_KHR_vertex_attribute_divisor = glad_vk_has_extension("VK_KHR_vertex_attribute_divisor", extension_count, extensions);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    GLAD_VK_NV_acquire_winrt_display = glad_vk_has_extension("VK_NV_acquire_winrt_display", extension_count, extensions);

#endif
#if defined(VK_USE_PLATFORM_SCI)
    GLAD_VK_NV_external_memory_sci_buf = glad_vk_has_extension("VK_NV_external_memory_sci_buf", extension_count, extensions);

#endif
#if defined(VK_USE_PLATFORM_SCI)
    GLAD_VK_NV_external_sci_sync = glad_vk_has_extension("VK_NV_external_sci_sync", extension_count, extensions);

#endif
#if defined(VK_USE_PLATFORM_SCI)
    GLAD_VK_NV_external_sci_sync2 = glad_vk_has_extension("VK_NV_external_sci_sync2", extension_count, extensions);

#endif
    GLAD_VK_NV_private_vendor_info = glad_vk_has_extension("VK_NV_private_vendor_info", extension_count, extensions);
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
    GLAD_VK_QNX_external_memory_screen_buffer = glad_vk_has_extension("VK_QNX_external_memory_screen_buffer", extension_count, extensions);

#endif

    GLAD_UNUSED(glad_vk_has_extension);

    glad_vk_free_extensions(extension_count, extensions);

    return 1;
}

static int glad_vk_find_core_vulkansc( VkPhysicalDevice physical_device) {
    int major = 1;
    int minor = 0;

#ifdef VK_VERSION_1_1
    if (glad_vkEnumerateInstanceVersion != NULL) {
        uint32_t version;
        VkResult result;

        result = glad_vkEnumerateInstanceVersion(&version);
        if (result == VK_SUCCESS) {
            major = (int) VK_VERSION_MAJOR(version);
            minor = (int) VK_VERSION_MINOR(version);
        }
    }
#endif

    if (physical_device != NULL && glad_vkGetPhysicalDeviceProperties != NULL) {
        VkPhysicalDeviceProperties properties;
        glad_vkGetPhysicalDeviceProperties(physical_device, &properties);

        major = (int) VK_VERSION_MAJOR(properties.apiVersion);
        minor = (int) VK_VERSION_MINOR(properties.apiVersion);
    }

    GLAD_VKSC_VERSION_1_0 = (major == 1 && minor >= 0) || major > 1;
    GLAD_VK_VERSION_1_1 = (major == 1 && minor >= 1) || major > 1;
    GLAD_VK_VERSION_1_2 = (major == 1 && minor >= 2) || major > 1;
    GLAD_VK_VERSION_1_3 = (major == 1 && minor >= 3) || major > 1;
    GLAD_VK_VERSION_1_4 = (major == 1 && minor >= 4) || major > 1;

    return GLAD_MAKE_VERSION(major, minor);
}

int gladLoadVulkanscUserPtr( VkPhysicalDevice physical_device, GLADuserptrloadfunc load, void *userptr) {
    int version;

#ifdef VK_VERSION_1_1
    glad_vkEnumerateInstanceVersion  = (PFN_vkEnumerateInstanceVersion) load(userptr, "vkEnumerateInstanceVersion");
#endif
    version = glad_vk_find_core_vulkansc( physical_device);
    if (!version) {
        return 0;
    }

    glad_vk_load_VKSC_VERSION_1_0(load, userptr);
    glad_vk_load_VK_VERSION_1_1(load, userptr);
    glad_vk_load_VK_VERSION_1_2(load, userptr);
    glad_vk_load_VK_VERSION_1_3(load, userptr);
    glad_vk_load_VK_VERSION_1_4(load, userptr);

    if (!glad_vk_find_extensions_vulkansc( physical_device)) return 0;
    glad_vk_load_VK_EXT_color_write_enable(load, userptr);
    glad_vk_load_VK_EXT_debug_utils(load, userptr);
    glad_vk_load_VK_EXT_direct_mode_display(load, userptr);
    glad_vk_load_VK_EXT_discard_rectangles(load, userptr);
    glad_vk_load_VK_EXT_display_control(load, userptr);
    glad_vk_load_VK_EXT_display_surface_counter(load, userptr);
    glad_vk_load_VK_EXT_extended_dynamic_state(load, userptr);
    glad_vk_load_VK_EXT_extended_dynamic_state2(load, userptr);
    glad_vk_load_VK_EXT_external_memory_host(load, userptr);
    glad_vk_load_VK_EXT_hdr_metadata(load, userptr);
    glad_vk_load_VK_EXT_headless_surface(load, userptr);
    glad_vk_load_VK_EXT_image_drm_format_modifier(load, userptr);
    glad_vk_load_VK_EXT_line_rasterization(load, userptr);
    glad_vk_load_VK_EXT_sample_locations(load, userptr);
    glad_vk_load_VK_EXT_vertex_input_dynamic_state(load, userptr);
    glad_vk_load_VK_KHR_calibrated_timestamps(load, userptr);
    glad_vk_load_VK_KHR_copy_commands2(load, userptr);
    glad_vk_load_VK_KHR_display(load, userptr);
    glad_vk_load_VK_KHR_display_swapchain(load, userptr);
    glad_vk_load_VK_KHR_external_fence_fd(load, userptr);
    glad_vk_load_VK_KHR_external_memory_fd(load, userptr);
    glad_vk_load_VK_KHR_external_semaphore_fd(load, userptr);
    glad_vk_load_VK_KHR_fragment_shading_rate(load, userptr);
    glad_vk_load_VK_KHR_get_display_properties2(load, userptr);
    glad_vk_load_VK_KHR_get_surface_capabilities2(load, userptr);
    glad_vk_load_VK_KHR_line_rasterization(load, userptr);
    glad_vk_load_VK_KHR_object_refresh(load, userptr);
    glad_vk_load_VK_KHR_performance_query(load, userptr);
    glad_vk_load_VK_KHR_shared_presentable_image(load, userptr);
    glad_vk_load_VK_KHR_surface(load, userptr);
    glad_vk_load_VK_KHR_swapchain(load, userptr);
    glad_vk_load_VK_KHR_synchronization2(load, userptr);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_vk_load_VK_NV_acquire_winrt_display(load, userptr);

#endif
#if defined(VK_USE_PLATFORM_SCI)
    glad_vk_load_VK_NV_external_memory_sci_buf(load, userptr);

#endif
#if defined(VK_USE_PLATFORM_SCI)
    glad_vk_load_VK_NV_external_sci_sync(load, userptr);

#endif
#if defined(VK_USE_PLATFORM_SCI)
    glad_vk_load_VK_NV_external_sci_sync2(load, userptr);

#endif
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
    glad_vk_load_VK_QNX_external_memory_screen_buffer(load, userptr);

#endif


    return version;
}


int gladLoadVulkansc( VkPhysicalDevice physical_device, GLADloadfunc load) {
    return gladLoadVulkanscUserPtr( physical_device, glad_vk_get_proc_from_userptr, GLAD_GNUC_EXTENSION (void*) load);
}






#ifdef __cplusplus
}
#endif
