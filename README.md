# Nautilus

Nautilus is an open-source 3d game engine written in modern C++.

## License

This project is released under the [GNU General Public License](https://www.gnu.org/licenses/gpl-3.0.en.html).

## Requirements & Dependencies

This project is built in C++23.

---

|*Platform*|*Windowing API*|*Graphics API*|
|-|-|-|
|Windows|Win32 API|DirectX 12|
|Unix (Not Apple)|XLib|OpenGL 4.6|
|MacOS|Cocoa|Metal 3|
|iOS|UIKit|Metal 3|
|Android|Android JNI|OpenGL ES 3.2|

## Project Generation

Run the [`Genproj.py`](https://github.com/Rohan-Bharatia/Nautilus/blob/main/Genproj.py) script to generate a CMake project for your platform.
