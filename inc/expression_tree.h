#pragma once

#include <memory>
#include <vector>
#include "token.h"
#include "icalculatable.h"
#include "calculatables.h"

using std::vector;
using std::shared_ptr;
using std::shared_ptr;
using std::make_shared;





class ExpressionTree {
    shared_ptr<ICalculatable> root_;
    bool valid_;

public:
    ExpressionTree(const vector<Token> &tokens);
    shared_ptr<ICalculatable>& getRoot();
    bool valid();

private:
    void buildTree(const vector<Token> &tokens);

};

