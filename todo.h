#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char tasks[100];
    int taskCount;
    char user[10];
    char *filename;
} todo;

void AddTask();
void TaskDelete();
void contunie();
void toUpperCase(char *str);