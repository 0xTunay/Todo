#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "todo.h"

typedef struct {
    char tasks[100];
    int taskCount;
    char user[10];
    char *filename;
} todo;

static char *filename = "user.dat";

void AddTask()
{
    todo *tasks = (todo *)malloc(sizeof(todo));

    if(tasks == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    int n = sizeof(*tasks);
    FILE *fp = fopen(filename, "a");

    printf("Write your tasks\n");
    printf("if you want exit - write exit\n");

    int taskCount = 0;
    char task[100];

    while (1)
    {
        printf("Add task %d: ", taskCount + 1);
        scanf(" %s", task);
        if (strcmp(task, "exit") == 0)
        {
            break;
        }
        strcpy(tasks->tasks, task);
        tasks->taskCount = ++taskCount;
        fprintf(fp,"%d.  %s\n", taskCount,task);
        taskCount + 1;
    }
    fclose(fp);

    printf("Your tasks: \n");

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }

    char line[100];
    int taksNum = 1;
    while (fgets(line, sizeof(line), fp)) 
    {
        printf(" task: %d  %s", taksNum++, line);
    }

    fclose(fp);

    free(tasks);

    printf("Do you want to continue?\n");
    char usssr[10];
    scanf("%s", usssr);
    if(strcmp(usssr, "Yes") == 0)
    {
        contunie();
    } 
    else if(strcmp(usssr, "No") == 0)  
    {
        printf("Thanks for using my program, your tasks are in the file user.dat. Goodbye\n");
        exit(1);
    }

}

void contunie()
{
    todo *todoN = (todo *)malloc(sizeof(todo));
    if (todoN == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Todo, Delete, Exit\n");
    scanf("%s", todoN->user);

    if (strcmp(todoN->user, "Todo") == 0) 
    {  
        AddTask(); 
    } 
    else if (strcmp(todoN->user, "Delete") == 0) 
    {
        TaskDelete(); 
    } 
    else if (strcmp(todoN->user, "Exit") != 0) 
    {
        printf("You entered something incorrect.\n");
        contunie();
    }

    free(todoN);

}

void TaskDelete()
{
    todo * task_delete;

    FILE *fp,*tempFile;
    
    int taskNumber = 1;
    int fTask = 0;
    

    fp = fopen(filename, "r");


    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), fp)) 
    {
        printf("task: %s", line);
    }

    printf("what task you want delete?");
    scanf("%s",task_delete->user);

    int  deleteTask = 0;

    strcpy(task_delete->user,deleteTask);

    while (fgets(line, sizeof(line), fp) == deleteTask) 


        fclose(fp);

}

int main(void) {
    todo Todo;
    Todo.taskCount = 0;

    printf("Hello, what do you want?\n");
    printf("Todo, Delete, Exit\n");
    scanf("%s", Todo.user);

    if (strcmp(Todo.user, "Todo") == 0) 
    {
        AddTask(); 
    } else if (strcmp(Todo.user, "Delete") == 0) 
    {
        TaskDelete(); 
    } else if (strcmp(Todo.user, "Exit") != 0) 
    {
        printf("You entered something incorrect.\n");
        main();
    }

    return 0;
}
