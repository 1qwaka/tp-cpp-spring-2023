#pragma once

#include <string>
#include <iostream>

enum class TokenType {
    kNumber,

    kSumOp,
    kSubOp,
    kDivOp,

    kRoundFunc,
    kFloorFunc,
    
    kOpenBracket,
    kCloseBracket,
};



struct Token {
    TokenType type_;
    std::string value_;
    
    explicit Token(TokenType type, const std::string &value): type_(type), value_(value) { }
    
    explicit Token(TokenType type): type_(type) { }

    // Token& operator=(Token &other) {  };

};


inline std::ostream &operator<<(std::ostream &os, TokenType const &type) {
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
        return os << "kUnknownType";
        break;
    }
}


inline std::ostream &operator<<(std::ostream &os, Token const &tok) {
    os << "{Token; type=" << tok.type_;
    return os << "; value=" << tok.value_<< "}";
}
