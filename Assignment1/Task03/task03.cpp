#include <iostream>
using namespace std;

int main() {
    int passengerAge = 20;
    float ticketFare = 25.5f;
    double cardBalance = 150.75;
    char passengerType = 'S';
    bool isStudent = true;

    cout << "METRO SMART CARD - DATA TYPES" << endl;
    cout << "Passenger Age: " << passengerAge << endl;
    cout << "Ticket Fare: Rs. " << ticketFare << endl;
    cout << "Card Balance: Rs. " << cardBalance << endl;
    cout << "Passenger Type: " << passengerType << endl;
    cout << "Student Status: " << boolalpha << isStudent << endl;

    return 0;
}
