#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <exception>
using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

void CheckSkip(stringstream& stream) {
    if (stream.peek() != '/') {
        stringstream ss;
        ss << "expected /, but has: " << char(stream.peek());
        throw runtime_error(ss.str());
    }
}

Date ParseDate (const string& s) {
    stringstream stream(s);
    Date date;
    stream >> date.year;
    
    CheckSkip(stream);
    stream.ignore(1);
    stream >> date.month;
    
    CheckSkip(stream);
    stream.ignore(1);
    stream >> date.day;
    return date;
}

int main() {
    string date_str = "2017a01/25";

    try {
        Date date = ParseDate(date_str);
        cout << setw(2) << setfill('0') << date.day << '.'
            << setw(2) << setfill('0') << date.month << '.'
            << date.year << endl;
    } catch (exception& ex) {
        cout << "Exception happens: " << ex.what() << endl;
    }

    return 0;
}