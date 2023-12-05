#include <iostream>
#include <vector>
#include <cstdint>
#include <limits>

using namespace std;

int main() {
    // Ошибка приведения типов
    {
        vector <int> t = {-8, -7, 3};
        int sum = 0;
        for (int x : t) {
            sum += x;
        } 

        int avg = sum / t.size(); // Неявное приведение типов! Отрицательное число приводится к беззнаковому
        cout << avg << endl;
    }

    // Ошибка переполнения типов
    {
        int x = 2'000'000'000;
        cout << x << endl;
        x *= 2;
        cout << x << endl; // Переполнение от -2 147 483 648 до 2 147 483 647 (4 байта - 32 бита)
    }

    // Целочисленные типы
    {
        unsigned int a; //0 - 2^32 - 1
        size_t b; //4 или 8 байт (если 32 и 64 битная система) - результат вызова size() для контейнеров
        int8_t c; //(8, 16, 32, 64)
        uint8_t d;
    }

    // Размеры и объемы памяти переменных
    {
        cout << sizeof(int) << endl;
        cout << sizeof(size_t) << endl;
        cout << numeric_limits<int>::min() << " " << numeric_limits<int>::max() << endl;
    }

    //For
    {
        vector<int> x = {4, 5};
        // Честно приводим к беззнаковому
        for (size_t i = 0; i < size(x); i++) {
            cout << x[i] << " ";
        }
        cout << endl;
        // Приводим все к знаковым
        for (int i = 0; i < static_cast<int>(x.size()); i++) {
            cout << x[i] << " ";
        }
        cout << endl;
        // Вычитание из беззнакового может привести к максимальному значению в типе (переполнение памяти)
        for (size_t i = 0; i + 3 < size(x); i++) {
            cout << x[i] << " ";
        }
        cout << endl;
    }
    return 0;
}