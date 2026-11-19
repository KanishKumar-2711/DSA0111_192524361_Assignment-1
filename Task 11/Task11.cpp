
#include <iostream>
#include <iomanip>
using namespace std;

enum class Zone {
    Inner,
    Middle,
    Outer
};

constexpr long long INNER_FARE = 1000;
constexpr long long MIDDLE_FARE = 2000;
constexpr long long OUTER_FARE = 3000;

constexpr int PEAK_SURCHARGE = 20;
constexpr long long MIN_BALANCE = 5000;

long long calculateFare(Zone zone, int hour) {
    long long fare = 0;

    switch (zone) {
        case Zone::Inner:
            fare = INNER_FARE;
            break;

        case Zone::Middle:
            fare = MIDDLE_FARE;
            break;

        case Zone::Outer:
            fare = OUTER_FARE;
            break;
    }

    if ((hour >= 8 && hour < 10) ||
        (hour >= 17 && hour < 20)) {
        fare = fare + (fare * PEAK_SURCHARGE / 100);
    }

    return fare;
}

class SmartCard {
private:
    long long balance;

public:
    SmartCard(long long amount) {
        balance = amount;
    }

    bool canTravel(long long fare) const {
        return fare >= 0 && balance - fare >= MIN_BALANCE;
    }

    bool deduct(long long fare) {
        if (canTravel(fare)) {
            balance -= fare;
            return true;
        }
        return false;
    }

    long long getBalance() const {
        return balance;
    }
};

int main() {
    SmartCard card(10000);

    long long fare = calculateFare(Zone::Outer, 9);

    cout << fixed << setprecision(2);

    cout << "NAMMA METRO SMART CARD SYSTEM\n";
    cout << "-----------------------------\n";

    cout << "Initial Balance: Rs "
         << card.getBalance() / 100.0 << '\n';

    cout << "Journey Fare: Rs "
         << fare / 100.0 << '\n';

    if (card.deduct(fare)) {
        cout << "Journey Status: APPROVED\n";
    } else {
        cout << "Journey Status: DENIED\n";
    }

    cout << "Remaining Balance: Rs "
         << card.getBalance() / 100.0 << '\n';

    // Network collection calculation
    long long journeys = 3000000;
    long long totalCollection = OUTER_FARE * journeys;

    cout << "\nNETWORK COLLECTION\n";
    cout << "Total Journeys: " << journeys << '\n';
    cout << "Total Collection: Rs "
         << totalCollection / 100.0 << '\n';

    return 0;
}

