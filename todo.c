#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct todo {
    char tasks[100][100];
    int taskCount;
    char taskToDelete[100]; 
};

void AddTask(struct todo *Todo) {
    int i = 0;

    do {
        scanf("%s", Todo->tasks[i]);
        i++;
    } while (strcmp(Todo->tasks[i - 1], "exit") != 0);

    AddPrintf(Todo, i);
}

void AddPrintf(struct todo *Todo, int count) {
    printf("Your tasks:\n");
    for (int j = 0; j < count - 1; j++) {
        printf("%s\n", Todo->tasks[j]);
    }
    main();
}

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
            break;
        }
    }

    if (i == Todo->taskCount) {
        printf("Task not found.\n");
        return;
    }

    // удаляет задачу из массива
    for (; i < Todo->taskCount - 1; i++) {
        strcpy(Todo->tasks[i], Todo->tasks[i + 1]);
    }

    (Todo->taskCount--);

        printf("Updated tasks:\n");
    for (int j = 0; j < Todo->taskCount; j++) {
        printf("%d. %s\n", j + 1, Todo->tasks[j]);
    }
}

void EditTask(struct todo *Todo) {
}

int main(void) {
    struct todo Todo;
    Todo.taskCount = 0; 

    char user[10];

    printf("Hello, what do you want?\n");
    printf("Todo, Delete, Edit, Exit\n");
    scanf("%s", user);

    if (strcmp(user, "Todo") == 0) {
        AddTask(&Todo); 
    } else if (strcmp(user, "Delete") == 0) {
        DeleteTask(&Todo); 
    } else if (strcmp(user, "Edit") == 0) {
        EditTask(&Todo); 
    } else if (strcmp(user, "Exit") != 0) {
        printf("You entered something incorrect.\n");
        main();
    }

    return 0;
}
