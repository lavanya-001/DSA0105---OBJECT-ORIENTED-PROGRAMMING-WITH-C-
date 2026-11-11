#include <iostream>
using namespace std;

// Procedural approach
void proceduralFare() {
    int fare = 10;
    int passengers = 3;

    cout << "Procedural Programming" << endl;
    cout << "Total Fare: Rs. " << fare * passengers << endl;
}

// Object-Oriented approach
class MetroCard {
public:
    int fare;
    int passengers;

    void calculateFare() {
        cout << "\nObject-Oriented Programming" << endl;
        cout << "Total Fare: Rs. " << fare * passengers << endl;
    }
};

int main() {
    proceduralFare();

    MetroCard card;
    card.fare = 10;
    card.passengers = 3;
    card.calculateFare();

    return 0;
}
