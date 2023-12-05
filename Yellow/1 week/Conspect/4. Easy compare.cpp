#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

struct Date {
    int year;
    string month;
    int day;
};

bool operator< (const Date& lhs, const Date& rhs) {
    // tuple <const int&, const string&, const int&> - кортеж, при создании ссылки на значения
    return tie(lhs.year, lhs.month, lhs.day) <
           tie(rhs.year, rhs.month, rhs.day);
}

int main() {
    cout << (Date{2017, "July" ,10} < Date{2200, "June", 2}) << endl;
    return 0;
}