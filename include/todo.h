#ifndef TODO_H
#define TODO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS_SIZE 128
#define MAX_USER_SIZE 32
#define MAX_LINE_SIZE 128

typedef struct {
    char tasks[MAX_TASKS_SIZE];
    int taskCount;
    char user[MAX_TASKS_SIZE];
    char *filename;
} todo;

void AddTask();
void TaskDelete();
void contunie();
void toUpperCase(char *str);

#endif // TODO_H