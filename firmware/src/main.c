#include "sensor_task.h"

int main(void)
{
    BaseType_t sensorResult = xTaskCreate(
        SensorTask, "Sensor",
        configMINIMAL_STACK_SIZE,
        NULL, 3, NULL
    );

    BaseType_t processingResult = xTaskCreate(
        ProcessingTask, "Processing",
        configMINIMAL_STACK_SIZE,
        NULL, 2, NULL
    );

    BaseType_t loggerResult = xTaskCreate(
        LoggerTask, "Logger",
        configMINIMAL_STACK_SIZE,
        NULL, 1, NULL
    );

    if (sensorResult != pdPASS ||
        processingResult != pdPASS ||
        loggerResult != pdPASS)
    {
        while (1) {}
    }

    vTaskStartScheduler();

    while (1) {}
}