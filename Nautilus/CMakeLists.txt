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

target_include_directories(Nautilus PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Core
)

set_target_properties(Nautilus PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
