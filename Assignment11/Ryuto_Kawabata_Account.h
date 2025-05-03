#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

class Account {
private:
    // Comment 1: Data member to store the account balance
    double balance;
public:
    // Comment 2: Constructor that receives and validates initial balance
    Account(double initialBalance);

    // Comment 3: Credit function adds amount to the current balance
    void credit(double amount);

    // Comment 4: Debit function withdraws money if sufficient funds exist
    // Returns true if successful, false otherwise
    bool debit(double amount);

    // Comment 5: GetBalance function returns the current balance
    double getBalance() const;

    // Comment 11: Overloaded insertion operator for printing account balance
    friend std::ostream& operator<<(std::ostream& output, const Account& account);
    
    // Comment 12: Overloaded += operator to credit money to the account
    Account& operator+=(double amount);
    
    // Comment 13: Overloaded -= operator to debit money from the account
    Account& operator-=(double amount);
    
    // Comment 14: Overloaded + operator (account + amount)
    Account operator+(double amount) const;
    
    // Comment 15: Overloaded + operator (amount + account)
    friend Account operator+(double amount, const Account& account);
    
    // Comment 16: Overloaded - operator (account - amount)
    Account operator-(double amount) const;
    
    // Comment 17: Overloaded assignment operator
    Account& operator=(const Account& rightSide);
};

#endif