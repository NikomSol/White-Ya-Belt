#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

class Duration {
private:
    int hour;
    int min;
public:
    Duration(const int& new_hour=0, const int& new_min=0) {
        int total = new_hour * 60 + new_min;
        hour = total / 60;
        min = total % 60;
    }

    int GetHour() const {
        return hour;
    }

    int GetMin() const {
        return min;
    }
};


bool operator < (const Duration& lhs, const Duration& rhs) {
    if (lhs.GetHour() == rhs.GetHour()) {
        return lhs.GetMin() < rhs.GetMin();
    }
    return lhs.GetHour() < rhs.GetHour();
}

istream& operator>>(istream& stream, Duration& duration) {
    int hour;
    stream >> hour;
    stream.ignore(1);
    int min;
    stream >> min;
    duration = Duration(hour, min);
    return stream;
}

ostream& operator<<(ostream& stream, const Duration& duration) {
    stream << setfill('0');
    stream << setw(2) << duration.GetHour() << ':'
           << setw(2) << duration.GetMin();
    return stream;
}

Duration operator + (const Duration& lhs, const Duration& rhs) {
    return Duration{lhs.GetHour() + rhs.GetHour(), lhs.GetMin() + rhs.GetMin()};
}

int main() {
    stringstream dur_ss("01:30");
    Duration dur1;

    dur_ss >> dur1;
    cout << dur1 << endl;

    // operator<<(operator<<(cout, "hello"), " world");

    Duration dur2 = {0, 50};
    cout << dur2 << endl;

    cout << dur2 + dur1  << endl;
    cout << boolalpha << (dur2 < dur1) << endl;

    vector<Duration> durs;
    durs.push_back(Duration{1, 50});
    durs.push_back(Duration{0, 50});
    durs.push_back(Duration{1, 30});

    for (const auto& dur : durs) {
        cout << dur << '\t';
    }
    cout << endl;
    sort(durs.begin(), durs.end());

    for (const auto& dur : durs) {
        cout << dur << '\t';
    }

    return 0;
}