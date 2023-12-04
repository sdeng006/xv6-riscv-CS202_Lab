#include "user/thread.h"
#include "kernel/riscv.h"

int thread_create(void*(start_routinue)(void*), void *arg){ 
    void* stack = malloc(PGSIZE);
    
    if(!stack) return -1;

    int tid = clone(stack);

    if (tid == 0) {
       start_routinue(arg);
       exit(0);
    }
    else {
        return 0;
    }

    return tid;
}

void lock_init(struct lock_t *lock){
    lock->locked = 0; 
    return;
}

void lock_acquire(struct lock_t *lock){
    while(1){
        if(__sync_lock_test_and_set(&lock->locked, 1) == 0)
        break;
    }
    __sync_synchronize();
    return;
}

void lock_release(struct lock_t *lock){ 
    __sync_synchronize();
    __sync_lock_release(&lock->locked); 
    return;
}