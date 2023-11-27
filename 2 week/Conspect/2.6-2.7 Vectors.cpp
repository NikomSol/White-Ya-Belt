#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Константная ссылка чтобы не плодить копию объекта
void PrintVector(const vector<string>& v) {
    for (string s : v) {
        cout << s << ' ';
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<string> v(n);
    // string& - позволяет менять строки в векторе
    for (string& s : v) {
        cin >> s;
    }
    PrintVector(v);

    vector<string> w;
    int i = 0;
    while (i < n) {
        string s;
        cin >> s;
        w.push_back(s);
        i++;
    }
    PrintVector(w);
    
    return 0;
}

