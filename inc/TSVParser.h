#pragma once


#include <string>
#include <vector>
#include <fstream>
#include <functional>

using TSVRecordPredicate = std::function<bool(std::vector<std::string>&)>;
using TSVRecordProcessor = std::function<void(std::vector<std::string>&)>;

class TSVParser {

    static constexpr char kFieldsDelim = '\t';

    std::vector<std::string> headers_;
    std::ifstream file_;

public:
    TSVParser(const std::string& path);
    void processByPred(TSVRecordPredicate pred, TSVRecordProcessor proc);
    void processLines(TSVRecordProcessor proc);

private:
    void readHeaders();

};
