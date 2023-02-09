#include "CheckingAccount.h"
#include "Customer.h"
#include <iostream>
#include <sstream>

Customer **customers;
int numCustomers = 0;

int main () {
    customers = new Customer*[100];

    // for processing string lines
    std::string args;
    std::string command;
    CheckingAccount *temp; // for withdraw and deposit operations

    while (true) {
        // getline and find out what command to process
        std::getline(std::cin, args);
        std::istringstream istr(args);
        istr >> command;

        // create new customer based on input and last ids
        if (command == "new") {
            int numAccounts;
            std::string fname, lname;
            istr >> numAccounts >> fname >> lname;
            customers[++numCustomers] = new Customer(fname + " " + lname, numAccounts);
        // add an account to an existing customer either by name or customer id
        } else if (command == "add") {
            int numAccounts;
            std::string fname, lname;
            istr >> numAccounts >> fname;
            // process by id
            if (std::isdigit(fname[0])) {
                int customerId = std::stoi(fname);
                customers[customerId-1000000]->add(numAccounts);
            // process by name
            } else {
                istr >> lname;
                for (int i = 1; i <= numCustomers; i++)
                {
                    if (customers[i]->getName() == (fname + " " + lname)) customers[i]->add(numAccounts);
                }
            }
        // go through list of users and search through their accounts
        // find approperiate account
        // withdraw the money
        } else if (command == "withdraw") {
            int accountId;
            double amount;
            istr >> accountId >> amount;
            for (int i = 1; i <= numCustomers; i++) {
                temp = customers[i]->findAccount(accountId);
                if (temp) {
                    temp->withdraw(amount);
                    break;
                }
            }
        // go through list of users and search through their accounts
        // find approperiate account
        // deposit the money
        } else if (command == "deposit") {
            int accountId;
            double amount;
            istr >> accountId >> amount;
            for (int i = 1; i <= numCustomers; i++) {
                temp = customers[i]->findAccount(accountId);
                if (temp) {
                    temp->deposit(amount);
                    break;
                }
            }
        } else {
            break;
        }
    }
}