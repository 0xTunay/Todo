#include "include/todo.h"
#include "include/Upper.h"


static char *filename = "user.dat";

void AddTask()
{
    int taskCount = 1, numbertask = 5;
    char task[MAX_TASKS_SIZE];
    char choice[MAX_USER_SIZE];

    todo *tasks =(todo*) malloc(numbertask * sizeof(todo));
    if(tasks == NULL){
        fprintf(stderr,"error memory");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(filename, "w");
    if(fp == NULL)
    {
        printf("Failed open file\n");
        exit(EXIT_FAILURE);
    }

    printf("Write your tasks\n");
    printf("if you want exit - write exit\n");


    while (1) {

        fgets(task, sizeof(task), stdin);
        
        task[strcspn(task, "\n")] = 0;


        if (strcmp(task, "exit") == 0) {
            break;
        }

         if (task[0] == '\0') {
            printf("Task %d is empty, keeping previous value.\n", taskCount);
        } else {
            taskCount++;
            fprintf(fp, "%d, %s\n",taskCount ,task);
        }

    }

    tasks = realloc(tasks, (taskCount + 1) * sizeof(todo));

    if (tasks == NULL) {
        fprintf(stderr, "Error: memory reallocation failed\n");
        free(tasks);
        exit(EXIT_FAILURE);
    }

    fclose(fp);

    printf("Your tasks: \n");

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }

    char line[MAX_TASKS_SIZE];
    int taksNum = 1;
    while (fgets(line, sizeof(line), fp)) 
    {
        printf(" task: %d  %s", taksNum++, line);
    }

    fclose(fp);
    free(tasks);

    printf("Do you want to continue?\n");
    fgets(choice,sizeof(choice),stdin);

    choice[strcspn(choice, "\n")] = 0;
    toUpperCase(choice);


    if(strcmp(choice, "YES") == 0){
        contunie();
    } else if(strcmp(choice, "NO") == 0)  {
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



    while(strcmp(todoN->user, "EXIT") != 0){


        todoN->user[strcspn(todoN->user, "\n")] = 0;
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

    int deleteTask = 0, crn = 1,fTask = 0;
    char line[MAX_LINE_SIZE];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }

    if (getc(fp) == EOF) {
        puts("you dont have any tasks, go to add tasks please!");
        AddTask();
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

int main(void){
    todo Todo;
    Todo.taskCount = 0;

    puts("Hello, what do you want?");
    puts("Todo, Delete, Exit");

    while (strcmp(Todo.user, "EXIT") != 0) {
    fgets(Todo.user, sizeof(Todo.user), stdin);

    Todo.user[strcspn(Todo.user, "\n")] = 0;

    toUpperCase(Todo.user);

    if (strcmp(Todo.user, "TODO") == 0) {
        AddTask(); 
    } else if (strcmp(Todo.user, "DELETE") == 0) {
        TaskDelete(); 
    } else if (strcmp(Todo.user, "EXIT") != 0) {
        printf("You entered something incorrect. Try again.\n");
    }
}
    return 0;
}
// THIS FINISH LINE, YOU KNOW :З