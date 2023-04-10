#pragma once

#include <vector>
#include "token.h"

using std::vector;

namespace expression_transformer
{
    vector<Token> infix_to_postfix(vector<Token> tokens);
}
