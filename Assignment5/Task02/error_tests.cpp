#include <iostream>
#include <stdexcept>
#include <string>
#include <new>
#include <limits>
using namespace std;

class Resource {
public:
    Resource() {
        cout << "Resource created\n";
    }

    ~Resource() {
        cout << "Resource released\n";
    }
};

void checkCharge(double amount) {
    if (amount < 0)
        throw invalid_argument("Negative charge");

    cout << "Charge accepted\n";
}

void checkClaim(double billed, double cover) {
    if (billed > cover)
        throw runtime_error("Claim exceeds cover");

    cout << "Claim accepted\n";
}

void checkPackage(int code) {
    if (code != 101 && code != 102)
        throw runtime_error("Unknown package code");

    cout << "Package accepted\n";
}

void checkInput(string value) {
    double amount = stod(value);
    cout << "Input amount: " << amount << endl;
}

void allocationTest() {
    try {
        volatile size_t requested = numeric_limits<size_t>::max();
        char* p = new char[requested];
        delete[] p;
    }
    catch (const bad_alloc&) {
        cout << "Allocation failed: bad_alloc caught" << endl;
    }
    catch (...) {
        cout << "Unknown allocation error caught" << endl;
    }
}
int main() {
    cout << "HOSPITAL ERROR TESTING\n\n";

    try {
        Resource r;
        checkCharge(-100);
    }
    catch (const exception& e) {
        cout << "Caught: " << e.what() << endl;
    }

    cout << "\n";

    try {
        checkClaim(60000, 50000);
    }
    catch (const exception& e) {
        cout << "Caught: " << e.what() << endl;
    }

    cout << "\n";

    try {
        checkPackage(999);
    }
    catch (const exception& e) {
        cout << "Caught: " << e.what() << endl;
    }

    cout << "\n";

    try {
        checkInput("abc");
    }
    catch (const exception& e) {
        cout << "Caught: " << e.what() << endl;
    }

    cout << "\n";

    try {
        allocationTest();
    }
    catch (const bad_alloc& e) {
        cout << "Memory error caught: " << e.what() << endl;
    }
    catch (...) {
        cout << "Unknown memory error caught\n";
    }

    cout << "\nProgram continues after errors.\n";

    return 0;
}
