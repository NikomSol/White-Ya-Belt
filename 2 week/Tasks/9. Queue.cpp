#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Command {
    string name = "";
    int value = 0;
};

class Queue {
private:
    vector <bool> queqe;

public:
    Queue () {
        queqe = {};
    }
    void PrintQueqe() {
        for (const int& i : queqe) {
            cout << queqe[i];
        }
        cout << endl;
    }
    // * **WORRY *i***: пометить ***i***-го человека с начала очереди (в нумерации с 0) как беспокоящегося;
    void Worry(const int& i) {
        queqe[i] = 1;
    }
    // * **QUIET *i***: пометить ***i***-го человека как успокоившегося;
    void Quiet(const int& i) {
        queqe[i] = 0;
    }
    // * **COME *k***: добавить ***k*** спокойных человек в конец очереди;
    // * **COME *-k***: убрать ***k*** человек из конца очереди;
    void Come(const int& k) {
        if (k > 0) {
            for (int i = 0; i < k ; i++) {
                queqe.push_back(0);
            }
        } else {
            for (int i = 0; i < -k ; i++) {
                queqe.pop_back();
            }
        }
    }
    // * **WORRY_COUNT**: узнать количество беспокоящихся людей в очереди.
    void Worry_count() {
        cout << count(queqe.begin(), queqe.end(), 1) <<endl;
    }

    void Get_command(const Command& command) {
        if (command.name == "WORRY_COUNT") {
            Worry_count();
        } else if (command.name == "COME") {
            Come(command.value);
        } else if (command.name == "QUIET") {
            Quiet(command.value);
        } else if (command.name == "WORRY") {
            Worry(command.value);
        } else {
            cout << "Unknown command" << endl;
        }
    }
};


int main() {
    stringstream teststream("8\nCOME 5\nWORRY 1\nWORRY 4\nCOME -2\nWORRY_COUNT\nCOME 3\nWORRY 3\nWORRY_COUNT\n");


    int commands_amount;
    teststream >> commands_amount;
    vector <Command> commands(commands_amount);
    Queue queue;

    for (int i = 0; i < commands_amount; i++) {
        teststream >> commands[i].name;
        if (teststream.peek() == ' ')
            teststream >> commands[i].value;
    }

    for (const auto& command : commands) {
        queue.Get_command(command);
    }

    return 0;
}