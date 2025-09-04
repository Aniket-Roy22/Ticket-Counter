#include "shared_sem.h"

int main() {
	// get the shared memory segment
	int shmid = shmget(SHM_KEY, SHM_SIZE, 0666);
	if (shmid == -1) { perror("shmget"); exit(1);}

	// attach
	int *totalTickets = (int*) shmat(shmid, NULL, 0);
	if (totalTickets == (void*) -1) { perror("shmat"); exit(1);}

	// get semaphore id
	int semid = semget(SEM_KEY, 1, 0666);
	if(semid == -1) { perror("semget"); exit(1);}

	// sell ticket
	while(1)
	{
		printf("Seller 4: Waiting...\n");
		sem_wait_op(semid);

		if(*totalTickets > 0)
		{
			(*totalTickets)--;
			printf("Seller 4: Sold 1 ticket!\n");
			sleep(8);
			sem_signal_op(semid);
		}
		else
		{
			sem_signal_op(semid);
			break;
		}
	}

	shmdt(totalTickets); // detach
 	return 0;
}
