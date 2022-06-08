# pybind11 Tutorial

## Description
Learning how to use pybind11.

## Usage
Everything should be done inside the Docker container.

Building and running the Docker image/container:
```bash
$ docker/build.sh
$ docker/run.sh
```

Building the source code:
```bash
$ mkdir build && cd build
$ cmake -DSHARED_LIBS=[<ON>/<OFF>] -DEXEC=[<ON>/<OFF>] ..
$ make
```
Specify `DSHARED_LIBS=ON` if you want to build shared libraries for use by Python. Specify `DEXEC=ON` if you want to build C++ executables (which will also build static libraries).

Running the examples:
```bash
$ python scripts/[file].py
```