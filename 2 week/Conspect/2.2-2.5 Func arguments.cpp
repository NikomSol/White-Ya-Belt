#include <iostream>
#include <string>
#include <vector>
using namespace std;

void PrintWords(vector<string> words) {
    for (auto w : words) {
        cout << w << " ";
    }
}

void ChangeInt (int x) {
    x = 42;
}

void Swap (int& x, int& y) {
    int buf = x;
    x = y;
    y = buf;
}

void PrintInt (const int& x){
    cout << x << endl;
}


int main () {
    PrintWords({"sd", "adsf", "dsf"});

    //В функцию передается копия a
    int a = 5;
    ChangeInt(a);
    cout << a << endl;
    
    //Передача по ссылке передает само значение, ссылку на переменную
    int b = 2;
    cout << a << " " << b << endl;
    Swap(a, b);
    cout << a << " " << b << endl;

    //Константная ссылка не делается копия a, но защищает от изменения a
    //Еще можно передавать результат вызова других функций
    //В целом, const запрещает изменение переменной
    PrintInt(a);
    cout << a << endl;

    return 0;
}
