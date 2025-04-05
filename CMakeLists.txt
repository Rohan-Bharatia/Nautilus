cmake_minimum_required(VERSION 3.10)

project(Nautilus VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Core)

file(GLOB NAUTILUS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Math/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Platform/*.cpp
)

if(NAUTILUS_SOURCES)
    if(WIN32)
        find_library(PLATFORM_SOURCES DirectX)
    elseif(UNIX AND NOT APPLE)
        find_library(PLATFORM_SOURCES X11)
    elseif(APPLE)
        if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
            find_library(PLATFORM_SOURCES Cocoa)
        elseif(CMAKE_SYSTEM_NAME MATCHES "iOS")
            find_library(PLATFORM_SOURCES UIKit)
        endif()
    elseif(ANDROID)
        find_library(PLATFORM_SOURCES android)
    endif()

    if(PLATFORM_SOURCES)
        list(APPEND NAUTILUS_SOURCES ${PLATFORM_SOURCES})
    endif()

    add_library(${PROJECT_NAME} STATIC ${NAUTILUS_SOURCES})
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Core)
    target_link_libraries(${PROJECT_NAME} PUBLIC Core)
endif()
