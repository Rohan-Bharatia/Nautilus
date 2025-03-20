if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    add_library(event STATIC
        Event.cpp
        EventWin32.cpp
    )
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Linux|BSD")
    add_library(event STATIC
        Event.cpp
        EventX11.cpp
    )
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    add_library(event STATIC
        Event.cpp
        EventCocoa.mm
    )
endif()

if(CMAKE_SYSTEM_NAME MATCHES "iOS")
    add_library(event STATIC
        Event.cpp
        EventUIKit.mm
    )
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Android")
    add_library(event STATIC
        Event.cpp
        EventAndroid.cpp
    )
endif()

target_include_directories(event PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
