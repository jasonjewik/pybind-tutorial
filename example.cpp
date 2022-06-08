#include <pybind11/pybind11.h>

namespace py = pybind11;

int add(int i, int j) {
    return i + j;
}

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    // Use the literals namespace
    // Otherwise, arguments have to be specified like py::arg("i")
    using namespace py::literals;
    m.def("add", &add, "A function that adds two numbers", "i"_a=1, "j"_a=2);
}