#include <stdint.h>

extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;

int main (void);

void Reset_Handler(void)
{
    uint32_t *p = &_sbss;
    uint32_t *source = &_sidata;
    uint32_t *destination = &_sdata;
    
    while (p < &_ebss) {    
        *p = 0;
        p++;
    }

    while (destination < &_edata) {    
        
        *destination = *source;
        destination++;
        source++;
    
    }

    main();
    while(1){

    }
}