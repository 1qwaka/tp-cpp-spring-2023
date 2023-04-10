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

};

std::ostream &operator<<(std::ostream &os, TokenType const &type);
std::ostream &operator<<(std::ostream &os, Token const &tok);
