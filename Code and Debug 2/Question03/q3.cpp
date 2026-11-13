#include <iostream>
using namespace std;

// Cuboid volume
double computeCuboid(double length, double width = 1.0,
                     double height = 1.0) {
    return length * width * height;
}

// Cube volume
double computeCube(double side) {
    return side * side * side;
}

// Cylinder volume
double computeCylinder(double radius, double height) {
    return 3.14159 * radius * radius * height;
}

int main() {
    cout << "Cube Volume: " << computeCube(5.0) << endl;
    cout << "Cylinder Volume: "
         << computeCylinder(3.0, 7.0) << endl;
    cout << "Cuboid Volume: "
         << computeCuboid(5.0, 2.0, 3.0) << endl;

    return 0;
}
