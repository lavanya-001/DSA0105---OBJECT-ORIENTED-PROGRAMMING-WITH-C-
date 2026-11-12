#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

const int N = 1000000;

int main() {
    double shifting[10] = {};
    double circular[10] = {};
    int next = 0;

    auto start1 = high_resolution_clock::now();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++)
            shifting[j] = shifting[j + 1];

        shifting[9] = i;
    }

    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();

    for (int i = 0; i < N; i++) {
        circular[next] = i;
        next = (next + 1) % 10;
    }

    auto end2 = high_resolution_clock::now();

    cout << "Shifting method time: "
         << duration_cast<microseconds>(end1 - start1).count()
         << " microseconds\n";

    cout << "Circular method time: "
         << duration_cast<microseconds>(end2 - start2).count()
         << " microseconds\n";

    return 0;
}
