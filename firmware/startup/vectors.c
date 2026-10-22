
#include <stdint.h>

void Reset_Handler(void);
void HardFault_Handler(void);
void Default_Handler(void);

extern uint32_t _estack;


__attribute__((section(".isr_vector"), used))
const uintptr_t vector_table[17] = {
    (uintptr_t)&_estack,           // 0: Initial Stack Pointer
    (uintptr_t)Reset_Handler,     // 1: Reset
    (uintptr_t)Default_Handler,   // 2: NMI
    (uintptr_t)HardFault_Handler, // 3: HardFault
    (uintptr_t)Default_Handler,   // 4: MemManage
    (uintptr_t)Default_Handler,   // 5: BusFault
    (uintptr_t)Default_Handler,   // 6: UsageFault  
    0,                            // 7: Reserved
    0,                            // 8: Reserved
    0,                            // 9: Reserved
    0,                            // 10: Reserved
    (uintptr_t)Default_Handler,   // 11: SVCall
    (uintptr_t)Default_Handler,   // 12: DebugMonitor
    0,                            // 13: Reserved
    (uintptr_t)Default_Handler,   // 14: PendSV
    (uintptr_t)Default_Handler,   // 15: SysTick
    (uintptr_t)Default_Handler    // 16: UART0
};
