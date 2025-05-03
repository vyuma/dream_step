#include <iostream>
#include "Ryuto_Kawabata_Ship.h"
using namespace std;

Ship::Ship(const string& shipName, const string& year)
{
    name = shipName;
    yearBuilt = year;
}

string Ship::getName() const
{
    return name;
}

string Ship::getYearBuilt() const
{
    return yearBuilt;
}

void Ship::setName(const string& shipName)
{
    name = shipName;
}

void Ship::setYearBuilt(const string& year)
{
    yearBuilt = year;
}

void Ship::print() const
{
    cout << "Name: " << name << endl;
    cout << "Year built: " << yearBuilt << endl;
}