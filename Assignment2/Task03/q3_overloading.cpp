#include <iostream>
using namespace std;

// Function overloading
void charge(int amount) {
    cout << "Integer charge: Rs. " << amount << '\n';
}

void charge(double amount) {
    cout << "Decimal charge: Rs. " << amount << '\n';
}

// Default arguments must be assigned from right to left.
void displayBill(int amount, int tax = 5, int service = 10) {
    cout << "Total bill: Rs. " << amount + tax + service << '\n';
}

int main() {
    charge(100);
    charge(150.50);

    displayBill(100);
    displayBill(100, 10);
    displayBill(100, 10, 15);

    return 0;
}
