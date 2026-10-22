#include <stdint.h>

void Reset_Handler(void);

extern uint32_t _estack;

__attribute__((section(".isr_vector"), used))
const uintptr_t vector_table[2] = {
    (uintptr_t)&_estack,
    (uintptr_t)Reset_Handler
};