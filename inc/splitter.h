#pragma once

#include <string>
#include <vector>

namespace splitter {
    void split(const std::string& src, std::vector<std::string>& dst, char delim, bool take_empty=true);
}
