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

    printf("Your tasks:\n");
    for (int j = 0; j < i - 1; j++) {
        printf("%s\n", tasks[j]);
        main();
    }

    free(tasks);
}
void DeleteTask(char tasks[][100], int *taskCount) {
    char *taskToDelete;
    int i;

    printf("Введите задачу, которую вы хотите удалить: ");
    scanf("%s", taskToDelete);


    for (i = 0; i < 100; i++) {
        if (strcmp(tasks[i], taskToDelete) == 0) {
            // Находим задачу, которую нужно удалить
            break;
        }
    }

    if (i == 100) {
        // Задача не найдена
        printf("Задача не найдена.\n");
        return;
    }

    // Удаляем задачу из массива
    for (; i < *taskCount - 1; i++) {
        strcpy(tasks[i], tasks[i + 1]);    }

    // Уменьшаем количество задач после удаления
    (*taskCount--);

    // Завершаем массив нулем
    tasks[99][0] = '\0';
}


void EditTask() {
    
}

int main(void) {
    char user[10];
    char tasks[100][100]; 
    int taskCount = 0;

    printf("Hello, what do you want?\n");
    printf("Todo, Delete, Edit, Exit\n");
    scanf("%s", user);

    if (strcmp(user, "Todo") == 0) {
        AddTask(tasks);
    } 
    else if (strcmp(user, "Delete") == 0) {
        DeleteTask(tasks,&taskCount);
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