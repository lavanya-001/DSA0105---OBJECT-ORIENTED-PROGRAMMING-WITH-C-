#include <iostream>
using namespace std;

int main() {
    int zone, category, fare = 0;
    double discount = 0, finalFare;

    cout << "CITY METRO SMART CARD SYSTEM" << endl;
    cout << "Select Zone (1.Inner  2.Outer  3.Interchange): ";
    cin >> zone;

    cout << "Select Category (1.Regular  2.Student  3.Senior): ";
    cin >> category;

    if (zone == 1)
        fare = 10;
    else if (zone == 2)
        fare = 20;
    else if (zone == 3)
        fare = 30;
    else {
        cout << "Invalid zone!" << endl;
        return 1;
    }

    if (category == 2)
        discount = 0.50;
    else if (category == 3)
        discount = 0.25;
    else if (category != 1) {
        cout << "Invalid category!" << endl;
        return 1;
    }

    finalFare = fare - (fare * discount);

    cout << "\nBase Fare: Rs. " << fare << endl;
    cout << "Discount: " << discount * 100 << "%" << endl;
    cout << "Final Fare: Rs. " << finalFare << endl;

    return 0;
}
