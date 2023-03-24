#include "splitter.h"

void splitter::split(std::string& src, std::vector<std::string>& dst, char delim) {
    size_t last_idx = 0;
    while (last_idx < src.size()) {
        size_t delim_idx = src.find(delim, last_idx);
        dst.push_back(src.substr(last_idx, delim_idx - last_idx));
    }
}