#include <iostream>
#include <iomanip>
#include "Ryuto_Kawabata_Account.h"
#include "Ryuto_Kawabata_SavingsAccount.h"
#include "Ryuto_Kawabata_CheckingAccount.h"
using namespace std;

int main() {
    // Set output formatting
    cout << fixed << setprecision(2);
    
    // Sample Run 4: Testing with decimal values and multiple operations
    cout << "===== SAMPLE RUN 4 =====" << endl;
    
    // Create account objects with decimal initial balances
    Account account1(567.89);
    Account account2(123.45);
    SavingsAccount savings1(789.01, 0.0425);
    SavingsAccount savings2(234.56, 0.0375);
    CheckingAccount checking1(901.23, 1.25);
    CheckingAccount checking2(345.67, 0.95);
    
    // Display initial balances using << operator
    cout << "Initial balances:" << endl;
    cout << "account1: " << account1 << endl;
    cout << "account2: " << account2 << endl;
    cout << "savings1: " << savings1 << endl;
    cout << "savings2: " << savings2 << endl;
    cout << "checking1: " << checking1 << endl;
    cout << "checking2: " << checking2 << endl;
    cout << endl;
    
    // Test multiple += operations
    cout << "Testing multiple += operations:" << endl;
    account1 += 50.00;
    account1 += 25.00;
    savings1 += 75.00;
    savings1 += 37.50;
    checking1 += 100.00;
    checking1 += 50.00;
    
    cout << "After multiple additions:" << endl;
    cout << "account1: " << account1 << endl;
    cout << "savings1: " << savings1 << endl;
    cout << "checking1: " << checking1 << endl;
    cout << endl;
    
    // Test multiple -= operations
    cout << "Testing multiple -= operations:" << endl;
    account1 -= 30.00;
    account1 -= 15.00;
    savings1 -= 45.00;
    savings1 -= 22.50;
    checking1 -= 60.00;
    checking1 -= 30.00;
    
    cout << "After multiple subtractions:" << endl;
    cout << "account1: " << account1 << endl;
    cout << "savings1: " << savings1 << endl;
    cout << "checking1: " << checking1 << endl;
    cout << endl;
    
    // Test combining + operators
    cout << "Testing combined + operations:" << endl;
    Account account3 = account1 + 100.00;
    account3 = account3 + 50.00;
    SavingsAccount savings3 = savings1 + 150.00;
    savings3 = savings3 + 75.00;
    CheckingAccount checking3 = checking1 + 200.00;
    checking3 = checking3 + 100.00;
    
    cout << "New objects after addition:" << endl;
    cout << "account3: " << account3 << endl;
    cout << "savings3: " << savings3 << endl;
    cout << "checking3: " << checking3 << endl;
    cout << endl;
    
    // Test combining different operator types
    cout << "Testing combined different operators:" << endl;
    account1 += 20.00;
    Account account4 = account1 - 10.00;
    savings1 += 30.00;
    SavingsAccount savings4 = savings1 - 15.00;
    checking1 += 40.00;
    CheckingAccount checking4 = checking1 - 20.00;
    
    cout << "Objects after mixed operations:" << endl;
    cout << "account1 after +=: " << account1 << endl;
    cout << "account4 (from combined ops): " << account4 << endl;
    cout << "savings1 after +=: " << savings1 << endl;
    cout << "savings4 (from combined ops): " << savings4 << endl;
    cout << "checking1 after +=: " << checking1 << endl;
    cout << "checking4 (from combined ops): " << checking4 << endl;
    cout << endl;
    
    // Test multiple assignment operations
    cout << "Testing multiple assignment operations:" << endl;
    account2 = account1;
    savings2 = savings1;
    checking2 = checking1;
    
    cout << "After first assignment:" << endl;
    cout << "account2: " << account2 << endl;
    cout << "savings2: " << savings2 << endl;
    cout << "checking2: " << checking2 << endl;
    
    // Modify the original objects
    account1 += 100.00;
    savings1 += 150.00;
    checking1 += 200.00;
    
    cout << "After modifying original objects:" << endl;
    cout << "account1: " << account1 << endl;
    cout << "account2 (should remain unchanged): " << account2 << endl;
    cout << "savings1: " << savings1 << endl;
    cout << "savings2 (should remain unchanged): " << savings2 << endl;
    cout << "checking1: " << checking1 << endl;
    cout << "checking2 (should remain unchanged): " << checking2 << endl;
    cout << endl;
    
    // Test interest calculation for SavingsAccount
    double interest = savings1.calculateInterest();
    cout << "Interest earned by savings1 (4.25% interest rate): $" << interest << endl;
    
    return 0;
}