#include "Terminal.h"
#include <iostream>

Terminal::Terminal(const std::string& id, const std::string& location)
    : id(id), location(location) {}

const std::string& Terminal::getId() const { return id; }

void Terminal::printInfo() const {
    std::cout << "Термінал " << id << ", адреса: " << location << std::endl;
}
