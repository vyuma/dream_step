#include <iostream>
#include "FuelGauge.h"
#include "Odometer.h"

int main() {
    // Comment 8: Create a FuelGauge object with 0 gallons initially.
    // This will be used to track the car's fuel level throughout the simulation.
    FuelGauge carFuel;
    
    // Comment 9: Create an Odometer object with 0 miles initially.
    // Associate it with the carFuel object so it can decrease fuel as miles are driven.
    // We pass the address of carFuel to establish the relationship between the two objects.
    Odometer carOdometer(0, &carFuel);
    
    // Fill the car up to maximum capacity (15 gallons)
    std::cout << "Filling up the car with fuel...\n";
    for (int i = 0; i < 15; i++) {
        carFuel.incrementFuel();
    }
    
    std::cout << "Initial fuel level: " << carFuel.getFuel() << " gallons\n";
    std::cout << "Initial mileage: " << carOdometer.getMileage() << " miles\n\n";
    
    std::cout << "Starting to drive the car...\n";
    std::cout << "Mileage\tFuel(gallons)\n";
    std::cout << "------------------------\n";
    
    // Comment 10: Run a simulation loop that increments the odometer
    // and outputs the current mileage and fuel level after each mile.
    // The loop continues until the car runs out of fuel (when fuel level becomes 0).
    while (carFuel.getFuel() > 0) {
        // Show current mileage and fuel level
        std::cout << carOdometer.getMileage() << "\t" << carFuel.getFuel() << std::endl;
        
        // Drive one mile
        carOdometer.incrementMileage();
    }
    
    // Show final statistics
    std::cout << "\nThe car has run out of fuel!\n";
    std::cout << "Final mileage: " << carOdometer.getMileage() << " miles\n";
    std::cout << "Final fuel level: " << carFuel.getFuel() << " gallons\n";
    
    return 0;
}