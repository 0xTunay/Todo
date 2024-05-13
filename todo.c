#include <stdio.h>
#include <string.h>

#include "todo.h"

struct todo {
    char tasks[100];
    int taskCount;
    char taskToDelete[100]; 
    char *taskName;
};

void AddTask()
    
{
    struct todo task[100];
    
    char *filename = "users.dat";
    int n = sizeof(task)/sizeof(task[0]);
    FILE *fp = fopen(filename,"a");
    
    printf("Write your tasks\n");
    printf("if you want exit - write exit\n");

    int i = 0;

    if(!fp)
    {
        printf("Error ");
    }
    for (i = 0; i < n; i++) {
        printf("Add task %d\n", i + 1);
        scanf("%s", task[i].tasks);
        if (strcmp(task[i].tasks, "exit") == 0) {
            break;
        }
        fprintf(fp, "%s\n", task[i].tasks);
    }
    for(int j = 0; j<n;j++)
    {
        fprintf(fp, "%s\n", task[j].tasks);
    }

    fclose(fp);

    fp = fopen(filename, "rb");
    if(!fp)
    {
        printf("Error ");
    }
    
char buffer[100];
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s\n", buffer);
    }
    fclose(fp);
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
