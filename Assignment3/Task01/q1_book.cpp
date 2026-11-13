#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int copies;

public:
    // Default constructor
    Book() : Book("Unknown", "Unknown", 0) {}

    // Title-only constructor
    Book(string t) : Book(t, "Unknown", 1) {}

    // Parameterized constructor
    Book(string t, string a, int c)
        : title(t), author(a), copies(c >= 0 ? c : 0) {}

    void display() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Copies: " << copies << endl;
        cout << "-------------------" << endl;
    }
};

int main() {
    Book b1;
    Book b2("C++ Programming");
    Book b3("Object Oriented Programming", "Bjarne Stroustrup", 5);
    Book b4("Invalid Book", "Unknown", -3);

    cout << "LIBRARY BOOK RECORDS\n";
    cout << "Default Constructor:\n";
    b1.display();

    cout << "Title-only Constructor:\n";
    b2.display();

    cout << "Parameterized Constructor:\n";
    b3.display();

    cout << "Negative Copies Test:\n";
    b4.display();

    return 0;
}
