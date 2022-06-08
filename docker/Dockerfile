FROM ubuntu

# Install packages
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    python3 \
    python3-dev \
    python3-pip

RUN pip3 install "pybind11[global]"

# We are going to mount the current working directory into my-project
RUN mkdir -p /home/my-project

# When running the container, we'll start in my-project
WORKDIR /home/my-project
CMD ["/bin/bash"]