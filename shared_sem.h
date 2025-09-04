#ifndef SHARED_SEM_H
#define SHARED_SEM_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SHM_KEY 0x1234
#define SHM_SIZE sizeof(int)
#define SHARED_MEMORY_FILE "tickets"
#define SEM_KEY 0x5678

// semaphore wait operation
static inline void sem_wait_op(int semid) {
    struct sembuf op = {0, -1, 0};
    semop(semid, &op, 1);
}

// semaphore signal operation
static inline void sem_signal_op(int semid) {
    struct sembuf op = {0, 1, 0};
    semop(semid, &op, 1);
}

#endif

