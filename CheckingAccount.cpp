#include "CheckingAccount.h"

int CheckingAccount::lastId = 5000000;

CheckingAccount::CheckingAccount (double argBalance) {
    balance = argBalance;
    id = ++lastId;
    std::cout << "Account ID: " << id << std::endl;
}

double CheckingAccount::getBalance () {
    return balance;
}

int CheckingAccount::getId() {
    return id;
}

void CheckingAccount::withdraw (double amount) {
    balance -= amount;
    std::cout << "New balance: " << getBalance() << std::endl;
}

void CheckingAccount::deposit (double amount) {
    balance += amount;
    std::cout << "New balance: " << getBalance() << std::endl;
}