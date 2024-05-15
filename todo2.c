#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "todo.h"

struct todo {
    char tasks[100];
    int taskCount;
};

void AddTask()
    
{
    
    struct todo *tasks = (struct todo *)malloc(sizeof(struct todo));


    if(tasks == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    char *filename = "users.dat";
    int n = sizeof(*tasks);
    FILE *fp = fopen(filename,"a");
    
    printf("Write your tasks\n");
    printf("if you want exit - write exit\n");

    int taskCount = 0;
    char task[100];

    while (1)
    {
        printf("Add task %d: ", taskCount + 1);
        scanf("%s", task);
        if (strcmp(task, "exit") == 0)
        {
            break;
        }
        strcpy(tasks->tasks, task);
        tasks->taskCount = ++taskCount;
        fprintf(fp, "%s\n", task);
    }

    fclose(fp);
    free(tasks);

}


void TaskDelete()
{
    printf("hello");
}
int main(void) {
    struct todo Todo;
    Todo.taskCount = 0; 

    char user[10];

    printf("Hello, what do you want?\n");
    printf("Todo, Delete, Exit\n");
    scanf("%s", user);

    if (strcasecmp(user, "Todo") == 0) {
        AddTask(); 
    } else if (strcasecmp(user, "Delete") == 0) {
        TaskDelete(); 
    } else if (strcasecmp(user, "Exit") != 0) {
        printf("You entered something incorrect.\n");
        main();
    }

    return 0;

}
