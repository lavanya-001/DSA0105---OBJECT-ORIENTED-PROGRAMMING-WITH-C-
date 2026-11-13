#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string title;

    Book(string t) : title(t) {}
};

int main() {
    Book books[3] = {
        Book("C++"),
        Book("Java"),
        Book("Python")
    };

    for (int i = 0; i < 3; i++) {
        cout << books[i].title << endl;
    }

    return 0;
}
