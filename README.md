# Nautilus

Nautilus is an open-source 3d game engine written in modern C++.

## License

This project is released under the [GNU General Public License](https://www.gnu.org/licenses/gpl-3.0.en.html).

## Requirements & Dependencies

This project is built in C++23.

---

|*Platform*|*Windowing API*|*Graphics API*|
|-|-|-|
|Windows|Win32 API|OpenGL (WGL)|
|Unix (Not Apple)|XLib|OpenGL (GLX)|
|MacOS|Cocoa|OpenGL (CGL)|
|iOS|UIKit|OpenGL (CGL)|
|Android|Android JNI|OpenGL (GLES)|
|WASM|Emscripten HTML5|OpenGL (GLES)|

## Project Generation

Run the [`Genproj.py`](https://github.com/Rohan-Bharatia/Nautilus/blob/main/genproj.py) script to generate a CMake project for your platform.
