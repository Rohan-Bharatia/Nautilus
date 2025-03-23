if(WIN32)
    add_library(window STATIC
        WindowBase.cpp
        WindowWin32.cpp
    )
elseif(UNIX AND NOT APPLE)
    add_library(window STATIC
        WindowBase.cpp
        WindowX11.cpp
    )
elseif(APPLE)
    add_library(window STATIC
        WindowBase.cpp
        WindowCocoa.mm
    )
elseif(IOS)
    add_library(window STATIC
        WindowBase.cpp
        WindowUIKit.mm
    )
elseif(ANDROID)
    add_library(window STATIC
        WindowBase.cpp
        WindowAndroid.cpp
    )
endif()

target_include_directories(window PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR})
