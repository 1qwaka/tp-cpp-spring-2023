#include "splitter.h"

void splitter::split(const std::string& src, std::vector<std::string>& dst, char delim, bool take_empty) {
    size_t last_idx = 0;

    while (last_idx < src.size()) {
        size_t delim_idx = src.find(delim, last_idx);
        
        if (delim_idx == std::string::npos) {
            dst.push_back(src.substr(last_idx, src.size() - last_idx));
            break;
        }
        
        if (take_empty && delim_idx - last_idx == 0) {
            ++last_idx;
            continue;
        }

        dst.push_back(src.substr(last_idx, delim_idx - last_idx));
        last_idx = delim_idx + 1;
    }
}
