#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct todo {
    char tasks[100][100];
    int taskCount;
    char taskToDelete[100]; 
    char *taskName;
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

void TaskDelete(struct todo *Todo) {
    int found = 0;

    for (int i = 0; i < Todo->taskCount; i++) {
        if (strcmp(Todo->tasks[i],  Todo->taskName) == 0) {
            found = 1;

            // Remove the task and shift the remaining tasks
            for (int j = i; j < Todo->taskCount - 1; j++) {
                strcpy(Todo->tasks[j], Todo->tasks[j + 1]);
            }

            Todo->taskCount--;
            break;
        }
    }

    if (found) {
        printf("Task '%s' deleted successfully.\n", Todo->taskName);
        AddPrintf(Todo, Todo->taskCount + 1);
    } else {
        printf("Task '%s' not found.\n", Todo->taskName);
        main();
    }

}
int main(void) {
    struct todo Todo;
    Todo.taskCount = 0; 

    char user[10];

    printf("Hello, what do you want?\n");
    printf("Todo, Delete, Exit\n");
    scanf("%s", user);

    if (strcmp(user, "Todo") == 0) {
        AddTask(&Todo); 
    } else if (strcmp(user, "Delete") == 0) {
        TaskDelete(&Todo); 
    } else if (strcmp(user, "Exit") != 0) {
        printf("You entered something incorrect.\n");
        main();
    }

    return 0;
}
