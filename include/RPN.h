#ifndef RPN_H
#define RPN_H

#include "Parser.h"
#include <vector>

class RPN {
public:
    std::vector<Token> toRPN(const std::vector<Token>& tokens);
};

#endif
