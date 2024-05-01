#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void addTask(vector<Task>& taskList, const string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    taskList.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

void completeTask(vector<Task>& taskList, int index) {
    if (index >= 0 && index < taskList.size()) {
        taskList[index].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task index!" << endl;
    }
}

void displayTasks(const vector<Task>& taskList) {
    if (taskList.empty()) {
        cout << "No tasks to display." << endl;
    } else {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < taskList.size(); ++i) {
            cout << i+1 << ". ";
            if (taskList[i].completed) {
                cout << "[X] ";
            } else {
                cout << "[ ] ";
            }
            cout << taskList[i].description << endl;
        }
    }
}

int main() {
    vector<Task> tasks;

    while (true) {
        cout << endl << "Choose an option:" << endl;
        cout << "1. Add a task" << endl;
        cout << "2. Mark a task as completed" << endl;
        cout << "3. View tasks" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter task description: ";
                string description;
                cin.ignore();
                getline(cin, description);
                addTask(tasks, description);
                break;
            }
            case 2: {
                cout << "Enter the index of the task to mark as completed: ";
                int index;
                cin >> index;
                completeTask(tasks, index - 1);
                break;
            }
            case 3:
                displayTasks(tasks);
                break;
            case 4:
                cout << "Exiting...";
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}









