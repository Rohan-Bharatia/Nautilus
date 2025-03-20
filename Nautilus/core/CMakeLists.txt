add_library(core STATIC
    Logger.cpp
    Timer.cpp
)

target_include_directories(core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
