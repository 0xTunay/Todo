#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "todo.h"



static char *filename = "user.dat";

int main(void) {
    todo Todo;
    Todo.taskCount = 0;

    printf("Hello, what do you want?\n");
    printf("Todo, Delete, Exit\n");
    fgets(Todo.user,sizeof(Todo.user),stdin);

    Todo.user[strcspn(Todo.user, "\n")] = 0;

    while(strcmp(Todo.user, "exit")!= 0){
        toUpperCase(Todo.user);

        if (strcmp(Todo.user, "TODO") == 0) {
            AddTask(); 
        } else if (strcmp(Todo.user, "DELETE") == 0) {
            TaskDelete(); 
        } else {
            printf("You entered something incorrect.\n");
        }
        printf("What do you want? (Todo, Delete, Exit)\n");
        fgets(Todo.user,sizeof(Todo.user),stdin);
    }

    return 0;
}
void toUpperCase(char *str){
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}
void AddTask()
{
    todo *tasks = NULL;


    int n = sizeof(*tasks);
    FILE *fp = fopen(filename, "a");
        if(fp == NULL)
    {
        printf("Failed open file\n");
        exit(1);
    }

    printf("Write your tasks\n");
    printf("if you want exit - write exit\n");

    int taskCount = 0;
    char task[100];

while (1) {
        printf("Add task %d: ", taskCount + 1);
        fgets(task, sizeof(task), stdin);

        task[strcspn(task, "\n")] = 0;

        if (strcmp(task, "exit") == 0) {
            break;
        }
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
    fgets(usssr,sizeof(usssr),stdin);
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
    fgets(todoN->user,sizeof(todoN->user),stdin);


    todoN->user[strcspn(todoN->user, "\n")] = 0;

    while(strcmp(todoN->user, "Exit") != 0){
    toUpperCase(todoN->user);

    if (strcmp(todoN->user, "TODO") == 0) {  
        AddTask(); 
    } 
    else if (strcmp(todoN->user, "DELETE") == 0) {
        TaskDelete(); 
    } 
    else {
        printf("You entered something incorrect.\n");
    }
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

// THIS FINISH LINE, YOU KNOW :З
