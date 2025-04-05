include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB CORE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Math/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform/*.cpp
)

if(WIN32)
    list(APPEND CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Platform/D3D12/Window.cpp)
    list(APPEND CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Platform/D3D12/Event.cpp)
elseif(UNIX AND NOT APPLE)
    list(APPEND CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Platform/X11/Window.cpp)
    list(APPEND CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Platform/X11/Event.cpp)
elseif(APPLE)
    if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
        list(APPEND CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Platform/Cocoa/Window.mm)
        list(APPEND CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Platform/Cocoa/Event.mm)
    elseif(CMAKE_SYSTEM_NAME MATCHES "iOS")
        list(APPEND CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Platform/UIKit/Window.mm)
        list(APPEND CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Platform/UIKit/Event.mm)
    endif()
elseif(ANDROID)
    list(APPEND CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Platform/Android/Window.cpp)
    list(APPEND CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Platform/Android/Event.cpp)
endif()

add_library(Core STATIC ${CORE_SOURCES})

target_include_directories(Core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Math
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform
)

target_link_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
