#include <iostream>
#include <string>
#include "Ryuto_Kawabata_Ship.h"
#include "Ryuto_Kawabata_CruiseShip.h"
#include "Ryuto_Kawabata_CargoShip.h"
using namespace std;


int main()
{
    // Create an array of Ship pointers, initialized with
    // the addresses of 3 dynamically allocated objects.
    Ship *ships[3] = { new Ship("USS Enterprise", "1961"),
                       new CruiseShip("Costa Concordia", "2006", 3780),
                       new CargoShip("Madrid Maersk", "2017", 196000)
                     };

    // Call each object's print function using polymorphism.
    for (int index=0; index < 3; index++)
    {
        ships[index]->print();
        cout << "----------------------------\n";
        
        delete ships[index];     //release memory (avoid memory leak)
        ships[index] = nullptr;   //avoid dangling pointer
    }
    
           
    system("PAUSE");
    return 0;
}