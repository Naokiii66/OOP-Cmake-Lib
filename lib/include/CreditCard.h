#ifndef CREDITCARD_H
#define CREDITCARD_H

#include "BankCard.h"

class CreditCard : public BankCard {
private:
    double creditLimit;

public:
    CreditCard(const std::string& number, const std::string& holder,
               const std::string& pin, double balance, double creditLimit);

    double getAvailable() const override;
    bool withdraw(double amount) override;
    std::string getType() const override;
};

#endif
