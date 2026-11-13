#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Time {
    int hours, minutes, seconds;

    void normalize() {
        seconds++;
        if (seconds >= 60) {
            seconds = 0;
            minutes++;
        }
        if (minutes >= 60) {
            minutes = 0;
            hours++;
        }
        if (hours >= 24)
            hours = 0;
    }

public:
    Time(int h = 0, int m = 0, int s = 0)
        : hours(h), minutes(m), seconds(s) {}

    Time& operator++() {
        normalize();
        return *this;
    }

    Time operator++(int) {
        Time old = *this;
        normalize();
        return old;
    }

    bool operator==(const Time& t) const {
        return hours == t.hours &&
               minutes == t.minutes &&
               seconds == t.seconds;
    }

    bool operator<(const Time& t) const {
        if (hours != t.hours) return hours < t.hours;
        if (minutes != t.minutes) return minutes < t.minutes;
        return seconds < t.seconds;
    }

    void display() const {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
};

class Playlist {
    vector<string> songs;

public:
    Playlist() {
        songs = {"Song One", "Song Two", "Song Three"};
    }

    string& operator[](int index) {
        if (index < 0 || index >= (int)songs.size())
            throw out_of_range("Invalid playlist index");
        return songs[index];
    }

    const string& operator[](int index) const {
        if (index < 0 || index >= (int)songs.size())
            throw out_of_range("Invalid playlist index");
        return songs[index];
    }

    int size() const {
        return songs.size();
    }
};

int main() {
    cout << "TIME OPERATOR OVERLOADING\n";

    Time t(10, 20, 30);

    cout << "Original: ";
    t.display();

    cout << "Postfix increment: ";
    (t++).display();

    cout << "After postfix: ";
    t.display();

    cout << "Prefix increment: ";
    (++t).display();

    Time a(10, 20, 32);
    cout << "Equality: "
         << (t == a ? "Equal" : "Not Equal") << endl;

    cout << "Less than: "
         << (t < a ? "True" : "False") << endl;

    Time rollover(23, 59, 59);
    cout << "Before rollover: ";
    rollover.display();
    ++rollover;
    cout << "After rollover: ";
    rollover.display();

    cout << "\nPLAYLIST SUBSCRIPT OPERATOR\n";

    Playlist p;
    for (int i = 0; i < p.size(); i++)
        cout << p[i] << endl;

    p[0] = "Updated Song";
    cout << "Modified first song: " << p[0] << endl;

    try {
        cout << p[5] << endl;
    }
    catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
