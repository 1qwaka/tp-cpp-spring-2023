#pragma once

#include "TSVParser.h"


class TitleBasicsParser : TSVParser {

    static constexpr size_t kTitleIdIdx = 0;
    static constexpr size_t kIsAdultIdx = 4;

    static constexpr char kNonAdultStrFirstChar = '0';
    static constexpr size_t kNonAdultStrFirstCharIdx = 0;

public:
    TitleBasicsParser(const std::string& path);
    void filterNonAdultIds(const std::vector<size_t>& src_ids, std::vector<size_t>& dst_ids);

private:
    bool isNonAdult(const std::string& adultField);
};
