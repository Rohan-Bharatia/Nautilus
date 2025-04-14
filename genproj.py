import os

# Define the directory where the files will be generated
gen_dir = '../'

# Define the contents of App.h
app_h_contents = """
#pragma once

#ifndef _APP_H_
    #define _APP_H_

#include \"Nautilus/Nautilus.h\"

class MyApplication :
    public nt::Application
{
public:
    MyApplication()
    {
        m_window = std::make_unique<nt::Window>();

        nt::Logger::debug(\"Nautilus Engine v%s\", NT_VERSION_STR);
        nt::Logger::debug(R\"(
                               GNU GENERAL PUBLIC LICENSE
                                  Version 3, 29 June 2007

            Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
            Everyone is permitted to copy and distribute verbatim copies
            of this license document, but changing it is not allowed.
                                            ...

                             Copyright (c) Rohan Bharatia 2025
        )\");

        nt::WindowDesc desc{};

        if (!m_window->initialize(desc))
        {
            nt::Logger::error(\"Failed to initialize window!\");
            abort();
        }
    }

    ~MyApplication()
    {
        m_window.reset();
    }

    void run() override
    {
        while (m_window->pollEvents())
        {
            if (nt::Input<nt::InputType::KEYBOARD>::isKeyPressed(nt::Key::ESCAPE))
                break;
            m_window->update();
        }

        m_window->close();
    }

private:
    std::unique_ptr<nt::Window> m_window;
};

#endif // _APP_H_
"""

# Define the contents of Main.cpp
main_cpp_contents = """
#include \"App.h\"

int main()
{
    std::unique_ptr<MyApplication> app = std::make_unique<MyApplication>();

    app->run();

    return 0;
}
"""

# Define the contents of CMakeLists.txt
cmake_contents = """
cmake_minimum_required(VERSION 3.10)

project(Main)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Nautilus)

add_executable(${PROJECT_NAME} Main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC Nautilus)
"""

# Define the contents of Build.bat/Build.sh
if os.name == 'nt':
    build_contents = """
@echo off

@echo Creating build directory...
if not exist Build mkdir Build

cd Build
@echo Building project with CMake -> MinGW Makefiles...
cmake -G \"MinGW Makefiles\" ..
cmake --build .
cd ..
    """
else:
    build_contents = """
#!/bin/bash

echo \"Creating build directory...\"
if [ ! -d "Build" ]; then
    mkdir Build
fi
cd Build
echo \"Building project with CMake -> Unix Makefiles...\"
cmake -G \"Unix Makefiles\" ..
cmake --build .
cd ..
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

# Generate Build.bat/Build.sh
if os.name == 'nt':
    if not os.path.exists(os.path.join(gen_dir, 'Build.bat')):
        with open(os.path.join(gen_dir, 'Build.bat'), 'w') as f:
            f.write(build_contents)
else:
    if not os.path.exists(os.path.join(gen_dir, 'Build.sh')):
        with open(os.path.join(gen_dir, 'Build.sh'), 'w') as f:
            f.write(build_contents)
