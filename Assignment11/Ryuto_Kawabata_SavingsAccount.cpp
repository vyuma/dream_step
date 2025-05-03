#include <iostream>
#include "Ryuto_Kawabata_SavingsAccount.h"
using namespace std;

// Comment 8: Constructor initializes the base Account with initialBalance
// and sets the interest rate
SavingsAccount::SavingsAccount(double initialBalance, double rate)
    : Account(initialBalance)
{
    interestRate = rate;
}

double SavingsAccount::calculateInterest() {
    // Comment 9: Calculate interest by multiplying balance by interest rate
    return getBalance() * interestRate;
}

// Implementation of the overloaded insertion operator
ostream& operator<<(ostream& output, const SavingsAccount& account) {
    output << static_cast<const Account&>(account);
    return output;
}

// Implementation of the overloaded += operator
SavingsAccount& SavingsAccount::operator+=(double amount) {
    Account::operator+=(amount);
    return *this;
}

// Implementation of the overloaded -= operator
SavingsAccount& SavingsAccount::operator-=(double amount) {
    Account::operator-=(amount);
    return *this;
}

// Implementation of the overloaded + operator (savingsAccount + amount)
SavingsAccount SavingsAccount::operator+(double amount) const {
    SavingsAccount temp(getBalance(), interestRate);
    temp += amount;
    return temp;
}

// Implementation of the overloaded + operator (amount + savingsAccount)
SavingsAccount operator+(double amount, const SavingsAccount& account) {
    SavingsAccount temp(account.getBalance(), account.interestRate);
    temp += amount;
    return temp;
}

// Implementation of the overloaded - operator (savingsAccount - amount)
SavingsAccount SavingsAccount::operator-(double amount) const {
    SavingsAccount temp(getBalance(), interestRate);
    temp -= amount;
    return temp;
}

// Implementation of the overloaded assignment operator
SavingsAccount& SavingsAccount::operator=(const SavingsAccount& rightSide) {
    if (this != &rightSide) {
        Account::operator=(rightSide);
        interestRate = rightSide.interestRate;
    }
    return *this;
}