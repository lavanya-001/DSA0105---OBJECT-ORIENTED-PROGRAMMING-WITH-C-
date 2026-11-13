#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;
using namespace chrono;

class Money {
    long long paise;

public:
    Money(long long p = 0) : paise(p) {}

    Money operator+(const Money& m) const {
        return Money(paise + m.paise);
    }

    Money operator-(const Money& m) const {
        return Money(paise - m.paise);
    }

    Money& operator+=(const Money& m) {
        paise += m.paise;
        return *this;
    }

    bool operator==(const Money& m) const {
        return paise == m.paise;
    }

    bool operator<(const Money& m) const {
        return paise < m.paise;
    }

    friend ostream& operator<<(ostream& out, const Money& m) {
        long long value = m.paise;
        if (value < 0) {
            out << "-";
            value = -value;
        }
        out << "Rs. " << value / 100 << "."
            << setw(2) << setfill('0') << value % 100
            << setfill(' ');
        return out;
    }

    friend istream& operator>>(istream& in, Money& m) {
        long long rupees;
        int p;
        cout << "Enter rupees and paise: ";
        if (in >> rupees >> p && p >= 0 && p < 100)
            m.paise = rupees * 100 + (rupees < 0 ? -p : p);
        else
            in.setstate(ios::failbit);
        return in;
    }
};

int main() {
    Money a(75), b(50);

    cout << "MONEY OPERATOR OVERLOADING\n";

    cout << "First amount: " << a << endl;
    cout << "Second amount: " << b << endl;

    cout << "Addition: " << a + b << endl;
    cout << "Subtraction: " << a - b << endl;

    a += b;
    cout << "After += : " << a << endl;

    cout << "Equality: " << (a == b ? "Equal" : "Not Equal") << endl;
    cout << "Less than: " << (b < a ? "True" : "False") << endl;

    Money negative = Money(50) - Money(100);
    cout << "Negative subtraction: " << negative << endl;

    cout << "\nSTREAM INPUT TEST\n";
    Money input;
    if (cin >> input)
        cout << "Entered amount: " << input << endl;

    cout << "\nPERFORMANCE TEST\n";
    Money total;
    auto start = high_resolution_clock::now();

    for (int i = 0; i < 1000000; i++)
        total += Money(1);

    auto stop = high_resolution_clock::now();

    cout << "One million additions: " << total << endl;
    cout << "Integer time: "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds\n";

    double value = 0.0;
    start = high_resolution_clock::now();

    for (int i = 0; i < 1000000; i++)
        value += 0.01;

    stop = high_resolution_clock::now();

    cout << fixed << setprecision(2);
    cout << "Double result: " << value << endl;
    cout << "Double time: "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds\n";

    return 0;
}
