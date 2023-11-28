#include <iostream>
#include <string>
using namespace std;

void PrintParity(int x) {
    string parity = (x % 2 == 0) ? "even" : "odd";
    cout << x << " if " << parity << endl;
}

string GetPosit(int x) {
    if (x > 0) {
        return "pos";
    } else if (x < 0) {
        return "neg";
    }
    return "zero";
}

void PrintPosit(int x) {
    string parity = GetPosit(x);
    cout << x << " if " << parity << endl;
}

int main () {
    {
        // x++; Не видно до
        int x;
        {
            x++; // Внутренние функции видят
        }
        x++;
    }
    // x++; Вне блока не видим
    
    PrintParity(5);
    PrintPosit(5);

    return 0;
}