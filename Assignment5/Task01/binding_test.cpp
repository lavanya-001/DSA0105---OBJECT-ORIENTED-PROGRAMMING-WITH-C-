#include <iostream>
using namespace std;

class Bill {
public:
    virtual ~Bill() = default;

    // Non-virtual function
    double total() const {
        return 100;
    }
};

class OutPatient : public Bill {
public:
    double total() const {
        return 500;
    }
};

int main() {
    Bill* b = new OutPatient();

    cout << "Base pointer total: " << b->total() << endl;
    cout << "Derived object total: "
         << static_cast<OutPatient*>(b)->total() << endl;

    delete b;
    return 0;
}
