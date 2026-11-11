#include <iostream>
using namespace std;

int main() {
    int zone1, zone2, day, peak, monthlyPass;
    double fare = 0;

    cout << "CITY METRO SMART CARD SYSTEM" << endl;
    cout << "1. Inner - Rs. 10" << endl;
    cout << "2. Outer - Rs. 20" << endl;
    cout << "3. Interchange - Rs. 30" << endl;
    cout << "4. Airport - Rs. 60" << endl;

    cout << "Select Zone: ";
    cin >> zone1;

    if (zone1 == 1) fare = 10;
    else if (zone1 == 2) fare = 20;
    else if (zone1 == 3) fare = 30;
    else if (zone1 == 4) fare = 60;
    else {
        cout << "Invalid zone!" << endl;
        return 1;
    }

    cout << "Monthly Pass? (1-Yes, 0-No): ";
    cin >> monthlyPass;

    if (monthlyPass == 1) {
        cout << "Select second zone (1-4): ";
        cin >> zone2;

        if (zone2 < 1 || zone2 > 4 || zone2 == zone1) {
            cout << "Invalid second zone!" << endl;
            return 1;
        }

        cout << "Monthly pass covers zones "
             << zone1 << " and " << zone2 << endl;
    }
    else {
        cout << "Weekend? (1-Yes, 0-No): ";
        cin >> day;

        cout << "Peak hour? (1-Yes, 0-No): ";
        cin >> peak;

        if (day == 1)
            fare = fare * 0.90;
        else if (peak == 1)
            fare = fare * 1.20;

        cout << "Final Fare: Rs. " << fare << endl;
    }

    return 0;
}
