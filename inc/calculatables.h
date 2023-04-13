#pragma once

#include <memory>
#include "icalculatable.h"


using std::shared_ptr;


struct BinaryOp : public ICalculatable {
    shared_ptr<ICalculatable> right_;
    shared_ptr<ICalculatable> left_;
};

struct UnaryOp : public ICalculatable {
    shared_ptr<ICalculatable> child_;
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
