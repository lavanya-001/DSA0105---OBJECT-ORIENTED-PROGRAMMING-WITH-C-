#include <iostream>
using namespace std;

// Return by value to avoid dangling reference
int getMaximumScaled(int a, int b, int scaleFactor) {
    int maxVal = (a > b) ? a : b;
    return maxVal * scaleFactor;
}

// Safe return by reference to an array element
int& getArrayElement(int arr[], int index) {
    return arr[index];
}

int main() {
    int x = 10, y = 20;

    int scaledValue = getMaximumScaled(x, y, 2);
    cout << "Scaled Max: " << scaledValue << endl;

    int data[3] = {100, 200, 300};
    getArrayElement(data, 1) = 999;

    cout << "Updated Array[1]: " << data[1] << endl;
    cout << "Scaled Max Value: " << scaledValue << endl;

    return 0;
}
