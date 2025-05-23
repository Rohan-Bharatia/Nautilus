@echo off

@echo Generate preprocessor files with Python...
python3 Scripts/genPCH.py
python3 Scripts/genDefs.py

@echo Creating build directory...
if not exist Build mkdir Build

@echo Compiling with CMake...
cd Build
cmake -G "MinGW Makefiles" -S ../Sandbox
cmake --build .

@echo Done...
cd ..
exit 0
