#pragma once
 
#include <iostream>
#include <string>
#include <vector>

#include <token.h>

namespace arithmetic_tokenizer {
    static constexpr int kNoError = 0;
    static constexpr int kUnknownFunction = 1;
    static constexpr int kInvalidNum = 2;
    static constexpr int kUnknownSymbol = 3;

    int tokenize(const std::string &expr, std::vector<Token> &result);
};
