add_library(math STATIC
    Internal.cpp
    Angle.cpp
    Vec2.cpp
    Vec3.cpp
    Vec4.cpp
    Mat4x4.cpp
    Ray2.cpp
    Ray3.cpp
    Rect.cpp
    Color.cpp
)

target_include_directories(math PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
