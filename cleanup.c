#include "shared_sem.h"

int main() {
	// access existing shared memory
	int shmid = shmget(SHM_KEY, SHM_SIZE, 0666);
	if(shmid == -1) {perror("shmget"); exit(1);}

	// access existing semaphore
	int semid = semget(SEM_KEY, 1, 0666);
	if(semid == -1) {perror("semget"); exit(1);}

	// destroy segment and semaphore
	shmctl(shmid, IPC_RMID, NULL);
	semctl(semid, 0, IPC_RMID);

	return 0;
}
