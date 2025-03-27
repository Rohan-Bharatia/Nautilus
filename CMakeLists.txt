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
    add_library(Nautilus STATIC ${NAUTILUS_SOURCES})
    target_include_directories(Nautilus PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/core
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window
        ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event
    )

    find_package(OpenGL REQUIRED)
    include_directories(${OPENGL_INCLUDE_DIR})
    link_directories(${OPENGL_LIBRARY_DIR})
    target_link_libraries(Nautilus PUBLIC ${OPENGL_LIBRARIES})

    if(UNIX AND NOT APPLE)
        find_package(X11 REQUIRED)
        include_directories(${X11_INCLUDE_DIR})
        link_directories(${X11_LIBRARY_DIR})
        target_link_libraries(Nautilus PUBLIC ${X11_LIBRARIES})
    elseif(APPLE)
        find_package(Cocoa REQUIRED)
        include_directories(${Cocoa_INCLUDE_DIR})
        link_directories(${Cocoa_LIBRARY_DIR})
        target_link_libraries(Nautilus PUBLIC ${Cocoa_LIBRARIES})
    elseif(IOS)
        find_package(UIKit REQUIRED)
        include_directories(${UIKit_INCLUDE_DIR})
        link_directories(${UIKit_LIBRARY_DIR})
        target_link_libraries(Nautilus PUBLIC ${UIKit_LIBRARIES})
    elseif(ANDROID)
        find_package(Android REQUIRED)
        include_directories(${Android_INCLUDE_DIR})
        link_directories(${Android_LIBRARY_DIR})
        target_link_libraries(Nautilus PUBLIC ${Android_LIBRARIES})
    endif()

    target_link_libraries(Nautilus PUBLIC core math window event)
endif()
