if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    add_library(window STATIC
        WindowBase.cpp
        WindowWin32.cpp
    )
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Linux|BSD")
    add_library(window STATIC
        WindowBase.cpp
        WindowX11.cpp
    )
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    add_library(window STATIC
        WindowBase.cpp
        WindowCocoa.mm
    )
endif()

if(CMAKE_SYSTEM_NAME MATCHES "iOS")
    add_library(window STATIC
        WindowBase.cpp
        WindowUIKit.mm
    )
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Android")
    add_library(window STATIC
        WindowBase.cpp
        WindowAndroid.cpp
    )
endif()

target_include_directories(window PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
