if(WIN32)
    add_library(backends STATIC
        src/gl.c
        src/wgl.c
        src/vulkan.c
    )
    add_definitions(-DVK_USE_PLATFORM_WIN32_KHR)
elseif(UNIX AND NOT APPLE)
    add_library(backends STATIC
        src/gl.c
        src/x11.c
        src/vulkan.c
    )
    add_definitions(-DVK_USE_PLATFORM_X11_KHR)
elseif(APPLE)
    add_library(backends STATIC
        src/gl.c
        src/egl.m
        src/vulkan.c
    )
    add_definitions(-DVK_USE_PLATFORM_MACOS_MVK)
elseif(IOS)
    add_library(backends STATIC
        src/gl.c
        src/gles1.m
        src/gles2.m
        src/vulkan.c
    )
    add_definitions(-DVK_USE_PLATFORM_IOS_MVK)
elseif(ANDROID)
    add_library(backends STATIC
        src/gl.c
        src/gles1.m
        src/gles2.m
        src/vulkan.c
    )
    add_definitions(-DVK_USE_PLATFORM_ANDROID_KHR)
endif()

target_include_directories(backends PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
