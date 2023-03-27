#pragma once

#include "TSVParser.h"


class AkasParser : TSVParser {

    static constexpr size_t kTitleIdIdx = 0;
    static constexpr size_t kTitleNameIdx = 2;
    static constexpr size_t kRegionIdx = 3;
    static constexpr size_t kLanguageIdx = 4;

    static constexpr std::string_view kRuRegion = "RU";
    static constexpr std::string_view kRuLanguage = "ru";

public:
    AkasParser(const std::string& path);
    void printRuNames(std::vector<size_t>& title_ids);
};
