#pragma once

#include <memory>
#include "icalculatable.h"


using std::unique_ptr;


struct BinaryOp : public ICalculatable {
    unique_ptr<ICalculatable> right_;
    unique_ptr<ICalculatable> left_;
};

struct UnaryOp : public ICalculatable {
    unique_ptr<ICalculatable> child_;
};

struct SumOp : public BinaryOp {
    double calculate() override;
};

struct SubOp : public BinaryOp {
    double calculate() override;
};

struct DivOp : public BinaryOp {
    double calculate() override;
};

struct RoundFunc : public UnaryOp {
    double calculate() override;
};

struct FloorFunc : public UnaryOp {
    double calculate() override;
};

struct Number : public ICalculatable {
    double value_;
    double calculate() override;
};
