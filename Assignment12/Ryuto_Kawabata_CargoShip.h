#ifndef CARGOSHIP_H
#define CARGOSHIP_H
#include "Ryuto_Kawabata_Ship.h"

using namespace std;

class CargoShip : public Ship
{
private:
    // Comment 10: Private member variable to store cargo capacity in tons
    int cargoCapacity;

public:
    CargoShip(const string& shipName, const string& year, int tonnage);

    int getCargoCapacity() const;

    void setCargoCapacity(int tonnage);

    virtual void print() const;
};

#endif