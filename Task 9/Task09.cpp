
#include <iostream>
#include <string>
using namespace std;

const long long MIN_BALANCE = 5000;

enum class Zone { Inner = 1, Middle, Outer };

bool isPeak(int hour) {
    return (hour >= 8 && hour < 10) ||
           (hour >= 17 && hour < 20);
}

long long calculateFare(int zone, int hour) {
    long long baseFare;

    switch (zone) {
        case 1: baseFare = 1000; break;
        case 2: baseFare = 2000; break;
        case 3: baseFare = 3000; break;
        default: return -1;
    }

    if (hour < 0 || hour > 23)
        return -1;

    if (isPeak(hour))
        baseFare += baseFare * 20 / 100;

    return baseFare;
}

bool canTravel(long long balance, long long fare) {
    return balance >= 0 && fare >= 0 &&
           balance - fare >= MIN_BALANCE;
}

int main() {
    cout << "METRO FARE TESTING\n\n";

    int hours[] = {8, 10, 17, 20};

    for (int hour : hours) {
        cout << hour << ":00 - "
             << (isPeak(hour) ? "Peak" : "Off-peak")
             << '\n';
    }

    cout << "\nZone fare tests:\n";

    for (int zone = 1; zone <= 3; zone++) {
        for (int hour : {9, 12}) {
            cout << "Zone " << zone
                 << ", Hour " << hour
                 << ", Fare " << calculateFare(zone, hour)
                 << " paise\n";
        }
    }

    cout << "\nBalance boundary test:\n";
    cout << (canTravel(8000, 3000) ?
             "Approved" : "Denied") << '\n';

    cout << "\nInvalid zone test:\n";
    cout << (calculateFare(4, 12) == -1 ?
             "Invalid zone rejected" : "Accepted") << '\n';

    cout << "\nNegative recharge test:\n";
    long long recharge = -500;
    cout << (recharge < 0 ?
             "Negative recharge rejected" : "Accepted") << '\n';

    cout << "\nInvalid hour input test:\n";
    int hour;
    cout << "Enter hour: ";

    if (!(cin >> hour)) {
        cout << "Invalid input rejected\n";
        cin.clear();
        cin.ignore(10000, '\n');
    } else if (hour < 0 || hour > 23) {
        cout << "Invalid hour rejected\n";
    } else {
        cout << "Valid hour\n";
    }

    cout << "\nFive journey calculation:\n";

    int zones[] = {1, 2, 3, 1, 2};
    int journeyHours[] = {8, 12, 18, 20, 9};

    long long total = 0;

    for (int i = 0; i < 5; i++) {
        long long f = calculateFare(zones[i], journeyHours[i]);
        total += f;

        cout << "Journey " << i + 1
             << ": " << f << " paise\n";
    }

    cout << "Total fare: " << total << " paise\n";
    cout << "Total fare: Rs " << total / 100.0 << '\n';

    return 0;
}

