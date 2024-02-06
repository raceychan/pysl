// #include <iostream>
#include <pybind11/pybind11.h>
#include <string>
#include <utility>

namespace py = pybind11;

auto add(int i, int j) -> int {
    return i + j;
}

struct Pet {
private:
    std::string name;

public:
    explicit Pet(std::string name) :
        name(std::move(name)) {
    }
    void set_name(const std::string &name_) {
        name = name_;
    }
    [[nodiscard]] auto get_name() const -> const std::string & {
        return name;
    }
};

PYBIND11_MODULE(pysl, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("add", &add, "A function which adds two numbers");
    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &>())
        .def("set_name", &Pet::set_name)
        .def("get_name", &Pet::get_name);
}