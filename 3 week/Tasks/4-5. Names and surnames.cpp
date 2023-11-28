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
    vector<string> all_name = GetAll(name, year);
    vector<string> all_surname = GetAll(surname, year);

    if (all_name.size() == 0) {
        if (all_surname.size() == 0) {return "Incognito";}
        else { return GetHistoryString(all_surname) + " with unknown first name";}
    }
    else {
        if (all_surname.size() == 0) {return GetHistoryString(all_name)  + " with unknown last name";}  
        else {return GetHistoryString(all_name) + ' ' + GetHistoryString(all_surname);}  
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

  vector<string> GetAll(const map <int, string>& map, const int& year) {
    vector<string> current = {};
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
    reverse(all(current));
    return current;
  }
  
  string GetHistoryString(const vector<string> vector) {
    int len = vector.size();
    if (len == 1) {
      return vector[0];
    }

    string ans = vector[0] + " (";
    for (int i = 1; i < vector.size() - 1; i++) {
      ans = ans + vector[i] + ", ";
    }
    ans += vector.back() + ")";
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