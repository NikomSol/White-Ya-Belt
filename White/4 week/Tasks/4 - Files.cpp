#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {
    string dir_path = "D:\\Data\\Work\\Other\\Cpp Learning\\White Ya Belt\\4 week\\Tasks\\";
    ifstream input(dir_path + "input.txt");
    ofstream output(dir_path + "output.txt");
    
    string line;
    if (input.is_open() && output.is_open()) {
        while (getline(input, line)) {
            output << line << endl;
            }
    } else {
        cout << "error" << endl;
    }

    input.close();
    output.close();

}