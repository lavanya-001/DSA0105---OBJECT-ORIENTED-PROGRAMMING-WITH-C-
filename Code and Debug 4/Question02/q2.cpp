#include <iostream>
#include <string>
using namespace std;

class Device {
protected:
    string macAddress;

public:
    Device(string mac) : macAddress(mac) {
        cout << "Device configured with MAC: "
             << macAddress << endl;
    }
};

class Sensor : public Device {
private:
    int samplingRate;

public:
    Sensor(string mac, int rate)
        : Device(mac), samplingRate(rate) {
    }

    void display() const {
        cout << "MAC: " << macAddress
             << ", Rate: " << samplingRate
             << " Hz" << endl;
    }
};

int main() {
    Sensor tempSensor("00:1A:2B:3C:4D:5E", 100);

    tempSensor.display();

    return 0;
}
