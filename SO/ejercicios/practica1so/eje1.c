#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>



int main()
{
	
	pid_t pid;

	int status;
		
	int i;
	
	int hijo;
	
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
			exit(-1);
			
			break;

			default: /* padre */
			printf("Proceso padre:\n"); 
			sleep(2);	
		}	
	}
	while(wait(&status)!=-1);
	return 0;
}
