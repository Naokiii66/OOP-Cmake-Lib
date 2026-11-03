#include "CreditCard.h"

CreditCard::CreditCard(const std::string& number, const std::string& holder,
                       const std::string& pin, double balance, double creditLimit)
    : BankCard(number, holder, pin, balance), creditLimit(creditLimit) {}

double CreditCard::getAvailable() const {
    return balance + creditLimit;
}

bool CreditCard::withdraw(double amount) {
    if (amount <= 0 || amount > getAvailable()) return false;
    balance -= amount;
    return true;
}

std::string CreditCard::getType() const { return "Кредитна картка"; }
