#include <iostream>
using namespace std;

void calculate(int amount, double rate) {
    cout << "Integer amount selected\n";
}

void calculate(double amount, int rate) {
    cout << "Decimal amount selected\n";
}

int main() {
    // calculate(100, 100); 
    // This call is ambiguous because both overloads
    // require one conversion.

    calculate(100, 5.5);
    calculate(100.5, 5);

    return 0;
}
