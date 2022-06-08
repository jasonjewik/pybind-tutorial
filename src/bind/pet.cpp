#include <pybind11/pybind11.h>
#include "pet.h"

namespace py = pybind11;

PYBIND11_MODULE(pet_clib, m) {
    m.doc() = "pybind11 example custom data structure";

    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &, int>())
        // We can bind the getter and setter to new names
        .def("get_name", &Pet::getName)
        .def("set_name", &Pet::setName)
        // Or we can use Python's property getter/setter
        .def_property("age", &Pet::getAge, &Pet::setAge)
        .def("__repr__",
            [](const Pet &a) {
                return "Pet('" + a.getName() + "')";
            }
        );
}