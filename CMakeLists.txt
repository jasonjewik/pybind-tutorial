cmake_minimum_required(VERSION 3.18)
project(pybind-tutorial)

# Do not run cmake in the main project directory, to keep
# build artifacts from becoming clutter
if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "In source builds not allowed.
    Please make a build directory and run CMake from there.
    You may need to remove CMakeCache.txt")
endif()

# Let the user specify what type of build they want
option(SHARED_LIBS "Build shared libs for use by Python" OFF)
option(EXEC "Build executables" OFF)

# Enable compiler warnings
add_compile_options(-Wall -Wextra -pedantic)

# Point to libraries path
include_directories(${CMAKE_SOURCE_DIR}/src/lib)

if (SHARED_LIBS)
    # Find Python libraries
    find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
    find_package(PythonLibs 3.0 REQUIRED)
    find_package(pybind11 REQUIRED)
    include_directories(${Python3_INCLUDE_DIRS})

    # Build shared libraries
    set(BUILD_SHARED_LIBS ON)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/shared)
    pybind11_add_module(example_clib src/lib/example.cpp src/bind/example.cpp)
    pybind11_add_module(pet_clib src/lib/pet.cpp src/bind/pet.cpp)
endif()


if (EXEC)
    # Build executables
    set(BUILD_SHARED_LIBS OFF)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    add_library(examplelib src/lib/example.cpp)
    add_library(petlib src/lib/pet.cpp)
    add_executable(main src/main.cpp)
    target_link_libraries(main examplelib petlib)
endif()