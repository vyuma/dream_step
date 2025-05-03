#include <iostream>
#include <iomanip>
#include "Ryuto_Kawabata_Account.h" // Account class definition
#include "Ryuto_Kawabata_SavingsAccount.h" // SavingsAccount class definition
#include "Ryuto_Kawabata_CheckingAccount.h" // CheckingAccount class definition
using namespace std;

int main()
{
   Account account1( 1000.0 ); // create Account object
   SavingsAccount account2( 2500.0, .06 ); // create SavingsAccount object
   CheckingAccount account3( 750.0, 2.5 ); // create CheckingAccount object

   cout << fixed << setprecision( 2 );

   // display initial balance of each object
   cout << "account1 balance: $" << account1.getBalance() << endl;
   cout << "account2 balance: $" << account2.getBalance() << endl;
   cout << "account3 balance: $" << account3.getBalance() << endl;

   cout << "\nAttempting to debit $500.00 from account1." << endl;
   account1.debit( 500.0 ); // try to debit $500.00 from account1
   cout << "\nAttempting to debit $3000.00 from account2." << endl;
   account2.debit( 3000.0 ); // try to debit $3000.00 from account2
   cout << "\nAttempting to debit $400.00 from account3." << endl;
   account3.debit( 400.0 ); // try to debit $400.00 from account3

   // display balances
   cout << "\naccount1 balance: $" << account1.getBalance() << endl;
   cout << "account2 balance: $" << account2.getBalance() << endl;
   cout << "account3 balance: $" << account3.getBalance() << endl;

   cout << "\nCrediting $250.00 to account1." << endl;
   account1.credit( 250.0 ); // credit $250.00 to account1
   cout << "\nCrediting $500.00 to account2." << endl;
   account2.credit( 500.0 ); // credit $500.00 to account2
   cout << "\nCrediting $300.00 to account3." << endl;
   account3.credit( 300.0 ); // credit $300.00 to account3

   // display balances
   cout << "\naccount1 balance: $" << account1.getBalance() << endl;
   cout << "account2 balance: $" << account2.getBalance() << endl;
   cout << "account3 balance: $" << account3.getBalance() << endl;

   // add interest to SavingsAccount object account2
   double interestEarned = account2.calculateInterest();
   cout << "\nAdding $" << interestEarned << " interest to account2." 
      << endl;
   account2.credit( interestEarned );

   cout << "\nNew account2 balance: $" << account2.getBalance() << endl;

   system("PAUSE");
   return 0;
}