#include <iostream>
#include <cstring>
using namespace std;

class Text {
private:
    char* data;

public:
    Text(const char* str = "") {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    Text(const Text& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        cout << "Copy constructor called\n";
    }

    Text& operator=(const Text& other) {
        if (this != &other) {
            char* temp = new char[strlen(other.data) + 1];
            strcpy(temp, other.data);
            delete[] data;
            data = temp;
        }
        return *this;
    }

    Text operator+(const Text& other) const {
        char* temp = new char[strlen(data) + strlen(other.data) + 1];
        strcpy(temp, data);
        strcat(temp, other.data);

        Text result(temp);
        delete[] temp;
        return result;
    }

    bool operator==(const Text& other) const {
        return strcmp(data, other.data) == 0;
    }

    bool operator!=(const Text& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& out, const Text& t) {
        out << t.data;
        return out;
    }

    ~Text() {
        delete[] data;
    }
};

int main() {
    cout << "TEXT OPERATOR OVERLOADING\n";

    Text first("Hello ");
    Text second("World");

    Text result = first + second;

    cout << "First text: " << first << endl;
    cout << "Second text: " << second << endl;
    cout << "Combined text: " << result << endl;

    cout << "Equality: "
         << (first == second ? "Equal" : "Not Equal") << endl;

    cout << "Inequality: "
         << (first != second ? "True" : "False") << endl;

    Text empty("");
    Text longText("C++ Operator Overloading");

    cout << "Empty text: [" << empty << "]" << endl;
    cout << "Long text: " << longText << endl;

    cout << "\nSELF ASSIGNMENT TEST\n";
    first = first;
    cout << first << endl;

    cout << "\nCOPY TEST\n";
    Text copied = longText;
    cout << "Copied text: " << copied << endl;

    cout << "\nRULES OF OPERATOR OVERLOADING\n";
    cout << "1. At least one operand must be a user-defined type.\n";
    cout << "2. Operator precedence cannot be changed.\n";
    cout << "3. Number of operands cannot be changed.\n";
    cout << "4. Operators cannot be created or invented.\n";
    cout << "5. Some operators cannot be overloaded.\n";

    cout << "\nNon-overloadable operators: .  .*  ::  ?:  sizeof\n";

    return 0;
}
