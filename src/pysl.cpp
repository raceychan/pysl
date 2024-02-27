#include "pysl.hpp"
#include <pybind11/pybind11.h>

namespace py = pybind11;

using std::string, std::declval, std::ostream, std::cout, std::size_t;

auto add(const int &i, const int &j) -> int {
    return i + j;
}

// =========================================
PYBIND11_MODULE(pysl, m) {
    m.doc() = "python standard lib implemented in c++"; // optional module docstring
    m.def("add", &add, "A function which adds two numbers");
    m.def("print", &pysl::print, "A function which prints a number");
}
