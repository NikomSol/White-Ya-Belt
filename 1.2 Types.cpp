#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Person
{
    string name;
    string surname;
    int age;
};


int main()
{
    //base types

    int x = -5;
    double pi = 3.14;
    bool logic = false;
    char symbol = 'Z';
    // char symbol2 = "Z"; - doesn't work

    //included types

    string str = "Hello, world";
    // string str2 = 'Hello, world?'; - doesn't work

    //array
    vector<int> nums = {1, 3, 5, 7};
    cout << nums.size() << "\n";

    //dictionary
    map<string, int> name_to_value;
    name_to_value["one"] = 1;
    name_to_value["two"] = 2;
    cout << "two is " << name_to_value["two"] << "\n";

    //struct types
    vector<Person> staff;
    staff.push_back({"Nikita", "Kovalenko", 29});
    staff.push_back({"Sandaara", "Kovalenko", 27});
    cout << staff[0].name;

    return 0;
}