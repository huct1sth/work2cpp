@echo off
pushd .

if exist build (
     rm -r build
     md build
)

if not exist build (
     md build
)

cd build
cmake -G"MinGW Makefiles" C:\Users\20486\Desktop\cpp-training
mingw32-make.exe

popd
