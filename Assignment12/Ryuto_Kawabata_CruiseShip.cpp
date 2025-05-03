#include <iostream>
#include "Ryuto_Kawabata_CruiseShip.h"
using namespace std;

CruiseShip::CruiseShip(const string& shipName, const string& year, int passengers)
    : Ship(shipName, year)
{
    maxPassengers = passengers;
}

int CruiseShip::getMaxPassengers() const
{
    return maxPassengers;
}

void CruiseShip::setMaxPassengers(int passengers)
{
    maxPassengers = passengers;
}

// Comment 9: Implementation of the overridden print function
void CruiseShip::print() const
{
    cout << "Name: " << getName() << endl;
    cout << "Maximum passengers: " << maxPassengers << endl;
}