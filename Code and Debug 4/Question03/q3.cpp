#include <iostream>
using namespace std;

class Vehicle {
public:
    int maxSpeed;

    Vehicle(int s) : maxSpeed(s) {}

    virtual ~Vehicle() = default;

    void honk() {
        cout << "General Horn" << endl;
    }
};

class SportsCar : public Vehicle {
public:
    bool turboEnabled;

    SportsCar(int s, bool turbo)
        : Vehicle(s), turboEnabled(turbo) {}

    void engageTurbo() {
        cout << "Turbo Engaged!" << endl;
    }
};

int main() {
    Vehicle* vPtr = new SportsCar(300, true);

    vPtr->honk();

    SportsCar* sportsPtr = static_cast<SportsCar*>(vPtr);
    sportsPtr->engageTurbo();

    cout << "Maximum Speed: " << sportsPtr->maxSpeed << endl;

    SportsCar car(250, true);

    // Object slicing
    Vehicle plainVehicle = car;

    cout << "Sliced Vehicle Speed: "
         << plainVehicle.maxSpeed << endl;

    delete vPtr;

    return 0;
}
