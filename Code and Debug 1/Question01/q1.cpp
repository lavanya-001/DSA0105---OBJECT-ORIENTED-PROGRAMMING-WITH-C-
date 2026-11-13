#include <iostream>
using namespace std;

int main() {
    unsigned char num = 15;

    if ((num & 1) == 1 && num > 10) {
        cout << "Valid Odd Number: " << (int)num << endl;
    } else {
        cout << "Condition Failed for: " << (int)num << endl;
    }

    for (int i = 3; i >= 0; --i) {
        cout << i << " ";
    }

    cout << endl;
    return 0;
}
