#include "TSVParser.h"
#include "splitter.h"

TSVParser::TSVParser(const std::string& path) {
    file_.open(path);
    
    if (!file_.is_open())
        throw std::runtime_error("cannot open file: " + path);
    
    readHeaders();
}

void TSVParser::processByPred(TSVRecordPredicate pred, TSVRecordProcessor proc) {
    std::vector<std::string> fields;
    
    for (std::string line; std::getline(file_, line); ) {
        fields.clear();
        splitter::split(line, fields, kFieldsDelim);
        
        if (pred(fields))
            proc(fields);
    }
}

void TSVParser::processLines(TSVRecordProcessor proc) {
    std::vector<std::string> fields;
    
    for (std::string line; std::getline(file_, line); ) {
        fields.clear();
        splitter::split(line, fields, kFieldsDelim);
        proc(fields);
    }
}

void TSVParser::readHeaders() {
    std::string head;
    std::getline(file_, head);
    splitter::split(head, headers_, kFieldsDelim);
}