#!/bin/bash

echo "Generate preprocessor files with Python..."
python3 Scripts/genPCH.py
python3 Scripts/genDefs.py

echo "Creating build directory..."
mkdir -p Build

echo "Compiling with CMake..."
cd Build
cmake -G "Unix Makefiles" -S ../Sandbox
cmake --build .

echo "Done..."
cd ..
exit 0
