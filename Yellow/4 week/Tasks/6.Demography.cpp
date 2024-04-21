#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


enum class Gender {
  FEMALE,
  MALE
};


struct Person {
  int age;  // возраст
  Gender gender;  // пол
  bool is_employed;  // имеет ли работу
};


template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }
  vector<typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size() / 2;
  nth_element(
      begin(range_copy), middle, end(range_copy),
      [](const Person& lhs, const Person& rhs) {
        return lhs.age < rhs.age;
      }
  );
  return middle->age;
}


void PrintStats(vector<Person> persons) {
    // Поиск медианы
    // * все люди;
    // * все женщины;
    // * все мужчины;
    // * все безработные женщины;
    // * все занятые женщины;
    // * все безработные мужчины;
    // * все занятые мужчины.
    int age = ComputeMedianAge(begin(persons), end(persons));
    cout << "Median age = " << age << endl;

    auto bound_gender = partition(begin(persons), end(persons),
        [](const Person& person) {
            return person.gender == Gender::FEMALE;
        });
    age = ComputeMedianAge(begin(persons), bound_gender);
    cout << "Median age for females = " << age << endl;
    age = ComputeMedianAge(bound_gender, end(persons));
    cout << "Median age for males = " << age << endl;

    auto bound_female_employed = partition(begin(persons), bound_gender,
        [](const Person& person) {
            return person.is_employed;
        }
    );
    age = ComputeMedianAge(begin(persons), bound_female_employed);
    cout << "Median age for employed females = " << age << endl;
    age = ComputeMedianAge(bound_female_employed, bound_gender);
    cout << "Median age for unemployed females = " << age << endl;

    auto bound_male_employed = partition(bound_gender, end(persons),
        [](const Person& person) {
            return person.is_employed;
        }
    );
    age = ComputeMedianAge(bound_gender, bound_male_employed);
    cout << "Median age for employed males = " << age << endl;
    age = ComputeMedianAge(bound_male_employed, end(persons));
    cout << "Median age for unemployed males = " << age << endl;
}


int main() {
  vector<Person> persons = {
      {31, Gender::MALE, false},
      {40, Gender::FEMALE, true},
      {24, Gender::MALE, true},
      {20, Gender::FEMALE, true},
      {80, Gender::FEMALE, false},
      {78, Gender::MALE, false},
      {10, Gender::FEMALE, false},
      {55, Gender::MALE, true},
  };
  PrintStats(persons);
    // Median age = 40
    // Median age for females = 40
    // Median age for males = 55
    // Median age for employed females = 40
    // Median age for unemployed females = 80
    // Median age for employed males = 55
    // Median age for unemployed males = 78
  return 0;
}