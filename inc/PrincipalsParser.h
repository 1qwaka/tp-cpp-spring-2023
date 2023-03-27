#pragma once

#include "TSVParser.h"

#include <string_view>


class PrincipalsParser : TSVParser
{
    static constexpr size_t kTitleIdIdx = 0;
    static constexpr size_t kCategoryIdx = 3;
    static constexpr size_t kCharactersIdx = 5;

    static constexpr std::string_view kActorCategory = "actor";
    static constexpr std::string_view kActressCategory = "actress";

public:
    PrincipalsParser(const std::string& path);
    void getTitleIdsByCharacterName(std::vector<size_t>& ids, const std::string& name);

private:
    size_t getTitleId(const std::string& titleIdStr);
    bool isActorCategory(const std::string& category);

};
