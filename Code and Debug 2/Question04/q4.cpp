#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;

public:
    // Default constructor
    Student() {
        rollNumber = 0;
        name = "Unknown";
    }

    // Parameterized constructor
    Student(int r, string n) {
        rollNumber = r;
        name = n;
    }

    void display() const {
        cout << "Roll: " << rollNumber
             << ", Name: " << name << endl;
    }
};

int main() {
    Student batch[3];

    batch[0] = Student(101, "Aarav");
    batch[1] = Student(102, "Bhavna");
    batch[2] = Student(103, "Chirag");

    for (int i = 0; i < 3; ++i) {
        batch[i].display();
    }

    return 0;
}
