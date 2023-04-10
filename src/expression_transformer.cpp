#include "expression_transformer.h"

#include <stack>
#include <queue>

using std::stack;
using std::queue;


// верное количество скобок
// нет двух чисел подряд
// нет двух операторов подряд
// выражение не начинается с оператора


vector<Token> expression_transformer::infix_to_postfix(vector<Token> tokens) {
    queue<Token> result;
    stack<Token> operations;

    for (Token &tok : tokens) {
        switch (tok.type_)
        {
        case TokenType::kNumber: {
            result.push(tok);
            break;
        }
        
        case TokenType::kSumOp:
        case TokenType::kSubOp:
        case TokenType::kDivOp: {
            if (operations.empty() || 
                operations.top().type_ == TokenType::kOpenBracket ||
                tok.type_ > operations.top().type_) {
                operations.push(tok);
                break;
            }

            while (!operations.empty() && operations.top().type_ >= tok.type_) {
                result.push(operations.top());
                operations.pop();
            }
            
            operations.push(tok);

            break;
        }

        case TokenType::kOpenBracket: {
            operations.push(tok);
            break;
        }

        case TokenType::kCloseBracket: {
            while (operations.top().type_ != TokenType::kOpenBracket) {
                result.push(operations.top());
                operations.pop();
            }
            
            operations.pop();

            break;
        }

        default:
            break;
        }
    }

    while (!operations.empty()) {
        result.push(operations.top());
        operations.pop();
    }

    vector<Token> ret;
    while (!result.empty()) {
        ret.push_back(result.front());
        result.pop();
    }

    return ret;
}
