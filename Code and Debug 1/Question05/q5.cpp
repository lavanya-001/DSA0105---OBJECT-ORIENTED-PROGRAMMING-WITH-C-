#include <iostream>
using namespace std;

int main() {
    int size = 5;

    int* readings = new int[size];

    for (int i = 0; i < size; ++i) {
        readings[i] = (i + 1) * 10;
    }

    int total = 0;

    for (int i = 0; i < size; ++i) {
        total += readings[i];
    }

    cout << "Total: " << total << endl;

    delete[] readings;

    return 0;
}
