#include "token.h"


std::ostream &operator<<(std::ostream &os, TokenType const &type) {
    switch (type)
    {
    case TokenType::kNumber:
        return os << "kNumber";
    case TokenType::kSumOp:
        return os << "kSumOp";
    case TokenType::kSubOp:
        return os << "kSubOp";
    case TokenType::kDivOp:
        return os << "kDivOp";
    case TokenType::kRoundFunc:
        return os << "kRoundFunc";
    case TokenType::kFloorFunc:
        return os << "kFloorFunc";
    case TokenType::kOpenBracket:
        return os << "kOpenBracket";
    case TokenType::kCloseBracket:
        return os << "kCloseBracket";
    default:
        return os << "UNKNOWN TYPE";
        break;
    }
}


std::ostream &operator<<(std::ostream &os, Token const &tok) {
    return  os << "{Token; type=" << tok.type_ << "; value=" << tok.value_<< "}";
}
