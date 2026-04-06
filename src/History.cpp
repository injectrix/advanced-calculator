#include "History.h"
#include <iostream>

void History::add(const std::string& entry) {
    logs.push_back(entry);
}

void History::show() {
    for (auto &l : logs) {
        std::cout << l << std::endl;
    }
}
