int thread_create(void*(start_routinue)(void*), void *arg){ 

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