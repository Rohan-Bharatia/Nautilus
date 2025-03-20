cmake_minimum_required(VERSION 3.10)

project(Nautilus)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/core)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event)

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
add_library(Nautilus STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/core/Logger.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/core/Timer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Internal.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Angle.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Vec2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Vec3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Vec4.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Mat4x4.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Ray2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Ray3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Rect.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Color.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowBase.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowWin32.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/Event.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/EventWin32.cpp)
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Linux|BSD")
add_library(Nautilus STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/core/Logger.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/core/Timer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Internal.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Angle.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Vec2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Vec3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Vec4.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Mat4x4.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Ray2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Ray3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Rect.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Color.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowBase.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowX11.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/Event.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/EventX11.cpp)
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
add_library(Nautilus STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/core/Logger.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/core/Timer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Internal.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Angle.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Vec2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Vec3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Vec4.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Mat4x4.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Ray2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Ray3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Rect.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Color.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowBase.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowCocoa.mm
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/Event.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/EventCocoa.mm)
endif()

if(CMAKE_SYSTEM_NAME MATCHES "iOS")
add_library(Nautilus STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/core/Logger.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/core/Timer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Internal.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Angle.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Vec2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Vec3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Vec4.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Mat4x4.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Ray2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Ray3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Rect.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Color.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowBase.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowUIKit.mm
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/Event.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/EventUIKit.mm)
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Android")
add_library(Nautilus STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/core/Logger.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/core/Timer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Internal.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Angle.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Vec2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Vec3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Vec4.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Mat4x4.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Ray2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Ray3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Rect.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math/Color.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowBase.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window/WindowAndroid.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/Event.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event/EventAndroid.cpp)
endif()

target_include_directories(Nautilus PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/core
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/math
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/window
    ${CMAKE_CURRENT_SOURCE_DIR}/Nautilus/event
)

target_link_libraries(Nautilus PUBLIC core math window event)
