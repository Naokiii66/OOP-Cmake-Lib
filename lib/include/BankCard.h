#ifndef BANKCARD_H
#define BANKCARD_H

#include <string>

class BankCard {
protected:
    std::string number;
    std::string holder;
    std::string pin;
    double balance;

public:
    BankCard(const std::string& number, const std::string& holder,
             const std::string& pin, double balance);
    virtual ~BankCard() = default;

    bool checkPin(const std::string& enteredPin) const;
    double getBalance() const;
    const std::string& getNumber() const;
    const std::string& getHolder() const;

    virtual double getAvailable() const;

    virtual bool withdraw(double amount);

    void deposit(double amount);

    virtual std::string getType() const;

    void printInfo() const;
};

#endif
