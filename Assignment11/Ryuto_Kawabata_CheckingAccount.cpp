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

// Implementation of the overloaded insertion operator
ostream& operator<<(ostream& output, const CheckingAccount& account) {
    output << static_cast<const Account&>(account);
    return output;
}

// Implementation of the overloaded += operator
CheckingAccount& CheckingAccount::operator+=(double amount) {
    credit(amount);
    return *this;
}

// Implementation of the overloaded -= operator
CheckingAccount& CheckingAccount::operator-=(double amount) {
    debit(amount);
    return *this;
}

// Implementation of the overloaded + operator (checkingAccount + amount)
CheckingAccount CheckingAccount::operator+(double amount) const {
    CheckingAccount temp(getBalance(), transactionFee);
    temp += amount;
    return temp;
}

// Implementation of the overloaded + operator (amount + checkingAccount)
CheckingAccount operator+(double amount, const CheckingAccount& account) {
    CheckingAccount temp(account.getBalance(), account.transactionFee);
    temp += amount;
    return temp;
}

// Implementation of the overloaded - operator (checkingAccount - amount)
CheckingAccount CheckingAccount::operator-(double amount) const {
    CheckingAccount temp(getBalance(), transactionFee);
    temp -= amount;
    return temp;
}

// Implementation of the overloaded assignment operator
CheckingAccount& CheckingAccount::operator=(const CheckingAccount& rightSide) {
    if (this != &rightSide) {
        Account::operator=(rightSide);
        transactionFee = rightSide.transactionFee;
    }
    return *this;
}