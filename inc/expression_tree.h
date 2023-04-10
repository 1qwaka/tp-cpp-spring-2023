#pragma once

#include <memory>
#include <vector>
#include "token.h"
#include "icalculatable.h"
#include "calculatables.h"

using std::vector;
using std::unique_ptr;





class ExpressionTree {
    unique_ptr<ICalculatable> root_;

public:
    ExpressionTree(const vector<Token> &tokens);
    unique_ptr<ICalculatable>& getRoot();

private:
    void buildTree(const vector<Token> &tokens);

};

