#ifndef TASK_LOG_H
#define TASK_LOG_H

#include <stdint.h>

#define LOG_SIZE 100

typedef struct
{
    uint32_t tick;
    char task;
} LogEntry;

extern volatile LogEntry task_log[LOG_SIZE];
extern volatile uint32_t log_index;

void LogTask(char task);

#endif