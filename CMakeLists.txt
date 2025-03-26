cmake_minimum_required(VERSION 3.10)

project(Nautilus)

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
elseif(UNIX AND NOT APPLE)
    set(WINDOW_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowBase.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowX11.cpp
    )

    set(EVENT_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/Event.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/EventX11.cpp
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
elseif(IOS)
    set(WINDOW_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowBase.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowUIKit.cpp
    )

    set(EVENT_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/Event.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/EventUIKit.cpp
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
endif()

file(GLOB NAUTILUS_SOURCES
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
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/core
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event
    )

    target_link_libraries(Nautilus PUBLIC core math window event)
endif()
