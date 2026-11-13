#include <iostream>
#include <string>
using namespace std;

class Prescription {
private:
    string* medicines;
    int count;

public:
    // Parameterized constructor
    Prescription(string names[], int n) {
        count = n;
        medicines = new string[count];

        for (int i = 0; i < count; i++) {
            medicines[i] = names[i];
        }
    }

    // Deep copy constructor
    Prescription(const Prescription& other) {
        count = other.count;
        medicines = new string[count];

        for (int i = 0; i < count; i++) {
            medicines[i] = other.medicines[i];
        }
    }

    // Copy assignment operator
    Prescription& operator=(const Prescription& other) {
        if (this != &other) {
            string* temp = new string[other.count];

            for (int i = 0; i < other.count; i++) {
                temp[i] = other.medicines[i];
            }

            delete[] medicines;
            medicines = temp;
            count = other.count;
        }
        return *this;
    }

    // Display medicines
    void display() const {
        for (int i = 0; i < count; i++) {
            cout << medicines[i] << " ";
        }
        cout << endl;
    }

    // Destructor
    ~Prescription() {
        delete[] medicines;
    }
};

int main() {
    string names[] = {"Paracetamol", "Cetirizine"};

    Prescription p1(names, 2);
    Prescription p2 = p1;

    string newNames[] = {"Ibuprofen", "ORS"};
    Prescription p3(newNames, 2);

    // Copy assignment
    p2 = p3;
    p2 = p2;

    cout << "Original: ";
    p1.display();

    cout << "Copied and Assigned: ";
    p2.display();

    cout << "Assignment Source: ";
    p3.display();

    return 0;
}
