#include "expression_tree.h"
#include <stack>
#include <memory>

using std::stack;
using std::shared_ptr;
using std::make_shared;


template <typename BinaryOperation>
static bool add_binary_operation(stack<shared_ptr<ICalculatable>> &tree_branches);

template <typename UnaryOperation>
static bool add_unary_operation(stack<shared_ptr<ICalculatable>> &tree_branches);


ExpressionTree::ExpressionTree(const vector<Token> &tokens) {
    valid_ = true;
    buildTree(tokens);
}

bool ExpressionTree::valid() {
    return valid_;
}

shared_ptr<ICalculatable>& ExpressionTree::getRoot() {
    return root_;
}

void ExpressionTree::buildTree(const vector<Token> &tokens) {
    stack<shared_ptr<ICalculatable>> tree_branches;

    for (const Token &tok : tokens) {
        if (!valid_)
            break;

        switch (tok.type_)
        {
        case TokenType::kNumber: {
            shared_ptr<Number> n = make_shared<Number>();
            n->value_ = std::stod(tok.value_);
            tree_branches.push(std::move(n));
            break;
        }
        
        case TokenType::kSumOp: {
            valid_ = add_binary_operation<SumOp>(tree_branches);
            break;
        }
        
        case TokenType::kSubOp: {
            valid_ = add_binary_operation<SubOp>(tree_branches);
            break;
        }
        
        case TokenType::kDivOp: {
            valid_ = add_binary_operation<DivOp>(tree_branches);
            break;
        }
        
        case TokenType::kRoundFunc: {
            valid_ = add_unary_operation<RoundFunc>(tree_branches);
            break;
        }
        
        case TokenType::kFloorFunc: {
            valid_ = add_unary_operation<FloorFunc>(tree_branches);
            break;
        }

        default:
            break;
        }
    }

    if (!tree_branches.empty()) {
        root_ = std::move(tree_branches.top());
        tree_branches.pop();
    } else {
        valid_ = false;
    }
}


template <typename BinaryOperation>
static bool add_binary_operation(stack<shared_ptr<ICalculatable>> &tree_branches) {
    shared_ptr<BinaryOperation> bop = make_shared<BinaryOperation>();

    if (tree_branches.size() < 2) 
        return false;

    bop->right_ = std::move(tree_branches.top());
    tree_branches.pop();
    bop->left_ = std::move(tree_branches.top());
    tree_branches.pop();
    
    tree_branches.push(std::move(bop));

    return true;
}

template <typename UnaryOperation>
static bool add_unary_operation(stack<shared_ptr<ICalculatable>> &tree_branches) {
    shared_ptr<UnaryOperation> uop = make_shared<UnaryOperation>();

    if (tree_branches.size() < 1) 
        return false;

    uop->child_ = std::move(tree_branches.top());
    tree_branches.pop();
    
    tree_branches.push(std::move(uop));

    return true;
}
