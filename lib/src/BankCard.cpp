#include "BankCard.h"
#include <iostream>

BankCard::BankCard(const std::string& number, const std::string& holder,
                   const std::string& pin, double balance)
    : number(number), holder(holder), pin(pin), balance(balance) {}

bool BankCard::checkPin(const std::string& enteredPin) const {
    return pin == enteredPin;
}

double BankCard::getBalance() const { return balance; }
const std::string& BankCard::getNumber() const { return number; }
const std::string& BankCard::getHolder() const { return holder; }

double BankCard::getAvailable() const { return balance; }

bool BankCard::withdraw(double amount) {
    if (amount <= 0 || amount > balance) return false;
    balance -= amount;
    return true;
}

void BankCard::deposit(double amount) {
    if (amount > 0) balance += amount;
}

std::string BankCard::getType() const { return "Банківська картка"; }

void BankCard::printInfo() const {
    std::cout << getType() << " " << number << ", власник: " << holder
              << ", баланс: " << balance << " грн, доступно: "
              << getAvailable() << " грн" << std::endl;
}
