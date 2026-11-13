#include <iostream>
using namespace std;

class Prescription {
public:
    static int copyCount;

    Prescription() {}

    Prescription(const Prescription& other) {
        copyCount++;
        cout << "Copy constructor called!" << endl;
    }
};

int Prescription::copyCount = 0;

void passByValue(Prescription p) {
    cout << "Passed by value." << endl;
}

void passByReference(const Prescription& p) {
    cout << "Passed by reference." << endl;
}

int main() {
    Prescription p;

    cout << "Passing by value:" << endl;
    passByValue(p);

    cout << "Copy count: " << Prescription::copyCount << endl;

    cout << "\nPassing by reference:" << endl;
    passByReference(p);

    cout << "Copy count: " << Prescription::copyCount << endl;

    return 0;
}
