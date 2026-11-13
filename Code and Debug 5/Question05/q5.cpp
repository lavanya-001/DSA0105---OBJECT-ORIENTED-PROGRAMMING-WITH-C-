#include <iostream>
using namespace std;

class Entity {
public:
    virtual ~Entity() {}

    virtual void attack() const {
        cout << "Entity performs generic scratch." << endl;
    }
};

class Dragon : public Entity {
public:
    void attack() const override {
        cout << "Dragon breathes scorching fire!" << endl;
    }
};

void triggerEncounter(const Entity& e) {
    e.attack();
}

int main() {
    Dragon boss;
    triggerEncounter(boss);

    return 0;
}
