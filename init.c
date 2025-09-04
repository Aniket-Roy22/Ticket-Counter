#include "shared_sem.h"

int main() {
	// create shared memory
	int shmid = shmget(SHM_KEY, SHM_SIZE, 0666 | IPC_CREAT);
        if (shmid == -1) { perror("shmget"); exit(1);}
	int *totalTickets = (int *) shmat(shmid, NULL, 0);
	*totalTickets = 100;

	// create semaphore
	int semid = semget(SEM_KEY, 1, 0666 | IPC_CREAT);
	if (semid == -1) { perror("semget"); exit(1);}

	// set semaphore to free
    	semctl(semid, 0, SETVAL, 1);
	printf("System ready with %d tickets.\n", *totalTickets);

	shmdt(totalTickets);

	return 0;
}
