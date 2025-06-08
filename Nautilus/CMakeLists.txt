cmake_minimum_required(VERSION 3.16)

include(${CMAKE_CURRENT_SOURCE_DIR}/PlatformDefs.cmake)

project(Nautilus)

file(GLOB Nautilus_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/*.cpp
)
if(NT_PLATFORM_WINDOWS)
    file(GLOB Nautilus_PLATFORM_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Core/Windows/*.cpp
    )
elseif(NT_PLATFORM_LINUX)
    file(GLOB Nautilus_PLATFORM_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Core/Linux/*.cpp
    )
elseif(NT_PLATFORM_MACOS)
    file(GLOB Nautilus_PLATFORM_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Core/MacOS/*.cpp
    )
elseif(NT_PLATFORM_IOS)
    file(GLOB Nautilus_PLATFORM_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Core/iOS/*.cpp
    )
elseif(NT_PLATFORM_ANDROID)
    file(GLOB Nautilus_PLATFORM_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Core/Android/*.cpp
    )
elseif(NT_PLATFORM_WASM)
    file(GLOB Nautilus_PLATFORM_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Core/WASM/*.cpp
    )
endif()
list(APPEND Nautilus_SOURCES ${Nautilus_PLATFORM_SOURCES})

add_library(Nautilus SHARED ${Nautilus_SOURCES})
target_precompile_headers(Nautilus PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/PCH.h)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../GLAD)

target_include_directories(Nautilus PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Core
    ${CMAKE_CURRENT_SOURCE_DIR}/../GLAD/include
)

if(NT_PLATFORM_WINDOWS)
    target_link_libraries(Nautilus PRIVATE
        d3d12
        dxgi
        d3dcompiler
    )
elseif(NT_PLATFORM_LINUX)
    find_library(XLIB_LIBRARY X11 REQUIRED)
    find_package(Vulkan REQUIRED)

    target_link_libraries(Nautilus PRIVATE
        ${X11_LIBRARY}
        pthread
        dl
        vulkan::Vulkan
    )
elseif(NT_PLATFORM_MACOS)
    find_library(COCOA_LIBRARY Cocoa REQUIRED)
    find_library(QUARTZ_LIBRARY QuartzCore REQUIRED)
    find_library(IOKIT_LIBRARY IOKit REQUIRED)
    find_library(METAL_LIBRARY Metal REQUIRED)
    find_library(METALKIT_LIBRARY MetalKit REQUIRED)

    target_link_libraries(Nautilus PRIVATE
        ${COCOA_LIBRARY}
        ${QUARTZ_LIBRARY}
        ${IOKIT_LIBRARY}
        ${METAL_LIBRARY}
        ${METALKIT_LIBRARY}
    )
elseif(NT_PLATFORM_IOS)
    find_library(UIKIT_LIBRARY UIKit REQUIRED)
    find_library(QUARTZ_LIBRARY QuartzCore REQUIRED)
    find_library(IOKIT_LIBRARY IOKit REQUIRED)
    find_library(METAL_LIBRARY Metal REQUIRED)
    find_library(METALKIT_LIBRARY MetalKit REQUIRED)

    target_link_libraries(Nautilus PRIVATE
        ${UIKIT_LIBRARY}
        ${QUARTZ_LIBRARY}
        ${IOKIT_LIBRARY}
        ${METAL_LIBRARY}
        ${METALKIT_LIBRARY}
    )
elseif(NT_PLATFORM_ANDROID)
    find_library(LOG_LIBRARY log-lib log REQUIRED)
    find_library(ANDROID_LIBRARY android-lib android REQUIRED)
    find_package(Vulkan REQUIRED)

    target_link_libraries(Nautilus PRIVATE
        ${android-lib}
        ${log-lib}
        vulkan::Vulkan
    )
elseif(NT_PLATFORM_WASM)
    target_link_options(Nautilus PRIVATE
        "-sUSE_WEBGPU=1"
        "-sASYNCIFY"
    )
endif()


set_target_properties(Nautilus PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
