#include <iostream>
#include <vector>
#include "../lib/include/DebitCard.h"
#include "../lib/include/CreditCard.h"
#include "../lib/include/ATM.h"

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    ATM atm("ATM-001", "м. Одеса, вул. Дерибасівська, 1", 20000);
    DebitCard debit("4000 1111 2222 3333", "Колісниченко М.", "1234", 5000);
    CreditCard credit("5000 4444 5555 6666", "Колісниченко М.", "4321", 1000, 10000);

    std::vector<BankCard*> cards = { &debit, &credit };

    std::cout << "=== Пристрій ===" << std::endl;
    atm.printInfo();

    std::cout << "\n=== Картки ===" << std::endl;
    for (BankCard* c : cards) c->printInfo();

    std::cout << "\n=== Зняття 3000 грн з дебетової картки ===" << std::endl;
    atm.withdrawCash(debit, "1234", 3000);

    std::cout << "\n=== Зняття 4000 грн з дебетової (недостатньо коштів) ===" << std::endl;
    atm.withdrawCash(debit, "1234", 4000);

    std::cout << "\n=== Зняття 8000 грн з кредитної (використовується ліміт) ===" << std::endl;
    atm.withdrawCash(credit, "4321", 8000);

    std::cout << "\n=== Невірний PIN ===" << std::endl;
    atm.withdrawCash(credit, "0000", 100);

    std::cout << "\n=== Внесення 1500 грн на дебетову ===" << std::endl;
    atm.depositCash(debit, "1234", 1500);

    std::cout << "\n=== Перевірка балансу ===" << std::endl;
    atm.showBalance(debit, "1234");
    atm.showBalance(credit, "4321");

    std::cout << "\n=== Підсумок ===" << std::endl;
    atm.printInfo();
    for (BankCard* c : cards) c->printInfo();

    return 0;
}
