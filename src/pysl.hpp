#include <iostream>
#include <vector>

namespace pysl {
using std::cout;

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