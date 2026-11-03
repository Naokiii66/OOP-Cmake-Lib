#ifndef ATM_H
#define ATM_H

#include "Terminal.h"
#include "BankCard.h"

class ATM : public Terminal {
private:
    double cashStock;

public:
    ATM(const std::string& id, const std::string& location, double cashStock);

    double getCashStock() const;

    bool withdrawCash(BankCard& card, const std::string& pin, double amount);

    bool depositCash(BankCard& card, const std::string& pin, double amount);

    void showBalance(const BankCard& card, const std::string& pin) const;

    void printInfo() const override;
};

#endif
