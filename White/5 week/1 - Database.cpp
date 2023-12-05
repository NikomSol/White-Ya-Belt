#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

class Date {
public:
    int GetYear() const {
        return year;
    };
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }
    
    Date (const int& new_year = 0, const int& new_month = 1, const int& new_day = 1) {
        if (new_year < 0 || new_year > 9999) {
            throw invalid_argument("Year value is invalid: " + to_string(new_year));
        } 
        if (new_month < 1 || new_month > 12) {
            throw invalid_argument("Month value is invalid: " + to_string(new_month));
        } 
        if (new_day < 1 || new_day > 31) {
            throw invalid_argument("Day value is invalid: " + to_string(new_day));
        } 
        year = new_year;
        month = new_month;
        day = new_day;
    }

private:
    int year;
    int month;
    int day;
};

istream& operator>> (istream& stream, Date& date) {
    string str;
    stream >> str;
    stringstream stream_local(str);

    int year;
    int month;
    int day;
    
    stream_local >> year;
    if (stream_local.fail() || stream_local.peek() != '-') {
        throw invalid_argument("Wrong date format: " + str);}
    stream_local.ignore(1);
    stream_local >> month;
    if (stream_local.fail() || stream_local.peek() != '-') {
        throw invalid_argument("Wrong date format: " + str);}
    stream_local.ignore(1);
    stream_local >> day;
    if (stream_local.fail()) {
        throw invalid_argument("Wrong date format: " + str);}
    
    date = Date(year, month, day);
    return stream;
}

ostream& operator<< (ostream& stream, const Date& date) {
    cout << setfill('0');
    cout << setw(4) << date.GetYear() << '-';
    cout << setw(2) << date.GetMonth() << '-';
    cout << setw(2) << date.GetDay();
    cout << setfill(' ');
    return stream;
}

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return (lhs.GetYear() < rhs.GetYear());
    } else if (lhs.GetMonth() != rhs.GetMonth()) {
        return (lhs.GetMonth() < rhs.GetMonth());
    } else {
        return (lhs.GetDay() < rhs.GetDay());
    }
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        data_base[date].insert(event);
    }
    
    bool DeleteEvent(const Date& date, const string& event) {
        if (data_base.count(date)) {
            if (data_base[date].count(event)) {
                data_base[date].erase(event);
                return true;
            }
            if (data_base[date].size() == 0)
                DeleteDate(date);
        }
        return false;
    }

    int  DeleteDate(const Date& date) {
        int events_num = data_base[date].size();
        data_base.erase(date);
        return events_num;
    }

    set<string> Find(const Date& date) const{
        set<string> ans = {};
        if (data_base.count(date)) {
            ans = data_base.at(date);
        }
        return ans;
    }

    void Print() const {
        for (const auto& [key, value] : data_base) {
            cout << key;
            for (const string& event : value) {
                cout << " " << event;
            }
        cout << endl;
        }
    }
    
    void GetCommandFromString(const string& command_string) {
        stringstream command(command_string);
        string task;
        command >> task;
        if (task == "Add") {
            Date date;
            string event;
            command >> date;
            command >> event;
            AddEvent(date, event);
        } else if (task == "Del") {
            Date date;
            string event = "";
            command >> date;
            command >> event;
            if (event == "") {
                cout << "Deleted " << DeleteDate(date) << " events" << endl;
            } else {
                if (DeleteEvent(date, event)) {
                    cout << "Deleted successfully" << endl;
                } else {
                    cout << "Event not found" << endl;
                }
            }
        } else if (task == "Print") {
            Print();
        } else if (task == "Find") {
            Date date;
            command >> date;
            set<string> events = Find(date);
            for (const string& event : events) {
                cout << event << endl;
            }
        } else if (task == "") {
        } else {
            cout << "Unknown command: " << task << endl;
        }
    }


private:
    map <Date, set <string>> data_base;
};

int main() {
    stringstream cin("Add 0-1-2 event1\nAdd 1-2-3 event2\nFind 0-1-2\nDel 0-1-2\nPrint\n\
    Del 0-1-2\nDel 1-2-3 event2\nDel 1-2-3 event2\n\nQu\nAdd 0-0-2 event1\nFind 10000-0-2 event1\n");
    Database db;
        
    string command;
    while (getline(cin, command)) {
        try {
            db.GetCommandFromString(command);
        } catch (exception& ex) {
            cout << ex.what() << endl;
        }
    }

    return 0;
}