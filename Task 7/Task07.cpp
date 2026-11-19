
#include <iostream>
using namespace std;

const long long MIN_BALANCE = 5000;

// Procedural approach
long long proceduralBalance = 10000;

bool proceduralCanTravel(long long fare) {
    return fare >= 0 && proceduralBalance - fare >= MIN_BALANCE;
}

bool proceduralDeduct(long long fare) {
    if (proceduralCanTravel(fare)) {
        proceduralBalance -= fare;
        return true;
    }
    return false;
}

// Object-oriented approach
class SmartCard {
private:
    long long balance;

public:
    SmartCard(long long initialBalance) {
        balance = initialBalance;
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
    long long fare = 3000;

    cout << "PROCEDURAL APPROACH\n";

    if (proceduralDeduct(fare)) {
        cout << "Journey approved\n";
    } else {
        cout << "Journey denied\n";
    }

    cout << "Remaining balance: " << proceduralBalance
         << " paise\n\n";

    cout << "OBJECT-ORIENTED APPROACH\n";

    SmartCard card(10000);

    if (card.deduct(fare)) {
        cout << "Journey approved\n";
    } else {
        cout << "Journey denied\n";
    }

    cout << "Remaining balance: " << card.getBalance()
         << " paise\n";

    return 0;
}

