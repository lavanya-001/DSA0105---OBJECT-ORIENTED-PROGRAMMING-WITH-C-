#include <iostream>
using namespace std;

class WindowBox {
private:
    int width;
    int height;

public:
    WindowBox() : width(0), height(0) {}

    WindowBox& setWidth(int width) {
        this->width = width;
        return *this;
    }

    WindowBox& setHeight(int height) {
        this->height = height;
        return *this;
    }

    void display() const {
        cout << "Window: " << width
             << " x " << height << endl;
    }
};

int main() {
    WindowBox box;

    box.setWidth(800).setHeight(600);

    box.display();

    return 0;
}
