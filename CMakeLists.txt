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

    pybind11_add_module(basic_math_clib src/lib/basic_math.cpp src/bind/basic_math.cpp)
    pybind11_add_module(person_clib src/lib/person.cpp src/bind/person.cpp)
endif()


if (EXEC)
    # Build executables
    set(BUILD_SHARED_LIBS OFF)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

    add_library(basicmathlib src/lib/basic_math.cpp)
    add_library(personlib src/lib/person.cpp)
    add_executable(basic_example src/basic_example.cpp)
    target_link_libraries(basic_example basicmathlib personlib)

    add_library(eventdispatcherlib src/lib/event_dispatcher.cpp)
    add_library(eventlib src/lib/event.cpp)
    add_library(petlib src/lib/pet.cpp)
    add_executable(adv_example src/adv_example.cpp)
    target_link_libraries(adv_example eventdispatcherlib eventlib petlib)
endif()