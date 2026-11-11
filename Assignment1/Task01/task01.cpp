#include <iostream>
using namespace std;

class Passenger {
public:
    string name;
    string category;
};

class SmartCard {
public:
    int balance;

    void displayBalance() {
        cout << "Card Balance: Rs. " << balance << endl;
    }
};

class Journey {
public:
    string zone;
    int fare;

    void displayJourney() {
        cout << "Travel Zone: " << zone << endl;
        cout << "Fare: Rs. " << fare << endl;
    }
};

int main() {
    Passenger p;
    p.name = "Lavanya";
    p.category = "Student";

    SmartCard card;
    card.balance = 100;

    Journey j;
    j.zone = "Inner Zone";
    j.fare = 10;

    cout << "CITY METRO SMART CARD SYSTEM\n";
    cout << "Passenger: " << p.name << endl;
    cout << "Category: " << p.category << endl;

    card.displayBalance();
    j.displayJourney();

    return 0;
}