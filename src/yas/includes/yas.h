#ifndef _YAS_H
#define _YAS_H

#include <settings.h>

typedef void (*yas_task) (void);

typedef enum  {TASK_READY, TASK_SEM, TASK_WAIT, TASK_ENDED, TASK_EMPTY} task_status;


typedef struct {
    void *sp;
  
} task_struct;

// Prototypes






#endif