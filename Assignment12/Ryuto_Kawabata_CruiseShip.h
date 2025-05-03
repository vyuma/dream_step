#ifndef CRUISESHIP_H
#define CRUISESHIP_H
#include "Ryuto_Kawabata_Ship.h"

using namespace std;

class CruiseShip : public Ship
{
private:
    // Comment 7: Private member variable to store maximum number of passengers
    int maxPassengers;

public:
    CruiseShip(const string& shipName, const string& year, int passengers);

    int getMaxPassengers() const;

    void setMaxPassengers(int passengers);

    // Comment 8: Override of the base class print function
    virtual void print() const;
};

#endif