#include <iostream>
using namespace std;

class Auditorium {
private:
    int rows, cols;
    char** seats;

public:
Auditorium(int r, int c) {
    if (r <= 0 || c <= 0) {
        cout << "Invalid auditorium dimensions!\n";
        rows = 0;
        cols = 0;
        seats = nullptr;
        return;
    }

    rows = r;
    cols = c;
        seats = new char*[rows];

        for (int i = 0; i < rows; i++) {
            seats[i] = new char[cols];

            for (int j = 0; j < cols; j++)
                seats[i][j] = 'O';
        }

        cout << "Auditorium created: "
             << rows << " rows, " << cols << " columns\n";
    }

    void bookSeat(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            cout << "Invalid seat number!\n";
        }
        else if (seats[r][c] == 'X') {
            cout << "Seat already booked!\n";
        }
        else {
            seats[r][c] = 'X';
            cout << "Seat booked successfully!\n";
        }
    }

    void cancelSeat(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            cout << "Invalid seat number!\n";
        }
        else if (seats[r][c] == 'O') {
            cout << "Seat is not booked!\n";
        }
        else {
            seats[r][c] = 'O';
            cout << "Booking cancelled!\n";
        }
    }

    void display() const {
        cout << "\nAUDITORIUM SEAT MAP\n";

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << seats[i][j] << " ";
            cout << endl;
        }
    }

    ~Auditorium() {
        for (int i = 0; i < rows; i++)
            delete[] seats[i];

        delete[] seats;

        cout << "Auditorium memory released.\n";
    }
};

int main() {
    Auditorium hall(3, 4);

    hall.display();

    hall.bookSeat(0, 1);
    hall.bookSeat(1, 2);

    hall.display();

    hall.cancelSeat(0, 1);

    hall.display();

    hall.bookSeat(5, 2);

    return 0;
}
