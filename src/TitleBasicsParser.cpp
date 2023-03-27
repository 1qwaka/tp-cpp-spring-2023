#include <algorithm>

#include "TitleBasicsParser.h"
#include "title.h"

TitleBasicsParser::TitleBasicsParser(const std::string& path): TSVParser(path) { };

void TitleBasicsParser::filterNonAdultIds(const std::vector<size_t>& src_ids, std::vector<size_t>& dst_ids) {
    processLines(
    [this, &src_ids, &dst_ids](std::vector<std::string>& fields){
        size_t titleId = title::parseId(fields[kTitleIdIdx]);
        
        if (std::find(src_ids.begin(), src_ids.end(), titleId) != src_ids.end()) {
            if (isNonAdult(fields[kIsAdultIdx])) 
                dst_ids.push_back(titleId);
        }
    });
}

bool TitleBasicsParser::isNonAdult(const std::string& adultField) {
    return adultField[kNonAdultStrFirstCharIdx] == kNonAdultStrFirstChar;
}
