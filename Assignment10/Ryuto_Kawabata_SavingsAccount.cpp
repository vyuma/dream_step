#include "Ryuto_Kawabata_SavingsAccount.h"

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