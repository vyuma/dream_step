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

// Implementation of the overloaded insertion operator
ostream& operator<<(ostream& output, const Account& account) {
    output << "$" << account.balance;
    return output;
}

// Implementation of the overloaded += operator
Account& Account::operator+=(double amount) {
    credit(amount);
    return *this;
}

// Implementation of the overloaded -= operator
Account& Account::operator-=(double amount) {
    debit(amount);
    return *this;
}

// Implementation of the overloaded + operator (account + amount)
Account Account::operator+(double amount) const {
    Account temp(balance);
    temp.credit(amount);
    return temp;
}

// Implementation of the overloaded + operator (amount + account)
Account operator+(double amount, const Account& account) {
    Account temp(account.getBalance());
    temp.credit(amount);
    return temp;
}

// Implementation of the overloaded - operator (account - amount)
Account Account::operator-(double amount) const {
    Account temp(balance);
    temp.debit(amount);
    return temp;
}

// Implementation of the overloaded assignment operator
Account& Account::operator=(const Account& rightSide) {
    if (this != &rightSide) {
        balance = rightSide.balance;
    }
    return *this;
}