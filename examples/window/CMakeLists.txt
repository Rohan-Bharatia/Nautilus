cmake_minimum_required(VERSION 3.10)

project(Main)

add_subdirectory(Nautilus)

add_executable(Main main.cpp)

target_link_libraries(Main PUBLIC Nautilus)
