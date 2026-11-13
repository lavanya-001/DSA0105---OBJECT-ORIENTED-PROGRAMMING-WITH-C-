#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

class Vehicle {
protected:
    string regNo;
    double dailyRate;
    bool rented;

public:
    Vehicle(string r, double rate)
        : regNo(r), dailyRate(rate), rented(false) {}

    virtual double rentalCharge(int days) = 0;

    virtual void display() {
        cout << regNo << " | Daily Rate: Rs. " << dailyRate
             << " | Status: " << (rented ? "Rented" : "Available") << endl;
    }

    void rent() {
        if (!rented) {
            rented = true;
            cout << regNo << " rented successfully.\n";
        } else {
            cout << regNo << " is already rented.\n";
        }
    }

    void returnVehicle(int lateDays) {
        if (rented) {
            double lateCharge = lateDays * dailyRate * 0.5;
            cout << regNo << " returned. Late charge: Rs. "
                 << lateCharge << endl;
            rented = false;
        } else {
            cout << regNo << " was not rented.\n";
        }
    }

    virtual ~Vehicle() = default;
};

class Bicycle : public Vehicle {
public:
    Bicycle(string r, double rate) : Vehicle(r, rate) {}

    double rentalCharge(int days) override {
        return dailyRate * days;
    }
};

class TwoWheeler : public Vehicle {
private:
    double fuelLevel;
    string serviceDate;

public:
    TwoWheeler(string r, double rate, double fuel, string date)
        : Vehicle(r, rate), fuelLevel(fuel), serviceDate(date) {}

    double rentalCharge(int days) override {
        return dailyRate * days + 50;
    }

    void display() override {
        Vehicle::display();
        cout << "Fuel: " << fuelLevel
             << " litres | Service Due: " << serviceDate << endl;
    }
};

class Car : public Vehicle {
private:
    int seats;
    double fuelLevel;
    string serviceDate;

public:
    Car(string r, double rate, int s, double fuel, string date)
        : Vehicle(r, rate), seats(s),
          fuelLevel(fuel), serviceDate(date) {}

    double rentalCharge(int days) override {
        return dailyRate * days + 200;
    }

    void display() override {
        Vehicle::display();
        cout << "Seats: " << seats
             << " | Fuel: " << fuelLevel
             << " litres | Service Due: " << serviceDate << endl;
    }
};

class ElectricCar : public Vehicle {
private:
    double batteryCapacity;

public:
    ElectricCar(string r, double rate, double battery)
        : Vehicle(r, rate), batteryCapacity(battery) {}

    double rentalCharge(int days) override {
        return dailyRate * days + batteryCapacity * 10;
    }

    void display() override {
        Vehicle::display();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};

// New vehicle type added without changing existing classes
class ElectricBus : public Vehicle {
private:
    double batteryCapacity;

public:
    ElectricBus(string r, double rate, double battery)
        : Vehicle(r, rate), batteryCapacity(battery) {}

    double rentalCharge(int days) override {
        return dailyRate * days + batteryCapacity * 10;
    }

    void display() override {
        Vehicle::display();
        cout << "Bus Battery: " << batteryCapacity << " kWh" << endl;
    }
};

int main() {
    vector<unique_ptr<Vehicle>> fleet;

    fleet.push_back(make_unique<Bicycle>("BIKE101", 100));
    fleet.push_back(make_unique<TwoWheeler>("TW202", 300, 5, "20-12-2026"));
    fleet.push_back(make_unique<Car>("CAR303", 1500, 5, 20, "15-12-2026"));
    fleet.push_back(make_unique<ElectricCar>("EV404", 2000, 60));

    cout << "VEHICLE RENTAL FLEET\n\n";

    cout << "AVAILABLE VEHICLES\n";
    for (auto& v : fleet)
        v->display();

    cout << "\nRENTING VEHICLES\n";
    for (auto& v : fleet)
        v->rent();

    cout << "\nRENTAL CHARGES FOR 2 DAYS\n";
    for (auto& v : fleet)
        cout << "Charge: Rs. " << v->rentalCharge(2) << endl;

    cout << "\nRETURNING VEHICLES\n";
    fleet[0]->returnVehicle(1);
    fleet[1]->returnVehicle(0);

    cout << "\nADDING NEW VEHICLE TYPE\n";
    fleet.push_back(make_unique<ElectricBus>("BUS505", 3000, 150));
    fleet.back()->display();

    cout << "\nFINAL FLEET LIST\n";
    for (auto& v : fleet)
        v->display();

    return 0;
}
