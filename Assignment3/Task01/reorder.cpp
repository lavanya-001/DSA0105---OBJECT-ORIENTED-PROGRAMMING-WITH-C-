#include <iostream>
using namespace std;

class Book {
    int copies;
    int price;

public:
    Book() : price(500), copies(10) {
        cout << "Copies: " << copies << endl;
        cout << "Price: " << price << endl;
    }
};

int main() {
    Book b;
    return 0;
}
