#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include <iostream>

class CheckingAccount {
    static int lastId;
    private:
        double balance;
        int id;
    public:
        CheckingAccount(double argBalance);
        double getBalance();
        int getId();
        void withdraw(double amount);
        void deposit(double amount);
};

#endif // CHECKINGACCOUNT_H