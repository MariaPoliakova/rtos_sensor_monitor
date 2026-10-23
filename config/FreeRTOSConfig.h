/* https://github.com/FreeRTOS/FreeRTOS-Kernel/blob/main/examples/
template_configuration/FreeRTOSConfig.h */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#define configUSE_PREEMPTION 1
#define configCPU_CLOCK_HZ 25000000UL
#define configTICK_RATE_HZ 1000

#define configMAX_PRIORITIES 5
#define configMINIMAL_STACK_SIZE 128
#define configMAX_TASK_NAME_LEN 16


#define configUSE_TIME_SLICING          1
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 0xA0
#define configKERNEL_INTERRUPT_PRIORITY      0xF0
#define configPRIO_BITS                 4

#define configTOTAL_HEAP_SIZE           (16 * 1024)
#define configSUPPORT_DYNAMIC_ALLOCATION 1
#define configUSE_MUTEXES               1

#define configUSE_IDLE_HOOK             0
#define configUSE_TICK_HOOK             0
#define configCHECK_FOR_STACK_OVERFLOW  0
#define configUSE_MALLOC_FAILED_HOOK    0

#define INCLUDE_vTaskDelay             1
#define INCLUDE_vTaskDelayUntil        1
#define INCLUDE_vTaskDelete            1

#define configUSE_PORT_OPTIMISED_TASK_SELECTION 0
#define configUSE_TICKLESS_IDLE                0
#define configUSE_TIMERS                       0

#define configUSE_TASK_NOTIFICATIONS           1
#define configUSE_QUEUE_SETS                   0
#define configUSE_COUNTING_SEMAPHORES          1

#define configIDLE_SHOULD_YIELD                1
#define configUSE_TRACE_FACILITY               0

#define configTICK_TYPE_WIDTH_IN_BITS          TICK_TYPE_WIDTH_32_BITS
#define configUSE_CO_ROUTINES 0
#define configMAX_CO_ROUTINE_PRIORITIES 1

#endif
