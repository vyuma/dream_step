// FuelGauge.h - Class specification file for the FuelGauge class
#ifndef FUEL_GAUGE_H
#define FUEL_GAUGE_H

class FuelGauge {
private:
    // Current amount of fuel in gallons
    double currentFuel;
    // Maximum amount of fuel the car can hold
    const double maxFuel = 15.0;

public:
    // Constructor
    FuelGauge(double initialFuel = 0.0);
    
    // Returns the current amount of fuel in gallons
    double getFuel() const;
    
    // Increments the fuel by 1 gallon, up to the maximum
    void incrementFuel();
    
    // Decrements the fuel by 1 gallon, if greater than 0
    void decrementFuel();
};

#endif