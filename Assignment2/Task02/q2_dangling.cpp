#include <iostream>
using namespace std;

// WRONG: Never return a reference to a local variable.
// int& wrongFunction() {
//     int value = 50;
//     return value;
// }

// CORRECT: Return the value instead.
int correctFunction() {
    int value = 50;
    return value;
}

int main() {
    int result = correctFunction();

    cout << "Returned value: " << result << '\n';

    return 0;
}
