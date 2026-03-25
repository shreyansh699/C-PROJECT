#include <iostream>
#include <string>
using namespace std;

class Bus {
private:
    int totalSeats;
    int bookedSeats;

public:
    Bus(int seats) {
        totalSeats = seats;
        bookedSeats = 0;
    }

    void showSeats() {
        cout << "Total Seats: " << totalSeats << endl;
        cout << "Available Seats: " << (totalSeats - bookedSeats) << endl;
    }

    void bookSeat(string name) {
        if (bookedSeats < totalSeats) {
            bookedSeats++;
            cout << "Seat booked successfully for " << name << endl;
        } else {
            cout << "No seats available!" << endl;
        }
    }

    void cancelSeat(string name) {
        if (bookedSeats > 0) {
            bookedSeats--;
            cout << "Seat cancelled for " << name << endl;
        } else {
            cout << "No bookings to cancel!" << endl;
        }
    }
};

int main() {
    Bus b(5);
    int choice;
    string name;

    do {
        cout << "\n--- Bus Reservation System ---\n";
        cout << "1. Show Available Seats\n";
        cout << "2. Book Seat\n";
        cout << "3. Cancel Seat\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                b.showSeats();
                break;

            case 2:
                cout << "Enter passenger name: ";
                cin >> name;
                b.bookSeat(name);
                break;

            case 3:
                cout << "Enter passenger name: ";
                cin >> name;
                b.cancelSeat(name);
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while(choice != 4);

    return 0;
}