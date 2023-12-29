#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct todo {
    char tasks[100][100];
    int taskCount;
    char taskToDelete[100]; // Changed to array to store the task to delete
};

// Function to add tasks to the todo list
void AddTask(struct todo *Todo) {
    int i = 0;

    do {
        scanf("%s", Todo->tasks[i]);
        i++;
    } while (strcmp(Todo->tasks[i - 1], "exit") != 0);

    // Call the function to print tasks
    AddPrintf(Todo, i);
}

// Function to print tasks in the todo list
void AddPrintf(struct todo *Todo, int count) {
    printf("Your tasks:\n");
    for (int j = 0; j < count - 1; j++) {
        printf("%s\n", Todo->tasks[j]);
    }
}

// Function to delete a task from the todo list
void DeleteTask(struct todo *Todo) {
    printf("Your tasks:\n");
    for (int j = 0; j < Todo->taskCount; j++) {
        printf("%d. %s\n", j + 1, Todo->tasks[j]);
    }

    int i;
    printf("Enter the task you want to delete: ");
    scanf("%s", Todo->taskToDelete);

    for (i = 0; i < Todo->taskCount; i++) {
        if (strcmp(Todo->tasks[i], Todo->taskToDelete) == 0) {
            // Task found, break out of the loop
            break;
        }
    }

    if (i == Todo->taskCount) {
        // Task not found
        printf("Task not found.\n");
        return;
    }

    // Remove the task from the array
    for (; i < Todo->taskCount - 1; i++) {
        strcpy(Todo->tasks[i], Todo->tasks[i + 1]);
    }

    // Decrease the task count after deletion
    (Todo->taskCount--);
}

// Function to edit a task in the todo list
void EditTask(struct todo *Todo) {
    // Add your implementation here
}

int main(void) {
    struct todo Todo;
    Todo.taskCount = 0; // Initialize task count

    char user[10];

    printf("Hello, what do you want?\n");
    printf("Todo, Delete, Edit, Exit\n");
    scanf("%s", user);

    if (strcmp(user, "Todo") == 0) {
        AddTask(&Todo); // Pass the struct reference
    } else if (strcmp(user, "Delete") == 0) {
        DeleteTask(&Todo); // Pass the struct reference
    } else if (strcmp(user, "Edit") == 0) {
        EditTask(&Todo); // Pass the struct reference
    } else if (strcmp(user, "Exit") != 0) {
        printf("You entered something incorrect.\n");
        main();
    }

    return 0;
}
