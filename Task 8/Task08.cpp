
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    long long balance, fare;

    cout << "Enter card balance in paise: ";

    while (!(cin >> balance) || balance < 0) {
        cout << "Invalid balance. Enter a non-negative number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter fare in paise: ";

    while (!(cin >> fare) || fare < 0) {
        cout << "Invalid fare. Enter a non-negative number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "\n----- METRO JOURNEY REPORT -----\n";
    cout << fixed << setprecision(2);

    cout << "Initial Balance: Rs "
         << balance / 100.0 << '\n';

    cout << "Journey Fare:    Rs "
         << fare / 100.0 << '\n';

    if (balance - fare >= 5000) {
        balance -= fare;
        cout << "Journey Status: APPROVED\n";
    } else {
        cout << "Journey Status: DENIED\n";
    }

    cout << "Remaining Balance: Rs "
         << balance / 100.0 << '\n';

    return 0;
}

