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

find_package(OpenGL REQUIRED)
message("OpenGL found: ${OPENGL_FOUND}")
message("OpenGL libraries: ${OPENGL_LIBRARIES}")

if(OPENGL_FOUND AND NAUTILUS_SOURCES)
    add_library(${PROJECT_NAME} STATIC ${NAUTILUS_SOURCES})
    add_dependencies(${PROJECT_NAME} Core)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Core)
    target_link_libraries(${PROJECT_NAME} PUBLIC Core OpenGL::GL)
endif()
