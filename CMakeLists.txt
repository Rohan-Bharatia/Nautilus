cmake_minimum_required(VERSION 3.10)

project(Nautilus VERSION 0.1.0 LANGUAGES C CXX)

if(APPLE)
    enable_language(OBJC OBJCXX)
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Core)

file(GLOB NAUTILUS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Math/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Platform/*.cpp
)

if(NAUTILUS_SOURCES)
    add_library(${PROJECT_NAME} STATIC ${NAUTILUS_SOURCES})
    add_dependencies(${PROJECT_NAME} Core)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Core)
    target_link_libraries(${PROJECT_NAME} PUBLIC Core)

    file(READ "../App.h" APP_H_CONTENTS)
    string(FIND "${APP_H_CONTENTS}" "NT_GRAPHICS_BACKEND_VULKAN" VULKAN_FOUND)
    string(FIND "${APP_H_CONTENTS}" "NT_GRAPHICS_BACKEND_OPENGL" OPENGL_FOUND)

    if(VULKAN_FOUND)
        find_package(Vulkan REQUIRED)

        if(WIN32)
            add_definitions(-DVK_USE_PLATFORM_WIN32_KHR)
        elseif(UNIX AND NOT APPLE)
            add_definitions(-DVK_USE_PLATFORM_XLIB_KHR)
        elseif(APPLE)
            if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
                add_definitions(-DVK_USE_PLATFORM_MACOS_MVK)
            elseif(CMAKE_SYSTEM_NAME MATCHES "iOS")
                add_definitions(-DVK_USE_PLATFORM_IOS_MVK)
            endif()
        elseif(ANDROID)
            add_definitions(-DVK_USE_PLATFORM_ANDROID_KHR)
        endif()
        add_definitions(-DVK_ENABLE_BETA_EXTENSIONS)

        set(GFX_LIBS Vulkan::Vulkan)
    elseif(OPENGL_FOUND)
        find_package(OpenGL REQUIRED)

        add_definitions(-DGL_GLEXT_PROTOTYPES)

        set(GFX_LIBS OpenGL::GL)
    endif()
    target_link_libraries(${PROJECT_NAME} PUBLIC ${GFX_LIBS})
endif()
