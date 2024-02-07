#include <iostream>
#include <map>
#include <string>
#include <tuple>

using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const {
    return data.at(person);
  }
  
  // Получить суммарное количество незавершенных задач конкретного разработчика
  int GetPersonNoDoneTasksCount(const string& person) const {
    TasksInfo person_info = data.at(person);
    return (person_info[TaskStatus::NEW] + 
            person_info[TaskStatus::IN_PROGRESS] + 
            person_info[TaskStatus::TESTING]);
  } 

  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person) {
    ++data[person][TaskStatus::NEW];
  }
  
  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
    TasksInfo old_tasks = data.at(person);
    TasksInfo new_tasks = old_tasks;
    TasksInfo updated_tasks;

    for(int i = 0; i < 3; i++) {
      if (old_tasks[TaskStatus(i)] > task_count) {
        new_tasks[TaskStatus(i)] = new_tasks[TaskStatus(i)] - task_count;
        new_tasks[TaskStatus(i+1)] = new_tasks[TaskStatus(i+1)] + task_count;
        updated_tasks[TaskStatus(i+1)] = task_count;
        break;
      } else {
        new_tasks[TaskStatus(i)] = new_tasks[TaskStatus(i)] - old_tasks[TaskStatus(i)];
        new_tasks[TaskStatus(i+1)] = new_tasks[TaskStatus(i+1)] + old_tasks[TaskStatus(i)];
        updated_tasks[TaskStatus(i+1)] = old_tasks[TaskStatus(i)];
        task_count -= old_tasks[TaskStatus(i)];
      }
    }

    TasksInfo untouched_tasks;
    for(int i = 0; i < 3; i++) {
      untouched_tasks[TaskStatus(i)] = old_tasks[TaskStatus(i)] - updated_tasks[TaskStatus(i+1)];
    }

    data[person] = new_tasks;
    return tie(updated_tasks, untouched_tasks);
  }

private:
    map<string, TasksInfo> data;

};

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
  TeamTasks tasks;
  
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }

  cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  
  TasksInfo updated_tasks, untouched_tasks;
  
  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
  
  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  return 0;
}