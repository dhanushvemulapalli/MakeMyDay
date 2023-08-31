# MakeMyDay


Project: Daily Task Manager

What: This project is a Daily Task Manager implemented in C programming language. It allows users to add tasks, list tasks, complete tasks, and delete all tasks.

Why: The Daily Task Manager aims to help individuals organize and track their daily tasks effectively. It provides a simple and efficient way to manage tasks and stay productive throughout the day.

How: The project is implemented using C programming language. It utilizes a linked list data structure to store and manage tasks. Here's a breakdown of the main functionalities:

1. Add a task:
    - Prompts the user to enter a task description.
    - Creates a new task struct and assigns the entered description.
    - Adds the task to the linked list of tasks.
    - Prints a success message.
2. List tasks:
    - Prints the list of tasks with their corresponding indices.
    - If no tasks are present, prints a message indicating the absence of tasks.
3. Complete a task:
    - Prompts the user to enter the index of the task to be marked as completed.
    - Traverses the linked list to find the task at the specified index.
    - Removes the task from the linked list and frees the memory.
    - Prints a completion message if the task was found and marked as completed.
    - Prints an error message if the provided task index is invalid.
4. Mark all tasks as done or Delete all tasks:
    - Frees the memory occupied by all the tasks in the linked list.
    - Sets the task list pointer to NULL.
    - Prints an exit message.

The project utilizes a constant `MAX_DESCRIPTION_LENGTH` to define the maximum length of a task description. It includes error handling to handle invalid user inputs and cases where no tasks are found. The `getchar()` function is used to clear the newline character from the input buffer.

This project demonstrates proficiency in C programming, data structures (linked list), dynamic memory allocation, and menu-driven program design. It showcases skills in handling user input, manipulating linked lists, and managing memory resources.
