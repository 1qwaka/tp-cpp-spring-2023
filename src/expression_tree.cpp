#include "expression_tree.h"
#include <stack>
#include <memory>

using std::stack;
using std::unique_ptr;
using std::make_unique;


template <typename BinaryOperation>
static void add_binary_operation(stack<unique_ptr<ICalculatable>> &tree_branches);

template <typename UnaryOperation>
static void add_unary_operation(stack<unique_ptr<ICalculatable>> &tree_branches);


ExpressionTree::ExpressionTree(const vector<Token> &tokens) {
    buildTree(tokens);
}

unique_ptr<ICalculatable>& ExpressionTree::getRoot() {
    return root_;
}

void ExpressionTree::buildTree(const vector<Token> &tokens) {
    stack<unique_ptr<ICalculatable>> tree_branches;

    for (const Token &tok : tokens) {
        switch (tok.type_)
        {
        case TokenType::kNumber: {
            Number *n = new Number();
            n->value_ = std::stod(tok.value_);
            tree_branches.push(unique_ptr<ICalculatable>(n));
            break;
        }
        
        case TokenType::kSumOp: {
            add_binary_operation<SumOp>(tree_branches);
            break;
        }
        
        case TokenType::kSubOp: {
            add_binary_operation<SubOp>(tree_branches);
            break;
        }
        
        case TokenType::kDivOp: {
            add_binary_operation<DivOp>(tree_branches);
            break;
        }
        
        case TokenType::kRoundFunc: {
            add_unary_operation<RoundFunc>(tree_branches);
            break;
        }
        
        case TokenType::kFloorFunc: {
            add_unary_operation<FloorFunc>(tree_branches);
            break;
        }

        default:
            break;
        }
    }

    root_ = std::move(tree_branches.top());
    tree_branches.pop();
}


template <typename BinaryOperation>
static void add_binary_operation(stack<unique_ptr<ICalculatable>> &tree_branches) {
    BinaryOperation *bop = new BinaryOperation();

    bop->right_ = std::move(tree_branches.top());
    tree_branches.pop();
    bop->left_ = std::move(tree_branches.top());
    tree_branches.pop();
    
    tree_branches.push(unique_ptr<ICalculatable>(bop));
}

template <typename UnaryOperation>
static void add_unary_operation(stack<unique_ptr<ICalculatable>> &tree_branches) {
    UnaryOperation *uop = new UnaryOperation();

    uop->child_ = std::move(tree_branches.top());
    tree_branches.pop();
    
    tree_branches.push(unique_ptr<ICalculatable>(uop));
}
