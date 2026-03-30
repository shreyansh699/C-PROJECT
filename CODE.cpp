#include <iostream>
using namespace std;

// 🔷 Abstract Class (Abstraction)
class BusSystem {
public:
    virtual void bookSeat(int seats) = 0;   // pure virtual function
    virtual void showSeats() = 0;
};

// 🔷 Base Class (Encapsulation + Inheritance)
class Bus : public BusSystem {
protected:
    int totalSeats;
    int bookedSeats;

public:
    Bus() {
        totalSeats = 30;
        bookedSeats = 0;
    }

    // Polymorphism (virtual function)
    void bookSeat(int seats) {
        if (bookedSeats + seats <= totalSeats) {
            bookedSeats += seats;
            cout << seats << " seats booked in Normal Bus.\n";
        } else {
            cout << "Seats not available in Normal Bus.\n";
        }
    }

    void showSeats() {
        cout << "Normal Bus Available Seats: " 
             << totalSeats - bookedSeats << endl;
    }
};

// 🔷 Derived Class (Inheritance + Polymorphism)
class LuxuryBus : public Bus {
public:
    // Function Overriding (Polymorphism)
    void bookSeat(int seats) {
        if (bookedSeats + seats <= totalSeats) {
            bookedSeats += seats;
            cout << seats << " seats booked in Luxury Bus.\n";
        } else {
            cout << "Luxury Bus Full!\n";
        }
    }

    void showSeats() {
        cout << "Luxury Bus Available Seats: " 
             << totalSeats - bookedSeats << endl;
    }
};

// 🔷 Main Function
int main() {
    int choice, seats;

    BusSystem* bus1;   // base class pointer (Abstraction + Polymorphism)

    Bus normalBus;
    LuxuryBus luxuryBus;

    do {
        cout << "\n--- Bus Booking System ---\n";
        cout << "1. Normal Bus Booking\n";
        cout << "2. Luxury Bus Booking\n";
        cout << "3. Show Seats\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            bus1 = &normalBus;
            cout << "Enter seats: ";
            cin >> seats;
            bus1->bookSeat(seats);
            break;

        case 2:
            bus1 = &luxuryBus;
            cout << "Enter seats: ";
            cin >> seats;
            bus1->bookSeat(seats);
            break;

        case 3:
            normalBus.showSeats();
            luxuryBus.showSeats();
            break;

        case 4:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}
