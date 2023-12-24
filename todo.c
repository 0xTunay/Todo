#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AddTask(char tasks[][100]) {
    printf("add task\n");
    int i = 0;
    do {
        scanf("%s", tasks[i]);
        i++;
    } while (strcmp(tasks[i - 1], "exit") != 0);
        printf("%s",tasks[i]);
}

void DeleteTask() {
    printf("Hello, delete added!\n");
}

void EditTask() {
    printf("Hello, Edit task!\n");
}

int main(void) {
    char user[10];
    char tasks[100][100];  // Массив для хранения задач

    printf("Hello, what do you want?\n");
    printf("Todo, Delete, Edit, Exit\n");
    scanf("%s", user);

    if (strcmp(user, "Todo") == 0) {
        AddTask(tasks);
    } 
    else if (strcmp(user, "Delete") == 0) {
        DeleteTask();
    } 
    else if (strcmp(user, "Edit") == 0) {
        EditTask();
    } 
    else if (strcmp(user, "Exit") == 0){}
    
    else {
        printf("вы ввели чтото неправильное");
        main();
    }

    return 0;
}