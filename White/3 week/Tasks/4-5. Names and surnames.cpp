#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
#define all(c) c.begin(), c.end()

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
    name[year] = first_name;
  }

  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
    surname[year] = last_name;
  }

  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
    string current_name = GetCurrent(name, year);
    string current_surname = GetCurrent(surname, year);

    if (current_name == "" ) {
        if (current_surname == "") {return "Incognito";}
        else {return current_surname + " with unknown first name";}
    }
    else {
        if (current_surname == "") {return current_name + " with unknown last name";}  
        else {return current_name + ' ' + current_surname;}  
    }
  }

  string GetFullNameWithHistory(int year) {
    // получить все имена и фамилии по состоянию на конец года year
    string current_name = GetCurrentHistory(name, year);
    string current_surname = GetCurrentHistory(surname, year);

    if (current_name == "" ) {
        if (current_surname == "") {return "Incognito";}
        else {return current_surname + " with unknown first name";}
    }
    else {
        if (current_surname == "") {return current_name + " with unknown last name";}  
        else {return current_name + ' ' + current_surname;}  
    }
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
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;
  
  return 0;
}