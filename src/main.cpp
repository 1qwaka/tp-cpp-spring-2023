#include <iostream>
#include <vector>
#include <string>

#include "tokenizer.h"
#include "expression_transformer.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

struct Cal {
    std::string bob;
};


int main() {
    //               1 1 2 5 - / +
    std::string s = "1 + 1 / (2 - 5)";
    // std::string s = "1 + 1 / (2 - 5) / 4";

    auto tokens = arithmetic_tokenizer::tokenize(s);

    std::cout << "size = " << tokens.size() << std::endl;

    for (auto &tok : tokens) {
        std::cout << tok << " ";
    }
    std::cout << std::endl;

    vector<Token> postfix = expression_transformer::infix_to_postfix(tokens);

    for (auto &tok : postfix) {
        std::cout << tok << " ";
    }
    std::cout << std::endl;



    return 0;
}
