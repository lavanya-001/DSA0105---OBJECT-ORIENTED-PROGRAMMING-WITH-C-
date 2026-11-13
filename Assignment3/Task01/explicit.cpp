#include <iostream>
using namespace std;

class Book {
public:
explicit Book(int copies) {

        cout << "Book created with " << copies << " copies." << endl;
    }
};

int main() {
Book b(5);
    return 0;
}
