
#include <iostream>
#include <climits>
using namespace std;

int main() {
    int hour = 8;
    bool peak = true;
    char zone = 'A';
    long long fare = 3000;
    long long journeys = 3000000;
    double rupees = 30.50;

    cout << "Data Type Sizes\n";

    cout << "Size of int: " << sizeof(int) << " bytes\n";
    cout << "Size of long long: " << sizeof(long long) << " bytes\n";
    cout << "Size of double: " << sizeof(double) << " bytes\n";
    cout << "Size of bool: " << sizeof(bool) << " bytes\n";
    cout << "Size of char: " << sizeof(char) << " bytes\n";

    cout << "\nData Values\n";
    cout << "Hour: " << hour << '\n';
    cout << "Peak: " << peak << '\n';
    cout << "Zone: " << zone << '\n';
    cout << "Fare: " << fare << " paise\n";
    cout << "Journeys: " << journeys << '\n';

    long long total = fare * journeys;

    cout << "\nTotal Fare: " << total << " paise\n";
    cout << "INT_MAX: " << INT_MAX << '\n';
    cout << "LONG_LONG_MAX: " << LLONG_MAX << '\n';

    cout << "\nDouble Example: " << rupees << '\n';

    return 0;
}

