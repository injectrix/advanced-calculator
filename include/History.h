#ifndef HISTORY_H
#define HISTORY_H

#include <vector>
#include <string>

class History {
private:
    std::vector<std::string> logs;

public:
    void add(const std::string& entry);
    void show();
};

#endif
