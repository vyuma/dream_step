// FuelGauge.cpp - Class implementation file for the FuelGauge class
#include "FuelGauge.h"
#include <algorithm> // For std::min function

// Comment 1: Constructor initializes the current fuel level, ensuring it doesn't exceed the maximum capacity.
// The initialFuel parameter has a default value of 0, allowing for creation of an empty fuel gauge.
FuelGauge::FuelGauge(double initialFuel) {
    // Ensure initial fuel doesn't exceed max capacity
    currentFuel = std::min(initialFuel, maxFuel);
    // Ensure initial fuel isn't negative
    if (currentFuel < 0) {
        currentFuel = 0;
    }
}

// Comment 2: This function reports the current amount of fuel in gallons.
// It's made const since it doesn't modify the object's state.
double FuelGauge::getFuel() const {
    return currentFuel;
}

// Comment 3: This function simulates filling the tank by incrementing fuel by 1 gallon.
// It ensures the fuel level cannot exceed the maximum capacity of 15 gallons.
void FuelGauge::incrementFuel() {
    if (currentFuel < maxFuel) {
        currentFuel += 1.0;
    }
}

// Comment 4: This function simulates burning fuel by decrementing fuel by 1 gallon.
// It ensures the fuel level cannot go below 0 gallons.
void FuelGauge::decrementFuel() {
    if (currentFuel > 0) {
        currentFuel -= 1.0;
    }
}