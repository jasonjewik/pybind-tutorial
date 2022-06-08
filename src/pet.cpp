#include <pybind11/pybind11.h>
#include <string>

namespace py = pybind11;

struct Pet {
    Pet(const std::string &name) : name(name) { }
    void setName(const std::string &name_) { name = name_; }
    const std::string &getName() const { return name; }

    std::string name;
};

PYBIND11_MODULE(pet_clib, m) {
    m.doc() = "pybind11 example custom data structure";

    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &>())
        .def("set_name", &Pet::setName)
        .def("get_name", &Pet::getName);
}