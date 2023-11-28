#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct Command {
    string name = "";
    int day = 0;
    string business = "";
};


main () {
    stringstream cin("12\nADD 5 Salary\nADD 31 Walk\nADD 30 WalkPreparations\nNEXT\n\
    DUMP 5\nDUMP 28\nNEXT\nDUMP 31\nDUMP 30\nDUMP 28\nADD 28 Payment\nDUMP 28\n");
    
    vector <int> day_in_mounth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int current_mounth = 0;
    map <int, vector <string>> plan;
    
    int command_amount;
    cin >> command_amount;

    for (int i = 0; i < command_amount; i++) {
        Command command;
        cin >> command.name;
        if (command.name == "ADD") {
            cin >> command.day;
            cin >> command.business;
            plan[command.day].push_back(command.business);
        } else if (command.name == "DUMP") {
            cin >> command.day;
            cout << plan[command.day].size() << ' ';
            for (const auto& item : plan[command.day]) {
                cout << item << ' ';
            }
            cout << endl;
        } else if (command.name == "NEXT") {
            int old_mounth = current_mounth;
            current_mounth = (old_mounth + 1) % 12;
            int days_in_old_mounth = day_in_mounth[old_mounth]; 
            int days_in_current_mounth = day_in_mounth[current_mounth];
            
            for (int i = days_in_current_mounth + 1; i <= days_in_old_mounth; i++) {
                plan[days_in_current_mounth].insert(end(plan[days_in_current_mounth]), begin(plan[i]), end(plan[i]));
                plan[i].clear();
            }
        } else {
            cout << "Unknown command" << endl;
        }
    }
    return 0;
}

// ##### Пример #####
// ###### Ввод ######
// ```objectivec
// 12
// ADD 5 Salary
// ADD 31 Walk
// ADD 30 WalkPreparations
// NEXT
// DUMP 5
// DUMP 28
// NEXT
// DUMP 31
// DUMP 30
// DUMP 28
// ADD 28 Payment
// DUMP 28
// ```

// ###### Вывод ######
// ```objectivec
// 1 Salary
// 2 WalkPreparations Walk
// 0
// 0
// 2 WalkPreparations Walk
// 3 WalkPreparations Walk Payment
// ```