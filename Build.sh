#!/bin/bash

python3 genPCH.py

echo "Creating build directory..."
mkdir -p Build

echo "Compiling with CMake..."
cd Build
cmake -G "Unix Makefiles" ../Sandbox
cmake --build .

echo "Done..."
cd ..
exit 0
