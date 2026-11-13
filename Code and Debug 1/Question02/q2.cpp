#include <iostream>
using namespace std;

double taxRate = 0.18;

int main() {
    double itemPrice = 1000.0;
    double localTaxRate = 0.05;

    cout << "Local Rate: " << localTaxRate << endl;

    double totalWithGlobalTax =
        itemPrice + (itemPrice * ::taxRate);

    {
        int corporateTaxRate = 12;

        double totalWithLocalTax =
            itemPrice + (itemPrice * localTaxRate);

        cout << "Corporate Rate: " << corporateTaxRate << endl;
        cout << "Inner total: " << totalWithLocalTax << endl;
    }

    cout << "Final Global Calculation: "
         << totalWithGlobalTax << endl;

    return 0;
}
