#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESCRIPTION_LENGTH 100

typedef struct Task {
    char description[MAX_DESCRIPTION_LENGTH];
    struct Task* next;
} Task;

Task* taskList = NULL;

void addTask(const char* description) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strncpy(newTask->description, description, MAX_DESCRIPTION_LENGTH);
    newTask->next = NULL;

    if (taskList == NULL) {
        taskList = newTask;
    } else {
        Task* current = taskList;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTask;
    } 

    printf("Task added successfully.\n");
}

void listTasks() {
    if (taskList == NULL) {
        printf("No tasks found.\n");
        return;
    }

    printf("Task List:\n");
    int count = 1;
    Task* current = taskList;
    while (current != NULL) {
        printf("%d. %s\n", count++, current->description);
        current = current->next;
    }
}

void completeTask(int taskIndex) {
    if (taskList == NULL) {
        printf("No tasks found.\n");
        return;
    }

    Task* current = taskList;
    Task* prev = NULL;
    int count = 1;

    while (current != NULL) {
        if (count == taskIndex) {
            if (prev == NULL) {
                taskList = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Task marked as completed.\n");
            return;
        }
        prev = current;
        current = current->next;
        count++;
    }

    printf("Invalid task index.\n");
}

void freeTaskList() { 
    Task* current = taskList;
    while (current != NULL) {
        Task* temp = current;
        current = current->next;
        free(temp);
    }
    taskList = NULL;
}

int main() {
    int choice;
    do {
        printf("\n---- Daily Task Manager ----\n");
        printf("1. Add a task\n");
        printf("2. List tasks\n");
        printf("3. Complete a task\n");
        printf("4. Mark all tasks as done or Delete all tasks\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char description[MAX_DESCRIPTION_LENGTH];
                printf("Enter task description: ");
                scanf(" %[^\n]s", description);
                addTask(description);
                break;
            }
            case 2:
                listTasks();
                break;
            case 3: {
                int taskIndex;
                printf("Enter the task index to complete: ");
                scanf("%d", &taskIndex);
                completeTask(taskIndex);
                break;
            }
            case 4:
                printf("Exiting...\n");
                freeTaskList();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        getchar(); // Clear the newline character from input buffer
    } while (choice != 4);

    return 0;
}




/*
This code is a simple To-Do List application implemented in C. It provides a menu-driven interface for the user to add tasks, list tasks, mark tasks as completed, and exit the program. Here's an explanation of the code:

1.	The Task structure represents a single task in the To-Do List. It contains a character array description to store the task description and a pointer next to point to the next task in the list.

2.	The taskList variable is a pointer to the first task in the list. It is initially set to NULL.

3.	The addTask function is used to add a new task to the list. It takes a description string as input. It dynamically allocates memory for a new task, copies the description into the description field of the task, and appends the task to the end of the task list.

4.	The listTasks function is used to display all the tasks in the list. It traverses the task list and prints each task's description along with a corresponding index.

5.	The completeTask function is used to mark a task as completed and remove it from the list. It takes a taskIndex as input, representing the index of the task to be completed. It traverses the task list, finds the task with the given index, updates the next pointers to remove the task from the list, frees the memory occupied by the task, and marks it as completed.

6.	The freeTaskList function is used to deallocate the memory occupied by the entire task list. It traverses the list, frees the memory for each task, and sets the taskList pointer to NULL.

7.	In the main function, a menu-driven interface is provided using a do-while loop. The user is prompted to enter their choice (1 to add a task, 2 to list tasks, 3 to complete a task, and 4 to exit). The corresponding functions are called based on the user's choice.

8.	In case 1 (add a task), the user is prompted to enter a task description, which is then passed to the addTask function.

9.	In case 2 (list tasks), the listTasks function is called to display all the tasks in the list.

10.	In case 3 (complete a task), the user is prompted to enter the index of the task to be completed. The index is then passed to the completeTask function.

11.	In case 4 (exit), the program prints a message and calls the freeTaskList function to deallocate the memory before terminating.

12.	The getchar function is called to clear the newline character from the input buffer after reading the choice. This prevents any issues with the subsequent input operations.

Overall, this code provides a basic To-Do List functionality allowing the user to manage tasks through a simple command-line interface.
*/