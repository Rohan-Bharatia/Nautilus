cmake_minimum_required(VERSION 3.10)

project(Nautilus)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/backends)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/core)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event)

if(WIN32)
    set(WINDOW_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowBase.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowWin32.cpp
    )

    set(EVENT_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/Event.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/EventWin32.cpp
    )

    set(BACKEND_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/backends/src/gl.c
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/backends/src/wgl.c
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/backends/src/vulkan.c
    )
    add_definitions(-DVK_USE_PLATFORM_WIN32_KHR)
elseif(UNIX AND NOT APPLE)
    set(WINDOW_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowBase.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowX11.cpp
    )

    set(EVENT_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/Event.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/EventX11.cpp
    )

    set(BACKEND_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/backends/src/gl.c
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/backends/src/glx.c
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/backends/src/vulkan.c
    )
    add_definitions(-DVK_USE_PLATFORM_XLIB_KHR)
elseif(APPLE)
    set(WINDOW_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowBase.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowCocoa.cpp
    )

    set(EVENT_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/Event.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/EventCocoa.cpp
    )

    set(BACKEND_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/backends/src/gl.c
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/backends/src/egl.c
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/backends/src/vulkan.c
    )
    add_definitions(-DVK_USE_PLATFORM_MACOS_MVK)
elseif(IOS)
    set(WINDOW_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowBase.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowUIKit.cpp
    )

    set(EVENT_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/Event.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/EventUIKit.cpp
    )

    set(BACKEND_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/backends/src/gl.c
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/backends/src/egl.c
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/backends/src/vulkan.c
    )
    add_definitions(-DVK_USE_PLATFORM_IOS_MVK)
elseif(ANDROID)
    set(WINDOW_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowBase.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowAndroid.cpp
    )

    set(EVENT_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/Event.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/EventAndroid.cpp
    )

    set(BACKEND_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/backends/src/gl.c
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/backends/src/egl.c
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/backends/src/vulkan.c
    )
    add_definitions(-DVK_USE_PLATFORM_ANDROID_KHR)
endif()

file(GLOB NAUTILUS_SOURCES
    ${BACKEND_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/core/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/*.cpp
    ${WINDOW_SOURCES}
    ${EVENT_SOURCES}
)

if (NAUTILUS_SOURCES)
    find_package(OpenGL REQUIRED)

    add_library(Nautilus STATIC ${NAUTILUS_SOURCES})
    target_include_directories(Nautilus PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/backends
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/core
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event
    )

    target_link_libraries(Nautilus PUBLIC opengl32 backends core math window event)
endif()
