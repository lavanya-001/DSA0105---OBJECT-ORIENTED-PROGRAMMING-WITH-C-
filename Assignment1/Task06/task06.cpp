#include <iostream>
using namespace std;

int main() {
    int age, choice;

    cout << "CITY METRO SMART CARD SYSTEM" << endl;
    cout << "Enter passenger age: ";
    cin >> age;

    if (age < 12) {
        cout << "Category: Child" << endl;
        cout << "Fare: Rs. 5" << endl;
    }
    else if (age >= 60) {
        cout << "Category: Senior Citizen" << endl;
        cout << "Fare: Rs. 5" << endl;
    }
    else {
        cout << "Category: Adult" << endl;
        cout << "Fare: Rs. 10" << endl;
    }

    cout << "\nSelect travel zone:" << endl;
    cout << "1. Inner Zone" << endl;
    cout << "2. Outer Zone" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Selected: Inner Zone" << endl;
            break;
        case 2:
            cout << "Selected: Outer Zone" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
    }

    return 0;
}
