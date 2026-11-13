#include <iostream>
using namespace std;

int main() {
    int tokenType = 2;
    float tokenValue = 0.0f;

    switch (tokenType) {
        case 1: {
            int offset = 10;
            tokenValue = 50.0f + offset;
            break;
        }

        case 2: {
            int multiplier = 5;
            tokenValue = 20.0f * multiplier;
            break;
        }

        case 3: {
            tokenValue += 100.0f;
            break;
        }

        case 4: {
            cout << "Integer token detected" << endl;
            break;
        }

        default:
            cout << "Unknown token" << endl;
    }

    cout << "Calculated Value: " << tokenValue << endl;

    return 0;
}
