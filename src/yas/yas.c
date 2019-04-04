#include <stdint.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <yas.h>

// Global Vars

static task_struct task_array[YAS_MAX_TASKS];
uint8_t yas_current_task;
uint16_t yas_current_sp;
uint16_t yas_next_sp;

void yas_idle_task()
{
    while(1) {};
}

void yas_system_timer_init() {

    TCCR0A = 0;
    TCCR0B = 0;
    TCNT0 = 0;

    OCR0A = YAS_TIMER_VALUE;
    TCCR0B |= (1 << WGM02)|(1<<CS00)|(1 << CS02);
    TIMSK0 |= (1 << OCIE0A);
   

    sei();                              // Habilita as interrupções
    
    
}

void yas_init() {
    
    yas_system_timer_init();    // Configure Timer and Enable Timer Interrupts

    uint8_t *idle_task_sp = malloc(40);
    yas_createTask(yas_idle_task,idle_task_sp);
    
}


void yas_createTask(yas_task task, void *stack) {
   // Initalizade Stack

   int8_t *sp = stack;
    int i;
    // Set return Address
    sp[0] =  (uint16_t) task & 0xFF;
    sp[-1] = (uint16_t)task >> 8;

    // Set 32 Registers and REG = 0
    for( i = -2; i>-34; i--)
    {
        sp[i] = 0x00;
    }

    sp[-34] = 0x00; // SREG
    sei();

    // Intialize and insert Task Block




    

}

void yas_removeTask(yas_task task) {

}

void yas_scheduler() {

}



ISR(TIMER0_COMPA_vect, ISR_NAKED) { 
    // Save Context

    asm volatile(   "push r0            \t\n"
                    "in r0, __SREG__    \t\n"
                    "cli                \t\n"
                    "push r0            \t\n"
                    "push r1            \t\n"
                    "clr r1             \t\n"
                    "push r2            \t\n"
                    "push r3            \t\n"
                    "push r4            \t\n"
                    "push r5            \t\n"
                    "push r6            \t\n"
                    "push r7            \t\n"
                    "push r8            \t\n"
                    "push r9            \t\n"
                    "push r10           \t\n"
                    "push r11           \t\n"
                    "push r12           \t\n"
                    "push r13           \t\n"
                    "push r14           \t\n"
                    "push r15           \t\n"
                    "push r16           \t\n"
                    "push r17           \t\n"
                    "push r18           \t\n"
                    "push r19           \t\n"
                    "push r20           \t\n"
                    "push r21           \t\n"
                    "push r22           \t\n"
                    "push r23           \t\n"
                    "push r24           \t\n"
                    "push r25           \t\n"
                    "push r26           \t\n"
                    "push r27           \t\n"
                    "push r28           \t\n"
                    "push r29           \t\n"
                    "push r30           \t\n"
                    "push r31           \t\n"
                    );

    yas_current_sp = SP;
    yas_scheduler();
    SP = yas_next_sp;


    // Restore Context
     asm volatile(  "pop r31            \t\n"
                    "pop r30            \t\n"
                    "pop r29            \t\n"
                    "pop r28            \t\n"
                    "pop r27            \t\n"
                    "pop r26            \t\n"
                    "pop r25            \t\n"
                    "pop r24            \t\n"
                    "pop r23            \t\n"
                    "pop r22            \t\n"
                    "pop r21            \t\n"
                    "pop r20            \t\n"
                    "pop r19            \t\n"
                    "pop r18            \t\n"
                    "pop r17            \t\n"
                    "pop r16            \t\n"
                    "pop r15            \t\n"
                    "pop r14            \t\n"
                    "pop r13            \t\n"
                    "pop r12            \t\n"
                    "pop r11            \t\n"
                    "pop r10            \t\n"
                    "pop r9             \t\n"
                    "pop r8             \t\n"
                    "pop r7             \t\n"
                    "pop r6             \t\n"
                    "pop r5             \t\n"
                    "pop r4             \t\n"
                    "pop r3             \t\n"
                    "pop r2             \t\n"
                    "pop r1             \t\n"
                    "pop r0             \t\n"
                    "out __SREG__, r0   \t\n"
                    "pop r0             \t\n"

                    );


    reti();

    
}


