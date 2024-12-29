#ifndef TODO_H
#define TODO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS_SIZE 128
#define MAX_USER_SIZE 32

typedef struct {
    char tasks[128];
    int taskCount;
    char user[32];
    char *filename;
} todo;

void AddTask();
void TaskDelete();
void contunie();
void toUpperCase(char *str);

#endif // TODO_H