#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Cart {
private:
    string items[10];
    double prices[10];
    int n = 0;
    double discount = 0;

public:
    Cart& add(string item, double price) {
        if (n < 10) {
            items[n] = item;
            prices[n] = price;
            n++;
        }
        return *this;
    }

    Cart& setDiscount(double discount) {
        this->discount = discount;
        return *this;
    }

    double total() const {
        double t = 0;
        for (int i = 0; i < n; i++)
            t += prices[i];

        return t * (100 - discount) / 100;
    }

    void display() const {
        cout << "Cart Total: Rs. "
             << fixed << setprecision(2) << total() << endl;
    }
};

int main() {
    cout << "GROCERY SHOPPING CART\n";

    Cart c;

    // Direct object
    c.add("Rice", 60);

    // Pointer using ->
    Cart* p = &c;
    p->add("Dal", 120);

    // Reference
    Cart& ref = c;
    ref.add("Oil", 180);

    // Method chaining using this pointer
    ref.setDiscount(10);

    cout << "\nMETHOD CHAINING\n";
    c.display();

    // Dynamic object
    Cart* dynamicCart = new Cart();
    dynamicCart->add("Milk", 50);
    dynamicCart->add("Bread", 40);
    dynamicCart->display();
    delete dynamicCart;

    // Array of pointers
    Cart c1, c2, c3;

    c1.add("Item A", 100);
    c2.add("Item B", 250);
    c3.add("Item C", 180);

    Cart* carts[] = {&c1, &c2, &c3};

    int highest = 0;

    for (int i = 1; i < 3; i++) {
        if (carts[i]->total() > carts[highest]->total())
            highest = i;
    }

    cout << "\nHIGHEST CART TOTAL\n";
    cout << "Cart " << highest + 1 << ": Rs. "
         << carts[highest]->total() << endl;

    return 0;
}
