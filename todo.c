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
        fprintf(fp,"%s\n",task);
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
void TaskDelete() {
    FILE *fp, *tempFile;
    
    int deleteTask = 0;
    int crn = 1;
    char line[100];
    int fTask = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }

    printf("Your tasks:\n");
    while (fgets(line, sizeof(line), fp)) {
        printf("%d %s",crn,line);
        crn++;
    }
    rewind(fp);

    printf("What task number do you want to delete?\n");
    scanf("%d", &deleteTask);

    if (deleteTask <= 0 || deleteTask >= crn) {
        printf("Invalid task number\n");
        fclose(fp);
        exit(1);
    }

    tempFile = fopen("temp.dat", "w");
    if (tempFile == NULL) {
        printf("Failed to open temporary file\n");
        fclose(fp);
        exit(1);
    }

    crn = 1;
    while (fgets(line, sizeof(line), fp)) {
        if (crn != deleteTask) {
            fputs(line, tempFile);
        } else {
            fTask = 1;
            printf("Deleting task %d: %s", deleteTask, line);
        }
        crn++;
    }

    fclose(fp);
    fclose(tempFile);

    if (fTask) {
        if (remove(filename) != 0) {
            printf("Failed to delete the original file.\n");
            exit(1);
        }
        if (rename("temp.dat", filename) != 0) {
            printf("Failed to rename the temporary file.\n");
            exit(1);
        }
        printf("Task %d successfully deleted.\n", deleteTask);
    } else {
        printf("Task %d not found in the file.\n", deleteTask);
        remove("temp.dat"); 
    }
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
// THIS FINISH LINE, YOU KNOW <З
