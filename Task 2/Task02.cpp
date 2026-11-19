
#include <iostream>
using namespace std;

// Enum class for metro zones
enum class Zone {
    Inner, Middle, Outer
};

// Fixed fare constants in paise
constexpr long long BASE_FARE[] = {
    1000, 2000, 3000
};

constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

int main() {
    cout << "Metro Fare Constants\n";

    cout << "Inner Zone Fare: "
         << BASE_FARE[0] << " paise\n";

    cout << "Middle Zone Fare: "
         << BASE_FARE[1] << " paise\n";

    cout << "Outer Zone Fare: "
         << BASE_FARE[2] << " paise\n";

    cout << "Peak Surcharge: "
         << PEAK_SURCHARGE_PERCENT << "%\n";

    cout << "Minimum Balance: "
         << MIN_BALANCE_PAISE << " paise\n";

    Zone selectedZone = Zone::Outer;

    cout << "Selected Zone: ";

    switch (selectedZone) {
        case Zone::Inner:
            cout << "Inner";
            break;

        case Zone::Middle:
            cout << "Middle";
            break;

        case Zone::Outer:
            cout << "Outer";
            break;
    }

    cout << '\n';

    return 0;
}

