#include <iostream>
#include <limits>
using namespace std;

int main() {
    int age;

    cout << "CITY METRO SMART CARD SYSTEM" << endl;
    cout << "Enter passenger age: ";

    if (!(cin >> age)) {
        cout << "Error: Invalid input. Please enter a number." << endl;
        return 1;
    }

    if (age < 0 || age > 120) {
        cout << "Error: Invalid age." << endl;
        return 1;
    }

    cout << "Passenger Age: " << age << endl;
    cout << "Input accepted successfully." << endl;

    return 0;
}
