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
    MyApplication();
    ~MyApplication();

    void run() override;

private:
    std::unique_ptr<nt::Window> m_window;
    std::unique_ptr<nt::Renderer> m_renderer;
};

#endif // _APP_H_
"""

# Define the contents of App.cpp
app_cpp_contents = """
#ifndef _APP_CPP_
    #define _APP_CPP_

#include \"App.h\"

MyApplication::MyApplication()
{
    m_window   = std::make_unique<nt::Window>();
    m_renderer = std::make_unique<nt::Renderer>();

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

    if (!m_renderer->initialize(*m_window))
    {
        nt::Logger::error(\"Failed to initialize renderer!\");
        abort();
    }
}

MyApplication::~MyApplication()
{
    m_window.reset();
    m_renderer.reset();
}

void MyApplication::run()
{
    nt::Vertex a(nt::Vec3f( 0.5f, -0.5f, 0.0f), nt::Vec2f(0.0f, 0.0f), NT_COLOR_RED);
    nt::Vertex b(nt::Vec3f(-0.5f, -0.5f, 0.0f), nt::Vec2f(1.0f, 0.0f), NT_COLOR_GREEN);
    nt::Vertex c(nt::Vec3f(-0.0f,  0.5f, 0.0f), nt::Vec2f(0.5f, 1.0f), NT_COLOR_BLUE);

    while (m_window->pollEvents())
    {
        if (nt::Input<nt::InputType::KEYBOARD>::isKeyPressed(nt::Key::ESCAPE))
            break;

        m_window->update();
        m_renderer->clear(NT_COLOR_WHITE);
        m_renderer->beginFrame();
        m_renderer->drawTriangle(a, b, c);
        m_renderer->endFrame();
        m_renderer->swapBuffers();
    }

    m_window->close();
}

#endif // _APP_CPP_
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

add_executable(${PROJECT_NAME} App.cpp Main.cpp)

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

# Generate App.cpp
if not os.path.exists(os.path.join(gen_dir, 'App.cpp')):
    with open(os.path.join(gen_dir, 'App.cpp'), 'w') as f:
        f.write(app_cpp_contents)

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
