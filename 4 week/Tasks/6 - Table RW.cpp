#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;


int main() {
    string dir_path = "D:\\Data\\Work\\Other\\Cpp Learning\\White Ya Belt\\4 week\\Tasks\\";
    ifstream input(dir_path + "input.txt");
    
    int N;
    int M;
    int data;

    if (input.is_open()) {
        input >> N;
        input >> M;
        // cout << N << ' ' << M <<endl;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                input >> data;
                input.ignore(1);
                cout << setw(10) << data;
                if (j != M-1) {
                    cout << ' ';
                }
            }
            cout << endl;
        }

    } else {
        cout << "error" << endl;
    }

    input.close();

}