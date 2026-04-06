#include "Parser.h"
#include <cctype>
#include <cstring>

std::vector<Token> Parser::tokenize(const std::string& input) {
    std::vector<Token> tokens;

    for (size_t i = 0; i < input.length();) {
        if (isdigit(input[i]) || input[i] == '.') {
            std::string num;
            while (i < input.length() && (isdigit(input[i]) || input[i] == '.')) {
                num += input[i++];
            }
            tokens.push_back({NUMBER, num});
        }
        else if (isalpha(input[i])) {
            std::string name;
            while (i < input.length() && isalnum(input[i])) {
                name += input[i++];
            }

            if (name == "sin" || name == "cos" || name == "log" || name == "ln") {
                tokens.push_back({FUNCTION, name});
            } else {
                tokens.push_back({NUMBER, name}); // variable
            }
        }
        else if (strchr("+-*/", input[i])) {
            tokens.push_back({OPERATOR, std::string(1, input[i++])});
        }
        else if (input[i] == '(') {
            tokens.push_back({LPAREN, "("});
            i++;
        }
        else if (input[i] == ')') {
            tokens.push_back({RPAREN, ")"});
            i++;
        }
        else {
            i++; // skip spaces
        }
    }

    return tokens;
}
