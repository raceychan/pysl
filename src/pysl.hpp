#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace pysl {
using std::cout, std::string, std::vector;
vector<string> split(const string &s, const string &delimiter);

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec) {
    os << "{";
    if (!vec.empty()) {
        auto it = vec.begin();
        os << *it;
        ++it;
        while (it != vec.end()) {
            os << ", " << *it;
            ++it;
        }
    }
    os << "}";
    return os;
}
template <typename... Args>
concept StreamInsertable = requires(Args... args, std::ostream &os) {
    { (os << ... << args) } -> std::same_as<std::ostream &>;
};

template <StreamInsertable... Args>
void print(const Args &...args) {
    ((cout << args << ' '), ...);
    cout << '\n';
};
} // namespace pysl