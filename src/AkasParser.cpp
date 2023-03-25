#include "AkasParser.h"

#include <iostream>

AkasParser::AkasParser(const std::string& path): TSVParser(path) { }

void AkasParser::printRuNames(std::vector<size_t>& title_ids) {
    processByPred(
    [](std::vector<std::string>& fields) -> bool {
        return fields[kRegionIdx] == kRuRegion || fields[kLanguageIdx] == kRuLanguage;
    }, 
    [](std::vector<std::string>& fields) {
        std::cout << fields[kTitleNameIdx] << std::endl;
    });
}