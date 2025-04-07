include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB CORE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Math/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Rendering/*.cpp
)

if(WIN32)
    list(APPEND CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Platform/DirectX/Window.cpp)
    list(APPEND CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Platform/DirectX/Event.cpp)
    list(APPEND CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Rendering/DirectX/Renderer.cpp)
elseif(UNIX AND NOT APPLE)
    list(APPEND CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Platform/X11/Window.cpp)
    list(APPEND CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Platform/X11/Event.cpp)
    list(APPEND CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Rendering/OpenGL/Renderer.cpp)
elseif(APPLE)
    if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
        list(APPEND CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Platform/Cocoa/Window.mm)
        list(APPEND CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Platform/Cocoa/Event.mm)
        list(APPEND CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Rendering/Metal/Renderer.cpp)
    elseif(CMAKE_SYSTEM_NAME MATCHES "iOS")
        list(APPEND CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Platform/UIKit/Window.mm)
        list(APPEND CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Platform/UIKit/Event.mm)
        list(APPEND CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Rendering/Metal/Renderer.cpp)
    endif()
elseif(ANDROID)
    list(APPEND CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Platform/Android/Window.cpp)
    list(APPEND CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Platform/Android/Event.cpp)
    list(APPEND CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Rendering/OpenGLES/Renderer.cpp)
endif()

add_library(Core STATIC ${CORE_SOURCES})

# Add platform specific libraries
if(WIN32)
    target_link_libraries(Core PRIVATE
        d3d12
        dxgi
        d3dcompiler
    )
elseif(UNIX AND NOT APPLE)
    target_link_libraries(Core PRIVATE
        X11
        GL
    )
elseif(APPLE)
    if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
        target_link_libraries(Core PRIVATE
            Cocoa
            Metal
            Quartz
            Foundation
        )
    elseif(CMAKE_SYSTEM_NAME MATCHES "iOS")
        target_link_libraries(Core PRIVATE
            UIKit
            Metal
            Quartz
            Foundation
        )
    endif()
elseif(ANDROID)
    target_link_libraries(Core PRIVATE
        android
        EGL
        GLESv2
    )
endif()

target_include_directories(Core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Math
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform
    ${CMAKE_CURRENT_SOURCE_DIR}/Rendering
)

target_link_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
