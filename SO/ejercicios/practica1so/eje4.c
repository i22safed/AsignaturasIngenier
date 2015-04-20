#include <sys/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main()
{ 
	pid_t pid;
	
	int i;
	
	pid = fork();
	
	switch(pid)
	{
		case -1:
			
			perror("Fork error\n");
			
			printf("errno value:%d\n", errno);
			
			exit(EXIT_FAILURE);
			
		case 0:
			
			printf(" El proceso hijo de id:%d, del proceso padre con id:%d\n", getpid(), getppid());		
			
			wait();
			
			break;
			
			
				
		default:
			
			sleep(30);
			
			printf("El proceso padre de id:%d, con el hijo con id: %d\n", getppid(), getpid());
			
			exit(EXIT_SUCCESS);
			
	
	}
	



	return 0;
}
