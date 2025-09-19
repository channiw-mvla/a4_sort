cmake_minimum_required(VERSION 3.10)
# Set the C++ standard to C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# used internally by CMake to identify your project
project(a4_sort)
# Include a4_sort directory headers are located
include_directories(${CMAKE_SOURCE_DIR}/include)
# Add the main executable
add_executable(a4_sort src/main.cpp src/array_bounds.cpp)