#include <iostream>
#include <string>
#include <stdexcept>
#include "Ryuto_Kawabata_Array.h"
using namespace std;

int main()
{
    // Create two Array objects: one for integers and one for strings
    Array<int> intArray(5);
    Array<string> stringArray(5);
    
    // Prompt user for integer input
    cout << "Enter 5 integer values:" << endl;
    for (int i = 0; i < 5; ++i) {
        cin >> intArray[i];
    }
    
    // Display integer array values
    cout << "\nThe values in the integer Array are:" << endl;
    cout << intArray << endl;
    
    // Prompt user for string input
    cout << "\nEnter 5 string values:" << endl;
    for (int i = 0; i < 5; ++i) {
        cin >> stringArray[i];
    }
    
    // Display string array values
    cout << "\nThe values in the string Array are:" << endl;
    cout << stringArray << endl;
    
    cout << "\nPress any key to continue . . . ";
    cin.ignore();
    cin.get();
    
    return 0;
}