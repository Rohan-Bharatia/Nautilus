cmake_minimum_required(VERSION 3.10)

project(Nautilus)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/backends)
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

    set(BACKENDS_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/backends/src/gl.c
        ${CMAKE_CURRENT_SOURCE_DIR}/backends/src/wgl.c
    )
elseif(UNIX AND NOT APPLE)
    set(WINDOW_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowBase.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowX11.cpp
    )

    set(EVENT_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/Event.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/EventX11.cpp
    )

    set(BACKENDS_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/backends/src/gl.c
        ${CMAKE_CURRENT_SOURCE_DIR}/backends/src/glx.c
    )
elseif(APPLE)
    set(WINDOW_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowBase.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowCocoa.cpp
    )

    set(EVENT_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/Event.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/EventCocoa.cpp
    )

    set(BACKENDS_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/backends/src/gl.c
        ${CMAKE_CURRENT_SOURCE_DIR}/backends/src/egl.c
    )
elseif(IOS)
    set(WINDOW_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowBase.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowUIKit.cpp
    )

    set(EVENT_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/Event.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/EventUIKit.cpp
    )

    set(BACKENDS_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/backends/src/gl.c
        ${CMAKE_CURRENT_SOURCE_DIR}/backends/src/gles1.c
        ${CMAKE_CURRENT_SOURCE_DIR}/backends/src/gles2.c
    )
elseif(ANDROID)
    set(WINDOW_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowBase.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowAndroid.cpp
    )

    set(EVENT_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/Event.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/EventAndroid.cpp
    )

    set(BACKENDS_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/backends/src/gl.c
        ${CMAKE_CURRENT_SOURCE_DIR}/backends/src/gles1.c
        ${CMAKE_CURRENT_SOURCE_DIR}/backends/src/gles2.c
    )
endif()

file(GLOB NAUTILUS_SOURCES
    ${BACKENDS_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/core/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/*.cpp
    ${WINDOW_SOURCES}
    ${EVENT_SOURCES}
)

if (NAUTILUS_SOURCES)
    add_library(Nautilus STATIC ${NAUTILUS_SOURCES})
    target_include_directories(Nautilus PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/backends/include
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/core
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event
    )

    find_package(OpenGL REQUIRED)
    find_package(Vulkan REQUIRED)

    include_directories(${OPENGL_INCLUDE_DIRS})
    include_directories(${VULKAN_INCLUDE_DIRS})

    target_link_libraries(Nautilus PUBLIC
        ${OPENGL_LIBRARIES}
        ${VULKAN_LIBRARIES}
        backends
        core
        math
        window
        event
    )
endif()
