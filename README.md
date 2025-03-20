# Nautilus

Nautilus is a cross-platform open source game engine written in modern C++ from scratch.

## License

This repository is licensed under the [GNU General Public License v3.0](https://github.com/Rohan-Bharatia/Nautilus/blob/main/LICENSE)

## Dependencies

### CMake

Nautilus uses [CMake](https://cmake.org/) for building.

[Download CMake](https://cmake.org/download/)

### Platform

|**Platform**|**System Deps**|
|-|-|
|Windows|~~Windows API~~|
|Linux|[XLib](https://github.com/walklang/Xlib)|
|BSD|[XLib](https://github.com/walklang/Xlib)|
|MAC OS|~~Cocoa~~|
|iOS|[UIKit](https://github.com/uikit/uikit)|
|Android|[Android SDK](https://developer.android.com/studio)|

## Usage

Create a file called `main.cpp` and use the following `CMakeLists.txt` file for it:

```cmake
cmake_minimum_required(VERSION 3.10)

project(Main)

add_executable(Main main.cpp)

target_link_libraries(Main PUBLIC Nautilus)
```

Here is an example of what `main.cpp` could look like:

```cpp
#include "Nautilus/Nautilus.h"

int main(int argc, char* argv[])
{
    // Window settings
    nt::WindowDesc desc{};
    desc.position.x      = 100;
    desc.position.y      = 100;
    desc.width           = 1024;
    desc.height          = 768;
    desc.title           = "Nautilus Application";
    desc.backgroundColor = NT_COLOR_DEFAULT;

    // Create window agent
    nt::WindowPtr window = nt::createWindow(desc);

    if (!window)
        return NT_EXIT_MINOR_ERROR;

    // Initialize
    window->initialize();

    // Main loop
    while (window->pollEvents())
    {
        // Exit condition
        if (nt::Event::isKeyPressed(VK_ESCAPE))
            break;

        // Draw frame
        window->update();
    }

    // Close window
    window->destroy();

    return NT_EXIT_SUCCESS;
}
```
