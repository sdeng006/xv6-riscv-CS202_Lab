int thread_create(void*(start_routinue)(void*), void *arg){ 

}

int lock_init(volatile lock_t *lock){
    lock->flag = 0; 
    return 0
}

void lock_acquire(volatile lock_t *lock){
    while(1){
        if(xchg(&lock->flag, 1) ==0)
        break;
    }
}

void lock_release(volatile lock_t *lock){ 
    xchg(&lock->flag,0); 
}