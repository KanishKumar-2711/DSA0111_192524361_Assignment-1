
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const long long farePaise = 3601;
    const double fareRupees = 36.01;

    long long journeys[] = {
        20000, 500000, 3000000
    };

    cout << fixed << setprecision(2);

    cout << "FARE TOTAL COMPARISON\n\n";

    for (long long n : journeys) {
        long long integerTotal = farePaise * n;
        double doubleTotal = fareRupees * n;

        cout << "Journeys: " << n << '\n';

        cout << "Integer paise total: "
             << integerTotal << " paise\n";

        cout << "Integer total in Rs: "
             << integerTotal / 100.0 << '\n';

        cout << "Double total in Rs: "
             << doubleTotal << '\n';

        cout << "Difference in Rs: "
             << doubleTotal - integerTotal / 100.0
             << "\n\n";
    }

    int intTotal = 3601 * 3000000;
    long long longTotal = 3601LL * 3000000;
    double doubleTotal = 36.01 * 3000000;

    cout << "DATA TYPE COMPARISON\n";
    cout << "int result: " << intTotal << '\n';
    cout << "long long result: " << longTotal << '\n';
    cout << "double result: " << fixed
         << setprecision(2) << doubleTotal << '\n';

    return 0;
}

