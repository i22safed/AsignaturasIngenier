#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char **argv)
{
	pid_t pid;
	
	int flag, valor ;
	atoi(argv [2]);
	
	pid = fork();
	
	if(argc!=3)
	{
		printf("El numero de argumentos tiene el formato ./eje5.c segundo valorEstado\n");
		
		exit(EXIT_FAILURE);
	
	}
	
	switch(pid)
	{
		case -1:
		
			perror("FORK ERROR\n");
			printf("errno value:%d\n", errno);
			
			exit(EXIT_FAILURE);
			
		case 0:
			
			sleep(atoi(argv [1]));
			
			printf("El proceso hijo con id:%d, del proceso padre con id:%d\n", getpid(), getppid());
			
			return atoi(argv[2]);
			
			break;
			
			
		default:
		
			while ((flag = wait(&valor)) > 0)
			{
				if (WIFEXITED(valor)) 
				{
           		 	printf("child exited, status=%d\n", WEXITSTATUS(valor));
       		 	} else if (WIFSIGNALED(valor)) 
       		 		{
           				printf("child killed (signal %d)\n", WTERMSIG(valor));
        			
        			} 
        				else if (WIFSTOPPED(valor)) 
        				{
           					printf("child stopped (signal %d)\n", WSTOPSIG(valor));
		  				}
			}
			printf("El proceso padre con id:%d, con proceso hijo con id:%d\n", getppid(), getpid());
			
	
	
	
	}
	


	return 0;
}
