#include <iostream>


#include "PrincipalsParser.h"
#include "title.h"


PrincipalsParser::PrincipalsParser(const std::string& path): TSVParser(path) { }

void PrincipalsParser::getTitleIdsByCharacterName(std::vector<size_t>& ids, const std::string& name) {
    processByPred(
    [this](std::vector<std::string>& fields) -> bool {
        return isActorCategory(fields[kCategoryIdx]);
    },
    [&](std::vector<std::string>& fields) {
        if (fields[kCharactersIdx].find(name) != std::string::npos) 
            ids.push_back(title::parseId(fields[kTitleIdIdx]));
    });
}

bool PrincipalsParser::isActorCategory(const std::string& category) {
    return category.find(kActorCategory) != std::string::npos || 
            category.find(kActressCategory) != std::string::npos;
}

