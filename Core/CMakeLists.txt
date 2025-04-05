include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(Core STATIC
    Math/Vec2.cpp
    Math/Vec3.cpp
    Math/Vec4.cpp
    Math/Mat4x4.cpp
    Math/Ray2.cpp
    Math/Ray3.cpp
    Math/Rect.cpp
    Math/Plane.cpp
    Logger.cpp
    File.cpp
    Threading.cpp
)

target_link_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )
