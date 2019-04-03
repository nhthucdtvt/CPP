#include <unistd.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define SHSIZE    100

int main() 
{ 
	char *str;
	// ftok to generate unique key 
	key_t key = 9876; //ftok("shmfile",65); 

	// shmget returns an identifier in shmid 
	int shmid = shmget(key,SHSIZE, IPC_CREAT | 0666); 

	// shmat to attach to shared memory 
	str = shmat(shmid,NULL,0); 

	//printf("Write Data : "); 
	//scanf("%s",str); 
	memcpy(str,"Hello World",11);

	printf("Data written in memory: %s\n",str); 
	
	//detach from shared memory 
	shmdt(str); 

	return 0; 
} 
