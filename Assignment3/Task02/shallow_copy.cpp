#include <iostream>
#include <string>
using namespace std;

class Prescription {
private:
    string* medicines;
    int count;

public:
    Prescription(string names[], int n) {
        count = n;
        medicines = new string[count];

        for (int i = 0; i < count; i++) {
            medicines[i] = names[i];
        }
    }

    void display() const {
        for (int i = 0; i < count; i++) {
            cout << medicines[i] << " ";
        }
        cout << endl;
    }

    ~Prescription() {
        delete[] medicines;
    }
};

int main() {
    string names[] = {"Paracetamol", "Cetirizine"};

    Prescription p1(names, 2);

    // Default copy constructor performs shallow copying
    Prescription p2 = p1;

    cout << "Original Prescription: ";
    p1.display();

    cout << "Copied Prescription: ";
    p2.display();

    return 0;
}
