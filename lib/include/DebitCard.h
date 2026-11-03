#ifndef DEBITCARD_H
#define DEBITCARD_H

#include "BankCard.h"

class DebitCard : public BankCard {
public:
    DebitCard(const std::string& number, const std::string& holder,
              const std::string& pin, double balance);

    bool withdraw(double amount) override;
    std::string getType() const override;
};

#endif
