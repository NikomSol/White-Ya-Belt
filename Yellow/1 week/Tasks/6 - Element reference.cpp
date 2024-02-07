#include <iostream>
#include <map>
using namespace std;

template<typename K, typename V>
V& GetRefStrict(map<K, V>& m, const K& key) {
    if (!m.count(key)) {
        throw runtime_error("Unknown key");
    }
    return m[key];
} 

int main() {

    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue

    try {
        string& item = GetRefStrict(m, 1);
    } catch (exception& ex) {
        cout << "Exception happens: " << ex.what() << endl;
    }

    return 0;
}