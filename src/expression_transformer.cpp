#include "expression_transformer.h"

#include <stack>
#include <queue>

using std::stack;
using std::queue;



vector<Token> expression_transformer::infix_to_postfix(vector<Token> tokens) {
    queue<Token> result;
    stack<Token> operations;
    bool error = false;

    for (Token &tok : tokens) {
        if (error)
            break;
            
        switch (tok.type_)
        {
        case TokenType::kNumber: {
            result.push(tok);
            break;
        }
        
        case TokenType::kFloorFunc:
        case TokenType::kRoundFunc:
        case TokenType::kSumOp:
        case TokenType::kSubOp:
        case TokenType::kDivOp: {
            if (operations.empty() || 
                operations.top().type_ == TokenType::kOpenBracket ||
                tok.type_ > operations.top().type_) {
                operations.push(tok);
                break;
            }

            while (!operations.empty() && 
                    operations.top().type_ >= tok.type_ && 
                    operations.top().type_ != TokenType::kOpenBracket) {
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
            while (!operations.empty() && operations.top().type_ != TokenType::kOpenBracket) {
                result.push(operations.top());
                operations.pop();
            }

            if (operations.empty())
                error = true;
            else
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
    while (!error && !result.empty()) {
        ret.push_back(result.front());
        result.pop();
    }

    return ret;
}
