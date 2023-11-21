#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main () {
    // Иначе работа в папке, где компилятор
    string dir_path = "D:\\Data\\Work\\Other\\Cpp Learning\\White Ya Belt\\4 week\\";
    ofstream output(dir_path + "hello.txt");
    // ofstream output(dir_path + "hello.txt", ios::app); // Дозапись
    output << "Hello" << endl;
    output << "string 2" << endl;
    
    
    ifstream input(dir_path + "hello.txt");
    string line;

    if (input.is_open()) {
        while (getline(input, line)) {
            cout << "Line is: " << line << endl;
            }
    } else {
        cout << "error" << endl;
    }

    ofstream output2(dir_path + "date.txt");
    output2 << "10-11-2023" << endl;

    ifstream input2(dir_path + "date.txt");
    string day;
    string month;
    string year;
    if (input2) {
        getline(input2, day, '-');
        getline(input2, month, '-');
        getline(input2, year, '-');
        cout << "Date is: " << day << "." << month << "." << year << endl;
    } else {
        cout << "error" << endl;
    }

    ifstream input3(dir_path + "date.txt");
    int day3;
    int month3;
    int year3;
    if (input3) {
        input3 >> day3;
        input3.ignore(1);
        input3 >> month3;
        input3.ignore(1);
        input3 >> year3;
        input3.ignore(1);
        cout << "Date is: " << day3 << "." << month3 << "." << year3 << endl;
    } else {
        cout << "error" << endl;
    }

    return 0;
}
