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
    
    // Sample Run 1: Using numbers from 10 to 50
    cout << "Enter 5 integer values:" << endl;
    intArray[0] = 10;
    intArray[1] = 20;
    intArray[2] = 30;
    intArray[3] = 40;
    intArray[4] = 50;
    
    // Echo input values
    cout << "10\n20\n30\n40\n50\n";
    
    // Display integer array values
    cout << "\nThe values in the integer Array are:" << endl;
    cout << intArray << endl;
    
    // Sample Run 1: Using COMSC course numbers
    cout << "\nEnter 5 string values:" << endl;
    stringArray[0] = "COMSC 110";
    stringArray[1] = "COMSC 165";
    stringArray[2] = "COMSC 200";
    stringArray[3] = "COMSC 210";
    stringArray[4] = "COMSC 260";
    
    // Echo input values
    cout << "COMSC 110\nCOMSC 165\nCOMSC 200\nCOMSC 210\nCOMSC 260\n";
    
    // Display string array values
    cout << "\nThe values in the string Array are:" << endl;
    cout << stringArray << endl;
    
    cout << "\nPress any key to continue . . . ";
    
    return 0;
}