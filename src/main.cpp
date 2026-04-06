#include <iostream>
#include <stack>
#include <cmath>
#include <algorithm>

#include "Parser.h"
#include "RPN.h"
#include "Context.h"
#include "History.h"

// Colors
#define GREEN "\033[32m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

double evaluateRPN(const std::vector<Token>& rpn, Context& context) {
    std::stack<double> s;

    for (auto &t : rpn) {
        if (t.type == NUMBER) {
            if (isdigit(t.value[0])) {
                s.push(std::stod(t.value));
            } else {
                s.push(context.getVar(t.value));
            }
        }
        else if (t.type == OPERATOR) {
            double b = s.top(); s.pop();
            double a = s.top(); s.pop();

            if (t.value == "+") s.push(a + b);
            else if (t.value == "-") s.push(a - b);
            else if (t.value == "*") s.push(a * b);
            else if (t.value == "/") s.push(a / b);
        }
        else if (t.type == FUNCTION) {
            double x = s.top(); s.pop();

            if (t.value == "sin") s.push(sin(x));
            else if (t.value == "cos") s.push(cos(x));
            else if (t.value == "log") s.push(log10(x));
            else if (t.value == "ln") s.push(log(x));
        }
    }

    return s.top();
}

int main() {
    Parser parser;
    RPN rpn;
    Context context;
    History history;

    std::string input;

    while (true) {
        std::cout << CYAN << ">> " << RESET;
        std::getline(std::cin, input);

        if (input == "exit") break;
        if (input == "history") {
            history.show();
            continue;
        }

        try {
            size_t eq = input.find('=');

            if (eq != std::string::npos) {
                std::string var = input.substr(0, eq);
                std::string expr = input.substr(eq + 1);

                var.erase(remove_if(var.begin(), var.end(), isspace), var.end());

                auto tokens = parser.tokenize(expr);
                auto postfix = rpn.toRPN(tokens);

                double result = evaluateRPN(postfix, context);

                context.setVar(var, result);

                std::cout << GREEN << var << " = " << result << RESET << std::endl;
                history.add(var + " = " + std::to_string(result));
            }
            else {
                auto tokens = parser.tokenize(input);
                auto postfix = rpn.toRPN(tokens);

                double result = evaluateRPN(postfix, context);

                std::cout << GREEN << result << RESET << std::endl;
                history.add(input + " = " + std::to_string(result));
            }
        }
        catch (std::exception &e) {
            std::cout << RED << "Error: " << e.what() << RESET << std::endl;
        }
    }

    return 0;
}
