#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <map>
#include <set>

using namespace std;

class Cities {
public:
    tuple<bool, string> FindCountry(const string& city) const {
        if (city_to_country.count(city)) {
            return {true, city_to_country.at(city)};
        } else if (amb_cities.count(city)) {
            return {false, "Ambiguous"};
        } else {
            return {false, "Not exist"};
        }
    }
private:
    map<string, string> city_to_country;
    set<string> amb_cities;
};

int main () {
    Cities cities;
    
    // Можно так
    // bool success;
    // string message;
    // tie(success, message) = cities.FindCountry("Ufa");

    // Как в цикле фор со словарями
    auto [success, message] = cities.FindCountry("Ufa");
    cout << success << " " << message << endl;

    return 0;
}