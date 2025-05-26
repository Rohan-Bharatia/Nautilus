# 📦 Building Nautilus Engine

Welcome to the build guide for the Nautilus Engine. This document will help you get started with compiling the engine on your platform of choice.

## 🚀 Quick Start

Nautilus Engine comes with simple build scripts tailored for different operating systems. All you need to do is run one of the following scripts from the root directory of the project:

### 🪟 On Windows

```bash
./Build.bat
```

> This script sets up the environment and builds the engine using a configured ```cmake``` toolchain.

### 🐧 On Linux, 🍎 MacOS, 📱 iOS, 🟢 Android, or 🕸️ WebAssembly

```bash
./Build.sh
```

> This script sets up the environment and builds the engine using a configured ```cmake``` toolchain.

## 🔧 Requirements

- A C++17 compatible compiler (Clang, GCC, ICC, MSVC, Borland, or CodeWarrior)
- CMake v3.16 or higher
- Python v3.0 or higher
- Platform specific SDK's

## 📝 Notes

- The scripts automatically detect your platform and configure the build accordingly.
- For platform-specific dependencies or troubleshooting, refer to the relevant documentation in the [Dependencies](https://github.com/Rohan-Bharatia/Nautilus/blob/main/docs/Dependencies.md) document.

## ❓ Need Help?

If you run into issues, feel free to check:

- Any contributor
- Nautilus Engine's [issue tracker](https://github.com/Rohan-Bharatia/Nautilus/issues)
