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
$ mkdir build && cd build && cmake .. && make
```

Running the examples:
```bash
$ python3 scripts/[file].py
```