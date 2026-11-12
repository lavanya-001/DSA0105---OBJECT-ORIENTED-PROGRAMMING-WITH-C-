#include <iostream>
#include <cstdlib>
using namespace std;

class Time {
private:
    int hours, minutes;

public:
    Time(int h, int m) : hours(h), minutes(m) {}

    friend int minutesBetween(Time t1, Time t2);
    friend bool earlier(Time t1, Time t2);
};

int minutesBetween(Time t1, Time t2) {
    int first = t1.hours * 60 + t1.minutes;
    int second = t2.hours * 60 + t2.minutes;
    return abs(first - second);
}

bool earlier(Time t1, Time t2) {
    int first = t1.hours * 60 + t1.minutes;
    int second = t2.hours * 60 + t2.minutes;
    return first < second;
}

inline int addMinutes(int a, int b) {
    return a + b;
}

int main() {
    Time first(9, 30);
    Time second(11, 15);

    cout << "Minutes between: "
         << minutesBetween(first, second) << '\n';

    cout << "Is first time earlier? "
         << (earlier(first, second) ? "Yes" : "No") << '\n';

    cout << "Inline function result: "
         << addMinutes(30, 15) << '\n';

    return 0;
}
