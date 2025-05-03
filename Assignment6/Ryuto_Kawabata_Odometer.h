// Odometer.h - Class specification file for the Odometer class
#ifndef ODOMETER_H
#define ODOMETER_H

#include "FuelGauge.h"

class Odometer {
private:
    // Current mileage on the odometer
    int currentMileage;
    // Maximum mileage the odometer can store before resetting
    const int maxMileage = 999999;
    // Miles per gallon - fuel economy of the car
    const int mpg = 24;
    // Counter to track when to decrease fuel
    int milesSinceLastGallonUsed;
    // Pointer to the associated FuelGauge object
    FuelGauge* fuelGaugePtr;

public:
    // Constructor
    Odometer(int initialMileage = 0, FuelGauge* fuelGauge = nullptr);
    
    // Returns the current mileage
    int getMileage() const;
    
    // Increments the mileage by 1 mile and updates the fuel accordingly
    void incrementMileage();
};

#endif