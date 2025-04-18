# Nautilus

Nautilus is an open-source 3d game engine written in modern C++.

## License

This project is released under the [GNU General Public License](https://www.gnu.org/licenses/gpl-3.0.en.html).

## Requirements & Dependencies

This project is built in C++23 with [CMake](https://cmake.org).

---

### Platform Specific Dependencies

|*Platform*|*Windowing API*|*Graphics API*|
|-|-|-|
|Windows|Win32 API|OpenGL or Vulkan|
|Linux/BSD|XLib|OpenGL or Vulkan|
|MacOS|Cocoa|OpenGL or Vulkan|
|iOS|UIKit|OpenGL or Vulkan|
|Android|Android JNI|OpenGL or Vulkan|
|WASM|Emscripten HTML5|OpenGL ~~or Vulkan~~|

## Project Generation

Run the [`genproj.py`](https://github.com/Rohan-Bharatia/Nautilus/blob/main/genproj.py) script to generate a CMake project for your platform.
