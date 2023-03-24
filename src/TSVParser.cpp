#include "TSVParser.h"

TSVParser::TSVParser(const std::string& path) {
    file_.open(path);
}