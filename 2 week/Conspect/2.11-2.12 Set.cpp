#include <iostream>
#include <set>
#include <vector>

using namespace std;

void PrintSet(const set<string>& mset) {
    cout << mset.size() << endl;
    for (const auto& key : mset) {
        cout << key << endl;
    }
}

int main () {
    set<string> famous_persons = {"Tesla"};
    famous_persons.insert("ROA");
    famous_persons.insert("Einstein");
    // All keys are unicum
    famous_persons.insert("Einstein");
    famous_persons.insert("KNV");
    famous_persons.erase("KNV");

    PrintSet(famous_persons);

    set<string> dubler = famous_persons;
    if (dubler == famous_persons) {
        cout << true << endl;
    }

    // 0 or 1 count
    cout << famous_persons.count("ROA") << endl;

    vector<string> v = {"kk", "gg", "vp", "kk"};
    set<string> s(begin(v), end(v));
    PrintSet(s);

    return 0;
}