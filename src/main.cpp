#include <iostream>
#include <vector>
#include <string>

#include "tokenizer.h"
#include "expression_transformer.h"
#include "expression_tree.h"


using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::vector;
using std::string;

static constexpr int kWrongArgs = 1;
static constexpr int kWrongTokens = 2;
static constexpr int kWrongExpr = 3;

/**
 * 
 */

int main(int argc, char **argv) {
    if (argc == 1) {
        cerr << "provide an expression" << endl;
        return kWrongArgs;
    }

    if (argc > 2) {
        cerr << "too much arguments" << endl;
        return kWrongArgs;
    }

    string s(argv[1]);
    vector<Token> tokens = arithmetic_tokenizer::tokenize(s);

    if (tokens.empty()) {
        cerr << "invalid tokens in expression" << endl;
        return kWrongTokens;
    }


#ifdef DEBUG
    std::cout << "TOKENS SIZE = " << tokens.size() << std::endl;
    for (auto &tok : tokens) {
        std::cout << tok << " ";
    }
    std::cout << std::endl;
#endif


    vector<Token> postfix = expression_transformer::infix_to_postfix(tokens);

    if (postfix.empty()) {
        cerr << "invalid expression" << endl;
        return kWrongExpr;
    }


#ifdef DEBUG
    std::cout << "POSTFIX SIZE = " << postfix.size() << std::endl;
    for (auto &tok : postfix) {
        std::cout << tok << " ";
    }
    std::cout << std::endl;
#endif


    ExpressionTree expr_tree(postfix);
    double res = expr_tree.getRoot()->calculate();

    cout << res << endl;

    return 0;
}
