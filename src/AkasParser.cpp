#include <iostream>
#include <algorithm>


#include "AkasParser.h"
#include "title.h"


AkasParser::AkasParser(const std::string& path): TSVParser(path) { }

void AkasParser::printRuNames(std::vector<size_t>& title_ids) {
    processByPred(
    [&title_ids](std::vector<std::string>& fields) -> bool {
        size_t titleId = title::parseId(fields[kTitleIdIdx]);
        return (fields[kRegionIdx] == kRuRegion || fields[kLanguageIdx] == kRuLanguage) &&
                std::find(title_ids.begin(), title_ids.end(), titleId) != title_ids.end();
    }, 
    [](std::vector<std::string>& fields) {
        std::cout << fields[kTitleNameIdx] << std::endl;
    });
}
