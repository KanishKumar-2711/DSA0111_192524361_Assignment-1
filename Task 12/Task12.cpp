

#include <iostream>
#include <iomanip>
using namespace std;

enum class Zone {
    Inner, Middle, Outer, Airport
};

const long long FARES[] = {
    1000, 2000, 3000, 6000
};

const long long MIN_BALANCE = 5000;

bool isPeak(int hour) {
    return (hour >= 8 && hour < 10) ||
           (hour >= 17 && hour < 20);
}

class MonthlyPass {
private:
    bool allowedZones[4];

public:
    MonthlyPass(Zone first, Zone second) {
        for (int i = 0; i < 4; i++)
            allowedZones[i] = false;

        allowedZones[static_cast<int>(first)] = true;
        allowedZones[static_cast<int>(second)] = true;
    }

    bool covers(Zone zone) const {
        return allowedZones[static_cast<int>(zone)];
    }
};

class SmartCard {
private:
    long long balance;

public:
    SmartCard(long long amount) {
        balance = amount;
    }

    bool deduct(long long fare) {
        if (fare < 0 || balance - fare < MIN_BALANCE)
            return false;

        balance -= fare;
        return true;
    }

    long long getBalance() const {
        return balance;
    }
};

long long calculateFare(Zone zone, int hour, bool weekend) {
    int index = static_cast<int>(zone);

    if (index < 0 || index >= 4 || hour < 0 || hour > 23)
        return -1;

    long long fare = FARES[index];

    if (weekend) {
        fare -= fare * 10 / 100;
    } else if (isPeak(hour)) {
        fare += fare * 20 / 100;
    }

    return fare;
}

int main() {
    SmartCard card(20000);

    MonthlyPass pass(Zone::Inner, Zone::Middle);

    cout << fixed << setprecision(2);

    cout << "REVISED METRO FARE SYSTEM\n\n";

    struct Journey {
        Zone zone;
        int hour;
        bool weekend;
    };

    Journey journeys[] = {
        {Zone::Airport, 9, false},
        {Zone::Airport, 12, true},
        {Zone::Outer, 18, false},
        {Zone::Inner, 12, false},
        {Zone::Middle, 9, true}
    };

    for (const Journey& j : journeys) {
        long long fare = calculateFare(
            j.zone, j.hour, j.weekend
        );

        if (pass.covers(j.zone)) {
            cout << "Monthly pass used. Fare Rs 0.00\n";
        } else if (fare >= 0 && card.deduct(fare)) {
            cout << "Fare Rs "
                 << fare / 100.0
                 << " approved\n";
        } else {
            cout << "Journey denied\n";
        }
    }

    cout << "\nRemaining card balance: Rs "
         << card.getBalance() / 100.0 << '\n';

    return 0;
}
