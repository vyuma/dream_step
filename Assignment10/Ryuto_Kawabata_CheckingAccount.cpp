#include <iostream>
#include "Ryuto_Kawabata_CheckingAccount.h"
using namespace std;

// Comment 10: Constructor initializes the base Account with initialBalance
// and sets the transaction fee
CheckingAccount::CheckingAccount(double initialBalance, double fee)
    : Account(initialBalance)
{
    transactionFee = fee;
}

void CheckingAccount::credit(double amount) {
    Account::credit(amount);

    Account::debit(transactionFee);

    cout << "$" << transactionFee << " transaction fee charged." << endl;
}

bool CheckingAccount::debit(double amount) {
    bool success = Account::debit(amount);

    if (success) {
        Account::debit(transactionFee);

        cout << "$" << transactionFee << " transaction fee charged." << endl;
    }

    return success;
}