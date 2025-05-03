#ifndef ACCOUNT_H
#define ACCOUNT_H

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
};

#endif