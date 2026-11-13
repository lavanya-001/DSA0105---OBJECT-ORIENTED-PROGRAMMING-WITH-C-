#include <iostream>
#include <cstring>

class DynamicString {
private:
    char *buffer;
    int length;

public:
    DynamicString(const char *str) {
        length = std::strlen(str);
        buffer = new char[length + 1];
        std::strcpy(buffer, str);
    }

    // Correct deep copy constructor
    DynamicString(const DynamicString &source) {
        length = source.length;
        buffer = new char[length + 1];
        std::strcpy(buffer, source.buffer);
    }

    ~DynamicString() {
        delete[] buffer;
    }

    void print() const {
        std::cout << buffer << std::endl;
    }
};

int main() {
    DynamicString s1("Antigravity C++");
    DynamicString s2 = s1;

    std::cout << "Copied String: ";
    s2.print();

    return 0;
}
