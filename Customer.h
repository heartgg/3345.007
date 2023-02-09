#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <sstream>
#include "CheckingAccount.h"

class Customer {
    static int lastId;
    private:
        std::string name;
        int id;
        CheckingAccount **accounts;
        int numAccounts;
    public:
        Customer (std::string argName, int argNumAccounts);
        void add (int argNumAccounts);
        std::string getName();
        int getNumAccounts();
        CheckingAccount *findAccount(int id);

        virtual ~Customer();
};

#endif // CUSTOMER_H