#pragma once
 
#include <iostream>
#include <string>
#include <vector>

#include <token.h>

namespace arithmetic_tokenizer {
    std::vector<Token> tokenize(const std::string &expr);
};
