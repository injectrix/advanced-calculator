#ifndef CONTEXT_H
#define CONTEXT_H

#include <map>
#include <string>

class Context {
public:
    std::map<std::string, double> variables;

    void setVar(const std::string& name, double value);
    double getVar(const std::string& name);
    bool exists(const std::string& name);
};

#endif
