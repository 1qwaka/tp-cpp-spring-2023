#include <algorithm> 
#include <cctype>
#include <locale>

#include "tokenizer.h"



using std::string;
using std::vector;
using std::array;
using std::cout, std::cin, std::endl;

static vector<Token> postprocess(vector<Token> &tokens);

static constexpr bool allow_after_num(char c) {
    return c == ' ' || c == '+' || c == '-' || c == '/' || c == '\0' || c == ')';
}

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

                char *end;
                double num_value = std::strtod(expr.c_str() + num_begin, &end);

                if (allow_after_num(*end)) {
                    pos = end - expr.c_str();
                    tokens.emplace_back(TokenType::kNumber, expr.substr(num_begin, pos - num_begin));
                    pos--;
                } else {
                    error = true;
                }

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

static vector<Token> postprocess(vector<Token> &tokens) {
    vector<Token>processed;

    for (size_t i = 1; i < tokens.size() - 1; i++) {
        // if ()
    }
    
    return processed;
}
