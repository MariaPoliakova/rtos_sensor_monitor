#include "sensor_task.h"
#include "task_log.h"

volatile uint32_t counter = 0;
volatile uint32_t processing_counter = 0;
volatile uint32_t logging_counter = 0;

// Wird 1, sobald ProcessingTask arbeitet
volatile uint32_t processing_active = 0;

// Zählt, wie oft SensorTask ProcessingTask unterbricht
volatile uint32_t preemption_count = 0;

void SensorTask(void *pvParameters) {
    (void)pvParameters;

    while (1) {
        if (processing_active) {
            preemption_count++;
        }

        LogTask('S');
        counter++;

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void ProcessingTask(void *pvParameters) {
    (void)pvParameters;

    processing_active = 1;

    while (1) {
        processing_counter++;

        // Arbeitet dauerhaft, ohne vTaskDelay()
        for (volatile uint32_t i = 0; i < 1000000; i++) {
        }
    }
}

void LoggerTask(void *pvParameters) {
    (void)pvParameters;

    while (1) {
        LogTask('L');
        logging_counter++;

        vTaskDelay(pdMS_TO_TICKS(500));
    }
}