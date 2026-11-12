#include <iostream>
#include <vector>
using namespace std;

int& bigger(int& a, int& b) {
    return (a > b) ? a : b;
}

int main() {
    int x = 10, y = 20;

    cout << "Before: x = " << x << ", y = " << y << '\n';

    bigger(x, y) = 100;

    cout << "After: x = " << x << ", y = " << y << '\n';

    vector<int> numbers = {10, 20, 30};

    int& first = numbers[0];
    cout << "First element: " << first << '\n';

    return 0;
}
