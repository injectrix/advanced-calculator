#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>

enum TokenType { NUMBER, OPERATOR, FUNCTION, LPAREN, RPAREN };

struct Token {
    TokenType type;
    std::string value;
};

class Parser {
public:
    std::vector<Token> tokenize(const std::string& input);
};

#endif
