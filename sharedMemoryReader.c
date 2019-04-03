#include <unistd.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
#include <stdlib.h>

#define SHSIZE    100

int main() 
{ 
	char *str;
	// ftok to generate unique key 
	key_t key = 9876; //ftok("shmfile",65); 

	// shmget returns an identifier in shmid 
	int shmid = shmget(key,SHSIZE,0666|IPC_CREAT); 

	// shmat to attach to shared memory 
	str = shmat(shmid,NULL,0); 

	printf("Data read from memory: %s\n",str); 
	
	//detach from shared memory 
	shmdt(str); 
	
	// destroy the shared memory 
	shmctl(shmid,IPC_RMID,NULL); 
	
	return 0; 
} 
