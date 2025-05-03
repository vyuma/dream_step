// Odometer.cpp - Class implementation file for the Odometer class
#include "Odometer.h"

// Comment 5: Constructor initializes the odometer with an initial mileage and associates
// it with a FuelGauge object through a pointer. The initial mileage is clamped to valid range.
Odometer::Odometer(int initialMileage, FuelGauge* fuelGauge) {
    // Ensure initial mileage is within valid range
    if (initialMileage >= 0 && initialMileage <= maxMileage) {
        currentMileage = initialMileage;
    } else if (initialMileage > maxMileage) {
        currentMileage = initialMileage % (maxMileage + 1);
    } else {
        currentMileage = 0;
    }
    
    // Initialize the miles counter since last gallon used
    milesSinceLastGallonUsed = 0;
    
    // Store the pointer to the FuelGauge object
    fuelGaugePtr = fuelGauge;
}

// Comment 6: This function returns the current mileage reading of the odometer.
// It's made const since it doesn't modify the object's state.
int Odometer::getMileage() const {
    return currentMileage;
}

// Comment 7: This function increments the mileage by 1 mile, handling rollover when maximum is reached.
// It also decreases the fuel by 1 gallon for every 24 miles traveled by collaborating with the FuelGauge object.
void Odometer::incrementMileage() {
    // Increment mileage, handling rollover if necessary
    currentMileage = (currentMileage + 1) % (maxMileage + 1);
    
    // Only update fuel if we have a valid FuelGauge pointer
    if (fuelGaugePtr != nullptr) {
        // Increment miles since last gallon used
        milesSinceLastGallonUsed++;
        
        // If we've traveled mpg miles, consume a gallon of fuel
        if (milesSinceLastGallonUsed >= mpg) {
            fuelGaugePtr->decrementFuel();
            milesSinceLastGallonUsed = 0;
        }
    }
}