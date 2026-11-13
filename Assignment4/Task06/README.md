# TASK 06 - VEHICLE RENTAL FLEET

Name: Lavanya K.
Register Number: 192565025

Compiler: g++ 15.2.0
Language: C++17

Concepts:
- Abstract base class
- Pure virtual function
- Inheritance
- Runtime polymorphism
- Virtual destructor
- Array of base class pointers
- Dynamic memory management using unique_ptr

PSEUDOCODE:

1. Create an abstract Vehicle class with registration number and daily rate.
2. Declare rentalCharge() as a pure virtual function.
3. Create Bicycle, TwoWheeler, Car and ElectricCar classes.
4. Override rentalCharge() in each derived class.
5. Store all vehicles using base class pointers.
6. Rent vehicles and calculate rental charges.
7. Return vehicles and calculate late charges.
8. Add a new ElectricBus class without modifying existing classes.
9. Display the complete vehicle fleet.

Compile:
g++ -std=c++17 -Wall -Wextra rental.cpp -o rental

Run:
./rental

Result:
The vehicle rental fleet was implemented successfully using
inheritance, abstraction and runtime polymorphism.
