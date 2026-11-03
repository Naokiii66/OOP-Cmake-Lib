#ifndef TERMINAL_H
#define TERMINAL_H

#include <string>

class Terminal {
protected:
    std::string id;
    std::string location;

public:
    Terminal(const std::string& id, const std::string& location);
    virtual ~Terminal() = default;

    const std::string& getId() const;

    virtual void printInfo() const;
};

#endif
