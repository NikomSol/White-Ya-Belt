#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct Day
{
    int value;
    explicit Day (int new_value) {
        value = new_value;
    }
};

struct Month
{
    int value;
    explicit Month(int new_value) {
        value = new_value;
    }
};

struct Year
{
    int value;
    explicit Year(int new_value) {
        value = new_value;
    }
};


struct Date {
    int day;
    int month;
    int year;

    Date(Day new_day, Month new_month, Year new_year) {
        day = new_day.value;
        month = new_month.value;
        year = new_year.value;
    }
};

void PrintDate(const Date& date) {
    cout << date.day << "." << date.month << "." << date.year << endl;
}

int main() {
    // Повышаем читаемость с помощью явных конструкторов
    Date date1 = {Day{10}, Month{11},Year{2014}};
    // Date date2 = {{10}, {11},{2014}};
    PrintDate(date1);

    return 0;
}