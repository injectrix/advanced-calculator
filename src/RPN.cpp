#include "RPN.h"
#include <stack>

int precedence(const std::string& op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    return 0;
}

std::vector<Token> RPN::toRPN(const std::vector<Token>& tokens) {
    std::vector<Token> output;
    std::stack<Token> ops;

    for (auto &t : tokens) {
        if (t.type == NUMBER) {
            output.push_back(t);
        }
        else if (t.type == FUNCTION) {
            ops.push(t);
        }
        else if (t.type == OPERATOR) {
            while (!ops.empty() &&
                   precedence(ops.top().value) >= precedence(t.value)) {
                output.push_back(ops.top());
                ops.pop();
            }
            ops.push(t);
        }
        else if (t.type == LPAREN) {
            ops.push(t);
        }
        else if (t.type == RPAREN) {
            while (!ops.empty() && ops.top().type != LPAREN) {
                output.push_back(ops.top());
                ops.pop();
            }
            if (!ops.empty()) ops.pop();

            if (!ops.empty() && ops.top().type == FUNCTION) {
                output.push_back(ops.top());
                ops.pop();
            }
        }
    }

    while (!ops.empty()) {
        output.push_back(ops.top());
        ops.pop();
    }

    return output;
}
