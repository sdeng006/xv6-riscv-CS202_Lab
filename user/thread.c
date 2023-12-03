#include "user/thread.h"

int thread_create(void*(start_routinue)(void*), void *arg){ 
    void* stack = malloc(PGSIZE);
    int pid = clone(stack);

    if (pid == 0) {
       start_routinue(arg);
    }
    else {
        return 0;
    }
}

int lock_init(volatile lock_t *lock){
    lock->locked = 0; 
    return 0
}

void lock_acquire(volatile lock_t *lock){
    while(1){
        if(xchg(&lock->locked, 1) ==0)
        break;
    }
}

void lock_release(volatile lock_t *lock){ 
    xchg(&lock->locked,0); 
}