#include "Context.h"
#include <stdexcept>

void Context::setVar(const std::string& name, double value) {
    variables[name] = value;
}

double Context::getVar(const std::string& name) {
    if (!exists(name)) {
        throw std::runtime_error("Undefined variable: " + name);
    }
    return variables[name];
}

bool Context::exists(const std::string& name) {
    return variables.find(name) != variables.end();
}
