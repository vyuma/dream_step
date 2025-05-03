#ifndef SHIP_H
#define SHIP_H
#include <string>

using namespace std;

class Ship
{
private:
    // Comment 1: Private member variables to store ship's name and year built
    string name;
    string yearBuilt;

public:
    // Comment 2: Constructor to initialize ship with name and year built
    Ship(const string& shipName, const string& year);

    // Comment 3: Accessor functions to retrieve ship's name and year built
    string getName() const;
    string getYearBuilt() const;

    // Comment 4: Mutator functions to set ship's name and year built
    void setName(const string& shipName);
    void setYearBuilt(const string& year);

    // Comment 5: Virtual print function to display ship information
    virtual void print() const;
};

#endif