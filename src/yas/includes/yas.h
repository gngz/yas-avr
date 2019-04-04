#ifndef _YAS_H
#define _YAS_H

#include <settings.h>

#define YAS_ERROR -1

typedef void (*yas_task) (void);

typedef enum  {TASK_READY, TASK_SEM, TASK_WAIT, TASK_ENDED, TASK_EMPTY} task_status;


typedef struct {
    void *sp;
    void *sem_pointer;
    uint8_t *TASK_NAME;
    uint8_t priority;
        task_status status;

  
} task_struct;

// Prototypes

void yas_system_timer_init();
void yas_init();
void yas_createTask(yas_task task, void *stack);
void yas_removeTask(yas_task task);
void yas_scheduler();
void yas_context_switch();



#endif