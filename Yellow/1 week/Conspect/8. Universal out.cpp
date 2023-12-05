#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <sstream>

using namespace std;

template <typename key, typename value>
ostream& operator<< (ostream& stream, const pair <key, value>& v) {
    return stream << '(' << v.first << ", " << v.second << ')';
}

template <typename Collection>
string Join(const Collection& c, const string& d) {
    stringstream ss;
    bool first = true;
    for (const auto& item : c) {
        if (!first) {
            ss << d;
        } else {
            first = false;
        }
        ss << item;
    }
    return ss.str();
}

template <typename T>
ostream& operator<< (ostream& stream, const vector <T>& v) {
    return cout << '[' << Join(v, ", ") << ']';
}

template <typename key, typename value>
ostream& operator<< (ostream& stream, const map <key, value>& m) {
    return cout << '{'  << Join(m, ", ") << '}';
}

int main () {
    vector <int> vi = {1, 2, 3};
    cout << vi << endl;

    vector <string> vs = {"a", "b", "c"};
    cout << vs << endl;

    // Не работает, т.к. вывод вектора определен ниже чем Join в котором он используется, а у ребят работает
    // vector <vector <int>> vvi = {{1, 2, 3}, {4, 5, 6}};
    // cout << vvi << endl;

    map<int, int> mii = {{1, 2.5}, {2, 4}};
    cout << mii << endl;
}