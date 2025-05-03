#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "Ryuto_Kawabata_Account.h"

class CheckingAccount : public Account {
private:
    double transactionFee;
public:
    CheckingAccount(double initialBalance, double fee);

    // Override credit to charge transaction fee
    void credit(double amount);

    // Override debit to charge transaction fee if transaction successful
    bool debit(double amount);
};

#endif