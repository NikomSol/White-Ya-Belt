#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


struct Duration {
    int hour = 0;
    int min = 0;
};

bool operator < (const Duration& lhs, const Duration& rhs) {
    if (lhs.hour == rhs.hour) {
        return lhs.min < rhs.min;
    }
    return lhs.hour < rhs.hour;
}

istream& operator>>(istream& stream, Duration& duration) {
    stream >> duration.hour;
    stream.ignore(1);
    stream >> duration.min;
    return stream;
}


ostream& operator<<(ostream& stream, const Duration& duration) {
    stream << setfill('0');
    stream << setw(2) << duration.hour << ':'
           << setw(2) << duration.min;
    return stream;
}

Duration operator + (const Duration& lhs, const Duration& rhs) {
    return Duration{lhs.hour + rhs.hour, lhs.min + rhs.min};
}

int main() {
    stringstream dur_ss("01:30");
    Duration dur1;

    dur_ss >> dur1;
    cout << dur1 << endl;

    // operator<<(operator<<(cout, "hello"), " world");

    Duration dur2 = {0, 10};
    cout << dur2 << endl;

    cout << boolalpha << (dur2 < dur1) << endl;
    cout << dur2 + dur1  << endl;

    return 0;
}