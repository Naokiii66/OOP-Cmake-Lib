#include "ATM.h"
#include <iostream>

ATM::ATM(const std::string& id, const std::string& location, double cashStock)
    : Terminal(id, location), cashStock(cashStock) {}

double ATM::getCashStock() const { return cashStock; }

bool ATM::withdrawCash(BankCard& card, const std::string& pin, double amount) {
    if (!card.checkPin(pin)) {
        std::cout << "  Помилка: невірний PIN-код" << std::endl;
        return false;
    }
    if (amount > cashStock) {
        std::cout << "  Помилка: у банкоматі недостатньо готівки" << std::endl;
        return false;
    }
    if (!card.withdraw(amount)) {
        std::cout << "  Помилка: недостатньо коштів на картці" << std::endl;
        return false;
    }
    cashStock -= amount;
    std::cout << "  Видано " << amount << " грн. Баланс картки: "
              << card.getBalance() << " грн" << std::endl;
    return true;
}

bool ATM::depositCash(BankCard& card, const std::string& pin, double amount) {
    if (!card.checkPin(pin) || amount <= 0) {
        std::cout << "  Помилка: невірний PIN-код або сума" << std::endl;
        return false;
    }
    card.deposit(amount);
    cashStock += amount;
    std::cout << "  Внесено " << amount << " грн. Баланс картки: "
              << card.getBalance() << " грн" << std::endl;
    return true;
}

void ATM::showBalance(const BankCard& card, const std::string& pin) const {
    if (!card.checkPin(pin)) {
        std::cout << "  Помилка: невірний PIN-код" << std::endl;
        return;
    }
    std::cout << "  Баланс: " << card.getBalance() << " грн, доступно: "
              << card.getAvailable() << " грн" << std::endl;
}

void ATM::printInfo() const {
    Terminal::printInfo();
    std::cout << "  Банкомат, готівки в касетах: " << cashStock << " грн" << std::endl;
}
