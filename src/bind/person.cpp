#include <pybind11/pybind11.h>
#include "person.h"

namespace py = pybind11;

PYBIND11_MODULE(person_clib, m) {
    m.doc() = "pybind11 example custom data structure";

    py::class_<Person>(m, "Person")
        .def(py::init<const std::string &, int>())
        // We can bind the getter and setter to new names
        .def("get_name", &Person::getName)
        .def("set_name", &Person::setName)
        // Or we can use Python's property getter/setter
        .def_property("age", &Person::getAge, &Person::setAge)
        .def("__repr__",
            [](const Person &a) {
                return "Person('" + a.getName() + "')";
            }
        );
}