#include <iostream>
using namespace std;

int main() {
    int fare = 10;
    double totalFare = fare;

    char category = 'S';
    int categoryCode = category;

    int passengers = 3;
    double averageFare = 25.5;
    double total = passengers * averageFare;

    cout << "METRO FARE - IMPLICIT CONVERSION" << endl;
    cout << "Integer Fare: " << fare << endl;
    cout << "Converted Double Fare: " << totalFare << endl;
    cout << "Character Category: " << category << endl;
    cout << "Character ASCII Value: " << categoryCode << endl;
    cout << "Total Fare: " << total << endl;

    return 0;
}
