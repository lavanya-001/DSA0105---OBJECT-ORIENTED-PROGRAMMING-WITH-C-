#include <iostream>
#include <climits>
using namespace std;

int main() {
    int fare = 10;
    int passengers = 5;
    double exactFare = 10.75;

    cout << "EXPECTED VS ACTUAL OUTPUT" << endl;

    cout << "Expected Total Fare: Rs. 50" << endl;
    cout << "Actual Total Fare: Rs. " << fare * passengers << endl;

    cout << "Exact Fare: Rs. " << exactFare << endl;
    cout << "Integer Fare: Rs. " << (int)exactFare << endl;

    cout << "Maximum Integer: " << INT_MAX << endl;

    return 0;
}
