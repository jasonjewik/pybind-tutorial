cmake_minimum_required(VERSION 3.18)
project(pybind-tutorial)

# Do not run cmake in the main project directory, to keep
# build artifacts from becoming clutter
if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "In source builds not allowed.
    Please make a build directory and run CMake from there.
    You may need to remove CMakeCache.txt")
endif()

# Enable compiler warnings
add_compile_options(-Wall -Wextra -pedantic)

# Find Python libraries
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
find_package(PythonLibs 3.0 REQUIRED)
find_package(pybind11 REQUIRED)
include_directories(${Python3_INCLUDE_DIRS})
include_directories(include)

# Build shared libraries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/shared)
pybind11_add_module(example SHARED src/example.cpp)