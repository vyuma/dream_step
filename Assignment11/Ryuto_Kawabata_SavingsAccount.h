#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include <iostream>
#include "Ryuto_Kawabata_Account.h"

class SavingsAccount : public Account {
private:
    // Comment 7: Data member to store interest rate percentage
    double interestRate;
public:
    SavingsAccount(double initialBalance, double rate);

    double calculateInterest();
    
    // Comment 18: Overloaded insertion operator for printing savings account balance
    friend std::ostream& operator<<(std::ostream& output, const SavingsAccount& account);
    
    // Comment 19: Overloaded += operator to credit money to the savings account
    SavingsAccount& operator+=(double amount);
    
    // Comment 20: Overloaded -= operator to debit money from the savings account
    SavingsAccount& operator-=(double amount);
    
    // Comment 21: Overloaded + operator (savingsAccount + amount)
    SavingsAccount operator+(double amount) const;
    
    // Comment 22: Overloaded + operator (amount + savingsAccount)
    friend SavingsAccount operator+(double amount, const SavingsAccount& account);
    
    // Comment 23: Overloaded - operator (savingsAccount - amount)
    SavingsAccount operator-(double amount) const;
    
    // Comment 24: Overloaded assignment operator
    SavingsAccount& operator=(const SavingsAccount& rightSide);
};

#endif