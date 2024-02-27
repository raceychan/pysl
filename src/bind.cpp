#include <pybind11/pybind11.h>

auto add(const int &i, const int &j) -> int {
    return i + j;
}

// =========================================
PYBIND11_MODULE(pysl, m) {
    m.doc() = "python standard lib implemented in c++"; // optional module docstring
    m.def("add", &add, "A function which adds two numbers");
}
