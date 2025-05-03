#include <iostream>
#include "Ryuto_Kawabata_Account.h"
using namespace std;

// Comment 6: Constructor with validation for non-negative initial balance
Account::Account(double initialBalance) {
    if (initialBalance >= 0.0) {
        balance = initialBalance;
    }
    else {
        balance = 0.0;
        cout << "Error: Initial balance cannot be negative. Balance set to $0.00." << endl;
    }
}

void Account::credit(double amount) {
    balance += amount;
}

bool Account::debit(double amount) {
    if (amount <= balance) {
        balance -= amount;
        return true;
    }
    else {
        cout << "Debit amount exceeded account balance." << endl;
        return false;
    }
}

double Account::getBalance() const {
    return balance;
}