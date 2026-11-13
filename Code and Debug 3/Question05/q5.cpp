#include <iostream>
using namespace std;

class Counter {
private:
    int value;

public:
    Counter(int v = 0) : value(v) {}

    // Prefix increment
    Counter& operator++() {
        ++value;
        return *this;
    }

    // Postfix increment
    Counter operator++(int) {
        Counter old = *this;
        value++;
        return old;
    }

    void display() const {
        cout << "Counter: " << value << endl;
    }
};

int main() {
    Counter c(5);

    cout << "Original: ";
    c.display();

    ++c;
    cout << "After prefix increment: ";
    c.display();

    c++;
    cout << "After postfix increment: ";
    c.display();

    return 0;
}
