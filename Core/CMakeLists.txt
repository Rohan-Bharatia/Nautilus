include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB CORE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Math/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform/*.cpp
)

if (WIN32)
    file(GLOB PLATFORM_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Platform/Windows/*.cpp
    )
elseif(UNIX AND NOT APPLE)
    file(GLOB PLATFORM_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Platform/Unix/*.cpp
    )
elseif(APPLE)
    if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
        file(GLOB PLATFORM_SOURCES
            ${CMAKE_CURRENT_SOURCE_DIR}/Platform/MacOS/*.mm
        )
    elseif(CMAKE_SYSTEM_NAME MATCHES "iOS")
        file(GLOB PLATFORM_SOURCES
            ${CMAKE_CURRENT_SOURCE_DIR}/Platform/iOS/*.mm
        )
    endif()
elseif(ANDROID)
    file(GLOB PLATFORM_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Platform/Android/*.cpp
    )
elseif(EMSCRIPTEN)
    file(GLOB PLATFORM_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Platform/Emscripten/*.cpp
    )
endif()

list(APPEND CORE_SOURCES ${PLATFORM_SOURCES})

add_library(Core STATIC ${CORE_SOURCES})

target_include_directories(Core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Math
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform
)

target_link_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
