#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
#define all(c) c.begin(), c.end()

class Person {
public:
  Person (const string& bname, const string& bsurname, const int& byear) {
    name[byear] = bname;
    surname[byear] = bsurname;
  }

  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
    if (year > name.begin() -> first) {
      name[year] = first_name;
    }
  }

  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
    if (year > surname.begin() -> first) {
      surname[year] = last_name;
    }
  }

  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
    string current_name = GetCurrent(name, year);
    string current_surname = GetCurrent(surname, year);

    if (current_name == "" && current_surname == "") {return "No person";}
    else {return current_name + ' ' + current_surname;}
    // if (current_name == "" {
    //     if (current_surname == "") {return "No person";}
    //     else {return current_surname + " with unknown first name";}
    // }
    // else {
    //     if (current_surname == "") {return current_name + " with unknown last name";}  
    //     else {return current_name + ' ' + current_surname;}  
    // }
  }

  string GetFullNameWithHistory(int year) {
    // получить имя и фамилию по состоянию на конец года year
    string current_name = GetCurrentHistory(name, year);
    string current_surname = GetCurrentHistory(surname, year);

    if (current_name == "" && current_surname == "") {return "No person";}
    else {return current_name + ' ' + current_surname;}
    // if (current_name == "" ) {
    //     if (current_surname == "") {return "No person";}
    //     else {return current_surname + " with unknown first name";}
    // }
    // else {
    //     if (current_surname == "") {return current_name + " with unknown last name";}  
    //     else {return current_name + ' ' + current_surname;}  
    // }
  }

private:
  map <int, string> name;
  map <int, string> surname; 

  string GetCurrent(const map <int, string>& map, const int& year) {
    string current = "";
    for (const auto& [key, value] : map) {
        if (key <= year) {current = value;} 
        else {break;}
    }
    return current;
  }

  string GetCurrentHistory(const map <int, string>& map, const int& year) {
    // Calc vector of names
    vector <string> current = {};
    for (const auto& [key, value] : map) {
        if (key <= year) {
          if (current.size() != 0 ) {
            if  (value != current.back()) {
              current.push_back(value);
            }
          } else {
            current.push_back(value);
          }
        } 
        else {break;}
    }
    
    // Create string answer
    if (current.size() == 0) {
      return "";
    }
    if (current.size() == 1) {
      return current[0];
    }

    reverse(all(current));
    string ans;
    for (int i = 1; i < current.size() - 1; i++) {
      ans = ans + current[i] + ", ";
    }
    ans = current[0] + " (" + ans + current.back() + ")";
    
    return ans;
  }
  
};


int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
