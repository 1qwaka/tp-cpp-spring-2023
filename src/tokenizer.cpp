#include <algorithm> 
#include <cctype>
#include <locale>

#include "tokenizer.h"



using std::string;
using std::vector;
using std::cout, std::cin, std::endl;


// static vector<string> tokenize_str(const string &buffer);

// static const vector<char> kAllowAfterNum = { ' ', '+', '-', '/' };


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

        // for (auto &tok : tokens) {
        //     std::cout << tok << " ";
        // }
        // std::cout << "error=" << error << std::endl;
        // std::cout << std::endl;
    }


    if (error) {
        tokens.clear();
    }
    
    return tokens;
}

// // trim from start (in place)
// static inline void ltrim(string &s) {
//     s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
//         return !std::isspace(ch);
//     }));
// }

// // trim from end (in place)
// static inline void rtrim(string &s) {
//     s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
//         return !std::isspace(ch);
//     }).base(), s.end());
// }

// // trim from both ends (in place)
// static inline void trim(string &s) {
//     rtrim(s);
//     ltrim(s);
// }

// static void inner_push(vector<string> &to, const string &from) {
//     string str = from;
//     trim(str);
//     if (!str.empty()) {
//         to.push_back(str);
//     }
// }


// static vector<string> tokenize_str(const string &buffer) {
//     vector<string> str_tokens;

//     ssize_t start = -1;
//     ssize_t end = 0;
//     size_t length = buffer.size();

//     while (end < length) {
//         switch (buffer.at(end)) {
//             case '+':
//             case '-':
//             case '*':
//             case '/':
//             case '(':
//             case ')':
//                 inner_push(str_tokens, buffer.substr(start + 1, end - start - 1));
//                 inner_push(str_tokens, {buffer.at(end)});
//                 start = end++;
//                 continue;
//         }
//         if (end == (length - 1)) {
//             inner_push(str_tokens, buffer.substr(start + 1, end - start));
//         }
//         ++end;
//     }

//     return str_tokens;
// }
