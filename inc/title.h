#pragma once

#include <string>

namespace title {
    inline size_t parseId(const std::string& id) {
        return std::stoul(id.substr(2));
    }
}