#include "Customer.h"
#include "CheckingAccount.h"

int Customer::lastId = 1000000;

Customer::Customer (std::string argName, int argNumAccounts) {
    name = argName;
    id = ++lastId;
    numAccounts = argNumAccounts;
    std::cout << "Customer ID: " << id << std::endl;

    accounts = new CheckingAccount* [5];

    std::string line;
    std::getline(std::cin, line);
    std::istringstream istr(line);

    for (int i = 0; i < numAccounts; i++) {
        double balance;
        istr >> balance;
        accounts[i] = new CheckingAccount(balance);
    }
    
}

void Customer::add (int argNumAccounts) {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream istr(line);

    for (int i = numAccounts; i < numAccounts+argNumAccounts; i++)
    {
        double balance;
        istr >> balance;
        accounts[i] = new CheckingAccount(balance);
    }
    numAccounts += argNumAccounts;
}

std::string Customer::getName() {
    return name;
}

int Customer::getNumAccounts() {
    return numAccounts;
}

CheckingAccount* Customer::findAccount(int argId) {
    for (int i = 0; i < numAccounts; i++)
        if (accounts[i]->getId() == argId) return accounts[i];

    return nullptr;
} 

Customer::~Customer() {
    for (int i = 0; i < 5; i++) {
        if (accounts[i]) delete accounts[i];
    }
    delete [] accounts;
}