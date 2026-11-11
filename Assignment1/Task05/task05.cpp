#include <iostream>
using namespace std;

int main() {
    int baseFare = 10;
    int passengers = 3;
    int discount = 5;

    int totalFare = baseFare * passengers + discount;
    int discountedFare = baseFare * passengers - discount;
    int result = 20 + 10 * 2;

    cout << "METRO FARE CALCULATION" << endl;
    cout << "Base Fare: Rs. " << baseFare << endl;
    cout << "Passengers: " << passengers << endl;
    cout << "Total Fare: Rs. " << totalFare << endl;
    cout << "Discounted Fare: Rs. " << discountedFare << endl;
    cout << "Operator Precedence Result: " << result << endl;

    return 0;
}
