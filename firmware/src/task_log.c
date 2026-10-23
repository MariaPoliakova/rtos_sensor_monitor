#include "task_log.h"
#include "FreeRTOS.h"
#include "task.h"

volatile LogEntry task_log[LOG_SIZE];
volatile uint32_t log_index = 0;

void LogTask(char task)
{
    taskENTER_CRITICAL();

    if (log_index < LOG_SIZE)
    {
        task_log[log_index].tick = xTaskGetTickCount();
        task_log[log_index].task = task;
        log_index++;
    }

    taskEXIT_CRITICAL();
}