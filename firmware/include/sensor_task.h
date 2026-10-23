#ifndef SENSOR_TASK_H
#define SENSOR_TASK_H

#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"

extern volatile uint32_t counter;
extern volatile uint32_t processing_counter;
extern volatile uint32_t logging_counter;

void SensorTask(void *pvParameters);

void ProcessingTask(void *pvParameters);    

void LoggerTask(void *pvParameters);

#endif