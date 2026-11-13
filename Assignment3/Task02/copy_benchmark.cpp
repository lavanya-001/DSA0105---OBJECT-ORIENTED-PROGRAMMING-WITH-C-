#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

class Data {
    int* values;
    int size;

public:
    Data(int n) {
        size = n;
        values = new int[size];
        for (int i = 0; i < size; i++)
            values[i] = i;
    }

    Data(const Data& other) {
        size = other.size;
        values = new int[size];

        for (int i = 0; i < size; i++)
            values[i] = other.values[i];
    }

    ~Data() {
        delete[] values;
    }
};

int main() {
    int sizes[] = {10, 1000, 100000};

    cout << "DEEP COPY TIME BENCHMARK\n";

    for (int n : sizes) {
        Data original(n);

        auto start = high_resolution_clock::now();

        for (int i = 0; i < 100; i++) {
            Data copy = original;
        }

        auto stop = high_resolution_clock::now();

        auto duration =
            duration_cast<microseconds>(stop - start).count();

        cout << "Size: " << n
             << " | 100 copies took: "
             << duration << " microseconds\n";
    }

    return 0;
}
