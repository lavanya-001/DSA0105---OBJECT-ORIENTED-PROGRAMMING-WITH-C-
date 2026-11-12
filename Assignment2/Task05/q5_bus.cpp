#include <iostream>
using namespace std;

class BusTicket {
private:
    int seatNumber;
    bool booked;

public:
    static int issuedCount;

    BusTicket() {
        seatNumber = 0;
        booked = false;
    }

    bool bookTicket(int seat) {
        if (booked) {
            cout << "Seat already booked\n";
            return false;
        }

        seatNumber = seat;
        booked = true;
        issuedCount++;

        cout << "Ticket booked for seat " << seatNumber << '\n';
        return true;
    }

    static void showIssuedCount() {
        cout << "Total tickets issued: " << issuedCount << '\n';
    }
};

int BusTicket::issuedCount = 0;

int main() {
    BusTicket tickets[3];

    tickets[0].bookTicket(1);
    tickets[1].bookTicket(2);
    tickets[2].bookTicket(3);

    BusTicket::showIssuedCount();

    return 0;
}
