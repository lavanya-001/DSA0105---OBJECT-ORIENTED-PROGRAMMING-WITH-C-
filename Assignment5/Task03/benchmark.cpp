#include <iostream>
#include <vector>
#include <chrono>
#include <stdexcept>
using namespace std;
using namespace chrono;

volatile long long result = 0;

class Bill {
public:
    virtual int total() const = 0;
    virtual ~Bill() = default;
};

class OutPatient : public Bill {
public:
    int total() const override { return 1000; }
};

class InPatient : public Bill {
public:
    int total() const override { return 5000; }
};

struct Record {
    int type;
};

template <typename Function>
long long measure(Function function) {
    auto start = high_resolution_clock::now();
    long long sum = function();
    auto stop = high_resolution_clock::now();

    result = sum;
    return duration_cast<microseconds>(stop - start).count();
}

bool returnCheck(bool invalid) {
    return !invalid;
}

bool exceptionCheck(bool invalid) {
    if (invalid)
        throw runtime_error("Invalid bill");
    return true;
}

int main() {
    OutPatient op;
    InPatient ip;

    cout << "VIRTUAL FUNCTION vs SWITCH CASE\n";

    vector<int> sizes = {10, 1000, 1000000, 10000000};

    for (int n : sizes) {
        vector<Bill*> bills(n);
        vector<Record> records(n);

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                bills[i] = &op;
                records[i] = {0};
            } else {
                bills[i] = &ip;
                records[i] = {1};
            }
        }

        long long virtualTime = measure([&]() {
            long long sum = 0;
            for (Bill* b : bills)
                sum += b->total();
            return sum;
        });

        long long switchTime = measure([&]() {
            long long sum = 0;
            for (const auto& r : records) {
                switch (r.type) {
                    case 0: sum += 1000; break;
                    case 1: sum += 5000; break;
                }
            }
            return sum;
        });

        cout << "Bills: " << n
             << " | Virtual: " << virtualTime << " us"
             << " | Switch: " << switchTime << " us\n";
    }

    cout << "\nEXCEPTION vs RETURN CODE\n";

    const int n = 1000000;
    int rates[] = {0, 1, 50};

    for (int rate : rates) {
        vector<bool> invalid(n);

        for (int i = 0; i < n; i++)
            invalid[i] = (i % 100 < rate);

        long long returnTime = measure([&]() {
            long long count = 0;
            for (bool bad : invalid) {
                if (returnCheck(bad))
                    count++;
            }
            return count;
        });

        long long exceptionTime = measure([&]() {
            long long count = 0;
            for (bool bad : invalid) {
                try {
                    if (exceptionCheck(bad))
                        count++;
                }
                catch (const runtime_error&) {
                }
            }
            return count;
        });

        cout << "Invalid rate: " << rate
             << "% | Return code: " << returnTime
             << " us | Exception: " << exceptionTime << " us\n";
    }

    return 0;
}
