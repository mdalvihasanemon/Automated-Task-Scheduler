
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct Task {
    string name;
    time_t time;
    function<void()> function;
};

void executeTask(Task task) {
    time_t currentTime = time(nullptr);

    this_thread::sleep_until(chrono::system_clock::from_time_t(task.time));

    cout << "Executing task '" << task.name << "' at " << ctime(&currentTime);
    task.function();
}

Task getUserInputForTask() {
    Task newTask;

    cout << "Enter task name: ";
    cin.ignore();
    getline(cin, newTask.name);

    cout << "Enter task execution time (in seconds from now): ";
    cin >> newTask.time;

    return newTask;
}

int main() {
    // Vector to store tasks
    vector<Task> tasks;

    char choice;
    do {
        Task newTask = getUserInputForTask();

        tasks.push_back(newTask);

        cout << "Do you want to add another task? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');


    for (const auto& task : tasks) {
        thread(executeTask, task).detach();
    }

    this_thread::sleep_for(chrono::seconds(20));

    return 0;
}
