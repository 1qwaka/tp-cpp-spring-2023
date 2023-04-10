#include <algorithm> 
#include <cctype>
#include <locale>

#include "tokenizer.h"



using std::string;
using std::vector;
using std::cout, std::cin, std::endl;


vector<Token> arithmetic_tokenizer::tokenize(const string &expr) {
    vector<Token> tokens;
    bool error = false;

    for (size_t pos = 0; pos < expr.size() && !error; pos++) {
        char c = expr[pos];

        switch (c)
        {
        case ' ':
            break;

        case '+': {
            tokens.emplace_back(TokenType::kSumOp);
            break;
        }
        
        case '-': {
            tokens.emplace_back(TokenType::kSubOp);
            break;
        }
        
        case '/': {
            tokens.emplace_back(TokenType::kDivOp);
            break;
        }
        
        case 'r': {
            if (expr.substr(pos).find("round") == 0) {
                tokens.emplace_back(TokenType::kRoundFunc);
                pos += string("round").size() - 1;
            } else {
                error = true;
            }

            break;
        }
        
        case 'f': {
            if (expr.substr(pos).find("floor") == 0) {
                tokens.emplace_back(TokenType::kFloorFunc);
                pos += string("floor").size() - 1;
            }
            else {
                error = true;
            }

            break;
        }

        case '(': {
            tokens.emplace_back(TokenType::kOpenBracket);
            break;
        }

        case ')': {
            tokens.emplace_back(TokenType::kCloseBracket);
            break;
        }
        
        default: {
            if (c >= '0' && c <= '9') {
                size_t num_begin = pos;
                
                while (pos < expr.size() && expr[pos] >= '0' && expr[pos] <= '9')
                    pos++;
                tokens.emplace_back(TokenType::kNumber, expr.substr(num_begin, pos - num_begin));
                pos--;
            } else {
                error = true;
            }

            break;
        }
        }

    }


    if (error) {
        tokens.clear();
    }
    
    return tokens;
}
