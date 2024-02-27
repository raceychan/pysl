#include "pysl.hpp"

namespace pysl {
vector<string> split(const string &s, const string &delimiter) {
    vector<string> res;
    size_t pos = 0;
    size_t gap = delimiter.size();
    string token;

    while (pos < s.length()) {
        size_t found = s.find(delimiter, pos);

        if (found != string::npos) {
            token = s.substr(pos, found - pos);
            res.push_back(token);
            pos = found + gap;
        } else {
            token = s.substr(pos);
            res.push_back(token);
            break;
        }
    }
    return res;
}

}; // namespace pysl