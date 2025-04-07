import os

# Define the directory where the files will be generated
gen_dir = '../'

# Define the contents of App.h
app_h_contents = """
#pragma once

#ifndef _APP_H_
    #define _APP_H_

#include "Nautilus/Nautilus.h"

class MyApplication :
    public nt::Application
{
public:
    MyApplication()
    {
        nt::Logger::debug("Nautilus Engine v%s", NT_VERSION_STR);
        nt::Logger::debug(R"(
                               GNU GENERAL PUBLIC LICENSE
                                  Version 3, 29 June 2007

            Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
            Everyone is permitted to copy and distribute verbatim copies
            of this license document, but changing it is not allowed.
                                            ...

                             Copyright (c) Rohan Bharatia 2025
        )");

        nt::WindowDesc desc;
        desc.x       = 100;
        desc.y       = 100;
        desc.width   = 1024;
        desc.height  = 768;
        desc.title   = "Nautilus Engine Application";
        desc.bgColor = NT_COLOR_DEFAULT;
        window.create(desc);

        if (!renderer.initialize(window.getNativeHandle(), window.getSize()))
            abort();
    }

    void run() override
    {
        while (window.pollEvents())
        {
            if (nt::Event<nt::EVENT_KEYBOARD>::isKeyPressed(VK_ESCAPE))
                break;

            window.update();
            renderer.clear(NT_COLOR_WHITE);
        }

        renderer.shutdown();
        window.destroy();
    }

private:
    nt::Window window;
    nt::Renderer renderer;
};

#endif // _APP_H_
"""

# Define the contents of Main.cpp
main_cpp_contents = """
#include \"App.h\"

int main()
{
    MyApplication app;

    app.run();

    return 0;
}
"""

# Define the constants of CMakeLists.txt
cmake_contents = """
cmake_minimum_required(VERSION 3.10)

project(Main)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Nautilus)

add_executable(${PROJECT_NAME} Main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC Nautilus)
"""

# Generate App.h
if not os.path.exists(os.path.join(gen_dir, 'App.h')):
    with open(os.path.join(gen_dir, 'App.h'), 'w') as f:
        f.write(app_h_contents)

# Generate Main.cpp
if not os.path.exists(os.path.join(gen_dir, 'Main.cpp')):
    with open(os.path.join(gen_dir, 'Main.cpp'), 'w') as f:
        f.write(main_cpp_contents)

# Generate CMakeLists.txt
if not os.path.exists(os.path.join(gen_dir, 'CMakeLists.txt')):
    with open(os.path.join(gen_dir, 'CMakeLists.txt'), 'w') as f:
        f.write(cmake_contents)
