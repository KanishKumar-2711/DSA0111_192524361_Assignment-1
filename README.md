
#include <iostream>
#include <string>
using namespace std;

enum class Zone {
    Inner, Middle, Outer
};

class Passenger {
public:
    string name;

    Passenger(string n) {
        name = n;
    }
};

class FareTable {
public:
    static long long getFare(Zone z) {
        switch (z) {
            case Zone::Inner:
                return 1000;
            case Zone::Middle:
                return 2000;
            case Zone::Outer:
                return 3000;
        }
        return 0;
    }
};

class Journey {
public:
    Zone zone;
    bool peak;

    Journey(Zone z, bool p) {
        zone = z;
        peak = p;
    }

    long long calculateFare() {
        long long fare = FareTable::getFare(zone);

        if (peak) {
            fare += fare * 20 / 100;
        }

        return fare;
    }
};

class SmartCard {
private:
    long long balance;

public:
    SmartCard(long long b) {
        balance = b;
    }

    bool canTravel(long long fare) {
        return balance - fare >= 5000;
    }

    void deduct(long long fare) {
        if (canTravel(fare)) {
            balance -= fare;
        }
    }

    long long getBalance() {
        return balance;
    }
};

int main() {
    Passenger p("Kumar");

    SmartCard card(10000);

    Journey trip(Zone::Outer, true);

    long long fare = trip.calculateFare();

    cout << "Passenger: " << p.name << '\n';
    cout << "Fare: " << fare << " paise\n";

    if (card.canTravel(fare)) {
        card.deduct(fare);
        cout << "Journey Approved\n";
    } else {
        cout << "Journey Denied\n";
    }

    cout << "Remaining Balance: "
         << card.getBalance() << " paise\n";

    return 0;
}
