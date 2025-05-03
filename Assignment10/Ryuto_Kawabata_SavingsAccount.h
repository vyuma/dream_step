#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "Ryuto_Kawabata_Account.h"

class SavingsAccount : public Account {
private:
    // Comment 7: Data member to store interest rate percentage
    double interestRate;
public:
    SavingsAccount(double initialBalance, double rate);

    double calculateInterest();
};

#endif