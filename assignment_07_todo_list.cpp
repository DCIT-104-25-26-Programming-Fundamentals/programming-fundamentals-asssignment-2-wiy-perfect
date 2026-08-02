// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Feature 1: Add a Task
void addTask(vector<string>& taskList) {
    cin.ignore(); // Clear remaining newline character from cin
    cout << "Enter task: ";
    string task;
    getline(cin, task);
    taskList.push_back(task);
    cout << "Task added: \"" << task << "\"" << endl;
}

// Feature 2: View All Tasks
void viewTasks(const vector<string>& taskList) {
    if (taskList.empty()) {
        cout << "Your to-do list is currently empty!" << endl;
        return;
    }
    cout << "Your Tasks:" << endl;
    for (size_t i = 0; i < taskList.size(); i++) {
        cout << (i + 1) << ". " << taskList[i] << endl;
    }
}

// Feature 3: Delete a Task
void deleteTask(vector<string>& taskList) {
    if (taskList.empty()) {
        cout << "No tasks available to delete." << endl;
        return;
    }
    
    // Show tasks with numbers first so user knows what to choose
    viewTasks(taskList);
    
    cout << "Enter task number to delete: ";
    int taskNumber;
    cin >> taskNumber;
    
    // Validate number based on 1-based indexing rules
    if (taskNumber < 1 || taskNumber > static_cast<int>(taskList.size())) {
        cout << "Error: Invalid task number!" << endl;
    } else {
        int targetIndex = taskNumber - 1;
        string removedTask = taskList[targetIndex];
        taskList.erase(taskList.begin() + targetIndex); // Removes element from vector
        cout << "Task \"" << removedTask << "\" has been removed." << endl;
    }
}

int main() {
    vector<string> myTasks;
    int choice = 0;

    // Running menu execution loop
    while (choice != 4) {
        cout << "\n============================" << endl;
        cout << "     TO-DO LIST MENU" << endl;
        cout << "============================" << endl;
        cout << "1. Add task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Delete task" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(myTasks);
                break;
            case 2:
                viewTasks(myTasks);
                break;
            case 3:
                deleteTask(myTasks);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
                break;
        }
    }

    return 0;
}

