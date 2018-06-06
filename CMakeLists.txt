cmake_minimum_required(VERSION 3.6)   # CMake version check
project(simple_example)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 17)            # Enable c++11 standard

set(SOURCE_FILES main.cpp Nuoma.cpp ApartamentuNuoma.cpp AbsNuoma.cpp Data.cpp)            # Add main.cpp file of project root directory as source file
add_executable(simple_example ${SOURCE_FILES}) # Add executable target with source files listed in SOURCE_FILES variable

