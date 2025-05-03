#include <iostream>
#include "Ryuto_Kawabata_CargoShip.h"
using namespace std;

CargoShip::CargoShip(const string& shipName, const string& year, int tonnage)
    : Ship(shipName, year)
{
    cargoCapacity = tonnage;
}

int CargoShip::getCargoCapacity() const
{
    return cargoCapacity;
}

void CargoShip::setCargoCapacity(int tonnage)
{
    cargoCapacity = tonnage;
}

void CargoShip::print() const
{
    cout << "Name: " << getName() << endl;
    cout << "Cargo capacity: " << cargoCapacity << " tons" << endl;
}