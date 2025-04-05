include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(Core STATIC
    Logger.cpp
)

target_link_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )
