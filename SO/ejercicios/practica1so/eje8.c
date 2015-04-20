#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int global = 0;

int main()
{
	
	pid_t pid;

	int status;
	
	int hijo;	

	int i;
	
	int v = global;
	
	printf("global:%d , v:%d\n", global, v);
	

	printf("Introduce los hijos a crear\n");
	scanf("%d", &hijo);

	
	for(i = 0; i < hijo; i++)
	{
		pid = fork();
		

		switch(pid)
		{
			case -1: /* error del fork() */
				perror("fork error");
				printf("errno value= %d\n", errno);
		
				break;

			case 0: /* proceso hijo */
			
				printf("Proceso hijo %d; padre = %d \n", getpid(), getppid());
				
				global ++;
				v++;
				
				printf("global:%d , v:%d\n", global, v);
	
				exit(EXIT_SUCCESS);			

				break;

			default: /* padre */
				
				while(wait(&status)!=-1);			

				printf("Proceso padre:%d\n", getpid()); 
				sleep(2);	
		}	
	}
	
	
	
	return 0;
}
