#include <cmath>
#include "calculatables.h"


double SumOp::calculate() {
    return left_->calculate() + right_->calculate();
}

double SubOp::calculate() {
    return left_->calculate() - right_->calculate();
}

double DivOp::calculate() {
    return left_->calculate() / right_->calculate();
}

double RoundFunc::calculate() {
    return round(child_->calculate());
}

double FloorFunc::calculate() {
    return floor(child_->calculate());
}

double Number::calculate() {
    return value_;
}
