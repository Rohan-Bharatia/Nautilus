if(WIN32)
    add_library(backends STATIC
        src/gl.c
        src/wgl.c
    )
    target_compile_definitions(backends PUBLIC VK_USE_PLATFORM_WIN32_KHR)
elseif(UNIX AND NOT APPLE)
    add_library(backends STATIC
        src/gl.c
        src/glx.c
    )
    target_compile_definitions(backends PUBLIC VK_USE_PLATFORM_XLIB_KHR)
elseif(APPLE)
    add_library(backends STATIC
        src/gl.c
        src/egl.c
    )
    target_compile_definitions(backends PUBLIC VK_USE_PLATFORM_MACOS_MVK)
elseif(IOS)
    add_library(backends STATIC
        src/gl.c
        src/gles2.c
    )
    target_compile_definitions(backends PUBLIC VK_USE_PLATFORM_IOS_MVK)
elseif(ANDROID)
    add_library(backends STATIC
        src/gl.c
        src/gles2.c
    )
    target_compile_definitions(backends PUBLIC VK_USE_PLATFORM_ANDROID_KHR)
endif()

target_include_directories(backends PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
