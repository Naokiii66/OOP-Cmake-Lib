#include "DebitCard.h"

DebitCard::DebitCard(const std::string& number, const std::string& holder,
                     const std::string& pin, double balance)
    : BankCard(number, holder, pin, balance) {}

bool DebitCard::withdraw(double amount) {
    if (amount <= 0 || amount > balance) return false;
    balance -= amount;
    return true;
}

std::string DebitCard::getType() const { return "Дебетова картка"; }
