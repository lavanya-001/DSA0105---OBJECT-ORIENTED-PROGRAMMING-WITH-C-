#include <iostream>
using namespace std;

class BusTicket {
private:
    bool booked;

public:
    static int issuedCount;

    BusTicket() : booked(false) {}

    bool bookTicket(int seat) {
        if (booked) return false;

        booked = true;
        issuedCount++;
        cout << "Seat " << seat << " booked\n";
        return true;
    }

    static void showCount() {
        cout << "Tickets issued: " << issuedCount << '\n';
    }
};

int BusTicket::issuedCount = 0;

int main() {
    BusTicket tickets[3];
    int waitingList[10];
    int waitingCount = 0;

    for (int i = 0; i < 4; i++) {
        if (i < 3) {
            tickets[i].bookTicket(i + 1);
        } else {
            waitingList[waitingCount++] = 104;
            cout << "Passenger 104 added to waiting list\n";
        }
    }

    BusTicket::showCount();
    cout << "Waiting passengers: " << waitingCount << '\n';

    return 0;
}
