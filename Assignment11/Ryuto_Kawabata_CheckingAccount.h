#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include <iostream>
#include "Ryuto_Kawabata_Account.h"

class CheckingAccount : public Account {
private:
    double transactionFee;
    
    // Allow friend operators to access transactionFee
    friend CheckingAccount operator+(double amount, const CheckingAccount& account);
public:
    CheckingAccount(double initialBalance, double fee);

    // Override credit to charge transaction fee
    void credit(double amount);

    // Override debit to charge transaction fee if transaction successful
    bool debit(double amount);
    
    // Comment 25: Overloaded insertion operator for printing checking account balance
    friend std::ostream& operator<<(std::ostream& output, const CheckingAccount& account);
    
    // Comment 26: Overloaded += operator to credit money to the checking account
    CheckingAccount& operator+=(double amount);
    
    // Comment 27: Overloaded -= operator to debit money from the checking account
    CheckingAccount& operator-=(double amount);
    
    // Comment 28: Overloaded + operator (checkingAccount + amount)
    CheckingAccount operator+(double amount) const;
    
    // Comment 29: Overloaded + operator (amount + checkingAccount)
    friend CheckingAccount operator+(double amount, const CheckingAccount& account);
    
    // Comment 30: Overloaded - operator (checkingAccount - amount)
    CheckingAccount operator-(double amount) const;
    
    // Comment 31: Overloaded assignment operator
    CheckingAccount& operator=(const CheckingAccount& rightSide);
};

#endif